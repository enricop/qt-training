/*************************************************************************
 *
 * Copyright (c) 2008-2011, Nokia Corporation and/or its subsidiary(-ies).
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#ifndef SLIDER_H
#define SLIDER_H

#include <QtGui>

class QLabel;
class QSlider;

class Slider : public QWidget
{
public:
    Slider(Qt::Orientation orient = Qt::Horizontal, QWidget *parent = 0);
};

#endif // SLIDER_H
