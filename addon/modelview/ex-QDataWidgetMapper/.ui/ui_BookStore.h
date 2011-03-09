/********************************************************************************
** Form generated from reading UI file 'BookStore.ui'
**
** Created: Fri Jan 21 13:37:55 2011
**      by: Qt User Interface Compiler version 4.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BOOKSTORE_H
#define UI_BOOKSTORE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFormLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QToolButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BookStore
{
public:
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLineEdit *title;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *author;
    QLineEdit *price;
    QHBoxLayout *horizontalLayout;
    QToolButton *first;
    QToolButton *previous;
    QToolButton *next;
    QToolButton *last;

    void setupUi(QWidget *BookStore)
    {
        if (BookStore->objectName().isEmpty())
            BookStore->setObjectName(QString::fromUtf8("BookStore"));
        BookStore->resize(526, 136);
        verticalLayout = new QVBoxLayout(BookStore);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        title = new QLineEdit(BookStore);
        title->setObjectName(QString::fromUtf8("title"));

        formLayout->setWidget(0, QFormLayout::FieldRole, title);

        label = new QLabel(BookStore);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        label_2 = new QLabel(BookStore);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        label_3 = new QLabel(BookStore);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        author = new QLineEdit(BookStore);
        author->setObjectName(QString::fromUtf8("author"));

        formLayout->setWidget(1, QFormLayout::FieldRole, author);

        price = new QLineEdit(BookStore);
        price->setObjectName(QString::fromUtf8("price"));

        formLayout->setWidget(2, QFormLayout::FieldRole, price);


        verticalLayout->addLayout(formLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        first = new QToolButton(BookStore);
        first->setObjectName(QString::fromUtf8("first"));

        horizontalLayout->addWidget(first);

        previous = new QToolButton(BookStore);
        previous->setObjectName(QString::fromUtf8("previous"));

        horizontalLayout->addWidget(previous);

        next = new QToolButton(BookStore);
        next->setObjectName(QString::fromUtf8("next"));

        horizontalLayout->addWidget(next);

        last = new QToolButton(BookStore);
        last->setObjectName(QString::fromUtf8("last"));

        horizontalLayout->addWidget(last);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(BookStore);

        QMetaObject::connectSlotsByName(BookStore);
    } // setupUi

    void retranslateUi(QWidget *BookStore)
    {
        BookStore->setWindowTitle(QApplication::translate("BookStore", "Form", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("BookStore", "Title", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("BookStore", "Author", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("BookStore", "Price", 0, QApplication::UnicodeUTF8));
        first->setText(QApplication::translate("BookStore", "|<", 0, QApplication::UnicodeUTF8));
        previous->setText(QApplication::translate("BookStore", "<", 0, QApplication::UnicodeUTF8));
        next->setText(QApplication::translate("BookStore", ">", 0, QApplication::UnicodeUTF8));
        last->setText(QApplication::translate("BookStore", ">|", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class BookStore: public Ui_BookStore {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BOOKSTORE_H
