/*************************************************************************
 *
 * Copyright (c) 2008-2011, Nokia Corporation and/or its subsidiary(-ies).
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#ifndef LIGHTWIDGET_H
#define LIGHTWIDGET_H

#include <QDebug>
#include <QWidget>

class LightWidget : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(bool on READ isOn WRITE setOn)

public:
    LightWidget(const QColor &color, QWidget *parent = 0);
    bool isOn() const;
    void setOn(bool enable);
    QSize sizeHint() const;

protected:
    void paintEvent(QPaintEvent *event);

private:
    QColor color;
    bool m_on;
};

#endif
