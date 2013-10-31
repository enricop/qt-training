#include <QHBoxLayout>
#include <QProgressBar>
#include <QPushButton>

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

    connect(mStartButton, SIGNAL(clicked()), this, SLOT(startWork()));
}

void ProgressWindow::startWork()
{
    // Task: Create a worker object and thread. The worker object should
    // perform a CPU intensive task one thousand times, reporting the
    // progress back to the main GUI thread.
    //
    // Optional: Exit gracefully if the window is closed before the thread has
    // finished
    // 
    // Hint: The function busy_work() is provided in file work.cpp as the task
    // to be performed.
    //
    // Hint: Pressing the start button a second time should NOT start a second
    // thread!
}
