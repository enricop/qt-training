/*************************************************************************
 *
 * Copyright (c) 2008-2011, Nokia Corporation and/or its subsidiary(-ies).
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#ifndef INSERTREMOVEMODEL_H
#define INSERTREMOVEMODEL_H

#include <QtCore>

#include "editablemodel.h"

class Node;

class InsertRemoveModel : public EditableModel
{
public:
    InsertRemoveModel(QObject *parent=0);
    ~InsertRemoveModel();
    void insertNode(Node *parentNode, int pos, Node *node);
    void removeNode(Node *node);
    void removeAllNodes();
};

#endif // INSERTREMOVEMODEL_H
