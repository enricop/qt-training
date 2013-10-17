#include <QApplication>
#include <QLabel>
#include <QPropertyAnimation>
#include "tracer.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QWidget window;
    window.resize(914, 92);
    QPalette palette;
    palette.setColor(QPalette::Window, Qt::white);
    window.setPalette(palette);
    window.show();

    QLabel label;
    label.setPixmap(QPixmap(":icons/icon.png"));
    label.setParent(&window);
    label.show();

    QPropertyAnimation animation(&label, "geometry");
    animation.setDuration(3000);
    animation.setStartValue(QRect(0, 0, 64, 64));
    animation.setEndValue(QRect(850, 0, 64, 64));
    animation.setEasingCurve(QEasingCurve::OutQuad);

    Tracer tracer(&window, "animation-easing.svg");
    QObject::connect(&animation, SIGNAL(valueChanged(QVariant)),
                     &tracer, SLOT(drawPath(QVariant)));

    animation.start();
    return app.exec();
}
