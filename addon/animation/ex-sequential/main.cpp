/*************************************************************************
 *
 * Copyright (c) 2008-2011, Nokia Corporation and/or its subsidiary(-ies).
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include <QApplication>
#include <QLabel>
#include <QPropertyAnimation>
#include <QSequentialAnimationGroup>

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

    QSequentialAnimationGroup group;
    group.addAnimation(anim1);
    group.addAnimation(anim2);
    group.start();

    return app.exec();
}
