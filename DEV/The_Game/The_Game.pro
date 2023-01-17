TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        GameUtils.cpp \
        functions.cpp \
        tests.cpp \
        main.cpp

HEADERS += \
        typeDef.h \
        functions.h \
        tests.h \
        GameUtils.h
