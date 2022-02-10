#ifndef ITEMHELPER_H
#define ITEMHELPER_H

#include <QObject>
#include <QtSql/QSqlQuery>
#include <QVariant>
#include <string>
#include <QDebug>

#include <iomanip>
#include <ctime>
#include <sstream>
#include <mutex>          // std::mutex

#include <random>
#include <sstream>
//std::mutex dbmtx;

class itemHelper : public QObject
{
    Q_OBJECT
public:
    explicit itemHelper (QObject* parent = 0 ) : QObject(parent) {}

    Q_INVOKABLE void updateDeliverItems(QString dAmount,QString itemName, QString orderID){
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

        /*
        //change the username
        query.prepare("UPDATE delivereditems SET deliveredAmount = ? WHERE itemName = ? AND orderID = ?");
        query.addBindValue(dAmount);
        query.addBindValue(itemName);
        query.addBindValue(orderID);


        if (!query.exec()){
             qDebug("change picture Action failed");
        }
        */

        query.prepare("UPDATE delivereditems SET needed = needed - ? WHERE itemName = ? and orderID = ?");
        query.addBindValue(dAmount);
        query.addBindValue(itemName);
        query.addBindValue(orderID);

        if (!query.exec()){
             qDebug("item count increment Action failed");
        }


        }
    }

    Q_INVOKABLE void updateDeliverStatus(QString orderID){
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

        query.prepare("UPDATE `sf`.`orders` SET `completed` = '1' WHERE (`orderID` = ?);");
        query.addBindValue(orderID);

        if (!query.exec()){
             qDebug("update orderID in deliver Action failed");
        }


        }
    }

    Q_INVOKABLE int getDeliverItemsCount(QString itemName, QString orderID){
        {
        QSqlDatabase::removeDatabase("connectionpi3");
        QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL","connectionpi3");

        int theAmount = 0;

        db.setHostName("localhost");
        db.setPort(3306);
        db.setUserName("root");
        db.setPassword("admin");
        db.setDatabaseName("sf");

        db.open();

        QSqlQuery query(db);

        query.prepare("SELECT needed FROM delivereditems WHERE itemName = ? and orderID = ?");
        query.addBindValue(itemName);
        query.addBindValue(orderID);


        if (!query.exec()){
             qDebug("get deliver items for delivery Action failed");
             return 0;
        }


        while (query.next()) {
              theAmount = query.value(0).toString().toInt();
        }

        return theAmount;
        }
    }


    Q_INVOKABLE int deleteTemp(QString itemID){
        {

        int itemCount = NULL;

        QSqlDatabase::removeDatabase("connectionii");
        QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL","connectionii");
        db.setHostName("localhost");
        db.setPort(3306);
        db.setUserName("root");
        db.setPassword("admin");
        db.setDatabaseName("sf");

        db.open();

        QSqlQuery query(db);

        //check if itemcount > 0
        query.prepare("SELECT itemCount FROM inventory WHERE itemID = ?");
        query.addBindValue(itemID);


        if (!query.exec()){
             qDebug("get itemcount for delete Action failed");
             return 0;
        }


        while (query.next()) {
              itemCount = query.value(0).toString().toInt();
        }

        if(itemCount > 0){
            return 2;
        }




        //delete
        query.prepare("DELETE FROM `sf`.`inventory` WHERE (`itemID` = ?);");
        query.addBindValue(itemID);


        if (!query.exec()){
             qDebug("delete item template Action failed");
             return 0;
        }


        return 1;

        }
    }

    Q_INVOKABLE bool getAlertOn(QString itemID){
        {

        bool alertOn = NULL;

        QSqlDatabase::removeDatabase("connectionii");
        QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL","connectionii");
        db.setHostName("localhost");
        db.setPort(3306);
        db.setUserName("root");
        db.setPassword("admin");
        db.setDatabaseName("sf");

        db.open();

        QSqlQuery query(db);

        //get the user name
        query.prepare("SELECT alertOn FROM inventory WHERE itemID = ?");
        query.addBindValue(itemID);


        if (!query.exec()){
             qDebug("get alertOn Action failed");
             return 0;
        }

        QString alertOnStr;

        while (query.next()) {
              alertOnStr = query.value(0).toString();
        }

        if(alertOnStr == "1"){
            alertOn = true;
        }else{
            alertOn = false;
        }

        return alertOn;

        }
    }


    Q_INVOKABLE bool getReorderOn(QString itemID){
        {

        bool reorderOn = NULL;

        QSqlDatabase::removeDatabase("connectionii");
        QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL","connectionii");
        db.setHostName("localhost");
        db.setPort(3306);
        db.setUserName("root");
        db.setPassword("admin");
        db.setDatabaseName("sf");

        db.open();

        QSqlQuery query(db);

        //get the user name
        query.prepare("SELECT reorderOn FROM inventory WHERE itemID = ?");
        query.addBindValue(itemID);


        if (!query.exec()){
             qDebug("get alertOn Action failed");
             return 0;
        }

        QString reorderOnStr;

        while (query.next()) {
              reorderOnStr = query.value(0).toString();
        }

        if(reorderOnStr == "1"){
            reorderOn = true;
        }else{
            reorderOn = false;
        }

        return reorderOn;

        }
    }


    Q_INVOKABLE QString getItemname(QString itemID){
        {

        QString ItemName = NULL;

        QSqlDatabase::removeDatabase("connectionii");
        QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL","connectionii");
        db.setHostName("localhost");
        db.setPort(3306);
        db.setUserName("root");
        db.setPassword("admin");
        db.setDatabaseName("sf");

        db.open();

        QSqlQuery query(db);

        //get the user name
        query.prepare("SELECT itemName FROM inventory WHERE itemID = ?");
        query.addBindValue(itemID);


        if (!query.exec()){
             qDebug("get user name Action failed");
        }


        while (query.next()) {
              ItemName = query.value(0).toString();
        }

        return ItemName;

        }
    }

    Q_INVOKABLE int getReorderAmount(QString itemID){
        {

        int reorderCount = NULL;

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
        query.prepare("SELECT reorderAmount FROM inventory WHERE itemID = ?");
        query.addBindValue(itemID);


        if (!query.exec()){
             qDebug("get reorderAmount Action failed");
             return 0;
        }


        while (query.next()) {
              reorderCount = query.value(0).toString().toInt();
        }

        return reorderCount;

        }
    }


    Q_INVOKABLE QString getItemCount(QString itemID){
        {

        QString ItemCount = NULL;

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
        query.prepare("SELECT itemCount FROM inventory WHERE itemID = ?");
        query.addBindValue(itemID);


        if (!query.exec()){
             qDebug("get user name Action failed");
        }


        while (query.next()) {
              ItemCount = query.value(0).toString();
        }

        return ItemCount;

        }
    }

    Q_INVOKABLE QString getSupplierName(QString itemID){
        {

        QString SupplierName = NULL;

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
        query.prepare("SELECT supplierName FROM inventory WHERE itemID = ?");
        query.addBindValue(itemID);


        if (!query.exec()){
             qDebug("get user name Action failed");
        }


        while (query.next()) {
              SupplierName = query.value(0).toString();
        }

        return SupplierName;

        }
    }

    Q_INVOKABLE QString getSupplierEmail(QString itemID){
        {

        QString SupplierEmail = NULL;

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
        query.prepare("SELECT supplierEmail FROM inventory WHERE itemID = ?");
        query.addBindValue(itemID);


        if (!query.exec()){
             qDebug("get user name Action failed");
        }


        while (query.next()) {
              SupplierEmail = query.value(0).toString();
        }

        return SupplierEmail;

        }
    }

    Q_INVOKABLE int getAlert(QString itemID){
        {

        int Alert = NULL;

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
        query.prepare("SELECT alertWhen FROM inventory WHERE itemID = ?");
        query.addBindValue(itemID);


        if (!query.exec()){
             qDebug("get user name Action failed");
        }


        while (query.next()) {
              Alert = query.value(0).toString().toInt();
        }

        return Alert;

        }
    }


    Q_INVOKABLE int getReorder(QString itemID){
        {

        int Reorder = NULL;

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
        query.prepare("SELECT reorderWhen FROM inventory WHERE itemID = ?");
        query.addBindValue(itemID);


        if (!query.exec()){
             qDebug("get user name Action failed");
        }


        while (query.next()) {
              Reorder = query.value(0).toString().toInt();
        }

        return Reorder;

        }
    }


    //Change item picture
    Q_INVOKABLE void changePicture(QString itemID, QString newPicture){
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
        query.prepare("UPDATE inventory SET itemPic = ? WHERE itemID = ?");
        query.addBindValue(newPicture);
        query.addBindValue(itemID);


        if (!query.exec()){
             qDebug("change picture Action failed");
        }


        }
    }

    //Update the info of a item
    Q_INVOKABLE int updateItemInfo(QString itemName, QString supplierName, QString alertWhen, QString reorderWhen, QString supplierEmail, QString reorderAmount, bool alertOn, bool reorderOn ,QString itemID){
        {
        QSqlDatabase::removeDatabase("connectionpi4");
        QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL","connectionpi4");

        db.setHostName("localhost");
        db.setPort(3306);
        db.setUserName("root");
        db.setPassword("admin");
        db.setDatabaseName("sf");

        QString OGitemName;
        QString OGsupplierName;
        QString OGalertWhen;
        QString OGreorderWhen;
        QString OGsupplierEmail;
        QString OGreorderAmount;
        QString OGalertOn;
        QString OGreorderOn;



        int alertOnInt;
        int reorderOnInt;

        if (alertOn == true){
            alertOnInt = 1;
        }else{
            alertOnInt = 0;
        }

        if(reorderOn == true){
            reorderOnInt = 1;
        }else{
            reorderOnInt = 0;
        }

        db.open();

        QSqlQuery query(db);

        query.prepare("SELECT itemName FROM inventory WHERE itemID = ?");
        query.addBindValue(itemID);
        if (!query.exec()){
             qDebug("get user name Action failed");
        }
        while (query.next()) {
              OGitemName = query.value(0).toString();
        }


        query.prepare("SELECT supplierName FROM inventory WHERE itemID = ?");
        query.addBindValue(itemID);
        if (!query.exec()){
             qDebug("get user name Action failed");
        }
        while (query.next()) {
              OGsupplierName = query.value(0).toString();
        }

        query.prepare("SELECT alertWhen FROM inventory WHERE itemID = ?");
        query.addBindValue(itemID);
        if (!query.exec()){
             qDebug("get user name Action failed");
        }
        while (query.next()) {
              OGalertWhen = query.value(0).toString();
        }

        query.prepare("SELECT reorderWhen FROM inventory WHERE itemID = ?");
        query.addBindValue(itemID);
        if (!query.exec()){
             qDebug("get user name Action failed");
        }
        while (query.next()) {
              OGreorderWhen = query.value(0).toString();
        }


        query.prepare("SELECT supplierEmail FROM inventory WHERE itemID = ?");
        query.addBindValue(itemID);
        if (!query.exec()){
             qDebug("get user name Action failed");
        }
        while (query.next()) {
              OGsupplierEmail = query.value(0).toString();
        }


        query.prepare("SELECT reorderAmount FROM inventory WHERE itemID = ?");
        query.addBindValue(itemID);
        if (!query.exec()){
             qDebug("get user name Action failed");
        }
        while (query.next()) {
              OGreorderAmount = query.value(0).toString();
        }

        query.prepare("SELECT alertOn FROM inventory WHERE itemID = ?");
        query.addBindValue(itemID);
        if (!query.exec()){
             qDebug("get user name Action failed");
        }
        while (query.next()) {
              OGalertOn = query.value(0).toString();
        }

        query.prepare("SELECT reorderOn FROM inventory WHERE itemID = ?");
        query.addBindValue(itemID);
        if (!query.exec()){
             qDebug("get user name Action failed");
        }
        while (query.next()) {
              OGreorderOn = query.value(0).toString();
        }

//QString itemName, QString supplierName, QString alertWhen, QString reorderWhen, QString supplierEmail, QString reorderAmount, bool alertOn, bool reorderOn
        if((itemName == OGitemName) && (supplierName == OGsupplierName) && (alertWhen == OGalertWhen) && (reorderWhen == OGreorderWhen) && (supplierEmail == OGsupplierEmail) && (reorderAmount == OGreorderAmount) && (alertOnInt == OGalertOn.toInt()) && (reorderOnInt == OGreorderOn.toInt())){
            return 0;
        }


        //change the username
        query.prepare("UPDATE inventory SET itemName = ?, supplierName = ?, alertWhen = ?, reorderWhen = ?, supplierEmail = ?, reorderAmount = ?, alertOn = ? , reorderOn = ? WHERE itemID = ?");
        //query.prepare("UPDATE inventory SET itemPic = ? WHERE itemID = ?");
        query.addBindValue(itemName);
        query.addBindValue(supplierName);
        query.addBindValue(alertWhen);
        query.addBindValue(reorderWhen);
        query.addBindValue(supplierEmail);
        query.addBindValue(reorderAmount);
        query.addBindValue(alertOnInt);
        query.addBindValue(reorderOnInt);
        query.addBindValue(itemID);

        if (!query.exec()){
             qDebug("update item info Action failed");
             return 0;
        }
        return 1;

        }
    }



    //Create a new item
    //INSERT INTO `sf`.`inventory` (`itemName`, `fridgeID`, `itemCount`, `alertWhen`, `reorderWhen`) VALUES ('a', '1', '1', '1', '1');
    Q_INVOKABLE void addItem(QString itemName, QString fridgeID , QString alertWhen, QString reorderWhen, QString supplierName, QString supplierEmail, QString itemPic){
        {
        QSqlDatabase::removeDatabase("connectionpi4");
        QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL","connectionpi4");

        db.setHostName("localhost");
        db.setPort(3306);
        db.setUserName("root");
        db.setPassword("admin");
        db.setDatabaseName("sf");

        db.open();

        QSqlQuery query(db);


        query.prepare("INSERT INTO inventory (itemName, fridgeID, alertWhen, reorderWhen, supplierName, supplierEmail, itemPic) VALUES (?,?,?,?,?,?,?) ");

        query.addBindValue(itemName);
        query.addBindValue(fridgeID);
        query.addBindValue(alertWhen);
        query.addBindValue(reorderWhen);
        query.addBindValue(supplierName);
        query.addBindValue(supplierEmail);
        query.addBindValue(itemPic);

        if (!query.exec()){
             qDebug("Item Create Action failed");
        }


        }
        }

        bool is_number(const std::string &s) {
          return !s.empty() && std::all_of(s.begin(), s.end(), ::isdigit);
        }

        //insert a item
        Q_INVOKABLE void insertItem(QString itemID, QString fridgeID, QString amount, QString expiryDate){
            {
            QSqlDatabase::removeDatabase("connectionpi5");
            QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL","connectionpi5");

            bool isNumber = is_number(amount.toStdString());
            if(isNumber){
                QString insertDate;
                //QString expiryDate;

                auto t = std::time(nullptr);
                auto tm = *std::localtime(&t);

                std::ostringstream oss;
                oss << std::put_time(&tm,"%Y-%m-%d");
                auto str = oss.str();

                insertDate = QString::fromStdString(str);
                //expiryDate = insertDate;


                //qDebug() << QString::fromStdString(str);

                db.setHostName("localhost");
                db.setPort(3306);
                db.setUserName("root");
                db.setPassword("admin");
                db.setDatabaseName("sf");
                db.open();

                QSqlQuery query(db);

                /*
                int itemCount;

                query.prepare("SELECT itemCount FROM inventory WHERE itemID = ?");
                query.addBindValue(itemID);
                if (!query.exec()){
                     qDebug("get item count Action failed");
                }

                while (query.next()) {
                      itemCount = query.value(0).toInt();
                }

                if(amount.toInt() > itemCount){

                }
                else{

                }
                */



                for (int i = 0; i < amount.toInt(); i++) {
                    //dbmtx.lock();

                    query.prepare("INSERT INTO itemdata (itemID, fridgeID, insertDate, expiryDate) VALUES (?,?,?,?)");
                    query.addBindValue(itemID);
                    query.addBindValue(fridgeID);
                    query.addBindValue(insertDate);
                    query.addBindValue(expiryDate);

                    if (!query.exec()){
                         qDebug("insert item info Action failed");
                    }

                    //dbmtx.unlock();
                }

                query.prepare("UPDATE inventory SET itemCount = itemCount + ? WHERE itemID = ?");
                query.addBindValue(amount);
                query.addBindValue(itemID);

                if (!query.exec()){
                     qDebug("item count increment Action failed");
                }

                }
            }

        }

        Q_INVOKABLE void insertItemDelivery(QString orderID, QString itemName , QString amount, QString expiryDate){
            {
            QSqlDatabase::removeDatabase("connectionpi5");
            QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL","connectionpi5");

            bool isNumber = is_number(amount.toStdString());
            if(isNumber){
                QString insertDate;
                //QString expiryDate;

                auto t = std::time(nullptr);
                auto tm = *std::localtime(&t);

                std::ostringstream oss;
                oss << std::put_time(&tm,"%Y-%m-%d");
                auto str = oss.str();

                insertDate = QString::fromStdString(str);
                //expiryDate = insertDate;


                //qDebug() << QString::fromStdString(str);

                db.setHostName("localhost");
                db.setPort(3306);
                db.setUserName("root");
                db.setPassword("admin");
                db.setDatabaseName("sf");
                db.open();

                QSqlQuery query(db);

                /*
                int itemCount;

                query.prepare("SELECT itemCount FROM inventory WHERE itemID = ?");
                query.addBindValue(itemID);
                if (!query.exec()){
                     qDebug("get item count Action failed");
                }

                while (query.next()) {
                      itemCount = query.value(0).toInt();
                }

                if(amount.toInt() > itemCount){

                }
                else{

                }
                */
                //Get fridgeID
                QString theFridgeID;
                query.prepare("SELECT fridgeID FROM orders WHERE orderID = ?");
                query.addBindValue(orderID);
                if (!query.exec()){
                     qDebug("get fridgeID in delivery insert Action failed");
                }

                while (query.next()) {
                      theFridgeID = query.value(0).toString();
                }

                qDebug() << "" + theFridgeID;


                //Get itemID
                QString theItemID;
                query.prepare("SELECT itemID FROM inventory WHERE itemName = ? and fridgeID = ?");
                query.addBindValue(itemName);
                query.addBindValue(theFridgeID);
                if (!query.exec()){
                     qDebug("get fridgeID in delivery insert Action failed");
                }

                while (query.next()) {
                      theItemID = query.value(0).toString();
                }



                for (int i = 0; i < amount.toInt(); i++) {
                    //dbmtx.lock();

                    query.prepare("INSERT INTO itemdata (itemID, fridgeID, insertDate, expiryDate) VALUES (?,?,?,?)");
                    query.addBindValue(theItemID);
                    query.addBindValue(theFridgeID);
                    query.addBindValue(insertDate);
                    query.addBindValue(expiryDate);

                    if (!query.exec()){
                         qDebug("insert item info Action failed");
                    }

                    //dbmtx.unlock();
                }

                query.prepare("UPDATE inventory SET itemCount = itemCount + ? WHERE itemID = ?");
                query.addBindValue(amount);
                query.addBindValue(theItemID);

                if (!query.exec()){
                     qDebug("item count increment Action failed");
                }

                }
            }

        }

    Q_INVOKABLE QString gettodayDate(){
        {

        auto t = std::time(nullptr);
        auto tm = *std::localtime(&t);

        std::ostringstream oss;
        oss << std::put_time(&tm,"%Y-%m-%d");
        auto str = oss.str();

        return QString::fromStdString(str);

        }
    }


    Q_INVOKABLE QString takeItem(QString itemID, QString amount){
        {

        //ORDER BY 'itemDataID' LIMIT 1
        QSqlDatabase::removeDatabase("connectionpi5");
        QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL","connectionpi5");

        bool isNumber = is_number(amount.toStdString());
        if(isNumber){

            QString actionDate;
            auto t = std::time(nullptr);
            auto tm = *std::localtime(&t);
            std::ostringstream oss;
            oss << std::put_time(&tm,"%Y-%m-%d");
            auto str = oss.str();
            actionDate = QString::fromStdString(str);





            db.setHostName("localhost");
            db.setPort(3306);
            db.setUserName("root");
            db.setPassword("admin");
            db.setDatabaseName("sf");
            db.open();

            QSqlQuery query(db);


            int itemCount;
            query.prepare("SELECT itemCount FROM inventory WHERE itemID = ?");
            query.addBindValue(itemID);
            if (!query.exec()){
                 qDebug("get item count Action failed");
            }

            while (query.next()) {
                  itemCount = query.value(0).toInt();
            }
            //qDebug() << amount.toInt();
            //qDebug() << itemCount;
            if(amount.toInt() > itemCount){
                //qDebug() << QString::fromStdString("testing");
                return "tooLarge";
            }
            else{
                bool succeed = false;
                for (int i = 0; i < amount.toInt(); i++) {
                    //dbmtx.lock();
                    //DELETE FROM `sf`.`itemdata` WHERE (`itemID` = '1') ORDER BY 'itemDataID' LIMIT 1;

                    query.prepare("DELETE FROM `sf`.`itemdata` WHERE (`itemID` = ?) ORDER BY 'itemDataID' LIMIT 1");
                    query.addBindValue(itemID);

                    if (!query.exec()){
                         qDebug("delete item info Action failed");

                    }
                    else{
                        succeed = true;
                    }

                    //dbmtx.unlock();
                }
                if(succeed){
                    query.prepare("UPDATE inventory SET itemCount = itemCount - ? WHERE itemID = ?");
                    query.addBindValue(amount);
                    query.addBindValue(itemID);

                    if (!query.exec()){
                         qDebug("item count increment Action failed");
                         return 0;
                    }

                    int alertOn;
                    int reorderOn;

                    query.prepare("SELECT alertOn FROM inventory WHERE itemID = ?");
                    query.addBindValue(itemID);
                    if (!query.exec()){
                         qDebug("get alertOn count Action failed");
                    }
                    while (query.next()) {
                          alertOn = query.value(0).toInt();
                    }

                    query.prepare("SELECT reorderOn FROM inventory WHERE itemID = ?");
                    query.addBindValue(itemID);
                    if (!query.exec()){
                         qDebug("get reorderOn count Action failed");
                    }
                    while (query.next()) {
                          reorderOn = query.value(0).toInt();
                    }


                    int newItemCount;

                    query.prepare("SELECT itemCount FROM inventory WHERE itemID = ?");
                    query.addBindValue(itemID);
                    if (!query.exec()){
                         qDebug("get new item count Action failed");
                    }
                    while (query.next()) {
                          newItemCount = query.value(0).toInt();
                    }


                    if(alertOn == 1){
                        int alertWhen;
                        query.prepare("SELECT alertWhen FROM inventory WHERE itemID = ?");
                        query.addBindValue(itemID);
                        if (!query.exec()){
                             qDebug("get alertWhen Action failed");
                        }
                        while (query.next()) {
                              alertWhen = query.value(0).toInt();
                        }

                        if(newItemCount <= alertWhen){
                            //get fridgeID first

                            int fridgeID;
                            query.prepare("SELECT fridgeID FROM inventory WHERE itemID = ?");
                            query.addBindValue(itemID);
                            if (!query.exec()){
                                 qDebug("get alertWhen Action failed");
                            }
                            while (query.next()) {
                                  fridgeID = query.value(0).toInt();
                            }



                            //UPDATE `sf`.`notice` SET `haveNotice` = '1' WHERE (`idnotice` = '1');
                            query.prepare("UPDATE `sf`.`notice` SET `haveNotice` = '1' WHERE (`fridgeID` = ?);");
                            query.addBindValue(fridgeID);

                            if (!query.exec()){
                                 qDebug("item count increment Action failed");
                                 return 0;
                            }



                            QString theMessage;
                            QString theItemName;
                            //get item name
                            query.prepare("SELECT itemName FROM inventory WHERE itemID = ?");
                            query.addBindValue(itemID);
                            if (!query.exec()){
                                 qDebug("get alertWhen Action failed");
                            }
                            while (query.next()) {
                                  theItemName = query.value(0).toString();
                            }
                            QString newCount = QString::number(newItemCount);

                            theMessage = "Only " + newCount + " " + theItemName + " left";


                            //insert alert
                            //INSERT INTO `sf`.`noticelist` (`firdgeID`, `message`) VALUES ('1', '123');
                            query.prepare("INSERT INTO `sf`.`noticelist` (`fridgeID`, `message`) VALUES (?, ?);");
                            query.addBindValue(fridgeID);
                            query.addBindValue(theMessage);

                            if (!query.exec()){
                                 qDebug("item count increment Action failed");
                                 return 0;
                            }


                        }
                    }


                    if(reorderOn == 1){

                        int reorderWhen;
                        query.prepare("SELECT reorderWhen FROM inventory WHERE itemID = ?");
                        query.addBindValue(itemID);
                        if (!query.exec()){
                             qDebug("get reorderWhen Action failed");
                        }
                        while (query.next()) {
                              reorderWhen = query.value(0).toInt();
                        }

                        if(newItemCount <= reorderWhen){
                            int reorderAmount;
                            query.prepare("SELECT reorderAmount FROM inventory WHERE itemID = ?");
                            query.addBindValue(itemID);
                            if (!query.exec()){
                                 qDebug("get reorderAmount Action failed");
                            }
                            while (query.next()) {
                                  reorderAmount = query.value(0).toInt();
                            }

                            if(reorderAmount > 0){
                                //reorder the item
                                QString uuid;

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

                               uuid = QString::fromStdString(ss.str());;

                               int fridgeID;
                               query.prepare("SELECT fridgeID FROM inventory WHERE itemID = ?");
                               query.addBindValue(itemID);
                               if (!query.exec()){
                                    qDebug("get alertWhen Action failed");
                               }
                               while (query.next()) {
                                     fridgeID = query.value(0).toInt();
                               }

                               QString supplierName;
                               query.prepare("SELECT supplierName FROM inventory WHERE itemID = ?");
                               query.addBindValue(itemID);
                               if (!query.exec()){
                                    qDebug("get alertWhen Action failed");
                               }
                               while (query.next()) {
                                     supplierName = query.value(0).toString();
                               }

                               QString supplierEmail;
                               query.prepare("SELECT supplierEmail FROM inventory WHERE itemID = ?");
                               query.addBindValue(itemID);
                               if (!query.exec()){
                                    qDebug("get alertWhen Action failed");
                               }
                               while (query.next()) {
                                     supplierEmail = query.value(0).toString();
                               }


                               //query.prepare("UPDATE uawe SET Username = ? WHERE UserID = ?");
                               query.prepare("INSERT INTO orders (orderID, fridgeID, supplierName, supplierEmail) VALUES (?,?,?,?)");
                               query.addBindValue(uuid);
                               query.addBindValue(fridgeID);
                               query.addBindValue(supplierName);
                               query.addBindValue(supplierEmail);


                               if (!query.exec()){
                                    qDebug("Create order in reorder Action failed");
                               }

                               query.prepare("INSERT INTO deliver (orderID) VALUES (?)");
                               query.addBindValue(uuid);


                               if (!query.exec()){
                                    qDebug("Create order in reorder Action failed");
                               }


                               QString theItemName;
                               //get item name
                               query.prepare("SELECT itemName FROM inventory WHERE itemID = ?");
                               query.addBindValue(itemID);
                               if (!query.exec()){
                                    qDebug("get alertWhen Action failed");
                               }
                               while (query.next()) {
                                     theItemName = query.value(0).toString();
                               }


                               //get image
                               query.prepare("SELECT itemPic FROM inventory WHERE itemName = ?");
                               query.addBindValue(theItemName);


                               if (!query.exec()){
                                    qDebug("find itemPic in order Action failed");
                                    return 0;
                               }


                               QString theImage = "";

                               while (query.next()) {
                                     theImage = query.value(0).toString();
                               }




                               query.prepare("INSERT INTO orderdata (orderID, itemName, itemCount,image) VALUES (?,?,?,?)");
                               query.addBindValue(uuid);
                               query.addBindValue(theItemName);
                               query.addBindValue(reorderAmount);
                               query.addBindValue(theImage);


                               if (!query.exec()){
                                    qDebug("add item to order in reorder Action failed");
                                    return 0;
                               }


                               query.prepare("INSERT INTO delivereditems (orderID, itemName, needed,image) VALUES (?,?,?,?)");
                               query.addBindValue(uuid);
                               query.addBindValue(theItemName);
                               query.addBindValue(reorderAmount);
                               query.addBindValue(theImage);


                               if (!query.exec()){
                                    qDebug("add item to order in reorder Action failed");
                                    return 0;
                               }

                               QString theMessage;
                               QString thereoderAmount = QString::number(reorderAmount);
                               theMessage = "Reordered " + thereoderAmount + " of " + theItemName;






                               //insert alert
                               //INSERT INTO `sf`.`noticelist` (`firdgeID`, `message`) VALUES ('1', '123');
                               query.prepare("INSERT INTO `sf`.`noticelist` (`fridgeID`, `message`) VALUES (?, ?);");
                               query.addBindValue(fridgeID);
                               query.addBindValue(theMessage);

                               if (!query.exec()){
                                    qDebug("item count increment Action failed");
                                    return 0;
                               }


                               query.prepare("UPDATE `sf`.`notice` SET `haveNotice` = '1' WHERE (`fridgeID` = ?);");
                               query.addBindValue(fridgeID);

                               if (!query.exec()){
                                    qDebug("item count increment Action failed");
                                    return 0;
                               }


                            }
                        }
                    }












                    return "OK";
                }

                return "error";

            }






            }
            return "error";
        }

    }


};
#endif // ITEMHELPER_H
