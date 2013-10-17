#ifndef TRACER_H
#define TRACER_H

#include <QObject>
#include <QPoint>
class QPainter;
class QSvgGenerator;

class Tracer : public QObject
{
    Q_OBJECT

public:
    Tracer(QWidget *parent, const QString &path);
    ~Tracer();

public slots:
    void drawPath(const QVariant &value);

private:
    QPainter *painter;
    QSvgGenerator *generator;
    int currentSnapshot;
    QPoint lastPoint;
};

#endif
