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
