#ifndef ORDER2MODEL_H
#define ORDER2MODEL_H


#include <QSqlQueryModel>
#include <QObject>
#include <QSqlQuery>

class order2Model : public QSqlQueryModel
{
    Q_OBJECT
    Q_PROPERTY(QString theorderID READ theorderID WRITE setorderID)
public:
    explicit order2Model(QObject *parent = 0);

    QString theorderID() const;
    void setorderID(const QString &theorderID);

    QVariant data(const QModelIndex &item, int role = Qt::DisplayRole) const override;

    QHash<int, QByteArray> roleNames() const override;

    Q_INVOKABLE void updateorderModel();

private:
    QString m_orderID;
};

#endif // ORDER2MODEL_H
