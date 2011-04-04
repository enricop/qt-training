#include <QApplication>
#include <QDeclarativeView>
#include "ellipseitem.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    qmlRegisterType<EllipseItem>("Shapes", 5, 0, "Ellipse");

    QDeclarativeView view;
    view.setSource(QUrl("qrc:ellipse5.qml"));
    view.show();
    return app.exec();
}
