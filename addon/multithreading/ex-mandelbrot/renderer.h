#ifndef RENDERER_H
#define RENDERER_H

#include <QObject>
#include <QRectF>
#include <QSize>
#include <QRgb>

class Renderer : public QObject
{
    Q_OBJECT
public:
    explicit Renderer(QRectF viewrect, QSize imagesize);
    ~Renderer();

public slots:
    void render();

signals:
    void scanLineRendered(QRgb* data, int row, int width);
    void finished();

private:
    const QRectF mViewRect;
    const QSize mImageSize;

    volatile bool mAbort;
};

#endif // RENDERER_H
