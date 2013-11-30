#include <primefinderdialog.h>
#include <QApplication>

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);
    PrimeFinderDialog dlg;
    return dlg.exec();
}
