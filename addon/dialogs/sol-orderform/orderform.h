/*************************************************************************
 *
 * Copyright (c) 2008-2011, Nokia Corporation and/or its subsidiary(-ies).
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#ifndef ORDERFORM_H
#define ORDERFORM_H

#include <QtGui/QDialog>

namespace Ui {
    class OrderForm;
}

class OrderForm : public QDialog
{
    Q_OBJECT

public:
    OrderForm(QWidget *parent = 0);
    ~OrderForm();

private slots:
    void updateTotal();

private:
    Ui::OrderForm *ui;
};

#endif // ORDERFORM_H
