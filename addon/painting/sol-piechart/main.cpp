/*************************************************************************
 *
 * Copyright (c) 2008-2011, Nokia Corporation and/or its subsidiary(-ies).
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include <QtGui>
#include "piechart.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    PieChart chart;
    chart.setValue("Germany", 80);
    chart.setValue("Italy", 40);
    chart.setValue("Sweden", 20);
    chart.setValue("Norway", 5);
    chart.show();
    return app.exec();
}
