/*************************************************************************
 *
 * Copyright (c) 2008-2011, Nokia Corporation and/or its subsidiary(-ies).
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include "keysxmlwriter.h"

#include "keyengine.h"

KeysXmlWriter::KeysXmlWriter(KeyEngine *input)
    : m_input(input)
{
    setAutoFormatting(true);
}

bool KeysXmlWriter::write()
{
    if(!m_input || !device()) {
        return false;
    }
    return true;
}
