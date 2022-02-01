#ifndef SUPPLIERMODEL_H
#define SUPPLIERMODEL_H


#include <QSqlQueryModel>
#include <QObject>
#include <QSqlQuery>

class supplierModel : public QSqlQueryModel
{
    Q_OBJECT
    Q_PROPERTY(QString thefridgeID READ thefridgeID WRITE setfridgeID)
public:
    explicit supplierModel(QObject *parent = 0);

    QString thefridgeID() const;
    void setfridgeID(const QString &thefridgeID);

    QVariant data(const QModelIndex &item, int role = Qt::DisplayRole) const override;

    QHash<int, QByteArray> roleNames() const override;

    Q_INVOKABLE void updatesupplierModel();

private:
    QString m_fridgeID;
};

#endif // SUPPLIERMODEL_H
