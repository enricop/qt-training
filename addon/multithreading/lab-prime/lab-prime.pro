
TEMPLATE = app
TARGET = lab-prime

# Input
SOURCES += nothreads.cpp \
    primefinderdialog.cpp \
    isprime.cpp
QT += gui widgets

FORMS += \
    primefinderdialog.ui

HEADERS += \
    primefinderdialog.h \
    isprime.h

OTHER_FILES += \
    README.txt
