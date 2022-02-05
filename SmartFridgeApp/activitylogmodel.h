#ifndef ACTIVITYLOGMODEL_H
#define ACTIVITYLOGMODEL_H


#include <QSqlQueryModel>
#include <QObject>
#include <QSqlQuery>

class activitylogmodel : public QSqlQueryModel
{
    Q_OBJECT
    Q_PROPERTY(QString fridgeID READ fridgeID WRITE setfridgeID)
public:
    explicit activitylogmodel(QObject *parent = 0);

    QString fridgeID() const;
    void setfridgeID(const QString &theorderID);

    QVariant data(const QModelIndex &item, int role = Qt::DisplayRole) const override;

    QHash<int, QByteArray> roleNames() const override;

    Q_INVOKABLE void updateactivitylogModel();

private:
    QString m_fridgeID;
};

#endif // ACTIVITYLOGMODEL_H
