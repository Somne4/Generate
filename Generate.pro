TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        ClassUnit.cpp \
        MethodUnit.cpp \
        PrintOperatorUnit.cpp \
        Unit.cpp \
        cgen.cpp \
        cppunit.cpp \
        cshgen.cpp \
        cshunit.cpp \
        generate.cpp \
        javagen.cpp \
        javaunit.cpp \
        main.cpp

HEADERS += \
    ClassUnit.h \
    GenInterface.h \
    MethodUnit.h \
    MyClass.h \
    PrintOperatorUnit.h \
    Unit.h \
    cgen.h \
    cppunit.h \
    cshgen.h \
    cshunit.h \
    generate.h \
    javagen.h \
    javaunit.h \
    unit.h

DISTFILES +=
