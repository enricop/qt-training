#ifndef KEYSXMLREADER_H
#define KEYSXMLREADER_H

#include <QtCore>

class KeyEngine;

class KeysXmlReader : public QXmlStreamReader
{
public:
    KeysXmlReader(KeyEngine *input);
    bool read();
private:
    void readKeys();
    void readItem();
private:
    KeyEngine *m_input;
};

#endif // KEYSXMLREADER_H
