#ifndef USERSMANAGEMENTHELPER_H
#define USERSMANAGEMENTHELPER_H


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


class usersManagementHelper : public QObject
{
    Q_OBJECT
public:
    explicit usersManagementHelper

    (QObject* parent = 0 ) : QObject(parent) {}

    Q_INVOKABLE int updateInfo(QString pic, QString Username, QString email, QString tel, QString userID){
        {

        //QString name = NULL;

        QSqlDatabase::removeDatabase("connectionumh");
        QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL","connectionumh");
        db.setHostName("localhost");
        db.setPort(3306);
        db.setUserName("root");
        db.setPassword("admin");
        db.setDatabaseName("sf");

        db.open();

        QString OGname;
        QString OGemail;
        QString OGtel;
        QString OGPic;

        QSqlQuery query(db);

        query.prepare("SELECT Username FROM user WHERE UserID = ?");
        query.addBindValue(userID);
        if (!query.exec()){
             qDebug("get username Action failed");
        }
        while (query.next()) {
              OGname = query.value(0).toString();
        }


        query.prepare("SELECT email FROM user WHERE UserID = ?");
        query.addBindValue(userID);
        if (!query.exec()){
             qDebug("get restaurant info Action failed");
        }
        while (query.next()) {
              OGemail = query.value(0).toString();
        }

        query.prepare("SELECT tel FROM user WHERE UserID = ?");
        query.addBindValue(userID);
        if (!query.exec()){
             qDebug("get restaurant info Action failed");
        }
        while (query.next()) {
              OGtel = query.value(0).toString();
        }

        query.prepare("SELECT profilePic FROM user WHERE UserID = ?");
        query.addBindValue(userID);
        if (!query.exec()){
             qDebug("get restaurant info Action failed");
        }
        while (query.next()) {
              OGPic = query.value(0).toString();
        }

        //qDebug() << "OGPic:" + OGPic + " pic:" + pic;
        if((OGname == Username) && (OGemail == email) && (OGtel == tel) && (OGPic == pic)){
            return 0;
        }

        query.prepare("UPDATE `sf`.`user` SET `Username` = ?, `email` = ?, `tel` = ?, `profilePic` = ?  WHERE (`userID` = ?);");
        //query.prepare("SELECT name FROM restaurant WHERE fridgeID = ?");
        query.addBindValue(Username);
        query.addBindValue(email);
        query.addBindValue(tel);
        query.addBindValue(pic);
        query.addBindValue(userID);



        if (!query.exec()){
             qDebug("update restaurant info Action failed");
             return 0;
        }

/*
        while (query.next()) {
              name = query.value(0).toString();
        }
*/
        return 1;

        }
    }


    Q_INVOKABLE int createaAccount(QString userID, QString userPW, QString username, QString accountType, QString fridgeID, QString profilePic, QString email, QString tel){
        {

        //QString name = NULL;

        QSqlDatabase::removeDatabase("connectionumh");
        QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL","connectionumh");
        db.setHostName("localhost");
        db.setPort(3306);
        db.setUserName("root");
        db.setPassword("admin");
        db.setDatabaseName("sf");

        db.open();

        QSqlQuery query(db);

        query.prepare("INSERT INTO `sf`.`user` (`UserID`, `UserPW`, `Username`, `AccountType`, `fridgeID`, `profilePic`, `email`, `tel`) VALUES (?, ?, ?, ?, ?, ?, ?, ?);");
        //query.prepare("SELECT name FROM restaurant WHERE fridgeID = ?");
        query.addBindValue(userID);
        query.addBindValue(userPW);
        query.addBindValue(username);
        query.addBindValue(accountType);
        query.addBindValue(fridgeID);
        query.addBindValue(profilePic);
        query.addBindValue(email);
        query.addBindValue(tel);

        if (!query.exec()){
             qDebug("create account Action failed");
             return 0;
        }


        query.prepare("INSERT INTO `sf`.`permission` (`userID`, `fridgeID`) VALUES (?, ?);");
        //query.prepare("SELECT name FROM restaurant WHERE fridgeID = ?");
        query.addBindValue(userID);
        query.addBindValue(fridgeID);

        if (!query.exec()){
             qDebug("create account permission Action failed");
             return 0;
        }

        //INSERT INTO `sf`.`notice` (`fridgeID`, `haveNotice`, `userID`) VALUES ('1', '1', '1');
        query.prepare("INSERT INTO `sf`.`notice` (`fridgeID`, `userID`) VALUES (?, ?);");
        //query.prepare("SELECT name FROM restaurant WHERE fridgeID = ?");

        query.addBindValue(fridgeID);
        query.addBindValue(userID);

        if (!query.exec()){
             qDebug("create account notice Action failed");
             return 0;
        }

/*
        while (query.next()) {
              name = query.value(0).toString();
        }
*/
        return 1;

        }
    }

    Q_INVOKABLE int deleteAccount(QString userID){
        {

        QString isAdmin = NULL;

        QSqlDatabase::removeDatabase("connectionumh");
        QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL","connectionumh");
        db.setHostName("localhost");
        db.setPort(3306);
        db.setUserName("root");
        db.setPassword("admin");
        db.setDatabaseName("sf");

        db.open();

        QSqlQuery query(db);


        //Check if the user is an admin
        query.prepare("SELECT isAdmin FROM user WHERE UserID = ?");
        query.addBindValue(userID);
        if (!query.exec()){
             qDebug("get isAdmin Action failed");
        }
        while (query.next()) {
              isAdmin = query.value(0).toString();
        }

        if(isAdmin == "1"){
            return 2;
        }



        query.prepare("DELETE FROM `sf`.`user` WHERE (`UserID` = ?);");
        //query.prepare("SELECT name FROM restaurant WHERE fridgeID = ?");
        query.addBindValue(userID);

        if (!query.exec()){
             qDebug("delete account Action failed");
             return 0;
        }



        query.prepare("DELETE FROM `sf`.`permission` WHERE (`userID` = ?);");
        //query.prepare("SELECT name FROM restaurant WHERE fridgeID = ?");
        query.addBindValue(userID);

        if (!query.exec()){
             qDebug("delete account permission Action failed");
             return 0;
        }


        query.prepare("DELETE FROM `sf`.`notice` WHERE (`userID` = ?);");
        //query.prepare("SELECT name FROM restaurant WHERE fridgeID = ?");
        query.addBindValue(userID);

        if (!query.exec()){
             qDebug("delete account notice Action failed");
             return 0;
        }

/*
        while (query.next()) {
              name = query.value(0).toString();
        }
*/
        return 1;

        }
    }

    Q_INVOKABLE int updatePW(QString oldPW, QString newPW, QString userID){
        {

        //QString name = NULL;

        QSqlDatabase::removeDatabase("connectionumh");
        QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL","connectionumh");
        db.setHostName("localhost");
        db.setPort(3306);
        db.setUserName("root");
        db.setPassword("admin");
        db.setDatabaseName("sf");

        db.open();

        QString OGPw;

        QSqlQuery query(db);

        query.prepare("SELECT UserPW FROM user WHERE UserID = ?");
        query.addBindValue(userID);
        if (!query.exec()){
             qDebug("get username Action failed");
        }
        while (query.next()) {
              OGPw = query.value(0).toString();
        }

        if((OGPw != oldPW)){
            return 0;
        }

        query.prepare("UPDATE `sf`.`user` SET `UserPW` = ? WHERE (`userID` = ?);");
        //query.prepare("SELECT name FROM restaurant WHERE fridgeID = ?");
        query.addBindValue(newPW);
        query.addBindValue(userID);


        if (!query.exec()){
             qDebug("update restaurant info Action failed");
             return 0;
        }

/*
        while (query.next()) {
              name = query.value(0).toString();
        }
*/
        return 1;

        }
    }

    Q_INVOKABLE QString getPic(QString userID){
        {

        QString url = NULL;

        QSqlDatabase::removeDatabase("connectionumh");
        QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL","connectionumh");
        db.setHostName("localhost");
        db.setPort(3306);
        db.setUserName("root");
        db.setPassword("admin");
        db.setDatabaseName("sf");

        db.open();

        QSqlQuery query(db);

        //get the user name
        query.prepare("SELECT profilePic FROM user WHERE userID = ?");
        query.addBindValue(userID);


        if (!query.exec()){
             qDebug("get url Action failed");
        }


        while (query.next()) {
              url = query.value(0).toString();
        }

        return url;

        }
    }

    Q_INVOKABLE QString getName(QString userID){
        {

        QString name = NULL;

        QSqlDatabase::removeDatabase("connectionumh");
        QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL","connectionumh");
        db.setHostName("localhost");
        db.setPort(3306);
        db.setUserName("root");
        db.setPassword("admin");
        db.setDatabaseName("sf");

        db.open();

        QSqlQuery query(db);

        //get the user name
        query.prepare("SELECT Username FROM user WHERE userID = ?");
        query.addBindValue(userID);


        if (!query.exec()){
             qDebug("get restaurant name Action failed");
        }


        while (query.next()) {
              name = query.value(0).toString();
        }

        return name;

        }
    }

    Q_INVOKABLE QString getEmail(QString userID){
        {

        QString email = NULL;

        QSqlDatabase::removeDatabase("connectionumh");
        QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL","connectionumh");
        db.setHostName("localhost");
        db.setPort(3306);
        db.setUserName("root");
        db.setPassword("admin");
        db.setDatabaseName("sf");

        db.open();

        QSqlQuery query(db);

        //get the user name
        query.prepare("SELECT email FROM user WHERE userID = ?");
        query.addBindValue(userID);


        if (!query.exec()){
             qDebug("get restaurant name Action failed");
        }


        while (query.next()) {
              email = query.value(0).toString();
        }

        return email;

        }
    }

    Q_INVOKABLE QString getTel(QString userID){
        {

        QString tel = NULL;

        QSqlDatabase::removeDatabase("connectionumh");
        QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL","connectionumh");
        db.setHostName("localhost");
        db.setPort(3306);
        db.setUserName("root");
        db.setPassword("admin");
        db.setDatabaseName("sf");

        db.open();

        QSqlQuery query(db);

        //get the user name
        query.prepare("SELECT tel FROM user WHERE userID = ?");
        query.addBindValue(userID);


        if (!query.exec()){
             qDebug("get restaurant name Action failed");
        }


        while (query.next()) {
              tel = query.value(0).toString();
        }

        return tel;

        }
    }




};

#endif // USERSMANAGEMENTHELPER_H
