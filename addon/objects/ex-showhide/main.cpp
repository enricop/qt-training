/*************************************************************************
 *
 * Copyright (c) 2008-2011, Nokia Corporation and/or its subsidiary(-ies).
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include<QtGui>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QWidget *top = new QWidget;
    QCheckBox *cb1 = new QCheckBox("b1");
    QCheckBox *cb2 = new QCheckBox("b2");
    QCheckBox *cb3 = new QCheckBox("b3");

    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(cb1);
    layout->addWidget(cb2);
    layout->addWidget(cb3);
    top->setLayout(layout);

    cb2->hide();
    top->show();
    top->hide();
    top->show();

    return app.exec();
}
