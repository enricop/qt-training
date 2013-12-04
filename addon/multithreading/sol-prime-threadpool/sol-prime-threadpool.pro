
TEMPLATE = app

# Input
SOURCES += main.cpp \
    primefinderdialog.cpp \
    isprime.cpp \
    primefinder.cpp
QT += gui widgets

FORMS += \
    primefinderdialog.ui

HEADERS += \
    primefinderdialog.h \
    isprime.h \
    primefinder.h

OTHER_FILES += \
    README.txt
