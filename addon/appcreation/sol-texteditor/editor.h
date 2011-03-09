/*************************************************************************
 *
 * Copyright (c) 2008-2011, Nokia Corporation and/or its subsidiary(-ies).
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#ifndef EDITOR_H
#define EDITOR_H

#include <QMainWindow>
#include <QTextEdit>

class QAction;
class QLabel;

class Editor : public QMainWindow
{
    Q_OBJECT

public:
    Editor(QWidget *parent = 0);

protected slots:
    void slotFileOpen();
    void slotFileSave();
    void slotFilePrint();
    void slotQuit();

    void slotAbout();
    void slotAboutQt();

    void slotTextChanged();

protected:
    void closeEvent(QCloseEvent *);

private:
    QAction   *m_fileSave;
    QAction   *m_filePrint;
    QTextEdit *m_edit;
    QLabel    *m_fileLabel;

    QString    m_fileName;
};

#endif // EDITOR_H
