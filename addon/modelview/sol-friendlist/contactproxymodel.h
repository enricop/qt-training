#ifndef CONTACTPROXYMODEL_H
#define CONTACTPROXYMODEL_H

#include <QSortFilterProxyModel>

/** A model for the left listview which allows you to
    select contacts to view friendlists.
    As a proxy model, it simply filters out the CheckState role values
    from data and flags.
    */
class ContactProxyModel: public QSortFilterProxyModel
{
    Q_OBJECT
public:
    typedef QSortFilterProxyModel SUPER;
    explicit ContactProxyModel(QObject *parent = 0); 
    Qt::ItemFlags flags(const QModelIndex &index) const;
    QVariant data(const QModelIndex &index, int role) const;
};

#endif // CONTACTPROXYMODEL_H
