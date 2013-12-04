#include <QApplication>
#include "friendslists.h"

int main (int argc, char* argv[]) {
    QApplication app(argc, argv);
    FriendsLists fl;
    fl.show();
    return app.exec();
}

