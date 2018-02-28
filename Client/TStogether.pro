#-------------------------------------------------
#
# Project created by QtCreator 2017-06-06T19:33:34
#
#-------------------------------------------------

QT       += core gui sql network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TStogether
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    logindialog.cpp \
    coursewindow.cpp \
    searchdialog.cpp \
    createcourse.cpp \
    chatroom.cpp \
    showuserdialog.cpp \
    utils.cpp \
    studentinfodialog.cpp \
    teacherwindow.cpp \
    teacherinfodialog.cpp \
    student.cpp \
    tcpcomhandler.cpp \
    handler.cpp \
    teacher.cpp \
    course.cpp \
    dept.cpp \
    studentcourse.cpp \
    message.cpp \
    fileprocessdialog.cpp \
    courseware.cpp \
    bubbleltiptoolbutton.cpp \
    informdialog.cpp

HEADERS  += mainwindow.h \
    logindialog.h \
    coursewindow.h \
    searchdialog.h \
    createcourse.h \
    chatroom.h \
    showuserdialog.h \
    utils.h \
    studentinfodialog.h \
    teacherwindow.h \
    teacherinfodialog.h \
    student.h \
    tcpcomhandler.h \
    handler.h \
    teacher.h \
    course.h \
    dept.h \
    studentcourse.h \
    message.h \
    fileprocessdialog.h \
    courseware.h \
    bubbleltiptoolbutton.h \
    informdialog.h

FORMS    += mainwindow.ui \
    logindialog.ui \
    coursewindow.ui \
    searchdialog.ui \
    createcourse.ui \
    chatroom.ui \
    showuserdialog.ui \
    studentinfodialog.ui \
    teacherwindow.ui \
    teacherinfodialog.ui \
    studentcourse.ui \
    fileprocessdialog.ui \
    informdialog.ui

RESOURCES += \
    icons.qrc
