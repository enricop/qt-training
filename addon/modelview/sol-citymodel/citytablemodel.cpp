#include "citytablemodel.h"
#include "cityengine.h"

CityTableModel::CityTableModel(QObject *parent) :
    QAbstractTableModel(parent), m_input(0)
{
}

void CityTableModel::setInput(CityEngine *input)
{
    Q_ASSERT(input);
    beginResetModel();
    m_input = input;
    endResetModel();
}

int CityTableModel::columnCount ( const QModelIndex & parent) const {
    if(parent.isValid() || !m_input) {
        return 0;
    }
    return 4; // city, country+flag, population, area
}
int	CityTableModel::rowCount ( const QModelIndex & parent) const {
    if(parent.isValid() || !m_input) {
        return 0;
    }
    return m_input->cities().count();
}
QVariant CityTableModel::data ( const QModelIndex & index, int role) const {
    if(!index.isValid() || !m_input) {
        return QVariant();
    }
    QString city = m_input->cities().at(index.row());
    switch(role) {
    case Qt::DisplayRole:
        switch(index.column()) {
        case CityEngine::CityName:
            return city;
        case CityEngine::CityCountry:
            return m_input->country(city);
        case CityEngine::CityPopulation:
            return m_input->population(city);
        case CityEngine::CityArea:
            return m_input->area(city);
        }
        break;
    case Qt::DecorationRole:
        if(index.column() == CityEngine::CityCountry) { // country
            QString country = m_input->country(city);
            return m_input->flag(country);
        }
        break;
    }
    return QVariant();
}

QVariant CityTableModel::headerData ( int section, Qt::Orientation orientation, int role ) const {
    if(role != Qt::DisplayRole) {
        return QVariant();
    }
    switch(orientation) {
    case Qt::Horizontal:
        return m_input->header(section);
    case Qt::Vertical:
        return QString("City %1").arg(section+1);
    }
    return QVariant();
}

