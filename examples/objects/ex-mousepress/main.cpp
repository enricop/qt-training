#include <QApplication>
#include "widget.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Widget window;

    Widget *child1 = new Widget(&window);
    child1->setGeometry(50, 50, 100, 100);
    Widget *child2 = new Widget(&window);
    child2->setGeometry(350, 100, 100, 100);
    Widget *child3 = new Widget(&window);
    child3->setGeometry(200, 350, 100, 100);

    window.setFixedSize(500, 500);
    window.show();

    return app.exec();
}
