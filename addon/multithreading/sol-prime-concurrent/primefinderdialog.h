#ifndef PRIMEFINDERDIALOG_H
#define PRIMEFINDERDIALOG_H

#include <QList>
#include <QDialog>
#include <QFutureWatcher>
#include <QTime>

namespace Ui {
class PrimeFinderDialog;
}

class PrimeFinderDialog : public QDialog
{
    Q_OBJECT

public:
    explicit PrimeFinderDialog(QWidget *parent = 0);
    ~PrimeFinderDialog();

protected:
    void changeEvent(QEvent *e);

private slots:
    void on_powerBox_valueChanged(int arg1);
    void handleWatcherFinished();
    void reject();
    void accept();

    void on_nThreadsSpinBox_valueChanged(int arg1);

private:
    Ui::PrimeFinderDialog *ui;
    bool m_Busy;
    QTime m_startTime;
    QList<qlonglong> m_primes;
    QFutureWatcher<void> m_watcher;
};

#endif // PRIMEFINDERDIALOG_H
