#ifndef REORDERHELPER_H
#define REORDERHELPER_H


#include <random>
#include <sstream>

#include <QObject>
#include <QtSql/QSqlQuery>
#include <QVariant>
#include <string>
#include <QDebug>

#include <iomanip>
#include <ctime>
#include <sstream>
#include <mutex>          // std::mutex


class reorderHelper : public QObject
{
    Q_OBJECT
public:
    explicit reorderHelper (QObject* parent = 0 ) : QObject(parent) {}


    Q_INVOKABLE void createOrder(QString orderID, QString fridgeID, QString supplierName, QString supplierEmail){
        {
        QSqlDatabase::removeDatabase("connectionoh");
        QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL","connectionoh");
        db.setHostName("localhost");
        db.setPort(3306);
        db.setUserName("root");
        db.setPassword("admin");
        db.setDatabaseName("sf");
        db.open();

        QSqlQuery query(db);

        //query.prepare("UPDATE uawe SET Username = ? WHERE UserID = ?");
        query.prepare("INSERT INTO orders (orderID, fridgeID, supplierName, supplierEmail) VALUES (?,?,?,?)");
        query.addBindValue(orderID);
        query.addBindValue(fridgeID);
        query.addBindValue(supplierName);
        query.addBindValue(supplierEmail);


        if (!query.exec()){
             qDebug("Create order Action failed");
        }



        query.prepare("INSERT INTO deliver (orderID) VALUES (?)");
        query.addBindValue(orderID);


        if (!query.exec()){
             qDebug("Create order, deliver Action failed");
        }


        }
    }

    Q_INVOKABLE int addItemToOrder(QString orderID, QString itemName, QString itemCount){
        {


        int count = itemCount.toInt();
        if(count <= 0){
            return 0;
        }

        QSqlDatabase::removeDatabase("connectionoh");
        QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL","connectionoh");
        db.setHostName("localhost");
        db.setPort(3306);
        db.setUserName("root");
        db.setPassword("admin");
        db.setDatabaseName("sf");
        db.open();

        QSqlQuery query(db);


        //get image
        query.prepare("SELECT itemPic FROM inventory WHERE itemName = ?");
        query.addBindValue(itemName);


        if (!query.exec()){
             qDebug("find itemPic in order Action failed");
             return 0;
        }


        QString theImage = "";

        while (query.next()) {
              theImage = query.value(0).toString();
        }


        //query.prepare("UPDATE uawe SET Username = ? WHERE UserID = ?");
        query.prepare("INSERT INTO orderdata (orderID, itemName, itemCount, image) VALUES (?,?,?,?)");
        query.addBindValue(orderID);
        query.addBindValue(itemName);
        query.addBindValue(count);
        query.addBindValue(theImage);


        if (!query.exec()){
             qDebug("add item to order Action failed");
             return 0;
        }


        query.prepare("INSERT INTO delivereditems (orderID, itemName, needed, image) VALUES (?,?,?,?)");
        query.addBindValue(orderID);
        query.addBindValue(itemName);
        query.addBindValue(count);
        query.addBindValue(theImage);


        if (!query.exec()){
             qDebug("add item to delivereditems Action failed");
             return 0;
        }


        return 1;



        }
    }
};

#endif // REORDERHELPER_H
