#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QPropertyAnimation>
#include "graphicspixmapitem.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QGraphicsScene scene;
    GraphicsPixmapItem icon(QPixmap(":/icons/logo.png"));
    icon.setPos(0, 0);
    scene.addItem(&icon);

    QPainterPath path;
    path.moveTo(0, 0);
    path.lineTo(200, 50);
    path.lineTo(150, 250);
    path.lineTo(-50, 200);
    path.closeSubpath();
    QGraphicsPathItem track(path);
    scene.addItem(&track);

    QGraphicsView view;
    view.setScene(&scene);
    view.resize(480, 360);
    view.show();

    QPropertyAnimation animation(&icon, "pos");
    animation.setDuration(10000);
    animation.setStartValue(QPointF(0, 0));
    animation.setKeyValueAt(0.25, QPointF(200, 50));
    animation.setKeyValueAt(0.5, QPointF(150, 250));
    animation.setKeyValueAt(0.75, QPointF(-50, 200));
    animation.setEndValue(QPointF(0, 0));

    animation.start();
    return app.exec();
}
