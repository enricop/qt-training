#include "citymodel.h"

CityModel::CityModel(QObject *parent) : QStandardItemModel(parent)
{
    setupModel();
}

void CityModel::setupModel()
{
    CityEngine engine;

    const QStringList countries = engine.countries();
    Q_FOREACH (const QString &country, countries) {
        const QIcon flag = engine.flag(country);
        const QStringList cities = engine.citiesByCountry(country);

        Q_FOREACH (const QString &city, cities) {
            const qreal area = engine.area(city);
            const int population = engine.population(city);

            QStandardItem *item = new QStandardItem;
            item->setData(city, CityRole);
            item->setData(country, CountryRole);
            item->setData(flag, FlagRole);
            item->setData(population, PopulationRole);
            item->setData(area, AreaRole);

            appendRow(item);
        }
    }

    QHash<int, QByteArray> roleNames;
    roleNames[CityRole] = "city";
    roleNames[CountryRole] = "country";
    roleNames[FlagRole] = "flag";
    roleNames[PopulationRole] = "population";
    roleNames[AreaRole] = "area";

    setRoleNames(roleNames);

    setSortRole(CountryRole);
}
