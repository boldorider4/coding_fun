TEMPLATE = app
TARGET = qt_tutorial

QT = core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

SOURCES += \
    main.cpp \
    window.cpp \
    examples.cpp

HEADERS += \
    window.h \
    examples.h
