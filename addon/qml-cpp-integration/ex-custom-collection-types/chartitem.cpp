#include <QtGui>
#include "baritem.h"
#include "chartitem.h"

ChartItem::ChartItem(QDeclarativeItem *parent)
    : QDeclarativeItem(parent)
{
    setFlag(QGraphicsItem::ItemHasNoContents, false);
}

void ChartItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                        QWidget * /*widget*/)
{
    if (m_bars.count() == 0)
        return;

    qreal minimum = m_bars[0]->value();
    qreal maximum = minimum;

    for (int i = 1; i < m_bars.count(); ++i) {
        minimum = qMin(minimum, m_bars[i]->value());
        maximum = qMax(maximum, m_bars[i]->value());
    }

    if (maximum == minimum)
        return;

    painter->save();

    qreal scale = option->rect.height()/(maximum - minimum);
    qreal barWidth = option->rect.width()/m_bars.count();

    for (int i = 0; i < m_bars.count(); ++i) {
        BarItem *bar = m_bars[i];
        qreal barEdge1 = scale * (maximum - bar->value());
        qreal barEdge2 = scale * maximum;
        QRectF barRect(option->rect.x() + i * barWidth,
                       option->rect.y() + qMin(barEdge1, barEdge2),
                       barWidth, qAbs(barEdge1 - barEdge2));

        painter->setBrush(bar->color());
        painter->drawRect(barRect);
    }

    painter->restore();
}

QDeclarativeListProperty<BarItem> ChartItem::bars()
{
    return QDeclarativeListProperty<BarItem>(this, 0, &ChartItem::append_bar);
}

void ChartItem::append_bar(QDeclarativeListProperty<BarItem> *list, BarItem *bar)
{
    ChartItem *chart = qobject_cast<ChartItem *>(list->object);
    if (chart) {
        bar->setParentItem(chart);
        chart->m_bars.append(bar);
        chart->barsChanged();
    }
}
