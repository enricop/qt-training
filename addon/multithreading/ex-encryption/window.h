#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>

class QLineEdit;
class QPlainTextEdit;
class QThread;

class Window : public QWidget
{
    Q_OBJECT
public:
    Window(QWidget *parent = 0);

public slots:
    void encryptText();
    void onEncryptionFinished(const QString &encrypted);

signals:
    void encrypt(const QString &text, const QString &password);

protected:
    void closeEvent(QCloseEvent *event);

private:
    QLineEdit *mPassword;
    QPlainTextEdit *mText;
    QPlainTextEdit *mEncryptedText;

    QThread *mThread;
};

#endif // WINDOW_H
