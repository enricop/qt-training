/*************************************************************************
 *
 * Copyright (c) 2012 Digia Plc.
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include "bargraphdelegate.h"
#include <QPainter>


const int MAX_VALUE = 100;
const int MIN_BAR_WIDTH = 64;

BarGraphDelegate::BarGraphDelegate(QObject *parent) :
    QStyledItemDelegate(parent)
{
}

void BarGraphDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{      
    if(index.data(Qt::EditRole).userType() == QVariant::Int) {
        int value = index.data(Qt::EditRole).toInt();

        // rect with width proportional to value
        QRect rect(option.rect.adjusted(4,4,-4,-4));
        rect.setWidth(rect.width()*value/MAX_VALUE);

        // draw the value bar
        painter->fillRect(rect, QBrush(QColor("steelblue").lighter(200-value)));

        // calculate text min width
        QString text = index.data().toString();
        // draw value text centered
        painter->drawText(option.rect, text, QTextOption(Qt::AlignCenter));
    }
    else QStyledItemDelegate::paint(painter, option, index);
}

QSize BarGraphDelegate::sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    if(index.data(Qt::EditRole).userType() == QVariant::Int) 
        return QSize(MIN_BAR_WIDTH, option.fontMetrics.height());
    else return QStyledItemDelegate::sizeHint(option, index);
}
