#ifndef ORDERDETAILMODEL_H
#define ORDERDETAILMODEL_H

#include <QSqlQueryModel>
#include <QObject>
#include <QSqlQuery>

class orderdetailModel : public QSqlQueryModel
{
    Q_OBJECT
    Q_PROPERTY(QString theorderID READ theorderID WRITE setorderID)
public:
    explicit orderdetailModel(QObject *parent = 0);

    QString theorderID() const;
    void setorderID(const QString &theorderID);

    QVariant data(const QModelIndex &item, int role = Qt::DisplayRole) const override;

    QHash<int, QByteArray> roleNames() const override;

    Q_INVOKABLE void updateorderdetailModel();

private:
    QString m_orderID;
};

#endif // ORDERDETAILMODEL_H
