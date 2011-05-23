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
    QWidget window;
    window.setWindowTitle("Layout Buttons");
    QVBoxLayout *windowLayout = new QVBoxLayout(&window);

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
        layout->addWidget(one, 2);
        layout->addWidget(two, 1);
        layout->addWidget(three, 1);
        windowLayout->addLayout(layout);
    }

    // Exercise 2: Find this stretch
    {
        QPushButton *one = new QPushButton("One");
        QPushButton *two = new QPushButton("Two");
        QPushButton *three = new QPushButton("Three");

        QHBoxLayout *layout = new QHBoxLayout;
        layout->addWidget(one, 1);
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
        layout->addStretch(1);
        windowLayout->addLayout(layout);
    }

    // Exercise 4: Stretch the middle
    {
        QPushButton *one = new QPushButton("One");
        QPushButton *two = new QPushButton("Two");
        QPushButton *three = new QPushButton("Three");

        QHBoxLayout *layout = new QHBoxLayout;
        layout->addWidget(one);
        layout->addStretch(1);
        layout->addWidget(two);
        layout->addStretch(1);
        layout->addWidget(three);
        windowLayout->addLayout(layout);
    }

    // This is how you would make the buttons take up the available space
    // vertically: by changing their size policy.
    QList<QPushButton *> buttons = window.findChildren<QPushButton *>();
    foreach (QPushButton *button, buttons) {
        // preserve horizontal policy
        QSizePolicy::Policy horizPolicy = button->sizePolicy().horizontalPolicy();
        // set vertical policy to MinimumExpanding
        button->setSizePolicy( QSizePolicy( horizPolicy, QSizePolicy::MinimumExpanding ) );
    }
    window.resize(640,480);
    window.show();

    return app.exec();
}
