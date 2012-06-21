#include <QDebug>
#include <QGuiApplication>
#include <QQmlContext>
#include <QQmlEngine>
#include <QQuickView>
#include <QSortFilterProxyModel>

#include "citymodel.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQuickView viewer;

    CityModel model;
    QSortFilterProxyModel filter;
    filter.setSourceModel(&model);
    filter.setFilterRole(CityModel::CityRole);

    viewer.engine()->rootContext()->setContextProperty("_model", &filter);
    viewer.setSource(QUrl("qrc:///main.qml"));
    viewer.show();

    return app.exec();
}
