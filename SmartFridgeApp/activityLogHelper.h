#ifndef ACTIVITYLOGHELPER_H
#define ACTIVITYLOGHELPER_H


#include <QObject>
#include <QtSql/QSqlQuery>
#include <QVariant>
#include <string>
#include <QDebug>

#include <iomanip>
#include <ctime>
#include <sstream>
#include <mutex>          // std::mutex


class activityLogHelper : public QObject
{
    Q_OBJECT
public:
    explicit activityLogHelper (QObject* parent = 0 ) : QObject(parent) {}

    bool is_number(const std::string &s) {
      return !s.empty() && std::all_of(s.begin(), s.end(), ::isdigit);
    }


    Q_INVOKABLE void createLog(QString action, QString by, QString fridgeID){
        {
       // qDebug() << action + "," + by + "," + fridgeID + ".";

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
        //query.prepare("INSERT INTO orders (orderID, fridgeID, supplierName, supplierEmail) VALUES (?,?,?,?)");
        query.prepare("INSERT INTO activitylog (action, by, fridgeID) VALUES (?, ?, ?)");
        query.prepare("INSERT INTO `sf`.`activitylog` (`action`, `by`, `fridgeID`) VALUES (?, ?, ?);");
        query.addBindValue(action);
        query.addBindValue(by);
        query.addBindValue(fridgeID);


        if (!query.exec()){
             qDebug("Create order Action failed");
        }


        }
    }
};

#endif // ACTIVITYLOGHELPER_H
