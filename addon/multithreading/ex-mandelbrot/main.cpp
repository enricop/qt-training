#include <QApplication>
#include "mandelbrot.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Mandelbrot window;
    window.show();

    return app.exec();
}
