#include <QApplication>
#include <QDeclarativeView>
#include <QUrl>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QDeclarativeView view;
    view.setSource(QUrl("qrc:animation.qml"));
    view.show();
    return app.exec();
}
