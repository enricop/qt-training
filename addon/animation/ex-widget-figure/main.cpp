/*************************************************************************
 *
 * Copyright (c) 2008-2011, Nokia Corporation and/or its subsidiary(-ies).
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include <QApplication>
#include <QPushButton>
#include <QPropertyAnimation>
#include "tracer.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QWidget window;
    window.resize(914, 62);
    QPalette palette;
    palette.setColor(QPalette::Window, Qt::white);
    window.setPalette(palette);
    window.show();

    QPushButton button("&Cancel");
    button.setParent(&window);
    button.show();

    QPropertyAnimation animation(&button, "geometry");
    animation.setDuration(10000);
    animation.setStartValue(QRect(0, 0, 64, 30));
    animation.setEndValue(QRect(850, 0, 64, 30));

    Tracer tracer(&window, "animation-widget.svg");
    QObject::connect(&animation, SIGNAL(valueChanged(QVariant)),
                     &tracer, SLOT(drawPath(QVariant)));

    animation.start();
    return app.exec();
}
