#-------------------------------------------------
#
# Project created by QtCreator 2018-05-23T04:04:00
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = YF_PerakendeSatisOtomasyonu
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        yf_perakendesatisotomasyonu.cpp \
    Backend/Data/urunbilgileri.cpp \
    Backend/Data/urun.cpp \
    Backend/Data/stok.cpp \
    Backend/veritabani.cpp \
    Backend/DataAccess/urunverierisimi.cpp \
    Frontend/urunbilgileriformu.cpp \
    Backend/DataAccess/stokverierisimi.cpp \
    Frontend/stokbilgileriformu.cpp \
    Frontend/SearchForms/stokaramaformu.cpp \
    Frontend/CorrectionForms/stokduzeltmeformu.cpp \
    Frontend/hakkimizda.cpp \
    Frontend/yardim.cpp \
    Frontend/SearchForms/musteriaramaformu.cpp \
    Frontend/SearchForms/faturaaramaformu.cpp \
    Backend/DataAccess/faturaverierisimi.cpp \
    Backend/DataAccess/musteriverierisimi.cpp \
    Frontend/CorrectionForms/musteriduzeltmeformu.cpp \
    Backend/Data/musteribilgileri.cpp \
    Backend/Data/faturabilgileri.cpp \
    Frontend/musteribilgileriformu.cpp \
    Frontend/faturabilgileriformu.cpp \
    Frontend/CorrectionForms/faturaduzeltmeformu.cpp

HEADERS += \
        yf_perakendesatisotomasyonu.h \
    Backend/Data/urunbilgileri.h \
    Backend/Data/urun.h \
    Backend/Data/stok.h \
    Backend/veritabani.h \
    Backend/DataAccess/urunverierisimi.h \
    Frontend/urunbilgileriformu.h \
    Backend/DataAccess/stokverierisimi.h \
    Frontend/stokbilgileriformu.h \
    Frontend/SearchForms/stokaramaformu.h \
    Frontend/CorrectionForms/stokduzeltmeformu.h \
    Frontend/hakkimizda.h \
    Frontend/yardim.h \
    Frontend/SearchForms/musteriaramaformu.h \
    Frontend/SearchForms/faturaaramaformu.h \
    Backend/DataAccess/faturaverierisimi.h \
    Backend/DataAccess/musteriverierisimi.h \
    Frontend/CorrectionForms/musteriduzeltmeformu.h \
    Backend/Data/musteribilgileri.h \
    Backend/Data/faturabilgileri.h \
    Frontend/musteribilgileriformu.h \
    Frontend/faturabilgileriformu.h \
    Frontend/CorrectionForms/faturaduzeltmeformu.h

FORMS += \
        yf_perakendesatisotomasyonu.ui \
    Frontend/urunbilgileriformu.ui \
    Frontend/stokbilgileriformu.ui \
    Frontend/SearchForms/stokaramaformu.ui \
    Frontend/hakkimizda.ui \
    Frontend/yardim.ui \
    Frontend/SearchForms/musteriaramaformu.ui \
    Frontend/SearchForms/faturaaramaformu.ui \
    Frontend/musteribilgileriformu.ui \
    Frontend/faturabilgileriformu.ui

RESOURCES += \
    materials.qrc
