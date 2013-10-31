#ifndef MANDELBROT_H
#define MANDELBROT_H

#include <QWidget>

class QImage;
class QThread;
class Renderer;

class Mandelbrot : public QWidget
{
    Q_OBJECT

public:
    Mandelbrot(QWidget *parent = 0);

public slots:
    void scanLineRendered(QRgb *data, int row, int width);
    void finished();

protected:
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void closeEvent(QCloseEvent *event);

private:
    QImage mImage;
    QThread *mRenderThread;
    Renderer *mRenderer;
};

#endif // MANDELBROT_H
