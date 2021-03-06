#include "orderdetailmodel.h"
#include <QDebug>
#include <QtSql/QSqlError>
#include <QtSql/QSqlQuery>
#include <QSqlRecord>
#include <QQmlEngine>
#include <QQmlComponent>
#include <QQuickView>
#include <QObject>

QString orderdetailModel::theorderID() const
{
    return m_orderID;
}


void orderdetailModel::setorderID(const QString &thetopic)
{

    //qDebug() << "In setTopic!!!!!!!!!!!!!!";
    /*
    if (thetopic == m_orderID)
        return;
*/
    m_orderID = thetopic;


    //qDebug() << "In setTopic, m_topic is" + m_topic;
    updateorderdetailModel();
}


Q_INVOKABLE void orderdetailModel::updateorderdetailModel(){

    beginResetModel();
    //scope
    {
    QSqlDatabase::removeDatabase("connection5");
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL","connection5");
    db.setHostName("localhost");
    db.setPort(3306);
    db.setUserName("root");
    db.setPassword("admin");
    db.setDatabaseName("sf");
    if (db.open()) {
        //dbmtx2.lock();
        //qInfo() << "database is connected in model constuctor";


        QString theorderID = m_orderID;

        QSqlQuery query(QSqlDatabase::database("connection5"));

        //query.prepare("SELECT orders.orderID, orders.supplierName, orders.supplierEmail, orders.dateTime, orders.completed FROM orders WHERE orders.fridgeID = ? ORDER BY orders.dateTime DESC");
        //query.prepare("SELECT delivereditems.itemName, delivereditems.needed, delivereditems.image FROM delivereditems WHERE delivereditems.orderID = ?");
        query.prepare("SELECT orderdata.itemName, orderdata.itemCount, orderdata.image FROM orderdata WHERE orderdata.orderID = ?");
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


QVariant orderdetailModel::data(const QModelIndex &item, int role) const
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



QHash<int, QByteArray> orderdetailModel::roleNames() const
{
    QHash<int, QByteArray> roles = QSqlQueryModel::roleNames();
    for (int i = 0; i < this->record().count(); i ++) {
        roles.insert(Qt::UserRole + i + 1, record().fieldName(i).toUtf8());
    }
    return roles;
}

orderdetailModel::orderdetailModel(QObject *parent):QSqlQueryModel(parent)
{

}
