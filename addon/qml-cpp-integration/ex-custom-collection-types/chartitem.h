/*************************************************************************
 *
 * Copyright (c) 2008-2011, Nokia Corporation and/or its subsidiary(-ies).
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#ifndef CHARTITEM_H
#define CHARTITEM_H

#include <QDeclarativeItem>

class BarItem;

class ChartItem : public QDeclarativeItem
{
    Q_OBJECT
    Q_PROPERTY(QDeclarativeListProperty<BarItem> bars READ bars NOTIFY barsChanged)

public:
    ChartItem(QDeclarativeItem *parent = 0);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget = 0);

    QDeclarativeListProperty<BarItem> bars();

signals:
    void barsChanged();

private:
    static void append_bar(QDeclarativeListProperty<BarItem> *list, BarItem *bar);
    QList<BarItem*> m_bars;
};

#endif