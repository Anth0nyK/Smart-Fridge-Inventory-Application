#ifndef ORDERITEMSMODEL_H
#define ORDERITEMSMODEL_H


#include <QSqlQueryModel>
#include <QObject>
#include <QSqlQuery>

class orderitemsmodel : public QSqlQueryModel
{
    Q_OBJECT
    Q_PROPERTY(QString fridgeID READ fridgeID WRITE setfridgeID)
    Q_PROPERTY(QString supplierName READ supplierName WRITE setsupplierName)
    Q_PROPERTY(QString supplierEmail READ supplierEmail WRITE setsupplierEmail)

public:
    explicit orderitemsmodel(QObject *parent = 0);

    QString fridgeID() const;
    void setfridgeID(const QString &fridgeID);

    QString supplierName() const;
    void setsupplierName(const QString &supplierName);

    QString supplierEmail() const;
    void setsupplierEmail(const QString &supplierEmail);

    QVariant data(const QModelIndex &item, int role = Qt::DisplayRole) const override;

    QHash<int, QByteArray> roleNames() const override;

    Q_INVOKABLE void updateorderitemsModel();

private:
    QString m_fridgeID;
    QString m_supplierName;
    QString m_supplierEmail;
};

#endif // ORDERITEMSMODEL_H
