#include <QApplication>
#include <QDeclarativeView>
#include "baritem.h"
#include "chartitem.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    qmlRegisterType<ChartItem>("Shapes", 8, 0, "Chart");
    qmlRegisterType<BarItem>("Shapes", 8, 0, "Bar");

    QDeclarativeView view;
    view.setSource(QUrl("qrc:chart1.qml"));
    view.show();
    return app.exec();
}
