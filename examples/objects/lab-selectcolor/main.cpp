#include <QApplication>
#include "selectcolor.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    SelectColor tester;
    tester.show();

    return app.exec();
}
