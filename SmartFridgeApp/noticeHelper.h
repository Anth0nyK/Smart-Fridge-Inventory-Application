#ifndef NOTICEHELPER_H
#define NOTICEHELPER_H

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


class noticeHelper : public QObject
{
    Q_OBJECT
public:
    explicit noticeHelper (QObject* parent = 0 ) : QObject(parent) {}


    Q_INVOKABLE int getNoticeStatus(QString userID){
        {
        QString notice;

        QSqlDatabase::removeDatabase("connectionnH");
        QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL","connectionnH");
        db.setHostName("localhost");
        db.setPort(3306);
        db.setUserName("root");
        db.setPassword("admin");
        db.setDatabaseName("sf");
        db.open();

        QSqlQuery query(db);

        query.prepare("SELECT haveNotice FROM notice WHERE userID = ?");
        query.addBindValue(userID);

        if (!query.exec()){
             qDebug("Select haveNotice status Action failed");
             return 0;
        }

        while (query.next()) {
              notice = query.value(0).toString();
        }

        //qDebug() << "testing: " + notice;
        if(notice == "1"){
            return 1;
        }else{
            return 0;
        }


        }
    }


    Q_INVOKABLE void resetNotice(QString userID){
        {
        QString notice;

        QSqlDatabase::removeDatabase("connectionnH2");
        QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL","connectionnH2");
        db.setHostName("localhost");
        db.setPort(3306);
        db.setUserName("root");
        db.setPassword("admin");
        db.setDatabaseName("sf");
        db.open();

        QSqlQuery query(db);

        query.prepare("UPDATE `sf`.`notice` SET `haveNotice` = '0' WHERE (`userID` = ?);");
        //query.prepare("SELECT haveNotice FROM notice WHERE userID = ?");
        query.addBindValue(userID);

        if (!query.exec()){
             qDebug("reset haveNotice status Action failed");
             //return 0;
        }


        //return 1;


        }
    }

};

#endif // NOTICEHELPER_H
