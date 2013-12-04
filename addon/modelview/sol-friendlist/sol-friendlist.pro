TEMPLATE = app
DEPENDPATH += .
INCLUDEPATH += .
QT += widgets gui 
# Input
HEADERS += friendslists.h \
    friendslistmodel.h \
    contactproxymodel.h
SOURCES += friendslists.cpp \
    friendslistmodel.cpp \
    main.cpp \
    contactproxymodel.cpp

FORMS += friendslists.ui
