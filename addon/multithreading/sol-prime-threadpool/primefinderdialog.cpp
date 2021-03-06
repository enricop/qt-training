#include <QVariant>
#include <QLabel>
#include <QPushButton>
#include <QTime>
#include <qmath.h>
#include <QDialogButtonBox>
#include "primefinderdialog.h"
#include "ui_primefinderdialog.h"

PrimeFinderDialog::PrimeFinderDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PrimeFinderDialog)
{
    ui->setupUi(this);
    connect (&m_finder, SIGNAL(progressValueChanged(int)), ui->progressBar, SLOT(setValue(int)));
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

void PrimeFinderDialog::reject() {
    if (m_finder.isBusy()) m_finder.cancel();
    else QDialog::reject();
}

void PrimeFinderDialog::accept()
{
    ui->buttonBox->setStandardButtons(QDialogButtonBox::Cancel);
    ui->nThreadsSpinBox->setEnabled(false);
    QTime startTime = QTime::currentTime();
    qlonglong maxValue = qPow((qlonglong)10, (qlonglong)(ui->powerBox->value()));
    m_finder.findPrimesUpTo(maxValue);
    QTime stopTime = QTime::currentTime();
    double secs = startTime.msecsTo(stopTime) / 1000.0;
    int nthreads = ui->nThreadsSpinBox->value();
    int nprimes = m_finder.foundPrimes().length();
    double kpps = nprimes / (1000.0 * secs);
    QString result = QString("%3 threads found %1 primes in %2 secs = %4 kpps\n")
            .arg(nprimes).arg(secs).arg(nthreads).arg(kpps);
    ui->resultsArea->append(result);
    ui->buttonBox->setStandardButtons(QDialogButtonBox::Ok | QDialogButtonBox::Close);
    ui->nThreadsSpinBox->setEnabled(true);
}

void PrimeFinderDialog::on_granularitySpinBox_valueChanged(int arg1)
{
    m_finder.setGranularity(arg1);
}

void PrimeFinderDialog::on_nThreadsSpinBox_valueChanged(int arg1)
{
    m_finder.setNumThreads(arg1);
}
