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
    animation.setDuration(10000);
    animation.setKeyValueAt(0, QRect(0, 0, 64, 64));
    animation.setKeyValueAt(0.8, QRect(425, 0, 64, 64));
    animation.setKeyValueAt(1, QRect(850, 0, 64, 64));

    Tracer tracer(&window, "animation-keyvalues.svg");
    QObject::connect(&animation, SIGNAL(valueChanged(QVariant)),
                     &tracer, SLOT(drawPath(QVariant)));

    animation.start();
    return app.exec();
}
