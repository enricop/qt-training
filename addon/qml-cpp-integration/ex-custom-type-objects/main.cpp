#include <QApplication>
#include <QDeclarativeView>
#include "ellipseitem.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    qmlRegisterType<EllipseItem>("Shapes", 7, 0, "Ellipse");
    qmlRegisterType<Style>("Shapes", 7, 0, "Style");

    QDeclarativeView view;
    view.setSource(QUrl("qrc:ellipse7.qml"));
    view.show();
    return app.exec();
}
