
#include <QApplication>
#include "objectbrowsertestermainwindow.h"

int main (int argc, char* argv[]) {
    QApplication app(argc, argv);
    ObjectBrowserTesterMainWindow mw;
    mw.show();
    return app.exec();
}
