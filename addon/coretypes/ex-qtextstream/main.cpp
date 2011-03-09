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

    QFile file("myfile.txt");

    // Let's read it if it exists
    if (file.open(QIODevice::ReadOnly))
    {
        QTextStream stream(&file);
        QString str;
        stream >> str; // Reads _one_ word
        int number;
        stream >> number;
        qDebug() << str << "--" << number;
    }
    // Otherwise let's create the file
    else if (file.open(QIODevice::WriteOnly))
    {
        QTextStream stream(&file);
        stream << "HelloWorld ";
        stream << 4711;
        stream << "\n";
        qDebug("File written.");
    }

    file.close();

    return 0;
}
