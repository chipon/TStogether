#-------------------------------------------------
#
# Project created by QtCreator 2017-06-12T14:47:07
#
#-------------------------------------------------

QT       += core gui sql network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TStogetherServer
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    tcpcomhandler.cpp \
    database.cpp \
    admin.cpp \
    logindialog.cpp \
    utils.cpp \
    student.cpp \
    teacher.cpp \
    course.cpp \
    dept.cpp \
    message.cpp \
    courseware.cpp

HEADERS  += \
    tcpcomhandler.h \
    mainwindow.h \
    database.h \
    admin.h \
    logindialog.h \
    utils.h \
    student.h \
    teacher.h \
    course.h \
    dept.h \
    message.h \
    courseware.h

FORMS    += mainwindow.ui \
    admin.ui \
    logindialog.ui

RESOURCES +=
