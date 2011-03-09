/*************************************************************************
 *
 * Copyright (c) 2008-2011, Nokia Corporation and/or its subsidiary(-ies).
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#ifndef CONTACTFORM_H
#define CONTACTFORM_H

#include <QtGui>

class ContactForm : public QWidget
{
    Q_OBJECT

public:
    ContactForm(QWidget *parent = 0);
    void createContactGroup();
    void createDetailsGroup();

private:
    QGroupBox *m_contactGroup;
    QGroupBox *m_detailsGroup;
};

#endif // CONTACTFORM_H
