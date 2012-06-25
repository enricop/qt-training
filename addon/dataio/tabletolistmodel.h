#ifndef TABLETOLISTMODEL_H
#define TABLETOLISTMODEL_H

#include <QAbstractListModel>

class QAbstractTableModel;

class TableToListModel : public QAbstractListModel
{
    Q_OBJECT
public:
    explicit TableToListModel(QObject *parent = 0);
    
    void setTableModel(QAbstractTableModel *sourceModel);

    void addColumnMapping(int column, const QByteArray &qmlProperty);

    QHash<int, QByteArray> roleNames() const;

    int rowCount(const QModelIndex &parent) const;

    QVariant data(const QModelIndex &proxyIndex, int role) const;

private:
    QAbstractTableModel *m_sourceModel;

    QHash<int, QByteArray> m_columnToProperty;
    QHash<QByteArray, int> m_propertyToColumn;
    QHash<int, QByteArray> m_roleToProperty;
};

#endif // TABLETOLISTMODEL_H
