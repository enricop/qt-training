/*************************************************************************
 *
 * Copyright (c) 2008-2011, Nokia Corporation and/or its subsidiary(-ies).
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

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
