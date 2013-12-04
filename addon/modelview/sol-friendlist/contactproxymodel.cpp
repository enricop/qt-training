#include "contactproxymodel.h"


ContactProxyModel::ContactProxyModel(QObject *parent)
    : SUPER(parent) {}

Qt::ItemFlags ContactProxyModel::flags(const QModelIndex &index) const {
    int r = index.row();
    if ((r < 0 ) || r >= rowCount()) return 0;
    return Qt::ItemIsSelectable | Qt::ItemIsEnabled;
}

QVariant ContactProxyModel::data(const QModelIndex &index, int role) const {
    if (role == Qt::CheckStateRole)
        return QVariant();
    else return SUPER::data(index, role);
}

