#include "citymodel.h"

enum ItemRoles {
    CityRole = Qt::UserRole + 1,
    CountryRole,
    PopulationRole,
    AreaRole,
    FlagRole
};


CityModel::CityModel(QObject *parent) : QAbstractListModel(parent)
{
    QHash<int, QByteArray> roleNames;
    roleNames[CityRole] = "city";
    roleNames[CountryRole] = "country";
    roleNames[FlagRole] = "flag";
    roleNames[PopulationRole] = "population";
    roleNames[AreaRole] = "area";

    setRoleNames(roleNames);

    const QStringList countries = m_engine.countries();
    Q_FOREACH (const QString &country, countries) {
        m_citiesSortedByCountry << m_engine.citiesByCountry(country);
    }
}

int CityModel::rowCount(const QModelIndex &parent) const
{
    return m_citiesSortedByCountry.count();
}

QVariant CityModel::data(const QModelIndex &index, int role) const
{
    const QString city = m_citiesSortedByCountry[index.row()];

    switch (role) {
    case Qt::DisplayRole:
    case CityRole:
        return city;

    case Qt::DecorationRole:
    case FlagRole:
        return m_engine.flag(city);

    case CountryRole:
        return m_engine.country(city);

    case PopulationRole:
        return m_engine.population(city);

    case AreaRole:
        return m_engine.area(city);

    default:
        return QVariant();
    }
}
