#ifndef LOGIN_H
#define LOGIN_H


#include <QObject>
#include <QtSql/QSqlQuery>
#include <QVariant>
#include <string>
#include <QDebug>

class login : public QObject
{
    Q_OBJECT

   public:
       explicit login (QObject* parent = 0 ) : QObject(parent) {}

       Q_INVOKABLE QString loginToAccount(QString ID, QString PW){
           {

            QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
            db.setHostName("localhost");
            db.setPort(3306);
            db.setUserName("root");
            db.setPassword("admin");
            db.setDatabaseName("sf");

            if(db.open())
            {
                qDebug() << "Open";
            }
            else{
                qDebug() << "Close";
            }

/*
           qDebug() << "ID in login: " + ID;
           qDebug() << "PW in login: " + PW;

           QString UserID = "";

           //QSqlDatabase::removeDatabase("connection0");
           QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");

           db.setHostName("127.0.0.1");
           db.setPort(3306);
           db.setDatabaseName("sf");
           db.setUserName("root");
           db.setPassword("admin");

           db.open();

           QSqlQuery query(db);

           query.prepare("SELECT Users.UserID FROM Users WHERE Users.UserID = ? AND Users.UserPW = ?");
           query.addBindValue(ID);
           query.addBindValue(PW);


           if (!query.exec()){
                qDebug("Login Action failed");
           }


           while (query.next()) {
                 UserID = query.value(0).toString();
                 qDebug() << "user id in next : " + UserID;
           }


           if (UserID == ""){
               return "error";
           }





           return UserID;

*/
           }

       }
};





#endif // LOGIN_H
