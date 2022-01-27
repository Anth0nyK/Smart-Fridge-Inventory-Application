#include "itemmodel.h"
#include <QDebug>
#include <QtSql/QSqlError>
#include <QtSql/QSqlQuery>
#include <QSqlRecord>
#include <QQmlEngine>
#include <QQmlComponent>
#include <QQuickView>
#include <QObject>

QString itemModel::theitemID() const
{
    return m_itemID;
}


void itemModel::setitemID(const QString &thetopic)
{

    //qDebug() << "In setTopic!!!!!!!!!!!!!!";
    if (thetopic == m_itemID)
        return;

    m_itemID = thetopic;


    //qDebug() << "In setTopic, m_topic is" + m_topic;
    updateitemModel();
}


Q_INVOKABLE void itemModel::updateitemModel(){

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


        QString theItemID = m_itemID;

        QSqlQuery query(QSqlDatabase::database("connection2"));

        query.prepare("SELECT itemdata.itemDataID, itemdata.insertDate, itemdata.expiryDate FROM itemdata WHERE itemdata.itemID = ?");
        query.addBindValue(theItemID);


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


QVariant itemModel::data(const QModelIndex &item, int role) const
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



QHash<int, QByteArray> itemModel::roleNames() const
{
    QHash<int, QByteArray> roles = QSqlQueryModel::roleNames();
    for (int i = 0; i < this->record().count(); i ++) {
        roles.insert(Qt::UserRole + i + 1, record().fieldName(i).toUtf8());
    }
    return roles;
}

itemModel::itemModel(QObject *parent):QSqlQueryModel(parent)
{

}

