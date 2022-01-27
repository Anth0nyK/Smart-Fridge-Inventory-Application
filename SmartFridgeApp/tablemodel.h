#ifndef TABLEMODEL_H
#define TABLEMODEL_H
#include <qqml.h>
#include <QAbstractTableModel>

class TableModel : public QAbstractTableModel
{
    Q_OBJECT
    QML_ELEMENT
    QML_ADDED_IN_MINOR_VERSION(1)

public:
    int rowCount(const QModelIndex & = QModelIndex()) const override
    {
        return 10;
    }

    int columnCount(const QModelIndex & = QModelIndex()) const override
    {
        return 5;
    }

    QVariant data(const QModelIndex &index, int role) const override
    {
        switch (role) {
            case Qt::DisplayRole:
                return QString("%1, %2").arg(index.column()).arg(index.row());
            default:
                break;
        }

        return QVariant();
    }

    QHash<int, QByteArray> roleNames() const override
    {
        return { {Qt::DisplayRole, "display"} };
    }
};
#endif // TABLEMODEL_H
