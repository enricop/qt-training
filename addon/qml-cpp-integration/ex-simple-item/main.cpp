#include <QApplication>
#include <QDeclarativeView>
#include "ellipseitem.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    qmlRegisterType<EllipseItem>("Shapes", 1, 0, "Ellipse");

    QDeclarativeView view;
    view.setSource(QUrl("qrc:ellipse1.qml"));
    view.show();
    return app.exec();
}
