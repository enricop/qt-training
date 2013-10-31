#include <QThread>
#include "renderer.h"

Renderer::Renderer(QRectF viewrect, QSize imagesize)
    : QObject(0),
      mViewRect(viewrect.normalized()),
      mImageSize(imagesize),
      mAbort(false)
{
}

Renderer::~Renderer()
{
    if (thread() != QThread::currentThread()) {
        mAbort = true;
        thread()->wait();
    }
}

void Renderer::render()
{
    const int maxIterations = 2048;
    const double xscalefactor = mViewRect.width() / mImageSize.width();
    const double yscalefactor = mViewRect.height() / mImageSize.height();

    // initialize colormap
    QRgb colormap[maxIterations];
    for (int n=0; n<maxIterations; n++) {
        if (n < 16) {
            int c = (n / 16.0) * 64;
            colormap[n] = qRgb(0, c, c);
        } else if (n < 32) {
            int c = ((n - 16) / 16.0) * 64 + 64;
            colormap[n] = qRgb(c/4, c, c);
        } else if (n < 128) {
            int c = ((n - 32) / 96.0) * 64 + 128;
            colormap[n] = qRgb(c/3, c, c);
        } else if (n < maxIterations) {
            int c = ((n - 128) / (double)(maxIterations-128)) * 64 + 192;
            colormap[n] = qRgb(c/2, c, c);
        }
    }

    // iterate over pixels
    for (int py=0; py<mImageSize.height(); py++) {
        if (mAbort) return;

        double y0 = py * yscalefactor + mViewRect.top();
        QRgb *scanline = (QRgb*)calloc(mImageSize.width(), sizeof(QRgb));

        for (int px=0; px<mImageSize.width(); px++) {
            double x0 = px * xscalefactor + mViewRect.left();
            double x = x0;
            double y = y0;

            int iteration = 0;

            do {
                iteration++;
                double xtemp = x*x - y*y + x0;
                y = 2 * x * y + y0;
                x = xtemp;

                if ((x*x + y*y > 4.0)) break;
            } while (iteration < maxIterations);

            if (iteration < maxIterations) {
                scanline[px] = colormap[iteration];
            } else {
                scanline[px] = qRgb(0, 0, 0);
            }
        }

        emit scanLineRendered(scanline, py, mImageSize.width());
    }

    emit finished();
}
