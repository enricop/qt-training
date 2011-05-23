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
    QWidget *window = new QWidget;
    window->setWindowTitle("Layout Buttons");
    QVBoxLayout *windowLayout = new QVBoxLayout(window);

    // Starting Point
    {
        QPushButton *one = new QPushButton("One");
        QPushButton *two = new QPushButton("Two");
        QPushButton *three = new QPushButton("Three");

        QHBoxLayout *layout = new QHBoxLayout;
        layout->addWidget(one);
        layout->addWidget(two);
        layout->addWidget(three);
        windowLayout->addLayout(layout);
    }


    // Exercise 1: Stretch 2-1-1
    {
        QPushButton *one = new QPushButton("One");
        QPushButton *two = new QPushButton("Two");
        QPushButton *three = new QPushButton("Three");

        QHBoxLayout *layout = new QHBoxLayout;
        layout->addWidget(one);
        layout->addWidget(two);
        layout->addWidget(three);
        windowLayout->addLayout(layout);
    }

    // Exercise 2: Find this stretch
    {
        QPushButton *one = new QPushButton("One");
        QPushButton *two = new QPushButton("Two");
        QPushButton *three = new QPushButton("Three");

        

        QHBoxLayout *layout = new QHBoxLayout;
        layout->addWidget(one);
        layout->addWidget(two);
        layout->addWidget(three);
        windowLayout->addLayout(layout);
    }

    // Exercise 3: Stretch at the end
    {
        QPushButton *one = new QPushButton("One");
        QPushButton *two = new QPushButton("Two");
        QPushButton *three = new QPushButton("Three");

        QHBoxLayout *layout = new QHBoxLayout;
        layout->addWidget(one);
        layout->addWidget(two);
        layout->addWidget(three);
        windowLayout->addLayout(layout);
    }

    // Exercise 4: Stretch the middle
    {
        QPushButton *one = new QPushButton("One");
        QPushButton *two = new QPushButton("Two");
        QPushButton *three = new QPushButton("Three");

        
        QHBoxLayout *layout = new QHBoxLayout;
        layout->addWidget(one);
        layout->addWidget(two);
        layout->addWidget(three);
        windowLayout->addLayout(layout);
        
    }

    // Exercise 5: Make all buttons vertical expanding
    // Hint use findChildren
    window->resize(640, 480);
    window->show();

    return app.exec();
}
