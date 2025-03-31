QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

HEADERS += ../lesson_5_test/Calculator.h
SOURCES +=  tst_test_calculator.cpp ../lesson_5_test/Calculator.cpp
