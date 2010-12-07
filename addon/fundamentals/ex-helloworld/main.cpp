/*
 * main.cpp -- main module
 *
 * Copyright (c) 2008-2011, Nokia Corporation and/or its subsidiary(-ies).
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *
 * This example shows the "Hello, world" in Qt.
 */

#include <QtGui>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QPushButton button("Hello world");
    button.show();
    return app.exec();
}
