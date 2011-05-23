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
#include "baritem.h"
#include "chartitem.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    qmlRegisterType<ChartItem>("Shapes", 8, 0, "Chart");
    qmlRegisterType<BarItem>("Shapes", 8, 0, "Bar");

    QDeclarativeView view;
    view.setSource(QUrl("qrc:chart1.qml"));
    view.show();
    return app.exec();
}
