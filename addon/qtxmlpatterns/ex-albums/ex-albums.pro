SOURCES += main.cpp
TEMPLATE = app
CONFIG += warn_on \
	  thread \
          qt \
TARGET = albums

QT -= gui
QT += xmlpatterns
QT += xml

