#ifndef GRAPHICSRECTITEM_H
#define GRAPHICSRECTITEM_H

#include <QGraphicsRectItem>
#include <QObject>

class GraphicsRectItem : public QObject, public QGraphicsRectItem
{
    Q_OBJECT
    Q_PROPERTY(QRectF geometry READ geometry WRITE setGeometry)

public:
    GraphicsRectItem(qreal x, qreal y, qreal width, qreal height, QGraphicsItem *parent = 0);
    QRectF geometry() const;
    void setGeometry(const QRectF &newRect);
};

#endif
