QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    detalle_publicacion.cpp \
    main.cpp \
    login.cpp \
    pagina_incio.cpp \
    perfil.cpp \
    publicar.cpp \
    registrarse.cpp \
    seguidores.cpp

HEADERS += \
    Arbol_busqueda.h \
    Comentario.h \
    Cuenta.h \
    Lista.h \
    Publicacion.h \
    detalle_publicacion.h \
    login.h \
    pagina_incio.h \
    perfil.h \
    publicar.h \
    registrarse.h \
    seguidores.h

FORMS += \
    detalle_publicacion.ui \
    login.ui \
    pagina_incio.ui \
    perfil.ui \
    publicar.ui \
    registrarse.ui \
    seguidores.ui

TRANSLATIONS += \
    Trabajo_final_es_PE.ts

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Recursos.qrc
