/*************************************************************************
 *
 * Copyright (c) 2008-2011, Nokia Corporation and/or its subsidiary(-ies).
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include "tagreader.h"
#if defined Q_WS_WIN
#include "qt_windows.h"
#endif

int main( int argc, char** argv )
{
  for ( int i=1; i < argc; i++ ) {
    TagReader reader;
    reader.parse( argv[i] );
  }
}
