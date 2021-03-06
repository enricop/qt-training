#include "citymodel.h"

enum ItemRoles {
    CityRole = Qt::UserRole + 1,
    CountryRole,
    PopulationRole,
    AreaRole,
    FlagRole
};


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

    setSortRole(CountryRole);
}

QHash<int, QByteArray> CityModel::roleNames() const
{
    QHash<int, QByteArray> mapping = QStandardItemModel::roleNames();

    mapping[CityRole] = "city";
    mapping[CountryRole] = "country";
    mapping[FlagRole] = "flag";
    mapping[PopulationRole] = "population";
    mapping[AreaRole] = "area";

    return mapping;
}
