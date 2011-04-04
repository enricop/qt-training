#include "style.h"

Style::Style(QDeclarativeItem *parent)
    : QDeclarativeItem(parent)
{
}

const QColor &Style::color() const
{
    return m_color;
}

void Style::setColor(const QColor &newColor)
{
    if (m_color != newColor) {
        m_color = newColor;
        emit colorChanged();
    }
}

bool Style::filled() const
{
    return m_filled;
}

void Style::setFilled(bool newFilled)
{
    if (m_filled != newFilled) {
        m_filled = newFilled;
        emit filledChanged();
    }
}
