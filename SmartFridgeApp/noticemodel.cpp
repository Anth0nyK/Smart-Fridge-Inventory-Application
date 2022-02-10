#include "noticemodel.h"

#include <QDebug>
#include <QtSql/QSqlError>
#include <QtSql/QSqlQuery>
#include <QSqlRecord>
#include <QQmlEngine>
#include <QQmlComponent>
#include <QQuickView>
#include <QObject>

QString noticeModel::fridgeID() const
{
    return m_fridgeID;
}




void noticeModel::setfridgeID(const QString &thetopic)
{

    //qDebug() << "In setTopic!!!!!!!!!!!!!!";
    if (thetopic == m_fridgeID)
        return;

    m_fridgeID = thetopic;


    //qDebug() << "In setTopic, m_topic is" + m_topic;
    updatenoticeModel();
}


Q_INVOKABLE void noticeModel::updatenoticeModel(){

    beginResetModel();
    //scope
    {
    QSqlDatabase::removeDatabase("connection6");
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL","connection6");
    db.setHostName("localhost");
    db.setPort(3306);
    db.setUserName("root");
    db.setPassword("admin");
    db.setDatabaseName("sf");
    if (db.open()) {
        //dbmtx2.lock();
        //qInfo() << "database is connected in model constuctor";


        QString theFridgeID = m_fridgeID;

        QSqlQuery query(QSqlDatabase::database("connection6"));

        //query.prepare("SELECT inventory.itemID, inventory.itemName, inventory.itemCount, inventory.itemPic FROM inventory WHERE inventory.fridgeID = ?");
        //query.prepare("SELECT orders.orderID, orders.supplierName, orders.supplierEmail, orders.dateTime, orders.completed FROM orders WHERE orders.fridgeID = ? ORDER BY orders.dateTime DESC");
        query.prepare("SELECT noticelist.message, noticelist.dateTime FROM noticelist WHERE noticelist.fridgeID = ? ORDER BY noticelist.dateTime DESC");
        query.addBindValue(theFridgeID);


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


QVariant noticeModel::data(const QModelIndex &item, int role) const
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



QHash<int, QByteArray> noticeModel::roleNames() const
{
    QHash<int, QByteArray> roles = QSqlQueryModel::roleNames();
    for (int i = 0; i < this->record().count(); i ++) {
        roles.insert(Qt::UserRole + i + 1, record().fieldName(i).toUtf8());
    }
    return roles;
}

noticeModel::noticeModel(QObject *parent):QSqlQueryModel(parent)
{

}
