#-------------------------------------------------
#
# Project created by QtCreator 2016-06-20T18:22:57
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = chat_client
TEMPLATE = app

QT += network

ICON = CHATICON.icns

SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui

DISTFILES += \
    CHATICON.icns
