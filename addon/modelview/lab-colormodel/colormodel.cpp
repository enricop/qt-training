#include "colormodel.h"

ColorModel::ColorModel(QObject *parent)
    : QAbstractListModel(parent)
{
    // TODO
}

ColorModel::~ColorModel()
{
    // TODO
}

QVariant ColorModel::data(const QModelIndex &index,
                          int role) const
{
    // TODO
    return QVariant();
}

bool ColorModel::setData(const QModelIndex &index,
                         const QVariant &value,
                         int role)
{
    // TODO
    return false;
}

bool ColorModel::insertRow(int row, const QModelIndex&)
{
    // TODO
    return false;
}

bool ColorModel::removeRow(int row, const QModelIndex&)
{
    // TODO
    return false;
}

Qt::ItemFlags ColorModel::flags(const QModelIndex &index) const
{
    // TODO
    return QAbstractListModel::flags(index);
}

int ColorModel::rowCount(const QModelIndex &parent) const
{
    // TODO
    return 0;
}
