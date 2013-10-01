#include <QApplication>
#include <QListView>
#include "colormodel.h"

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    ColorModel *model = new ColorModel(&app);
    QListView *view = new QListView(0);
    view->setModel(model);
    view->show();

    bool status = app.exec();

    delete view;
    return status;
}
 
