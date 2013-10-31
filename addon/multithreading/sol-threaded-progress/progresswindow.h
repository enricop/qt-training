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
    ~ProgressWindow();

public slots:
    void startWork();

signals:
    void finish();

private:
    QProgressBar *mProgress;
    QPushButton *mStartButton;
};

#endif // PROGRESSWINDOW_H
