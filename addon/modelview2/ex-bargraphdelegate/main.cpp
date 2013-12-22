/*************************************************************************
 *
 * Copyright (c) 2012 Digia Plc.
 * All rights reserved.
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


    // create a model with 10 values (0, 10, 20, ... 90) and 3 columns
    QStandardItemModel *model = new QStandardItemModel();
    QDate date = QDate::currentDate();
    for(int i=0; i<100; i += 10) {
        QVariant intVariant = QVariant(i);
        QStandardItem *item1 = new QStandardItem();
        item1->setData(intVariant, Qt::EditRole);

        QStandardItem *item2 = new QStandardItem();
        item2->setData(QVariant(date.addDays(i)), Qt::EditRole);

        QStandardItem *item3 = new QStandardItem();
        double v = (double)i + (double) i / 100.0;
        QVariant doubleVariant = QVariant(v);
        item3->setData(doubleVariant, Qt::EditRole);
        
        QStandardItem *item4 = new QStandardItem(QString("String: %1").arg(i));

        QList<QStandardItem *> items;
        items << item1 << item2 << item3 << item4;
        model->appendRow(items);
    }
    view.setModel(model);

    view.setItemDelegate(new BarGraphDelegate());

    view.show();    
    return app.exec();
}

