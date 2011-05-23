/*************************************************************************
 *
 * Copyright (c) 2008-2011, Nokia Corporation and/or its subsidiary(-ies).
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include <QApplication>
#include <QDeclarativeView>
#include "ellipseitem.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    qmlRegisterType<EllipseItem>("Shapes", 1, 0, "Ellipse");

    QDeclarativeView view;
    view.setSource(QUrl("qrc:ellipse1.qml"));
    view.show();
    return app.exec();
}
