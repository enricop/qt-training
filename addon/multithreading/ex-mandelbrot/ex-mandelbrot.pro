QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ex-mandelbrot
TEMPLATE = app


SOURCES += main.cpp\
    mandelbrot.cpp \
    renderer.cpp

HEADERS  += mandelbrot.h \
    renderer.h
