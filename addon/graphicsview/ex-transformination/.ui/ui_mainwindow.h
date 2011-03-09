/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Fri Jan 21 13:36:37 2011
**      by: Qt User Interface Compiler version 4.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDockWidget>
#include <QtGui/QGraphicsView>
#include <QtGui/QHeaderView>
#include <QtGui/QListWidget>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_Add_Transform;
    QAction *action_Quit;
    QAction *actionEdit;
    QAction *actionApply;
    QAction *actionRemove;
    QAction *actionZoom_in;
    QAction *actionZoom_out;
    QAction *actionPlay_All;
    QAction *actionMove_Up;
    QAction *actionMove_Down;
    QAction *actionReverse_Apply;
    QAction *actionCenter_After_Transform;
    QAction *actionReset;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout;
    QGraphicsView *graphicsView;
    QMenuBar *menubar;
    QMenu *menu_File;
    QMenu *menuView;
    QMenu *menuEdit;
    QMenu *menuOptions;
    QStatusBar *statusbar;
    QDockWidget *transformListDock;
    QWidget *dockWidgetContents;
    QVBoxLayout *verticalLayout_2;
    QListWidget *transformListWidget;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(596, 360);
        action_Add_Transform = new QAction(MainWindow);
        action_Add_Transform->setObjectName(QString::fromUtf8("action_Add_Transform"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/list-add.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_Add_Transform->setIcon(icon);
        action_Quit = new QAction(MainWindow);
        action_Quit->setObjectName(QString::fromUtf8("action_Quit"));
        actionEdit = new QAction(MainWindow);
        actionEdit->setObjectName(QString::fromUtf8("actionEdit"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/document-edit.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionEdit->setIcon(icon1);
        actionApply = new QAction(MainWindow);
        actionApply->setObjectName(QString::fromUtf8("actionApply"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/apply.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionApply->setIcon(icon2);
        actionRemove = new QAction(MainWindow);
        actionRemove->setObjectName(QString::fromUtf8("actionRemove"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/list-remove.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionRemove->setIcon(icon3);
        actionZoom_in = new QAction(MainWindow);
        actionZoom_in->setObjectName(QString::fromUtf8("actionZoom_in"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/images/zoom-In-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionZoom_in->setIcon(icon4);
        actionZoom_out = new QAction(MainWindow);
        actionZoom_out->setObjectName(QString::fromUtf8("actionZoom_out"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/images/zoom-out-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionZoom_out->setIcon(icon5);
        actionPlay_All = new QAction(MainWindow);
        actionPlay_All->setObjectName(QString::fromUtf8("actionPlay_All"));
        actionMove_Up = new QAction(MainWindow);
        actionMove_Up->setObjectName(QString::fromUtf8("actionMove_Up"));
        actionMove_Down = new QAction(MainWindow);
        actionMove_Down->setObjectName(QString::fromUtf8("actionMove_Down"));
        actionReverse_Apply = new QAction(MainWindow);
        actionReverse_Apply->setObjectName(QString::fromUtf8("actionReverse_Apply"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/images/undo.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionReverse_Apply->setIcon(icon6);
        actionCenter_After_Transform = new QAction(MainWindow);
        actionCenter_After_Transform->setObjectName(QString::fromUtf8("actionCenter_After_Transform"));
        actionCenter_After_Transform->setCheckable(true);
        actionReset = new QAction(MainWindow);
        actionReset->setObjectName(QString::fromUtf8("actionReset"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/images/original.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actionReset->setIcon(icon7);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout_3 = new QVBoxLayout(centralwidget);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(graphicsView->sizePolicy().hasHeightForWidth());
        graphicsView->setSizePolicy(sizePolicy);
        graphicsView->setMinimumSize(QSize(400, 0));
        graphicsView->setDragMode(QGraphicsView::ScrollHandDrag);
        graphicsView->setTransformationAnchor(QGraphicsView::NoAnchor);

        verticalLayout->addWidget(graphicsView);


        verticalLayout_3->addLayout(verticalLayout);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 596, 21));
        menu_File = new QMenu(menubar);
        menu_File->setObjectName(QString::fromUtf8("menu_File"));
        menuView = new QMenu(menubar);
        menuView->setObjectName(QString::fromUtf8("menuView"));
        menuEdit = new QMenu(menubar);
        menuEdit->setObjectName(QString::fromUtf8("menuEdit"));
        menuOptions = new QMenu(menubar);
        menuOptions->setObjectName(QString::fromUtf8("menuOptions"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);
        transformListDock = new QDockWidget(MainWindow);
        transformListDock->setObjectName(QString::fromUtf8("transformListDock"));
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QString::fromUtf8("dockWidgetContents"));
        verticalLayout_2 = new QVBoxLayout(dockWidgetContents);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        transformListWidget = new QListWidget(dockWidgetContents);
        transformListWidget->setObjectName(QString::fromUtf8("transformListWidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(transformListWidget->sizePolicy().hasHeightForWidth());
        transformListWidget->setSizePolicy(sizePolicy1);
        transformListWidget->setMinimumSize(QSize(120, 0));
        transformListWidget->setContextMenuPolicy(Qt::ActionsContextMenu);

        verticalLayout_2->addWidget(transformListWidget);

        transformListDock->setWidget(dockWidgetContents);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(1), transformListDock);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        menubar->addAction(menu_File->menuAction());
        menubar->addAction(menuEdit->menuAction());
        menubar->addAction(menuView->menuAction());
        menubar->addAction(menuOptions->menuAction());
        menu_File->addAction(actionPlay_All);
        menu_File->addAction(actionReset);
        menu_File->addAction(action_Quit);
        menuView->addAction(actionZoom_in);
        menuView->addAction(actionZoom_out);
        menuEdit->addAction(action_Add_Transform);
        menuEdit->addAction(actionRemove);
        menuEdit->addAction(actionEdit);
        menuEdit->addAction(actionApply);
        menuEdit->addAction(actionReverse_Apply);
        menuEdit->addAction(actionMove_Up);
        menuEdit->addAction(actionMove_Down);
        menuOptions->addAction(actionCenter_After_Transform);
        toolBar->addAction(actionPlay_All);
        toolBar->addAction(actionApply);
        toolBar->addAction(actionReverse_Apply);
        toolBar->addAction(action_Add_Transform);
        toolBar->addAction(actionRemove);
        toolBar->addAction(actionMove_Up);
        toolBar->addAction(actionMove_Down);
        toolBar->addAction(actionZoom_in);
        toolBar->addAction(actionZoom_out);
        toolBar->addAction(actionReset);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Transformination", 0, QApplication::UnicodeUTF8));
        action_Add_Transform->setText(QApplication::translate("MainWindow", "&Add Transform", 0, QApplication::UnicodeUTF8));
        action_Add_Transform->setShortcut(QApplication::translate("MainWindow", "Ctrl+N", 0, QApplication::UnicodeUTF8));
        action_Quit->setText(QApplication::translate("MainWindow", "&Quit", 0, QApplication::UnicodeUTF8));
        action_Quit->setShortcut(QApplication::translate("MainWindow", "Ctrl+Q", 0, QApplication::UnicodeUTF8));
        actionEdit->setText(QApplication::translate("MainWindow", "Edit", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionEdit->setToolTip(QApplication::translate("MainWindow", "Edit", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionEdit->setShortcut(QApplication::translate("MainWindow", "Ctrl+E", 0, QApplication::UnicodeUTF8));
        actionApply->setText(QApplication::translate("MainWindow", "Apply", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionApply->setToolTip(QApplication::translate("MainWindow", "Apply to \"after\" widget immediately", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionApply->setShortcut(QApplication::translate("MainWindow", "Ctrl+A", 0, QApplication::UnicodeUTF8));
        actionRemove->setText(QApplication::translate("MainWindow", "Remove", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionRemove->setToolTip(QApplication::translate("MainWindow", "Remove", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionRemove->setShortcut(QApplication::translate("MainWindow", "Del", 0, QApplication::UnicodeUTF8));
        actionZoom_in->setText(QApplication::translate("MainWindow", "Zoom in", 0, QApplication::UnicodeUTF8));
        actionZoom_in->setShortcut(QApplication::translate("MainWindow", "Ctrl++", 0, QApplication::UnicodeUTF8));
        actionZoom_out->setText(QApplication::translate("MainWindow", "Zoom out", 0, QApplication::UnicodeUTF8));
        actionZoom_out->setShortcut(QApplication::translate("MainWindow", "Ctrl+-", 0, QApplication::UnicodeUTF8));
        actionPlay_All->setText(QApplication::translate("MainWindow", "Play All", 0, QApplication::UnicodeUTF8));
        actionMove_Up->setText(QApplication::translate("MainWindow", "Move Up", 0, QApplication::UnicodeUTF8));
        actionMove_Down->setText(QApplication::translate("MainWindow", "Move Down", 0, QApplication::UnicodeUTF8));
        actionReverse_Apply->setText(QApplication::translate("MainWindow", "Reverse Apply", 0, QApplication::UnicodeUTF8));
        actionReverse_Apply->setShortcut(QApplication::translate("MainWindow", "Ctrl+Z", 0, QApplication::UnicodeUTF8));
        actionCenter_After_Transform->setText(QApplication::translate("MainWindow", "Center After Transform", 0, QApplication::UnicodeUTF8));
        actionReset->setText(QApplication::translate("MainWindow", "Reset to Original", 0, QApplication::UnicodeUTF8));
        actionReset->setShortcut(QApplication::translate("MainWindow", "F5", 0, QApplication::UnicodeUTF8));
        menu_File->setTitle(QApplication::translate("MainWindow", "&File", 0, QApplication::UnicodeUTF8));
        menuView->setTitle(QApplication::translate("MainWindow", "View", 0, QApplication::UnicodeUTF8));
        menuEdit->setTitle(QApplication::translate("MainWindow", "Items", 0, QApplication::UnicodeUTF8));
        menuOptions->setTitle(QApplication::translate("MainWindow", "Options", 0, QApplication::UnicodeUTF8));
        transformListDock->setWindowTitle(QApplication::translate("MainWindow", "TransformList", 0, QApplication::UnicodeUTF8));
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
