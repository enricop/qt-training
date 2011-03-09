/*************************************************************************
 *
 * Copyright (c) 2008-2011, Nokia Corporation and/or its subsidiary(-ies).
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include "orderform.h"
#include "ui_orderform.h"

OrderForm::OrderForm(QWidget *parent)
    : QDialog(parent),
      ui(new Ui::OrderForm)
{
    ui->setupUi(this);
}

OrderForm::~OrderForm()
{
    delete ui;
}

void OrderForm::updateTotal()
{
    ui->total->setValue(ui->quantity->value() * ui->price->value());
}
