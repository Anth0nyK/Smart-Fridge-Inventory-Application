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

            //query.prepare("UPDATE uawe SET Username = ? WHERE UserID = ?");
            query.prepare("INSERT INTO orderdata (orderID, itemName, itemCount) VALUES (?,?,?)");
            query.addBindValue(orderID);
            query.addBindValue(itemName);
            query.addBindValue(count);


            if (!query.exec()){
                 qDebug("add item to order Action failed");
                 return 0;
            }

            return 1;
        }

        return 0;
        }
    }
};
#endif // ORDERHELPER_H
