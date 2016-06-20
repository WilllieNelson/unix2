#-------------------------------------------------
#
# Project created by QtCreator 2016-06-20T15:28:11
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = chatterboxs
TEMPLATE = app

QT += network

CONFIG += console

SOURCES += main.cpp\
        chatterboxserver.cpp

HEADERS  += chatterboxserver.h

FORMS    += chatterboxserver.ui
