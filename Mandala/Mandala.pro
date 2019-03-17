#-------------------------------------------------
#
# Project created by QtCreator 2019-03-12T14:28:08
#
#-------------------------------------------------

QT       += core gui printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Mandala
TEMPLATE = app

INCLUDEPATH = ./header

SOURCES += src/main.cpp\
    src/ui/mainwindow.cpp \
    src/lib/images/Image.cpp \
    src/lib/images/Form.cpp \
    src/ui/MandalaPainter.cpp

HEADERS  +=  header/ui/mainwindow.h \
    header/lib/command/command.h \
    header/lib/images/Image.h \
    header/lib/images/Form.h \
    header/ui/MandalaPainter.h

FORMS    += \
    src/ui/mainwindow.ui
