QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

HEADERS += ../untitled/computer.h
SOURCES += tst_computer_test.cpp ../untitled/computer.cpp
