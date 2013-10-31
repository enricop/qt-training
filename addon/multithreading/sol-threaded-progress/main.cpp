#include "progresswindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    ProgressWindow window;
    window.resize(400, 100);
    window.show();
    
    return app.exec();
}
