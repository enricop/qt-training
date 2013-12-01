#ifndef PRIMEFINDERDIALOG_H
#define PRIMEFINDERDIALOG_H

#include <QDialog>
#include "primefinder.h"

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
    void reject();
    void accept();

    void on_nThreadsSpinBox_valueChanged(int arg1);

private:
    Ui::PrimeFinderDialog *ui;
    PrimeFinder m_finder;
};

#endif // PRIMEFINDERDIALOG_H
