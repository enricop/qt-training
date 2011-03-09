/*************************************************************************
 *
 * Copyright (c) 2008-2011, Nokia Corporation and/or its subsidiary(-ies).
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include <QtGui>

void showTimesTable()
{
    QTableWidget *w = new QTableWidget(12, 12);

    for (int row = 0; row < 12; ++row) {
        for (int column = 0; column < 12; ++column) {
            QString text = QString::number((row+1)*(column+1));
            QTableWidgetItem *item = new QTableWidgetItem(text);
            w->setItem(row, column, item);
        }
    }

    w->show();
}

void setItemsInTable()
{
    QTableWidget *w = new QTableWidget(3, 3);

    QTableWidgetItem *item1 = new QTableWidgetItem("X");
    QTableWidgetItem *item2 = new QTableWidgetItem("O");
    QTableWidgetItem *item3 = new QTableWidgetItem("X");
    w->setItem(1, 1, item1);
    w->setItem(1, 2, item2);
    w->setItem(2, 0, item3);

    w->show();
}

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    showTimesTable();
    setItemsInTable();

    return app.exec();
}
