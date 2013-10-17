#ifndef TRACER_H
#define TRACER_H

#include <QHash>
#include <QObject>
#include <QPixmap>
#include <QPoint>
class QPropertyAnimation;
class QPainter;
class QSvgGenerator;

class Tracer : public QObject
{
    Q_OBJECT

public:
    Tracer(QWidget *parent, const QString &path);
    ~Tracer();
    void setPixmap(QPropertyAnimation *animation, const QPixmap &pixmap);

public slots:
    void drawLast();
    void drawPath(const QVariant &value);

private:
    int alphaValue;
    int currentSnapshot;
    int lastSnapshot;
    QPropertyAnimation *lastAnimation;
    QHash<QPropertyAnimation *, QPixmap> pixmaps;
    QPainter *painter;
    QSvgGenerator *generator;
};

#endif
