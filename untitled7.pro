#-------------------------------------------------
#
# Project created by QtCreator 2016-07-08T00:01:14
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = untitled7
TEMPLATE = app

SOURCES += main.cpp\
        mainwindow.cpp \
        httphelper.cpp

HEADERS  += mainwindow.h \
    httphelper.h \
    thread.h

FORMS    += mainwindow.ui
