#include <QtGui>
#include "ellipseitem.h"

EllipseItem::EllipseItem(QDeclarativeItem *parent)
    : QDeclarativeItem(parent)
{
    setFlag(QGraphicsItem::ItemHasNoContents, false);
}

void EllipseItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                        QWidget * /*widget*/ )
{
    painter->save();
    if (m_style == Outline) {
        painter->setPen(m_color);
        painter->setBrush(Qt::NoBrush);
    } else {
        painter->setPen(Qt::NoPen);
        painter->setBrush(m_color);
    }
    painter->drawEllipse(option->rect);
    painter->restore();
}

const QColor &EllipseItem::color() const
{
    return m_color;
}

void EllipseItem::setColor(const QColor &newColor)
{
    if (m_color != newColor) {
        m_color = newColor;
        update();
        emit colorChanged();
    }
}

const EllipseItem::Style &EllipseItem::style() const
{
    return m_style;
}

void EllipseItem::setStyle(const Style &newStyle)
{
    if (m_style != newStyle) {
        m_style = newStyle;
        update();
        emit styleChanged();
    }
}
