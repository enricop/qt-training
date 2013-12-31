QT += gui widgets

TEMPLATE = app
TARGET = ex-objectbrowser
INCLUDEPATH += .

# Input
FORMS += gallery.ui \
    objectbrowsertestermainwindow.ui

HEADERS += \
    objectbrowsertestermainwindow.h

SOURCES += \
    objectbrowsertestermainwindow.cpp \
    main.cpp

# add this to your project if you want to use libobjectbrowser:
LIBS += -L../libobjectbrowser -lobjectbrowser
INCLUDEPATH += ../libobjectbrowser
