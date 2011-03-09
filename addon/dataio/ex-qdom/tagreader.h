/*************************************************************************
 *
 * Copyright (c) 2008-2011, Nokia Corporation and/or its subsidiary(-ies).
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#ifndef TAGREADER_H
#define TAGREADER_H

#include <QDomElement>

class TagReader
{
public:
  void parse( const char* file );
protected:
  void parseNode( QDomElement elm, int offset );
};

#endif /* TAGREADER_H */

