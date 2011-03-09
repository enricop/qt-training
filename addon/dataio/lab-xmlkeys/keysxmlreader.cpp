/*************************************************************************
 *
 * Copyright (c) 2008-2011, Nokia Corporation and/or its subsidiary(-ies).
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include "keysxmlreader.h"

#include "keyengine.h"

KeysXmlReader::KeysXmlReader(KeyEngine *input)
    : m_input(input)
{
}


bool KeysXmlReader::read()
{
    if(!m_input || !device()) {
        raiseError("No input object set");
    }
    return !error();
}
