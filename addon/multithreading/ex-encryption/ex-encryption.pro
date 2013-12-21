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
# place auto-generated files in "invisible" subdirectories

win32 {
    MOC_DIR = _moc
    OBJECTS_DIR = _obj
} else {
    MOC_DIR = .moc
    OBJECTS_DIR = .obj
}
