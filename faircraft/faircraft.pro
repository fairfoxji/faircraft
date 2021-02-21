QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

FAIRCRAFT_VERSION = "0.1"

DEFINES += FAIRCRAFT_VERSION=\\\"$${FAIRCRAFT_VERSION}\\\"


# Subdirectories
SourceDir = ./constant \
            ./controller \
            ./view \

for(var, SourceDir) {
    SOURCES += $$files($$join(var, , , /*.cpp), true)
    HEADERS += $$files($$join(var, , , /*.h)  , true)
    FORMS   += $$files($$join(var, , , /*.ui) , true)
}

SOURCES += \
    main.cpp \


HEADERS += \



TRANSLATIONS += \
    translation/faircraft_zh_CN.ts \
    translation/faircraft_en_US.ts \

RESOURCES += \
  translations.qrc

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

FORMS += \
  view/chooselanguagedialog.ui \
  view/mainwindow.ui
