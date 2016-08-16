QT          +=  core sql declarative
QT          += printsupport

SOURCES += \
    main.cpp \
    report/reporter.cpp \
    cmn/crc16.cpp \
    cmn/num_oper.cpp \
    cmn/rcpcomponent.cpp \
    cmn/str_oper.cpp \
    cmn/taskelement.cpp \
    view/simpleview.cpp

HEADERS += \
    report/reporter.hpp \
    cmn/crc16.h \
    cmn/num_oper.h \
    cmn/rcpcomponent.hpp \
    cmn/str_oper.h \
    cmn/taskelement.hpp \
    view/simpleview.hpp
