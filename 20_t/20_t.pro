#-------------------------------------------------
#
# Project created by QtCreator 2020-02-06T16:24:09
#
#-------------------------------------------------

QT       += core gui sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 20_t
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    person.cpp \
    login.cpp \
    form.cpp

HEADERS  += widget.h \
    person.h \
    login.h \
    form.h

FORMS    += widget.ui \
    person.ui \
    login.ui \
    form.ui

RESOURCES += \
    image.qrc
