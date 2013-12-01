#include "window.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Window window;
    window.resize(600, 400);
    window.show();

    return app.exec();
}
