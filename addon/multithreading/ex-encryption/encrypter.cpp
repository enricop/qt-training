#include "encryption/blowfish.h"
#include "encrypter.h"

Encrypter::Encrypter() : QObject()
{
}

void Encrypter::encrypt(const QString &text, const QString &password)
{
    if (password.isEmpty()) return;

    Blowfish BF;
    BF.Set_Passwd(password.toUtf8().data());

    int datasize = text.toUtf8().length() + 1;
    if (datasize % 8) datasize += 8 - (datasize % 8); // must be in multiple of 8 bytes

    char *data = (char*)malloc(datasize);
    strncpy(data, text.toUtf8().data(), datasize);

    BF.Encrypt(data, datasize);

    emit encryptionFinished(QByteArray(data).toBase64());

    free(data);
}
