#ifndef ITEMMODEL_H
#define ITEMMODEL_H

#include <QSqlQueryModel>
#include <QObject>
#include <QSqlQuery>

class itemModel : public QSqlQueryModel
{
    Q_OBJECT
    Q_PROPERTY(QString theitemID READ theitemID WRITE setitemID)
public:
    explicit itemModel(QObject *parent = 0);

    QString theitemID() const;
    void setitemID(const QString &itemID);

    QVariant data(const QModelIndex &item, int role = Qt::DisplayRole) const override;

    QHash<int, QByteArray> roleNames() const override;

    Q_INVOKABLE void updateitemModel();

private:
    QString m_itemID;
};


#endif // ITEMMODEL_H
