#ifndef WIDGETMODEL_H
#define WIDGETMODEL_H

#include <QAbstractItemModel>

class WidgetModel : public QAbstractItemModel
{
    Q_OBJECT
public:
    explicit WidgetModel(QObject *parent=0);

    void setRootWidget(QWidget *root);

    QVariant data(const QModelIndex &index, int role) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role=Qt::DisplayRole) const;

    QModelIndex index(int row, int column, const QModelIndex &parent=QModelIndex()) const;
    QModelIndex parent(const QModelIndex &index) const;

    int rowCount(const QModelIndex &parent=QModelIndex()) const;
    int columnCount(const QModelIndex &parent=QModelIndex()) const;

    Qt::ItemFlags flags(const QModelIndex &index) const;

private:
    QWidget *mRoot;
};

#endif // WIDGETMODEL_H
