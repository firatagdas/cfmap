CONFIG += testcase parallel_test
TARGET = tst_cfmap
osx:CONFIG -= app_bundle


QT += cfmap cfmap-private testlib
SOURCES += \
    tst_cfmap.cpp
