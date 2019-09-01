#-------------------------------------------------
#
# Project created by QtCreator 2019-03-02T01:25:26
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QtMinimalApp
TEMPLATE = app
CONFIG += C++14
CONFIG += precompile_header

# Use Precompiled headers (PCH)
PRECOMPILED_HEADER  = stdafx.h

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
    Interface/CentralWidgetHandler.cpp \
    Qt/MainWindow.cpp \
    ApplicationGlobals.cpp \
    ApplicationInterface.cpp \
    ApplicationLocals.cpp \
    ApplicationImplementation.cpp \
    Application.cpp \
    ExceptionHandler.cpp \
    cx11keyloggerworker.cpp \
    cx11keylogger.cpp \
    main.cpp


HEADERS += \
    Interface/CentralWidgetHandler.h \
    Qt/MainWindow.h \
    ApplicationGlobals.h \
    ApplicationInterface.h \
    ApplicationLocals.h \
    ApplicationImplementation.h \
    Application.h \
    ExceptionHandler.h \
    cx11keyloggerworker.h \
    cx11keylogger.h \
    stdafx.h

FORMS += \
        CMainWindow.ui

LIBS += -lX11 \
        -lXi
