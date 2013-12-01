QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ex-encryption
TEMPLATE = app


SOURCES += main.cpp\
    window.cpp \
    encrypter.cpp \
    encryption/blowfish.cpp  

HEADERS  += window.h \
    encrypter.h \
    encryption/blowfish.h
