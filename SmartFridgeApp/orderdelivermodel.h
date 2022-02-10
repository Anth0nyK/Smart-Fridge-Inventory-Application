#ifndef ORDERDELIVERMODEL_H
#define ORDERDELIVERMODEL_H

#include <QSqlQueryModel>
#include <QObject>
#include <QSqlQuery>

class orderDeliverModel : public QSqlQueryModel
{
    Q_OBJECT
    Q_PROPERTY(QString orderID READ orderID WRITE setorderID)
public:
    explicit orderDeliverModel(QObject *parent = 0);

    QString orderID() const;
    void setorderID(const QString &orderID);

    QVariant data(const QModelIndex &item, int role = Qt::DisplayRole) const override;

    QHash<int, QByteArray> roleNames() const override;

    Q_INVOKABLE void updateOrderDeliverModel();

private:
    QString m_orderID;
};

#endif // ORDERDELIVERMODEL_H
