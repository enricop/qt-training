#ifndef PROGRESSWINDOW_H
#define PROGRESSWINDOW_H

#include <QWidget>

class QProgressBar;
class QPushButton;

class ProgressWindow : public QWidget
{
    Q_OBJECT
public:
    ProgressWindow(QWidget *parent = 0);

public slots:
    void startWork();

private:
    QProgressBar *mProgress;
    QPushButton *mStartButton;
};

#endif // PROGRESSWINDOW_H
