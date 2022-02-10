#ifndef ORDERHELPER_H
#define ORDERHELPER_H
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


class orderHelper : public QObject
{
    Q_OBJECT
public:
    explicit orderHelper (QObject* parent = 0 ) : QObject(parent) {}

    bool is_number(const std::string &s) {
      return !s.empty() && std::all_of(s.begin(), s.end(), ::isdigit);
    }

    Q_INVOKABLE QString getUUID(){
        {
        static std::random_device              rd;
        static std::mt19937                    gen(rd());
        static std::uniform_int_distribution<> dis(0, 15);
        static std::uniform_int_distribution<> dis2(8, 11);



        std::stringstream ss;
        int i;
        ss << std::hex;
        for (i = 0; i < 8; i++) {
            ss << dis(gen);
        }
        ss << "-";
        for (i = 0; i < 4; i++) {
            ss << dis(gen);
        }
        ss << "-4";
        for (i = 0; i < 3; i++) {
            ss << dis(gen);
        }
        ss << "-";
        ss << dis2(gen);
        for (i = 0; i < 3; i++) {
            ss << dis(gen);
        }
        ss << "-";
        for (i = 0; i < 12; i++) {
            ss << dis(gen);
        };

        return QString::fromStdString(ss.str());;
        }
    }


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


    Q_INVOKABLE QString findOrder(QString orderID){
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

        qDebug() << "orderID: " + orderID;

        //query.prepare("UPDATE uawe SET Username = ? WHERE UserID = ?");
        //query.prepare("SELECT orderID FROM orders WHERE fridgeID = ? and orderID = ?");
        //SELECT fridgeID FROM sf.orders WHERE orderID = "02453bf8-b891-4aa4-a44e-957da2d05cbf"
        query.prepare("SELECT fridgeID FROM sf.orders WHERE orderID = ? and completed != 1");
        query.addBindValue(orderID);


        if (!query.exec()){
             qDebug("find order Action failed");
             return "error";
        }


        QString theFridgeID = "";

        while (query.next()) {
              theFridgeID = query.value(0).toString();
        }

        qDebug() << "" + theFridgeID;


        return theFridgeID;
    }
    }


    Q_INVOKABLE int addItemToOrder(QString orderID, QString itemName, QString itemCount){
        {



        bool isNumber = is_number(itemCount.toStdString());

        if(isNumber){


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

            query.prepare("INSERT INTO delivereditems (orderID, itemName,needed,image) VALUES (?,?,?,?)");
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

        return 0;
        }
    }
};
#endif // ORDERHELPER_H
