#-------------------------------------------------
#
# Project created by QtCreator 2016-03-30T21:40:46
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = JuegoDracula
TEMPLATE = app


SOURCES += main.cpp\
        juego.cpp \
        jugador.cpp \
    campodejuego.cpp

HEADERS  += juego.h \
    carta.h \
    mazo.h \
    arraylist.h \
    jugador.h \
    campodejuego.h


FORMS    += juego.ui

RESOURCES += \
    images.qrc
