/*************************************************************************
 *
 * Copyright (c) 2008-2011, Nokia Corporation and/or its subsidiary(-ies).
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include <QtGui>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QTreeWidget *w = new QTreeWidget;
    w->setSortingEnabled(true);

    QStringList headerTexts;
    headerTexts << "Column A" << "Column B" << "Column C";
    w->setHeaderLabels(headerTexts);

    QTreeWidgetItem *top = new QTreeWidgetItem(w);
    top->setText(0, "Top A");
    top->setText(1, "Top B");
    top->setText(2, "Top C");

    QTreeWidgetItem *top2 = new QTreeWidgetItem();
    top2->setText(0, "Second Top A");
    top2->setText(1, "Second Top B");
    w->addTopLevelItem(top2);

    for (int i = 1; i < 10; ++i) {
        QTreeWidgetItem *sub = new QTreeWidgetItem(top2);
        sub->setText(0, QString("Sub A - %1").arg(i));
        sub->setText(1, QString("Sub B - %1").arg(i));
        sub->setText(2, QString("Sub C - %1").arg(i));
        sub->setIcon(1, QPixmap(QString(":images/%1.png").arg(i)));
    }

    w->show();
    return app.exec();
}
