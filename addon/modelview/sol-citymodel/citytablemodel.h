#ifndef CITYTABLEMODEL_H
#define CITYTABLEMODEL_H

#include <QtGui>

class CityEngine;

class CityTableModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    explicit CityTableModel(QObject *parent = 0);
    void setInput(CityEngine *input);
    int columnCount ( const QModelIndex & parent = QModelIndex() ) const;
    int	rowCount ( const QModelIndex & parent = QModelIndex() ) const;
    QVariant data ( const QModelIndex & index, int role = Qt::DisplayRole ) const;
    QVariant headerData ( int section, Qt::Orientation orientation, int role = Qt::DisplayRole ) const;
private:
    CityEngine *m_input;
};

#endif // CITYTABLEMODEL_H
