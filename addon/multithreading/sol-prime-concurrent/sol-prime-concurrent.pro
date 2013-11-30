
TEMPLATE = app

# Input
SOURCES += main.cpp \
    primefinderdialog.cpp \
    isprime.cpp
QT += gui widgets concurrent

FORMS += \
    primefinderdialog.ui

HEADERS += \
    primefinderdialog.h \
    isprime.h
