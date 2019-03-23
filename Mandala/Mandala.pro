#-------------------------------------------------
#
# Project created by QtCreator 2019-03-12T14:28:08
#
#-------------------------------------------------

QT       += core gui printsupport

greaterThan(QT_MAJOR_VERSION, 5): QT += widgets

CONFIG += c++11;

QMAKE_CXXFLAGS += -std=c++0x

TARGET = Mandala
TEMPLATE = app

INCLUDEPATH += ./header \
        ./header/ui

SOURCES += src/main.cpp\
    src/lib/images/Image.cpp \
    src/lib/images/DrawerUtility.cpp \
    src/lib/images/forms/Form.cpp \
    src/lib/images/forms/FormSet.cpp \
    src/lib/images/forms/LineForm.cpp \
    src/lib/images/forms/PixelForm.cpp \
    src/ui/MainWindow.cpp \
    src/ui/MandalaPainter.cpp

HEADERS  +=  header/ui/MainWindow.h \
    header/lib/command/command.h \
    header/lib/images/Image.h \
    header/lib/images/DrawerUtility.h \
    header/lib/images/forms/Form.h \
    header/lib/images/forms/FormSet.h \
    header/lib/images/forms/LineForm.h \
    header/lib/images/forms/PixelForm.h \
    header/ui/MandalaPainter.h

FORMS    += \
    src/ui/MainWindow.ui

RESOURCES += \
    src/ui/icons.qrc
