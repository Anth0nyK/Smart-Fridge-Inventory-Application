#ifndef INVENTORYMODEL_H
#define INVENTORYMODEL_H

#include <QSqlQueryModel>
#include <QObject>
#include <QSqlQuery>

class inventoryModel : public QSqlQueryModel
{
    Q_OBJECT
    Q_PROPERTY(QString fridgeID READ fridgeID WRITE setfridgeID)
public:
    explicit inventoryModel(QObject *parent = 0);

    QString fridgeID() const;
    void setfridgeID(const QString &fridgeID);

    QVariant data(const QModelIndex &item, int role = Qt::DisplayRole) const override;

    QHash<int, QByteArray> roleNames() const override;

    Q_INVOKABLE void updateinventoryModel();

private:
    QString m_fridgeID;
};

#endif // INVENTORYMODEL_H
