#ifndef STYLE_H
#define STYLE_H

#include <QColor>
#include <QDeclarativeItem>

class Style : public QDeclarativeItem
{
    Q_OBJECT
    Q_PROPERTY(QColor color READ color WRITE setColor NOTIFY colorChanged)
    Q_PROPERTY(bool filled READ filled WRITE setFilled NOTIFY filledChanged)

public:
    Style(QDeclarativeItem *parent = 0);

    const QColor &color() const;
    void setColor(const QColor &newColor);
    bool filled() const;
    void setFilled(bool newFilled);

signals:
    void colorChanged();
    void filledChanged();

private:
    QColor m_color;
    bool m_filled;
};

#endif
