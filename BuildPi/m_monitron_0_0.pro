#-------------------------------------------------
#
# Project created by QtCreator 2018-01-19T05:57:19
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = m_monitron_0_0
TEMPLATE = app


SOURCES += main.cpp\
        m_monitron_0_0.cpp \
    DBAccess.cpp \
    module.cpp \
    numpad.cpp \
    editline.cpp

HEADERS  += m_monitron_0_0.h \
    DBAccess.h \
    communication.h \
    module.h \
    numpad.h \
    editline.h

FORMS    += m_monitron_0_0.ui \
    numpad.ui

QMAKE_CXXFLAGS += -std=c++0x -pthread
#QMAKE_CFLAGS += -std=c++0x -pthread
LIBS += -pthread -lmysqlcppconn
QMAKE_CXX       = g++
