#ifndef CITYMODEL_H
#define CITYMODEL_H

#include <QAbstractListModel>

#include "cityengine.h"

class CityModel : public QAbstractListModel
{
    Q_OBJECT
public:
    explicit CityModel(QObject *parent = 0);

    int rowCount(const QModelIndex &parent = QModelIndex()) const;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;

    QHash<int, QByteArray> roleNames() const;

private:
    CityEngine m_engine;
    QStringList m_citiesSortedByCountry;
};

#endif // CITYMODEL_H
