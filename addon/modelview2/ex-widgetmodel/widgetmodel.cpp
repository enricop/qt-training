#include <QWidget>
#include "widgetmodel.h"

WidgetModel::WidgetModel(QObject *parent) :
    QAbstractItemModel(parent)
{
}

void WidgetModel::setRootWidget(QWidget *root)
{
    if (root != mRoot) {
        beginResetModel();
        mRoot = root;
        endResetModel();
    }
}

QVariant WidgetModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid()) return QVariant();
    if (role != Qt::DisplayRole) return QVariant();

    QWidget *widget = static_cast<QWidget*>(index.internalPointer());

    if (widget) {
        switch(index.column()) {
        case 0: // class name
            return widget->metaObject()->className();
        case 1: // object name
            return widget->objectName();
        }
    }

    return QVariant();
}

QVariant WidgetModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (orientation == Qt::Horizontal && role == Qt::DisplayRole) {
        switch (section) {
        case 0: return tr("Class");
        case 1: return tr("Name");
        }
    }

    return QVariant();
}

QModelIndex WidgetModel::index(int row, int column, const QModelIndex &parent) const
{
    if (!hasIndex(row, column, parent)) return QModelIndex();

    QWidget *parentWidget;
    if (!parent.isValid()) {
        parentWidget = mRoot;
    } else {
        parentWidget = static_cast<QWidget*>(parent.internalPointer());
    }

    QList<QWidget*> children = parentWidget->findChildren<QWidget*>(QString(), Qt::FindDirectChildrenOnly);
    if (!children.isEmpty()) {
        return createIndex(row, column, children.at(row));
    } else {
        return QModelIndex();
    }
}

QModelIndex WidgetModel::parent(const QModelIndex &index) const
{
    if (!index.isValid()) return QModelIndex();

    QWidget *childWidget = static_cast<QWidget*>(index.internalPointer());
    QWidget *parentWidget = static_cast<QWidget*>(childWidget->parent());

    if (parentWidget == 0) return QModelIndex();

    // find row
    QWidget *grandparent = static_cast<QWidget*>(parentWidget->parent());
    if (grandparent == 0) return QModelIndex();
    QList<QWidget*> relations = grandparent->findChildren<QWidget*>(QString(), Qt::FindDirectChildrenOnly);

    int row = relations.indexOf(parentWidget);

    return createIndex(row, 0, parentWidget);
}

int WidgetModel::rowCount(const QModelIndex &parent) const
{
    if (parent.column() > 0) return 0;

    QWidget *parentWidget;
    if (!parent.isValid()) {
        parentWidget = mRoot;
    } else {
        parentWidget = static_cast<QWidget*>(parent.internalPointer());
    }

    return parentWidget->findChildren<QWidget*>(QString(), Qt::FindDirectChildrenOnly).count();
}

int WidgetModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return 2; // constant colum count
}

Qt::ItemFlags WidgetModel::flags(const QModelIndex &index) const
{
    if (!index.isValid()) return 0;

    return QAbstractItemModel::flags(index);
}
