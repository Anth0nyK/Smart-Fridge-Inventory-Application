#include "orderdelivermodel.h"

#include <QDebug>
#include <QtSql/QSqlError>
#include <QtSql/QSqlQuery>
#include <QSqlRecord>
#include <QQmlEngine>
#include <QQmlComponent>
#include <QQuickView>
#include <QObject>

QString orderDeliverModel::orderID() const
{
    return m_orderID;
}




void orderDeliverModel::setorderID(const QString &thetopic)
{

    //qDebug() << "In setTopic!!!!!!!!!!!!!!";
    if (thetopic == m_orderID)
        return;

    m_orderID = thetopic;


    //qDebug() << "In setTopic, m_topic is" + m_topic;
    updateOrderDeliverModel();
}


Q_INVOKABLE void orderDeliverModel::updateOrderDeliverModel(){

    beginResetModel();
    //scope
    {
    QSqlDatabase::removeDatabase("connection2");
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL","connection2");
    db.setHostName("localhost");
    db.setPort(3306);
    db.setUserName("root");
    db.setPassword("admin");
    db.setDatabaseName("sf");
    if (db.open()) {
        //dbmtx2.lock();
        //qInfo() << "database is connected in model constuctor";


        QString theOrderID = m_orderID;

        QSqlQuery query(QSqlDatabase::database("connection2"));

        //query.prepare("SELECT orderdata.itemName, orderdata.itemCount, orderdata.image, delivereditems.needed FROM orderdata INNER JOIN delivereditems ON delivereditems.orderID = orderdata.orderID WHERE orderdata.orderID = ?");
        //query.prepare("SELECT orderdata.itemName, orderdata.itemCount, orderdata.image FROM orderdata WHERE orderdata.orderID = ?");
        query.prepare("SELECT delivereditems.itemName, delivereditems.needed, delivereditems.image FROM delivereditems WHERE delivereditems.orderID = ?");
        query.addBindValue(theOrderID);
        //117ebc3a-6660-4c92-b34a-ac321488c42b

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


QVariant orderDeliverModel::data(const QModelIndex &item, int role) const
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



QHash<int, QByteArray> orderDeliverModel::roleNames() const
{
    QHash<int, QByteArray> roles = QSqlQueryModel::roleNames();
    for (int i = 0; i < this->record().count(); i ++) {
        roles.insert(Qt::UserRole + i + 1, record().fieldName(i).toUtf8());
    }
    return roles;
}


orderDeliverModel::orderDeliverModel(QObject *parent):QSqlQueryModel(parent)
{

}
