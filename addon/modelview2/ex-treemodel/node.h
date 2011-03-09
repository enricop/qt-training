/*************************************************************************
 *
 * Copyright (c) 2008-2011, Nokia Corporation and/or its subsidiary(-ies).
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#ifndef NODE_H
#define NODE_H

#include <QtCore>

class Node
{
public:
    Node(const QString& aText="No Data", Node *aParent=0);
    ~Node();
    QVariant data() const;
public:
    QString text;
    Node *parent;
    QList<Node*> children;

};

#endif // NODE_H
