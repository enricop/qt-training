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

LIBS += -L../libobjectbrowser -lobjectbrowser
INCLUDEPATH += ../libobjectbrowser
