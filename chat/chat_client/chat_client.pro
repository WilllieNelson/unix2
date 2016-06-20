#-------------------------------------------------
#
# Project created by QtCreator 2016-06-19T22:04:37
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = chat_client
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    chat_client.cpp

HEADERS  += mainwindow.h \
    chat_client.h

FORMS    += mainwindow.ui \
    client.ui \
    chat_client.ui
