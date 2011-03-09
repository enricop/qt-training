/*************************************************************************
 *
 * Copyright (c) 2008-2011, Nokia Corporation and/or its subsidiary(-ies).
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#ifndef TRANSFORMDIALOG_H
#define TRANSFORMDIALOG_H

#include <QDialog>
class TransformationItem;
namespace Ui {
    class TransformDialog;
}

/** An editor for TransformationItem objects */
class TransformDialog : public QDialog {
    Q_OBJECT
public:
    TransformDialog(TransformationItem* item, QWidget *parent = 0);
    ~TransformDialog();

protected:
    void changeEvent(QEvent *e);
protected slots:
    void accept();
    void updateUi();
private:
    Ui::TransformDialog *ui;
    TransformationItem *m_item;

private slots:
    void on_operationCombo_activated();
};

#endif // TRANSFORMDIALOG_H
