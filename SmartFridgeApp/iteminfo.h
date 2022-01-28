#ifndef ITEMINFO_H
#define ITEMINFO_H

#include <QObject>
#include <QtSql/QSqlQuery>
#include <QVariant>
#include <string>
#include <QDebug>

#include <iomanip>
#include <ctime>
#include <sstream>
#include <mutex>          // std::mutex

//std::mutex dbmtx;

class iteminfo : public QObject
{
    Q_OBJECT
public:
    explicit iteminfo (QObject* parent = 0 ) : QObject(parent) {}

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

    Q_INVOKABLE QString getAlert(QString itemID){
        {

        QString Alert = NULL;

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
              Alert = query.value(0).toString();
        }

        return Alert;

        }
    }


    Q_INVOKABLE QString getReorder(QString itemID){
        {

        QString Reorder = NULL;

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
              Reorder = query.value(0).toString();
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
    Q_INVOKABLE void updateItemInfo(QString itemName, QString supplierName, QString alertWhen, QString reorderWhen, QString supplierEmail, QString itemID){
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

        //change the username
        query.prepare("UPDATE inventory SET itemName = ?, supplierName = ?, alertWhen = ?, reorderWhen = ?, supplierEmail = ? WHERE itemID = ?");
        //query.prepare("UPDATE inventory SET itemPic = ? WHERE itemID = ?");
        query.addBindValue(itemName);
        query.addBindValue(supplierName);
        query.addBindValue(alertWhen);
        query.addBindValue(reorderWhen);
        query.addBindValue(supplierEmail);
        query.addBindValue(itemID);

        if (!query.exec()){
             qDebug("update item info Action failed");
        }


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



};
#endif // ITEMINFO_H
