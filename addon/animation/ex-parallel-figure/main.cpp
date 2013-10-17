#include <QApplication>
#include <QLabel>
#include <QPropertyAnimation>
#include <QParallelAnimationGroup>
#include "tracer.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QWidget window;
    window.resize(720, 96);
    window.show();

    QLabel *label1 = new QLabel(&window);
    label1->setPixmap(QPixmap(":/icons/left.png"));
    label1->move(16, 16);
    label1->show();

    QLabel *label2 = new QLabel(&window);
    label2->setPixmap(QPixmap(":/icons/right.png"));
    label2->move(320, 16);
    label2->show();

    QPropertyAnimation *anim1 = new QPropertyAnimation(label1, "pos");
    anim1->setDuration(2500);
    anim1->setStartValue(QPoint(16, 16));
    anim1->setEndValue(QPoint(320, 16));

    QPropertyAnimation *anim2 = new QPropertyAnimation(label2, "pos");
    anim2->setDuration(2500);
    anim2->setStartValue(QPoint(320, 16));
    anim2->setEndValue(QPoint(640, 16));

    QParallelAnimationGroup *group = new QParallelAnimationGroup;
    group->addAnimation(anim1);
    group->addAnimation(anim2);

    Tracer tracer(&window, "animation-parallel.svg");
    tracer.setPixmap(anim1, QPixmap(":/icons/left.png"));
    tracer.setPixmap(anim2, QPixmap(":/icons/right.png"));

    QObject::connect(anim1, SIGNAL(valueChanged(QVariant)),
                     &tracer, SLOT(drawPath(QVariant)));
    QObject::connect(anim2, SIGNAL(valueChanged(QVariant)),
                     &tracer, SLOT(drawPath(QVariant)));
    QObject::connect(anim1, SIGNAL(finished()), &tracer, SLOT(drawLast()));
    QObject::connect(anim2, SIGNAL(finished()), &tracer, SLOT(drawLast()));

    group->start();
    return app.exec();
}
