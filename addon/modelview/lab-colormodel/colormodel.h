#ifndef COLORMODEL_H
#define COLORMODEL_H

#include <QAbstractListModel>
#include <QModelIndex>

class ColorModel : public QAbstractListModel {
    Q_OBJECT
public:
    ColorModel(QObject *parent = 0);
    ~ColorModel();

    QVariant data(const QModelIndex &index, int role) const;
    bool setData(const QModelIndex &index,
                 const QVariant &value,
                 int role = Qt::EditRole);
    Qt::ItemFlags flags(const QModelIndex &index) const;
    bool insertRow(int row,
                   const QModelIndex & parent = QModelIndex());
    bool removeRow(int row,
                   const QModelIndex &parent = QModelIndex());
    int rowCount(const QModelIndex &parent = QModelIndex()) const;

private:
    // TODO
};

#endif // COLORMODEL_H
