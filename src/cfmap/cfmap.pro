include($$PWD/cfmap-lib.pri)

load(qt_build_config)

TARGET = CFMap

QT += quick qml cfmvc cfmvc-private core-private webview webview-private

load(qt_module)

