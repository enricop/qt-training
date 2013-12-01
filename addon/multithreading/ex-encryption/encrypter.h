#ifndef ENCRYPTER_H
#define ENCRYPTER_H

#include <QObject>

class Encrypter : public QObject
{
    Q_OBJECT
public:
    Encrypter();

public slots:
    void encrypt(const QString &text, const QString &password);

signals:
    void encryptionFinished(const QString &text);
};

#endif // ENCRYPTER_H
