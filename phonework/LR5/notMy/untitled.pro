TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle

greaterThan(QT_MAJOR_VERSION, 4) {
  QT += widgets
  DEFINES += HAVE_QT5
}

SOURCES += \
        doublelinkedlist.cpp \
        main.cpp \
        mainwidget.cpp \
        patient.cpp

FORMS += \
    mainwidget.ui

HEADERS += \
    doublelinkedlist.h \
    mainwidget.h \
    patient.h

DISTFILES += \
    data.txt
