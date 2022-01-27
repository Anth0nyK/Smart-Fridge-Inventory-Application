#ifndef PROFILEINFO_H
#define PROFILEINFO_H

#include <QObject>
#include <QtSql/QSqlQuery>
#include <QVariant>
#include <string>
#include <QDebug>

class profileinfo : public QObject
{
    Q_OBJECT
public:
    explicit profileinfo (QObject* parent = 0 ) : QObject(parent) {}

    Q_INVOKABLE QString getUsername(QString userID){
        {

        QString UserID = NULL;

        QSqlDatabase::removeDatabase("connectionpi");
        QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL","connectionpi");
        db.setHostName("localhost");
        db.setPort(3306);
        db.setUserName("root");
        db.setPassword("admin");
        db.setDatabaseName("sf");

        db.open();

        QSqlQuery query(db);

        //get the user name
        query.prepare("SELECT Username FROM user WHERE UserID = ?");
        query.addBindValue(userID);


        if (!query.exec()){
             qDebug("get user name Action failed");
        }


        while (query.next()) {
              UserID = query.value(0).toString();
        }

        return UserID;

        }
    }


    Q_INVOKABLE QString getImage(QString userID){
        {

        QString Image = NULL;

        QSqlDatabase::removeDatabase("connectionpi");
        QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL","connectionpi");
        db.setHostName("localhost");
        db.setPort(3306);
        db.setUserName("root");
        db.setPassword("admin");
        db.setDatabaseName("sf");

        db.open();

        QSqlQuery query(db);

        //get the user name
        query.prepare("SELECT profilePic FROM user WHERE UserID = ?");
        query.addBindValue(userID);


        if (!query.exec()){
             qDebug("get user name Action failed");
        }


        while (query.next()) {
              Image = query.value(0).toString();
        }

        return Image;

        }
    }

    Q_INVOKABLE QString getFridgeID(QString userID){
        {

        QString Image = NULL;

        QSqlDatabase::removeDatabase("connectionpi");
        QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL","connectionpi");
        db.setHostName("localhost");
        db.setPort(3306);
        db.setUserName("root");
        db.setPassword("admin");
        db.setDatabaseName("sf");

        db.open();

        QSqlQuery query(db);

        //get the user name
        query.prepare("SELECT fridgeID FROM user WHERE UserID = ?");
        query.addBindValue(userID);


        if (!query.exec()){
             qDebug("get user name Action failed");
        }


        while (query.next()) {
              Image = query.value(0).toString();
        }

        return Image;

        }
    }

    Q_INVOKABLE void changeUsername(QString userID, QString newuserName){
        {
        QSqlDatabase::removeDatabase("connectionpi2");
        QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL","connectionpi2");
        db.setHostName("localhost");
        db.setPort(3306);
        db.setUserName("root");
        db.setPassword("admin");
        db.setDatabaseName("sf");
        db.open();

        QSqlQuery query(db);

        //change the username
        query.prepare("UPDATE uawe SET Username = ? WHERE UserID = ?");
        query.addBindValue(newuserName);
        query.addBindValue(userID);


        if (!query.exec()){
             qDebug("change user name Action failed");
        }


        }
    }



    Q_INVOKABLE void changePicture(QString userID, QString newPicture){
        {

        QSqlDatabase::removeDatabase("connectionpi3");
        QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL","connectionpi3");
        db.setHostName("localhost");
        db.setPort(3306);
        db.setUserName("root");
        db.setPassword("admin");
        db.setDatabaseName("sf");
        db.open();

        QSqlQuery query(db);

        //change the username
        query.prepare("UPDATE user SET profilePic = ? WHERE UserID = ?");
        query.addBindValue(newPicture);
        query.addBindValue(userID);


        if (!query.exec()){
             qDebug("change picture Action failed");
        }


        }
    }

    Q_INVOKABLE void changePW(QString userID, QString newPW){
        {

        QSqlDatabase::removeDatabase("connectionpi3");
        QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL","connectionpi3");
        db.setHostName("localhost");
        db.setPort(3306);
        db.setUserName("root");
        db.setPassword("admin");
        db.setDatabaseName("sf");
        db.open();


        QSqlQuery query(db);

        //change the username
        query.prepare("UPDATE user SET UserPW = ? WHERE UserID = ?");
        query.addBindValue(newPW);
        query.addBindValue(userID);


        if (!query.exec()){
             qDebug("change picture Action failed");
        }


        }
    }


};

#endif // PROFILEINFO_H
