#ifndef PERMISSIONHELPER_H
#define PERMISSIONHELPER_H

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


class permissionHelper : public QObject
{
    Q_OBJECT
public:
    explicit permissionHelper (QObject* parent = 0 ) : QObject(parent) {}

    Q_INVOKABLE int checkIfAdmin(QString userID){
        {
        QSqlDatabase::removeDatabase("connectionoh");
        QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL","connectionoh");
        db.setHostName("localhost");
        db.setPort(3306);
        db.setUserName("root");
        db.setPassword("admin");
        db.setDatabaseName("sf");
        db.open();

        QString isAdmin;

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
            return 1;
        }else{
            return 0;
        }

        }
    }

    Q_INVOKABLE int checkViewPermission(QString userID){
        {
        QSqlDatabase::removeDatabase("connectionoh");
        QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL","connectionoh");
        db.setHostName("localhost");
        db.setPort(3306);
        db.setUserName("root");
        db.setPassword("admin");
        db.setDatabaseName("sf");
        db.open();

        QString canView;
        QString isAdmin;

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
            return 1;
        }


        //Check the permission
        query.prepare("SELECT canView FROM permission WHERE userID = ?");
        query.addBindValue(userID);


        if (!query.exec()){
             qDebug("get check permission canView Action failed");
             return 0;
        }


        while (query.next()) {
              canView = query.value(0).toString();
        }


        if(canView == "1"){
            return 1;
        }else{
            return 0;
        }

        }
    }




    Q_INVOKABLE int checkOpenPermission(QString userID){
        {
        QSqlDatabase::removeDatabase("connectionoh");
        QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL","connectionoh");
        db.setHostName("localhost");
        db.setPort(3306);
        db.setUserName("root");
        db.setPassword("admin");
        db.setDatabaseName("sf");
        db.open();

        QString canOpen;
        QString isAdmin;

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
            return 1;
        }


        //Check the permission
        query.prepare("SELECT canOpen FROM permission WHERE userID = ?");
        query.addBindValue(userID);


        if (!query.exec()){
             qDebug("get check permission canView Action failed");
             return 0;
        }


        while (query.next()) {
              canOpen = query.value(0).toString();
        }


        if(canOpen == "1"){
            return 1;
        }else{
            return 0;
        }

    }
    }

    Q_INVOKABLE int checkHistoryPermission(QString userID){
        {
        QSqlDatabase::removeDatabase("connectionoh");
        QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL","connectionoh");
        db.setHostName("localhost");
        db.setPort(3306);
        db.setUserName("root");
        db.setPassword("admin");
        db.setDatabaseName("sf");
        db.open();

        QString canHistory;
        QString isAdmin;

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
            return 1;
        }


        //Check the permission
        query.prepare("SELECT canHistory FROM permission WHERE userID = ?");
        query.addBindValue(userID);


        if (!query.exec()){
             qDebug("get history permission canView Action failed");
             return 0;
        }


        while (query.next()) {
              canHistory = query.value(0).toString();
        }


        if(canHistory == "1"){
            return 1;
        }else{
            return 0;
        }

        }
    }

    Q_INVOKABLE int checkOrderPermission(QString userID){
        {
        QSqlDatabase::removeDatabase("connectionoh");
        QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL","connectionoh");
        db.setHostName("localhost");
        db.setPort(3306);
        db.setUserName("root");
        db.setPassword("admin");
        db.setDatabaseName("sf");
        db.open();

        QString canOrder;
        QString isAdmin;

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
            return 1;
        }


        //Check the permission
        query.prepare("SELECT canOrder FROM permission WHERE userID = ?");
        query.addBindValue(userID);


        if (!query.exec()){
             qDebug("get order permission canView Action failed");
             return 0;
        }


        while (query.next()) {
              canOrder = query.value(0).toString();
        }


        if(canOrder == "1"){
            return 1;
        }else{
            return 0;
        }

        }
    }

    Q_INVOKABLE int update(QString canView, QString canOpen, QString canHistory, QString canOrder ,QString userID){
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
        int canHistoryInt;
        int canOrderInt;

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

        if(canHistory == "true"){
            canHistoryInt = 1;
        }else{
            canHistoryInt = 0;
        }

        if(canOrder == "true"){
            canOrderInt = 1;
        }else{
            canOrderInt = 0;
        }

        QSqlQuery query(db);

        int OGcanView;
        int OGcanOpen;
        int OGcanHistory;
        int OGcanOrder;

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


        query.prepare("SELECT canHistory FROM permission WHERE userID = ?");
        query.addBindValue(userID);


        if (!query.exec()){
             qDebug("get og canHistory Action failed");
        }


        while (query.next()) {
              OGcanHistory = query.value(0).toString().toInt();
        }


        query.prepare("SELECT canOrder FROM permission WHERE userID = ?");
        query.addBindValue(userID);


        if (!query.exec()){
             qDebug("get og canHistory Action failed");
        }


        while (query.next()) {
              OGcanOrder = query.value(0).toString().toInt();
        }



        if((canViewInt == OGcanView) && (canOpenInt == OGcanOpen) && (canHistoryInt == OGcanHistory) && (canOrderInt == OGcanOrder)){
            return 0;
        }


        //qDebug() << "canView:" + canView + " canOpen:" + canOpen + " userID:" + userID;

        query.prepare("UPDATE `sf`.`permission` SET `canView` = ? ,`canOpen` = ? ,`canHistory` = ? ,`canOrder` = ?  WHERE (`userID` = ? );");
        //query.prepare("UPDATE uawe SET Username = ? WHERE UserID = ?");
        //query.prepare("INSERT INTO orders (orderID, fridgeID, supplierName, supplierEmail) VALUES (?,?,?,?)");
        query.addBindValue(canViewInt);
        query.addBindValue(canOpenInt);
        query.addBindValue(canHistoryInt);
        query.addBindValue(canOrderInt);
        query.addBindValue(userID);


        if (!query.exec()){
             qDebug("Update permission Action failed");
             return 0;
        }

        return 1;
        }
    }


};

#endif // PERMISSIONHELPER_H
