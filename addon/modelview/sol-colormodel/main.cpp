#include <QApplication>
#include <QColor>
#include <QList>
#include <QListView>
#include "colormodel.h"

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    ColorModel *model = new ColorModel(&app);

    // create a color list
    QList<QColor> colors;
    foreach (QString color, QColor::colorNames()) {
        colors.append(QColor(color));
    }
    model->initialize(colors);

    QListView *view = new QListView(0);
    view->setViewMode(QListView::ListMode);
    view->setModel(model);
    view->setDragEnabled(true);
    view->show();

    bool status = app.exec();

    delete view;
    return status;
}
 
