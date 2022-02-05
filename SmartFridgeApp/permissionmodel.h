#ifndef PERMISSIONMODEL_H
#define PERMISSIONMODEL_H


#include <QSqlQueryModel>
#include <QObject>
#include <QSqlQuery>

class permissionModel : public QSqlQueryModel
{
    Q_OBJECT
    Q_PROPERTY(QString fridgeID READ fridgeID WRITE setfridgeID)
public:
    explicit permissionModel(QObject *parent = 0);

    QString fridgeID() const;
    void setfridgeID(const QString &fridgeID);

    QVariant data(const QModelIndex &item, int role = Qt::DisplayRole) const override;

    QHash<int, QByteArray> roleNames() const override;

    Q_INVOKABLE void updatepermissionmodel();

private:
    QString m_fridgeID;
};


#endif // PERMISSIONMODEL_H
