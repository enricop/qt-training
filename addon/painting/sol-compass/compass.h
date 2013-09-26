#ifndef COMPASS_H
#define COMPASS_H

#include <QWidget>

class Compass : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(double direction READ direction WRITE setDirection NOTIFY directionChanged)

public:
    explicit Compass(QWidget *parent = 0);

    double direction();
    virtual QSize sizeHint() const;

public slots:
    void setDirection(double d);

signals:
    void directionChanged(double d);

protected:
    virtual void mousePressEvent(QMouseEvent *event);
    virtual void paintEvent(QPaintEvent *event);

private:
    double m_direction;
};

#endif // COMPASS_H
