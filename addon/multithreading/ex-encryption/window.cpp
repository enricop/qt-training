#include <QFormLayout>
#include <QLineEdit>
#include <QPlainTextEdit>
#include <QThread>

#include "window.h"
#include "encrypter.h"

Window::Window(QWidget *parent)
    : QWidget(parent)
{
    QFormLayout *layout = new QFormLayout(this);

    mText = new QPlainTextEdit();
    layout->addRow(tr("Plain text"), mText);
    mPassword = new QLineEdit();
    mPassword->setEchoMode(QLineEdit::Password);
    layout->addRow(tr("Password"), mPassword);
    mEncryptedText = new QPlainTextEdit();
    mEncryptedText->setReadOnly(true);
    layout->addRow(tr("Encrypted text"), mEncryptedText);

    // connect to our encryption
    connect(mText, &QPlainTextEdit::textChanged, this, &Window::encryptText);
    connect(mPassword, &QLineEdit::textChanged, this, &Window::encryptText);

    // create thread and start the thread
    mThread = new QThread(this);
    Encrypter *encrypter = new Encrypter();
    encrypter->moveToThread(mThread);
    mThread->start();

    // clean up when we're finished
    connect(mThread, &QThread::finished, mThread, &QObject::deleteLater);
    connect(mThread, &QThread::finished, encrypter, &QObject::deleteLater);

    // setup communication to encrypter
    connect(this, &Window::encrypt, encrypter, &Encrypter::encrypt);
    connect(encrypter, &Encrypter::encryptionFinished, this, &Window::onEncryptionFinished);
}

void Window::encryptText()
{
    emit encrypt(mText->toPlainText(), mPassword->text());
}

void Window::onEncryptionFinished(const QString &encrypted)
{
    mEncryptedText->setPlainText(encrypted);
}

void Window::closeEvent(QCloseEvent *event)
{
    // quit the thread and give it a chance to finish
    mThread->quit();
    mThread->wait(250);
}
