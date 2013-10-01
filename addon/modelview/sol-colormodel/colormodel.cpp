#include "colormodel.h"
#include <QPixmap>

ColorModel::ColorModel(QObject *parent)
    : QAbstractListModel(parent),
      colors_()
{
}

ColorModel::~ColorModel()
{
}

void ColorModel::initialize(QList<QColor> colors)
{
    beginResetModel();
    colors_ = colors;
    endResetModel();
}

QVariant ColorModel::data(const QModelIndex &index,
                          int role) const
{
    if (!index.isValid()) return QVariant();
    if (index.row() >= colors_.count()) return QVariant();

    if (role == Qt::DisplayRole) {
        return colors_[index.row()].name();

    } else if (role == Qt::EditRole) {
        return colors_[index.row()].name();

    } else if (role == Qt::DecorationRole) {
        QPixmap pix(32, 32);
        pix.fill(colors_[index.row()]);
        return pix;

    } else {
        return QVariant();
    }
}

bool ColorModel::setData(const QModelIndex &index,
                         const QVariant &value,
                         int role)
{
    if (!index.isValid()) return false;
    if (role != Qt::EditRole) return false;
    if (index.row() >= colors_.count()) return false;

    colors_.replace(index.row(), value.value<QColor>());
    return true;
}

bool ColorModel::insertRow(int row, const QModelIndex&)
{
    if ((row < 0) || (row > colors_.count())) row = colors_.count();

    beginInsertRows(QModelIndex(), row, row);
    colors_.insert(row, QColor());
    endInsertRows();
    return true;
}

bool ColorModel::removeRow(int row, const QModelIndex&)
{
    if ((row < 0) || (row > colors_.count())) return false;

    beginRemoveRows(QModelIndex(), row, row);
    colors_.removeAt(row);
    endRemoveRows();
    return true;
}

Qt::ItemFlags ColorModel::flags(const QModelIndex &index) const
{
    if (!index.isValid()) return Qt::ItemIsEnabled;
    return QAbstractListModel::flags(index) | Qt::ItemIsEditable | Qt::ItemIsDragEnabled | Qt::ItemIsDropEnabled;
}

int ColorModel::rowCount(const QModelIndex &parent) const
{
    return colors_.count();
}
