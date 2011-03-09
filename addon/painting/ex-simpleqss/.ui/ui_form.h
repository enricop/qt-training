/********************************************************************************
** Form generated from reading UI file 'form.ui'
**
** Created: Fri Jan 21 13:42:56 2011
**      by: Qt User Interface Compiler version 4.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORM_H
#define UI_FORM_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QVBoxLayout *vboxLayout;
    QGridLayout *gridLayout;
    QLineEdit *age;
    QLabel *label;
    QComboBox *style;
    QLabel *label_2;
    QLineEdit *name;
    QLabel *label_3;
    QHBoxLayout *hboxLayout;
    QSpacerItem *spacerItem;
    QPushButton *pushButton;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QString::fromUtf8("Form"));
        Form->resize(283, 133);
        vboxLayout = new QVBoxLayout(Form);
        vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        age = new QLineEdit(Form);
        age->setObjectName(QString::fromUtf8("age"));

        gridLayout->addWidget(age, 2, 1, 1, 2);

        label = new QLabel(Form);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 2);

        style = new QComboBox(Form);
        style->setObjectName(QString::fromUtf8("style"));

        gridLayout->addWidget(style, 0, 2, 1, 1);

        label_2 = new QLabel(Form);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        name = new QLineEdit(Form);
        name->setObjectName(QString::fromUtf8("name"));

        gridLayout->addWidget(name, 1, 1, 1, 2);

        label_3 = new QLabel(Form);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);


        vboxLayout->addLayout(gridLayout);

        hboxLayout = new QHBoxLayout();
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        spacerItem = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout->addItem(spacerItem);

        pushButton = new QPushButton(Form);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        hboxLayout->addWidget(pushButton);


        vboxLayout->addLayout(hboxLayout);


        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QApplication::translate("Form", "Form", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Form", "Choose Qt Style", 0, QApplication::UnicodeUTF8));
        style->clear();
        style->insertItems(0, QStringList()
         << QApplication::translate("Form", "Windows", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Form", "Motif", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Form", "Plastique", 0, QApplication::UnicodeUTF8)
        );
        label_2->setText(QApplication::translate("Form", "Name", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("Form", "Age", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("Form", "OK", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM_H
