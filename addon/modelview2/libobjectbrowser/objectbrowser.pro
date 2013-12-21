TEMPLATE = lib
TARGET=objectbrowser

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

# Input
FORMS += qobjectbrowser.ui

HEADERS += qobjectbrowser.h qobjecttree.h obexport.h qobjectbrowseraction.h
SOURCES += qobjectbrowser.cpp qobjecttree.cpp qobjectbrowseraction.cpp

RESOURCES += objectbrowser.qrc
win32 {
    CONFIG += dll
    DEFINES += OBJECTBROWSER_DLL
}

OTHER_FILES += README.txt
