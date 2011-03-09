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
private:
    KeyEngine *m_input;
};

#endif // KEYSXMLREADER_H
