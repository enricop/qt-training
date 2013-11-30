#include <QVariant>
#include <QLabel>
#include <QPushButton>
#include <QTime>
#include <qmath.h>

#include "isprime.h"
#include "primefinderdialog.h"
#include "ui_primefinderdialog.h"

PrimeFinderDialog::PrimeFinderDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PrimeFinderDialog)
{
    ui->setupUi(this);
}

PrimeFinderDialog::~PrimeFinderDialog()
{
    delete ui;
}

void PrimeFinderDialog::changeEvent(QEvent *e)
{
    QDialog::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void PrimeFinderDialog::on_powerBox_valueChanged(int arg1)
{
    qlonglong displayValue = qPow((qlonglong)10, (qlonglong)(ui->powerBox->value()));
    QVariant var(displayValue);
    ui->valueLabel->setText(var.toString());
}

void PrimeFinderDialog::accept()
{
    // NOTE: You should probably move all the actual prime calculation out of this
    // class and into a separate QObject-derived class (PrimeFinder), so it can more easily
    // be parallelized.
    ui->buttonBox->setEnabled(false);
    m_foundPrimes.clear();

    QTime startTime = QTime::currentTime();
    m_foundPrimes << 2;

    qlonglong maxValue = qPow((qlonglong)10, (qlonglong)(ui->powerBox->value()));
    for (qlonglong i=3; i<maxValue; i += 2)
        if (isPrime(i)) m_foundPrimes << i;
    QTime stopTime = QTime::currentTime();
    int msecs = startTime.msecsTo(stopTime);
    QString result = QString("found %1 primes in %2 miliseconds\n")
            .arg(m_foundPrimes.length()).arg(msecs);
    ui->resultsArea->append(result);
    ui->buttonBox->setEnabled(true);
}
