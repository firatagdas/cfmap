CXX_MODULE = cfmap
TARGET  = declarative_cfmap
TARGETPATH = CFMap
IMPORT_VERSION = 1.0

QT += qml quick cfmap cfmap-private webview webview-private

SOURCES += \
    $$PWD/cfmap.cpp

load(qml_plugin)

OTHER_FILES += qmldir
