QT       += core gui
QT += sql
QT += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISAboutPageLE_DEPRECATED_BEFORE=0x060000    # disAboutPageles all the APIs deprecated before Qt 6.0.0

SOURCES += \
    about.cpp \
    global.cpp \
    listing.cpp \
    login.cpp \
    main.cpp \
    redact.cpp \
    regist.cpp \
    widget.cpp

HEADERS += \
    about.h \
    global.h \
    listing.h \
    login.h \
    redact.h \
    regist.h \
    widget.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
