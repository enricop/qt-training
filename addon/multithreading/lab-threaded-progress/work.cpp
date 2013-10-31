#include <QCryptographicHash>

void busy_work()
{
    // create array of random letters
    QByteArray data;
    for (int n=0; n<256; n++) {
        data += 'A' + qrand() % 26;
    }

    // do a whole bunch of useless CPU intensive busy work
    for (int n=0; n<10000; n++) {
        data = QCryptographicHash::hash(data, QCryptographicHash::Md4);
        data = QCryptographicHash::hash(data, QCryptographicHash::Md5);
        data = QCryptographicHash::hash(data, QCryptographicHash::Sha1);
    }
}
