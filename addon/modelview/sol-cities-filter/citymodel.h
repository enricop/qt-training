#ifndef CITYMODEL_H
#define CITYMODEL_H

#include <QStandardItemModel>

#include "cityengine.h"

class CityModel : public QStandardItemModel
{
    Q_OBJECT
public:
    enum ItemRoles {
        CityRole = Qt::UserRole + 1,
        CountryRole,
        PopulationRole,
        AreaRole,
        FlagRole
    };

    explicit CityModel(QObject *parent = 0);

    QHash<int, QByteArray> roleNames() const;

private:
    void setupModel();
};

#endif // CITYMODEL_H
