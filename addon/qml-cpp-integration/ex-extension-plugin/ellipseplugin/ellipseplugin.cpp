/*************************************************************************
 *
 * Copyright (c) 2008-2011, Nokia Corporation and/or its subsidiary(-ies).
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include <qdeclarative.h>
#include "ellipseplugin.h"
#include "ellipseitem.h"

void EllipsePlugin::registerTypes(const char *uri)
{
    qmlRegisterType<EllipseItem>(uri, 9, 0, "Ellipse");
}

Q_EXPORT_PLUGIN2(ellipseplugin, EllipsePlugin);
