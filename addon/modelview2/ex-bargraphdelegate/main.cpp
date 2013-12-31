/*************************************************************************
 *
 * Copyright (c) 2012 Digia Plc.
 * Parts Copyright (c) 2013 ics.com
 * Creative Commons License
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include <QApplication>
#include <QStandardItemModel>
#include <QStandardItem>
#include <QVariant>
#include <QDate>
#include <QTableView>

#include "bargraphdelegate.h"

int main(int argc, char** argv)
{
    QApplication app(argc, argv);
    QTableView view;
    view.setGeometry(200,200, 640, 480);
    /* create a model with 10 int values (0, 10, 20, ... 90) in first column, 
       and 3 columns with other typed values. */
    QStandardItemModel *model = new QStandardItemModel();
    QDate date = QDate::currentDate();
    for(int i=0; i<100; i += 10) {
        QVariant intVariant = QVariant(i);
        QStandardItem *item1 = new QStandardItem();
        item1->setData(intVariant, Qt::EditRole);

        QStandardItem *item2 = new QStandardItem();
        item2->setData(QVariant(date.addDays(0 - i)), Qt::EditRole);

        QStandardItem *item3 = new QStandardItem();
        double v = (double)i + (double) i / 100.0;
        QVariant doubleVariant = QVariant(v);
        item3->setData(doubleVariant, Qt::EditRole);

        // Just an ordinary string containing a base10 number:
        QStandardItem *item4 = new QStandardItem(QString("%1").arg(i));

        QList<QStandardItem *> items;
        items << item1 << item2 << item3 << item4;
        model->appendRow(items);
    }
    view.setModel(model);

    view.setItemDelegate(new BarGraphDelegate());

    view.show();    
    return app.exec();
}

