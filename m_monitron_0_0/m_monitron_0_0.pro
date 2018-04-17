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
    edit_cycles.cpp \
    edit_calibration.cpp \
    edit_lecture.cpp \
    edit_control_op.cpp \
    DBAccess.cpp \
    module.cpp \
    numpad.cpp \
    editline.cpp

HEADERS  += m_monitron_0_0.h \
    edit_cycles.h \
    edit_calibration.h \
    edit_lecture.h \
    edit_control_op.h \
    DBAccess.h \
    communication.h \
    module.h \
    numpad.h \
    editline.h

FORMS    += m_monitron_0_0.ui \
    edit_cycles.ui \
    edit_calibration.ui \
    edit_lecture.ui \
    edit_control_op.ui \
    numpad.ui

QMAKE_CXXFLAGS += -std=c++0x -pthread
#QMAKE_CFLAGS += -std=c++0x -pthread
LIBS += -pthread -lmysqlcppconn
QMAKE_CXX       = g++
