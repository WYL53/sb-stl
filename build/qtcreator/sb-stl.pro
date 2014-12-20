TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    ../../test.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    ../../sb_algo.h \
    ../../sb_config.h \
    ../../sb_construct.h \
    ../../sb_defalloc.h \
    ../../sb_memory.h \
    ../../sb_types.h

unix:!macx: CCFLAGS += -std=c++11
unix:!macx: QMAKE_CXXFLAGS += -std=c++11
