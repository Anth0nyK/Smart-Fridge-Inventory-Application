#include "ordermodel.h"
#include <QDebug>
#include <QtSql/QSqlError>
#include <QtSql/QSqlQuery>
#include <QSqlRecord>
#include <QQmlEngine>
#include <QQmlComponent>
#include <QQuickView>
#include <QObject>

QString orderModel::theorderID() const
{
    return m_orderID;
}


void orderModel::setorderID(const QString &thetopic)
{

    //qDebug() << "In setTopic!!!!!!!!!!!!!!";
    if (thetopic == m_orderID)
        return;

    m_orderID = thetopic;


    //qDebug() << "In setTopic, m_topic is" + m_topic;
    updateorderModel();
}


Q_INVOKABLE void orderModel::updateorderModel(){

    beginResetModel();
    //scope
    {
    QSqlDatabase::removeDatabase("connection3");
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL","connection3");
    db.setHostName("localhost");
    db.setPort(3306);
    db.setUserName("root");
    db.setPassword("admin");
    db.setDatabaseName("sf");
    if (db.open()) {
        //dbmtx2.lock();
        //qInfo() << "database is connected in model constuctor";


        QString theorderID = m_orderID;

        QSqlQuery query(QSqlDatabase::database("connection3"));

        query.prepare("SELECT orders.orderID, orders.supplierName, orders.supplierEmail, orders.dateTime, orders.completed FROM orders WHERE orders.fridgeID = ?");
        query.addBindValue(theorderID);


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


QVariant orderModel::data(const QModelIndex &item, int role) const
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



QHash<int, QByteArray> orderModel::roleNames() const
{
    QHash<int, QByteArray> roles = QSqlQueryModel::roleNames();
    for (int i = 0; i < this->record().count(); i ++) {
        roles.insert(Qt::UserRole + i + 1, record().fieldName(i).toUtf8());
    }
    return roles;
}

orderModel::orderModel(QObject *parent):QSqlQueryModel(parent)
{

}
