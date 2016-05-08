#-------------------------------------------------
#
# Project created by QtCreator 2016-05-03T23:37:46
#
#-------------------------------------------------

QT       += core gui
QT       += xml
QT       += opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Raytracer
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    scene.cpp \
    color.cpp \
    glwindow.cpp \
    vector2.cpp \
    vector3.cpp \
    myxml.cpp \
    object.cpp \
    camera.cpp \
    vector3f.cpp \
    vector2f.cpp \
    sphere.cpp \
    material.cpp \
    image.cpp \
    raytracethread.cpp \
    global.cpp \
    plan.cpp \
    light.cpp

HEADERS  += mainwindow.h \
    scene.h \
    color.h \
    glwindow.h \
    vector2.h \
    vector3.h \
    myxml.h \
    object.h \
    camera.h \
    vector3f.h \
    vector2f.h \
    sphere.h \
    material.h \
    image.h \
    raytracethread.h \
    global.h \
    plan.h \
    light.h

FORMS    += mainwindow.ui
