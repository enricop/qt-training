/*************************************************************************
 *
 * Copyright (c) 2008-2011, Nokia Corporation and/or its subsidiary(-ies).
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include <QtGui>

// Simple ListMode without icons
void showListWithoutIcons()
{
    QListWidget *w = new QListWidget;
    for (int i = 1; i < 10; ++i)
        w->addItem(QString("Item %1").arg(i));

    QListWidgetItem *item = new QListWidgetItem("Extra item");
    w->addItem(item);
    w->show();
}

// ListMode with Icons
void showListWithIcons()
{
    QListWidget *w = new QListWidget;
    for (int i = 1; i < 10; ++i) {
        QString text = QString("Item %1").arg(i);
        QListWidgetItem *item = new QListWidgetItem(text, w);
        item->setIcon(QPixmap(QString(":images/%1.png").arg(i)));
    }
    w->show();
}

// IconMode
void showListInIconMode()
{
    QListWidget *w = new QListWidget;
    for (int i = 1; i < 10; ++i) {
        QListWidgetItem *item = new QListWidgetItem(QString("Item %1").arg(i), w);
        item->setIcon(QPixmap(QString(":images/%1.png").arg(i)));
    }
    w->setViewMode(QListView::IconMode);
    w->show();
}

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    showListWithoutIcons();
    showListWithIcons();
    showListInIconMode();

    return app.exec();
}
