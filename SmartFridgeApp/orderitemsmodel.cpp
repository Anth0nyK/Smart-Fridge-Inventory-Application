#include "orderitemsmodel.h"
#include <QDebug>
#include <QtSql/QSqlError>
#include <QtSql/QSqlQuery>
#include <QSqlRecord>
#include <QQmlEngine>
#include <QQmlComponent>
#include <QQuickView>
#include <QObject>

QString orderitemsmodel::fridgeID() const
{
    return m_fridgeID;
}

QString orderitemsmodel::supplierName() const
{
    return m_supplierName;
}

QString orderitemsmodel::supplierEmail() const
{
    return m_supplierEmail;
}




void orderitemsmodel::setfridgeID(const QString &thetopic)
{

    //qDebug() << "In setTopic!!!!!!!!!!!!!!";
    if (thetopic == m_fridgeID)
        return;

    m_fridgeID = thetopic;


    //qDebug() << "In setTopic, m_topic is" + m_topic;
    updateorderitemsModel();
}

void orderitemsmodel::setsupplierName(const QString &supplierName)
{
    if (supplierName == m_supplierName)
        return;

    m_supplierName = supplierName;

    updateorderitemsModel();
}

void orderitemsmodel::setsupplierEmail(const QString &supplierEmail)
{
    if (supplierEmail == m_supplierEmail)
        return;

    m_supplierEmail = supplierEmail;

    updateorderitemsModel();
}



Q_INVOKABLE void orderitemsmodel::updateorderitemsModel(){

    beginResetModel();
    //scope
    {
    QSqlDatabase::removeDatabase("connection4");
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL","connection4");
    db.setHostName("localhost");
    db.setPort(3306);
    db.setUserName("root");
    db.setPassword("admin");
    db.setDatabaseName("sf");
    if (db.open()) {
        //dbmtx2.lock();
        //qInfo() << "database is connected in model constuctor";


        QString theFridgeID = m_fridgeID;
        QString theSupplierName = m_supplierName;
        QString theSupplierEmail = m_supplierEmail;


        QSqlQuery query(QSqlDatabase::database("connection4"));

        query.prepare("SELECT inventory.itemName, inventory.itemPic FROM inventory WHERE inventory.fridgeID = ? and inventory.supplierName = ? and inventory.supplierEmail = ?");
        //query.prepare("SELECT inventory.itemID, inventory.itemName, inventory.itemCount, inventory.itemPic FROM inventory WHERE inventory.fridgeID = ?");
        query.addBindValue(theFridgeID);
        query.addBindValue(theSupplierName);
        query.addBindValue(theSupplierEmail);

        if (!query.exec())
            qFatal("Contacts SELECT query failed: %s", qPrintable(query.lastError().text()));

        query.exec();

        setQuery(query);

        if (lastError().isValid())
            qFatal("Cannot set query on SqlContactModel: %s", qPrintable(lastError().text()));

        //dbmtx2.unlock();
    }
    else{
        qDebug() << "database is not online";
    }
    }

    endResetModel();
}


QVariant orderitemsmodel::data(const QModelIndex &item, int role) const
{
    QVariant value;
    if (item.isValid()) {
        if (role < Qt::UserRole) {
            value = QSqlQueryModel::data(item, role);
        } else {
            int columnIdx = role - Qt::UserRole - 1;
            QModelIndex modelIndex = this->index(item.row(), columnIdx);
            value = QSqlQueryModel::data(modelIndex, Qt::DisplayRole);
        }
    }
    return value;
}



QHash<int, QByteArray> orderitemsmodel::roleNames() const
{
    QHash<int, QByteArray> roles = QSqlQueryModel::roleNames();
    for (int i = 0; i < this->record().count(); i ++) {
        roles.insert(Qt::UserRole + i + 1, record().fieldName(i).toUtf8());
    }
    return roles;
}

orderitemsmodel::orderitemsmodel(QObject *parent):QSqlQueryModel(parent)
{

}
