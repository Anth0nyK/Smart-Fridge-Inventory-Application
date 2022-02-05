#ifndef RESTAURANTINFOHELPER_H
#define RESTAURANTINFOHELPER_H

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


class restaurantinfoHelper : public QObject
{
    Q_OBJECT
public:
    explicit restaurantinfoHelper (QObject* parent = 0 ) : QObject(parent) {}

    Q_INVOKABLE int update(QString name, QString address1, QString address2, QString address3, QString tel, QString fridgeID){
        {

        //QString name = NULL;

        QSqlDatabase::removeDatabase("connectionrh");
        QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL","connectionrh");
        db.setHostName("localhost");
        db.setPort(3306);
        db.setUserName("root");
        db.setPassword("admin");
        db.setDatabaseName("sf");

        db.open();

        QString OGname;
        QString OGaddress1;
        QString OGaddress2;
        QString OGaddress3;
        QString OGtel;

        QSqlQuery query(db);

        query.prepare("SELECT name FROM restaurant WHERE fridgeID = ?");
        query.addBindValue(fridgeID);
        if (!query.exec()){
             qDebug("get restaurant info Action failed");
        }
        while (query.next()) {
              OGname = query.value(0).toString();
        }


        query.prepare("SELECT address1 FROM restaurant WHERE fridgeID = ?");
        query.addBindValue(fridgeID);
        if (!query.exec()){
             qDebug("get restaurant info Action failed");
        }
        while (query.next()) {
              OGaddress1 = query.value(0).toString();
        }

        query.prepare("SELECT address2 FROM restaurant WHERE fridgeID = ?");
        query.addBindValue(fridgeID);
        if (!query.exec()){
             qDebug("get restaurant info Action failed");
        }
        while (query.next()) {
              OGaddress2 = query.value(0).toString();
        }

        query.prepare("SELECT address3 FROM restaurant WHERE fridgeID = ?");
        query.addBindValue(fridgeID);
        if (!query.exec()){
             qDebug("get restaurant info Action failed");
        }
        while (query.next()) {
              OGaddress3 = query.value(0).toString();
        }

        query.prepare("SELECT tel FROM restaurant WHERE fridgeID = ?");
        query.addBindValue(fridgeID);
        if (!query.exec()){
             qDebug("get restaurant info Action failed");
        }
        while (query.next()) {
              OGtel = query.value(0).toString();
        }

        if((OGname == name) && (OGaddress1 == address1) && (OGaddress2 == address2) && (OGaddress3 == address3) && (OGtel == tel)){
            return 0;
        }

        //get the user name
        query.prepare("UPDATE `sf`.`restaurant` SET `name` = ?, `address1` = ?, `address2` = ?, `address3` = ? , `tel` = ? WHERE (`fridgeID` = ?);");
        //query.prepare("SELECT name FROM restaurant WHERE fridgeID = ?");
        query.addBindValue(name);
        query.addBindValue(address1);
        query.addBindValue(address2);
        query.addBindValue(address3);
        query.addBindValue(tel);
        query.addBindValue(fridgeID);


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

    Q_INVOKABLE QString getName(QString fridgeID){
        {

        QString name = NULL;

        QSqlDatabase::removeDatabase("connectionrh");
        QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL","connectionrh");
        db.setHostName("localhost");
        db.setPort(3306);
        db.setUserName("root");
        db.setPassword("admin");
        db.setDatabaseName("sf");

        db.open();

        QSqlQuery query(db);

        //get the user name
        query.prepare("SELECT name FROM restaurant WHERE fridgeID = ?");
        query.addBindValue(fridgeID);


        if (!query.exec()){
             qDebug("get restaurant name Action failed");
        }


        while (query.next()) {
              name = query.value(0).toString();
        }

        return name;

        }
    }

    Q_INVOKABLE QString getAddress1(QString fridgeID){
        {

        QString address = NULL;

        QSqlDatabase::removeDatabase("connectionrh");
        QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL","connectionrh");
        db.setHostName("localhost");
        db.setPort(3306);
        db.setUserName("root");
        db.setPassword("admin");
        db.setDatabaseName("sf");

        db.open();

        QSqlQuery query(db);

        //get the user name
        query.prepare("SELECT address1 FROM restaurant WHERE fridgeID = ?");
        query.addBindValue(fridgeID);


        if (!query.exec()){
             qDebug("get restaurant name Action failed");
        }


        while (query.next()) {
              address = query.value(0).toString();
        }

        return address;

        }
    }

    Q_INVOKABLE QString getAddress2(QString fridgeID){
        {

        QString address = NULL;

        QSqlDatabase::removeDatabase("connectionrh");
        QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL","connectionrh");
        db.setHostName("localhost");
        db.setPort(3306);
        db.setUserName("root");
        db.setPassword("admin");
        db.setDatabaseName("sf");

        db.open();

        QSqlQuery query(db);

        //get the user name
        query.prepare("SELECT address2 FROM restaurant WHERE fridgeID = ?");
        query.addBindValue(fridgeID);


        if (!query.exec()){
             qDebug("get restaurant name Action failed");
        }


        while (query.next()) {
              address = query.value(0).toString();
        }

        return address;

        }
    }

    Q_INVOKABLE QString getAddress3(QString fridgeID){
        {

        QString address = NULL;

        QSqlDatabase::removeDatabase("connectionrh");
        QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL","connectionrh");
        db.setHostName("localhost");
        db.setPort(3306);
        db.setUserName("root");
        db.setPassword("admin");
        db.setDatabaseName("sf");

        db.open();

        QSqlQuery query(db);

        //get the user name
        query.prepare("SELECT address3 FROM restaurant WHERE fridgeID = ?");
        query.addBindValue(fridgeID);


        if (!query.exec()){
             qDebug("get restaurant name Action failed");
        }


        while (query.next()) {
              address = query.value(0).toString();
        }

        return address;

        }
    }

    Q_INVOKABLE QString getTel(QString fridgeID){
        {

        QString tel = NULL;

        QSqlDatabase::removeDatabase("connectionrh");
        QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL","connectionrh");
        db.setHostName("localhost");
        db.setPort(3306);
        db.setUserName("root");
        db.setPassword("admin");
        db.setDatabaseName("sf");

        db.open();

        QSqlQuery query(db);

        //get the user name
        query.prepare("SELECT tel FROM restaurant WHERE fridgeID = ?");
        query.addBindValue(fridgeID);


        if (!query.exec()){
             qDebug("get restaurant name Action failed");
        }


        while (query.next()) {
              tel = query.value(0).toString();
        }

        return tel;

        }
    }


    Q_INVOKABLE int update(QString canView, QString canOpen, QString userID){
        {
        QSqlDatabase::removeDatabase("connectionoh");
        QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL","connectionoh");
        db.setHostName("localhost");
        db.setPort(3306);
        db.setUserName("root");
        db.setPassword("admin");
        db.setDatabaseName("sf");
        db.open();

        int canViewInt;
        int canOpenInt;

        if(canView == "true"){
            canViewInt = 1;
        }else{
            canViewInt = 0;
        }

        if(canOpen == "true"){
            canOpenInt = 1;
        }else{
            canOpenInt = 0;
        }

        QSqlQuery query(db);

        int OGcanView;
        int OGcanOpen;

        query.prepare("SELECT canView FROM permission WHERE userID = ?");
        query.addBindValue(userID);


        if (!query.exec()){
             qDebug("get og canView Action failed");
        }


        while (query.next()) {
              OGcanView = query.value(0).toString().toInt();
        }

        query.prepare("SELECT canOpen FROM permission WHERE userID = ?");
        query.addBindValue(userID);


        if (!query.exec()){
             qDebug("get og canOpen Action failed");
        }


        while (query.next()) {
              OGcanOpen = query.value(0).toString().toInt();
        }

        if((canViewInt == OGcanView) && (canOpenInt == OGcanOpen)){
            return 0;
        }


        //qDebug() << "canView:" + canView + " canOpen:" + canOpen + " userID:" + userID;

        query.prepare("UPDATE `sf`.`permission` SET `canView` = ? ,`canOpen` = ?  WHERE (`userID` = ? );");
        //query.prepare("UPDATE uawe SET Username = ? WHERE UserID = ?");
        //query.prepare("INSERT INTO orders (orderID, fridgeID, supplierName, supplierEmail) VALUES (?,?,?,?)");
        query.addBindValue(canViewInt);
        query.addBindValue(canOpenInt);
        query.addBindValue(userID);


        if (!query.exec()){
             qDebug("Update permission Action failed");
             return 0;
        }

        return 1;
        }
    }


};

#endif // RESTAURANTINFOHELPER_H
