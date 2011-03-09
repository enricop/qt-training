/********************************************************************************
** Form generated from reading UI file 'transformdialog.ui'
**
** Created: Fri Jan 21 13:36:37 2011
**      by: Qt User Interface Compiler version 4.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRANSFORMDIALOG_H
#define UI_TRANSFORMDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QFormLayout>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_TransformDialog
{
public:
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QComboBox *operationCombo;
    QGroupBox *xyArgumentGroup;
    QFormLayout *formLayout;
    QLabel *label_3;
    QDoubleSpinBox *horizontalSpinbox;
    QLabel *label_4;
    QDoubleSpinBox *verticalSpinbox;
    QGroupBox *rotateGroup;
    QFormLayout *formLayout_2;
    QLabel *label_2;
    QDoubleSpinBox *angleSpinBox;
    QLabel *label_5;
    QComboBox *axisCombo;
    QGroupBox *matrixGroup;
    QGridLayout *gridLayout;
    QDoubleSpinBox *m11;
    QDoubleSpinBox *m13;
    QDoubleSpinBox *m21;
    QDoubleSpinBox *m22;
    QDoubleSpinBox *m23;
    QDoubleSpinBox *m31;
    QDoubleSpinBox *m32;
    QDoubleSpinBox *m33;
    QDoubleSpinBox *m12;
    QVBoxLayout *verticalLayout_2;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *TransformDialog)
    {
        if (TransformDialog->objectName().isEmpty())
            TransformDialog->setObjectName(QString::fromUtf8("TransformDialog"));
        TransformDialog->resize(332, 389);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(TransformDialog->sizePolicy().hasHeightForWidth());
        TransformDialog->setSizePolicy(sizePolicy);
        horizontalLayout_2 = new QHBoxLayout(TransformDialog);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetMinimumSize);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(TransformDialog);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        operationCombo = new QComboBox(TransformDialog);
        operationCombo->setObjectName(QString::fromUtf8("operationCombo"));

        horizontalLayout->addWidget(operationCombo);


        verticalLayout->addLayout(horizontalLayout);

        xyArgumentGroup = new QGroupBox(TransformDialog);
        xyArgumentGroup->setObjectName(QString::fromUtf8("xyArgumentGroup"));
        formLayout = new QFormLayout(xyArgumentGroup);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label_3 = new QLabel(xyArgumentGroup);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_3);

        horizontalSpinbox = new QDoubleSpinBox(xyArgumentGroup);
        horizontalSpinbox->setObjectName(QString::fromUtf8("horizontalSpinbox"));
        horizontalSpinbox->setMinimum(-100);
        horizontalSpinbox->setMaximum(100);
        horizontalSpinbox->setSingleStep(5);

        formLayout->setWidget(0, QFormLayout::FieldRole, horizontalSpinbox);

        label_4 = new QLabel(xyArgumentGroup);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_4);

        verticalSpinbox = new QDoubleSpinBox(xyArgumentGroup);
        verticalSpinbox->setObjectName(QString::fromUtf8("verticalSpinbox"));
        verticalSpinbox->setMinimum(-100);

        formLayout->setWidget(1, QFormLayout::FieldRole, verticalSpinbox);


        verticalLayout->addWidget(xyArgumentGroup);

        rotateGroup = new QGroupBox(TransformDialog);
        rotateGroup->setObjectName(QString::fromUtf8("rotateGroup"));
        formLayout_2 = new QFormLayout(rotateGroup);
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        label_2 = new QLabel(rotateGroup);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label_2);

        angleSpinBox = new QDoubleSpinBox(rotateGroup);
        angleSpinBox->setObjectName(QString::fromUtf8("angleSpinBox"));
        angleSpinBox->setMinimum(-360);
        angleSpinBox->setMaximum(360);
        angleSpinBox->setSingleStep(10);

        formLayout_2->setWidget(0, QFormLayout::FieldRole, angleSpinBox);

        label_5 = new QLabel(rotateGroup);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, label_5);

        axisCombo = new QComboBox(rotateGroup);
        axisCombo->setObjectName(QString::fromUtf8("axisCombo"));

        formLayout_2->setWidget(1, QFormLayout::FieldRole, axisCombo);


        verticalLayout->addWidget(rotateGroup);

        matrixGroup = new QGroupBox(TransformDialog);
        matrixGroup->setObjectName(QString::fromUtf8("matrixGroup"));
        gridLayout = new QGridLayout(matrixGroup);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setSizeConstraint(QLayout::SetMinimumSize);
        gridLayout->setVerticalSpacing(2);
        m11 = new QDoubleSpinBox(matrixGroup);
        m11->setObjectName(QString::fromUtf8("m11"));

        gridLayout->addWidget(m11, 0, 0, 1, 1);

        m13 = new QDoubleSpinBox(matrixGroup);
        m13->setObjectName(QString::fromUtf8("m13"));

        gridLayout->addWidget(m13, 0, 2, 1, 1);

        m21 = new QDoubleSpinBox(matrixGroup);
        m21->setObjectName(QString::fromUtf8("m21"));

        gridLayout->addWidget(m21, 1, 0, 1, 1);

        m22 = new QDoubleSpinBox(matrixGroup);
        m22->setObjectName(QString::fromUtf8("m22"));

        gridLayout->addWidget(m22, 1, 1, 1, 1);

        m23 = new QDoubleSpinBox(matrixGroup);
        m23->setObjectName(QString::fromUtf8("m23"));

        gridLayout->addWidget(m23, 1, 2, 1, 1);

        m31 = new QDoubleSpinBox(matrixGroup);
        m31->setObjectName(QString::fromUtf8("m31"));

        gridLayout->addWidget(m31, 2, 0, 1, 1);

        m32 = new QDoubleSpinBox(matrixGroup);
        m32->setObjectName(QString::fromUtf8("m32"));

        gridLayout->addWidget(m32, 2, 1, 1, 1);

        m33 = new QDoubleSpinBox(matrixGroup);
        m33->setObjectName(QString::fromUtf8("m33"));

        gridLayout->addWidget(m33, 2, 2, 1, 1);

        m12 = new QDoubleSpinBox(matrixGroup);
        m12->setObjectName(QString::fromUtf8("m12"));

        gridLayout->addWidget(m12, 0, 1, 1, 1);


        verticalLayout->addWidget(matrixGroup);


        horizontalLayout_2->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        buttonBox = new QDialogButtonBox(TransformDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Vertical);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout_2->addWidget(buttonBox);


        horizontalLayout_2->addLayout(verticalLayout_2);


        retranslateUi(TransformDialog);
        QObject::connect(buttonBox, SIGNAL(rejected()), TransformDialog, SLOT(reject()));
        QObject::connect(buttonBox, SIGNAL(accepted()), TransformDialog, SLOT(accept()));

        axisCombo->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(TransformDialog);
    } // setupUi

    void retranslateUi(QDialog *TransformDialog)
    {
        TransformDialog->setWindowTitle(QApplication::translate("TransformDialog", "Transform Operation", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("TransformDialog", "Operation", 0, QApplication::UnicodeUTF8));
        xyArgumentGroup->setTitle(QApplication::translate("TransformDialog", "Transform Arguments", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("TransformDialog", "Horizontal", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("TransformDialog", "Vertical", 0, QApplication::UnicodeUTF8));
        rotateGroup->setTitle(QApplication::translate("TransformDialog", "Rotate Params", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("TransformDialog", "Angle", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        angleSpinBox->setToolTip(QApplication::translate("TransformDialog", "angle (degrees)", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        label_5->setText(QApplication::translate("TransformDialog", "Axis", 0, QApplication::UnicodeUTF8));
        axisCombo->clear();
        axisCombo->insertItems(0, QStringList()
         << QApplication::translate("TransformDialog", "x", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("TransformDialog", "y", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("TransformDialog", "z", 0, QApplication::UnicodeUTF8)
        );
#ifndef QT_NO_TOOLTIP
        axisCombo->setToolTip(QApplication::translate("TransformDialog", "axis", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        matrixGroup->setTitle(QApplication::translate("TransformDialog", "Matrix", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        m11->setToolTip(QApplication::translate("TransformDialog", "m11", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        m13->setToolTip(QApplication::translate("TransformDialog", "m13", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        m21->setToolTip(QApplication::translate("TransformDialog", "m21", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        m22->setToolTip(QApplication::translate("TransformDialog", "m22", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        m23->setToolTip(QApplication::translate("TransformDialog", "m23", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        m31->setToolTip(QApplication::translate("TransformDialog", "m31", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        m32->setToolTip(QApplication::translate("TransformDialog", "m32", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        m33->setToolTip(QApplication::translate("TransformDialog", "m33", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        m12->setToolTip(QApplication::translate("TransformDialog", "m12", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
    } // retranslateUi

};

namespace Ui {
    class TransformDialog: public Ui_TransformDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRANSFORMDIALOG_H
