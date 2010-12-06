#include <QtGui>
#include "selectcolor.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    SelectColor widget;
    widget.show();

    return app.exec();
}
