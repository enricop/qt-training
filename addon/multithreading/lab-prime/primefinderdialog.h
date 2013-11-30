#ifndef PRIMEFINDERDIALOG_H
#define PRIMEFINDERDIALOG_H

#include <QDialog>

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

    void accept();

private:
    Ui::PrimeFinderDialog *ui;
    QList<qlonglong> m_foundPrimes;
};

#endif // PRIMEFINDERDIALOG_H
