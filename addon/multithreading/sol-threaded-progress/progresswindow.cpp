#include <QHBoxLayout>
#include <QProgressBar>
#include <QPushButton>
#include <QThread>

#include "worker.h"

#include "progresswindow.h"

ProgressWindow::ProgressWindow(QWidget *parent)
    : QWidget(parent)
{
    QHBoxLayout *layout = new QHBoxLayout(this);

    mStartButton = new QPushButton("Start");
    layout->addWidget(mStartButton);

    mProgress = new QProgressBar();
    mProgress->setMinimum(0);
    mProgress->setMaximum(100);
    layout->addWidget(mProgress);

    connect(mStartButton, &QPushButton::clicked, this, &ProgressWindow::startWork);
}

ProgressWindow::~ProgressWindow()
{
    // we are shutting down, to stop the thread
    emit finish();
}

void ProgressWindow::startWork()
{
    // disable start button
    mStartButton->setEnabled(false);

    // setup worker and thread
    QThread *workerthread = new QThread(this);
    Worker *worker = new Worker();
    worker->moveToThread(workerthread);

    connect(workerthread, &QThread::started, worker, &Worker::start);
    connect(worker, &Worker::finished, workerthread, &QThread::quit);
    connect(worker, &Worker::finished, worker, &Worker::deleteLater);
    connect(workerthread, &QThread::finished, workerthread, &QThread::deleteLater);

    // note the connection type (discuss: why a direct connection?)
    connect(this, &ProgressWindow::finish, worker, &Worker::finish, Qt::DirectConnection);

    // connect to progressbar
    connect(worker, SIGNAL(update(int)), mProgress, SLOT(setValue(int)));

    // start the thread
    workerthread->start();
}
