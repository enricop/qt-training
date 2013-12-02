#include <QtConcurrent>
#include <QVariant>
#include <QLabel>
#include <QPushButton>
#include <qmath.h>
#include <QDialogButtonBox>
#include <QProgressBar>
#include "isprime.h"
#include "primefinderdialog.h"
#include "ui_primefinderdialog.h"

PrimeFinderDialog::PrimeFinderDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PrimeFinderDialog)
{
    m_Busy = false;
    ui->setupUi(this);
    connect (&m_watcher, SIGNAL(finished()), this, SLOT(handleWatcherFinished()));
    connect (&m_watcher, SIGNAL(progressRangeChanged(int,int)), ui->progressBar, SLOT(setRange(int,int)));
    connect (&m_watcher, SIGNAL(progressValueChanged(int)), ui->progressBar, SLOT(setValue(int)));
    on_nThreadsSpinBox_valueChanged(1);
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
    qlonglong displayValue = qPow((qlonglong)10, (qlonglong)(arg1));
    QVariant var(displayValue);
    ui->valueLabel->setText(var.toString());
}

void PrimeFinderDialog::reject() {
    if (m_Busy) m_watcher.cancel();
    else QDialog::reject();
}

void PrimeFinderDialog::accept() {
    m_Busy = true;
    ui->buttonBox->setStandardButtons(QDialogButtonBox::Cancel);
    m_startTime = QTime::currentTime();
    qlonglong maxValue = qPow((qlonglong)10, ui->powerBox->value());
    m_primes.clear();
    m_primes << 2;
    qlonglong i;
    for (i=3; i<=maxValue; i += 2)
       m_primes << i;
    m_watcher.setFuture( QtConcurrent::filter(m_primes, isPrime));
}

void PrimeFinderDialog::handleWatcherFinished() {
    QTime stopTime = QTime::currentTime();
    double secs = (double) m_startTime.msecsTo(stopTime) / 1000.0;
    int nprimes = m_primes.length();
    double kpps = (double) nprimes / (secs * 1000.0);
    int tc = QThreadPool::globalInstance()->maxThreadCount();
    QString result = QString("%4 threads found %1 primes in %2 seconds = %3 kpps")
            .arg(nprimes).arg(secs).arg(kpps).arg(tc);
    ui->resultsArea->append(result);
    ui->buttonBox->setStandardButtons(QDialogButtonBox::Ok | QDialogButtonBox::Close);
    m_Busy = false;
}

void PrimeFinderDialog::on_nThreadsSpinBox_valueChanged(int tc) {
    QThreadPool::globalInstance()->setMaxThreadCount(tc);
}
