#include <QMouseEvent>
#include <QPainter>
#include <QThread>

#include "renderer.h"
#include "mandelbrot.h"

Mandelbrot::Mandelbrot(QWidget *parent)
    : QWidget(parent), mRenderThread(0), mRenderer(0)
{
    setWindowTitle("Mandelbrot");
    setFixedSize(720, 480);

    mImage = QImage(720, 480, QImage::Format_RGB32);
    mImage.fill(Qt::black);
}

void Mandelbrot::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.drawImage(0, 0, mImage);

    if (mRenderThread == 0) {
        painter.setPen(Qt::white);
        painter.drawText(rect(), Qt::AlignCenter, tr("Click to render"));
    }
}

void Mandelbrot::mousePressEvent(QMouseEvent *event)
{
    if (!mRenderThread && rect().contains(event->pos())) {
        // clear image
        mImage.fill(Qt::black);

        // create thread and renderer
        mRenderThread = new QThread(this);
        mRenderer = new Renderer(QRectF(QPointF(-2.0, -1.0), QPointF(1.0, 1.0)), mImage.size());
        mRenderer->moveToThread(mRenderThread);

        connect(mRenderThread, &QThread::started, mRenderer, &Renderer::render);
        connect(mRenderThread, &QThread::finished, mRenderThread, &QThread::deleteLater);
        connect(mRenderer, &Renderer::scanLineRendered, this, &Mandelbrot::scanLineRendered);
        connect(mRenderer, &Renderer::finished, this, &Mandelbrot::finished);

        mRenderThread->start();

        update();
        event->accept();
    }
}

void Mandelbrot::closeEvent(QCloseEvent*)
{
    finished();
}

void Mandelbrot::scanLineRendered(QRgb* data, int row, int width)
{
    if (width != mImage.width()) return;

    uint *scanline = reinterpret_cast<uint*>(mImage.scanLine(row));
    for (int n=0; n<width; ++n) *scanline++ = data[n];

    free(data);
    update();
}

void Mandelbrot::finished()
{
    // stop the thread
    if (mRenderThread) {
        if (mRenderThread->isRunning()) mRenderThread->quit();
        mRenderThread = 0;
    }

    // stop the rendering
    if (mRenderer) {
        delete mRenderer;
        mRenderer = 0;
    }
}
