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
