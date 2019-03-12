#-------------------------------------------------
#
# Project created by QtCreator 2019-03-12T14:28:08
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Mandala
TEMPLATE = app

INCLUDEPATH = ./header

SOURCES += main.cpp\
    ui/mainwindow.cpp \
    src/lib/images/Image.cpp \
    src/lib/images/Form.cpp

HEADERS  +=  ui/mainwindow.h \
    header/lib/command/command.h \
    header/lib/images/Image.h \
    header/lib/images/Form.h

FORMS    += \
    ui/mainwindow.ui
