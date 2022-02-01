#include "suppliermodel.h"
#include <QDebug>
#include <QtSql/QSqlError>
#include <QtSql/QSqlQuery>
#include <QSqlRecord>
#include <QQmlEngine>
#include <QQmlComponent>
#include <QQuickView>
#include <QObject>

QString supplierModel::thefridgeID() const
{
    return m_fridgeID;
}


void supplierModel::setfridgeID(const QString &thetopic)
{

    //qDebug() << "In setTopic!!!!!!!!!!!!!!";
    if (thetopic == m_fridgeID)
        return;

    m_fridgeID = thetopic;


    //qDebug() << "In setTopic, m_topic is" + m_topic;
    updatesupplierModel();
}


Q_INVOKABLE void supplierModel::updatesupplierModel(){

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


        QString thefridgeID = m_fridgeID;

        QSqlQuery query(QSqlDatabase::database("connection3"));
        query.prepare("SELECT DISTINCT inventory.supplierName, inventory.supplierEmail FROM inventory WHERE inventory.fridgeID = ?");
        query.addBindValue(thefridgeID);


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


QVariant supplierModel::data(const QModelIndex &item, int role) const
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



QHash<int, QByteArray> supplierModel::roleNames() const
{
    QHash<int, QByteArray> roles = QSqlQueryModel::roleNames();
    for (int i = 0; i < this->record().count(); i ++) {
        roles.insert(Qt::UserRole + i + 1, record().fieldName(i).toUtf8());
    }
    return roles;
}


supplierModel::supplierModel(QObject *parent):QSqlQueryModel(parent)
{

}
