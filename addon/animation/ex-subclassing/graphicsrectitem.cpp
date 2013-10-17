#include "graphicsrectitem.h"

GraphicsRectItem::GraphicsRectItem(qreal x, qreal y, qreal width, qreal height, QGraphicsItem *parent)
    : QGraphicsRectItem(x, y, width, height, parent)
{
}

QRectF GraphicsRectItem::geometry() const
{
    return rect();
}

void GraphicsRectItem::setGeometry(const QRectF &rectangle)
{
    setRect(rectangle);
}
