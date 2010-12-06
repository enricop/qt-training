#include <QtGui>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QWidget window; // our top-level window

    // ... your code here

    window.resize(480, 640);
    window.show();

    return app.exec();
}
