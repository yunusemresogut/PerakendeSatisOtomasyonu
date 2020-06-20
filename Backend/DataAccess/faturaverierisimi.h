#ifndef FATURAVERIERISIMI_H
#define FATURAVERIERISIMI_H

#include "Backend/Data/faturabilgileri.h"
#include <QVector>
#include <memory>

#include <QDataStream>

using namespace std;

class FaturaVeriErisimi
{
public:
    typedef FaturaBilgileri Veri;

    typedef shared_ptr <Veri> Pointer;

    typedef QVector <Pointer> Liste;

    typedef enum { IleBaslayan = 1, IleBiten = 2, Iceren = 3 } AramaTuru;

    FaturaVeriErisimi();

    Pointer yeniFatura();

    void listeyeEkle(Pointer fatura);

    Pointer faturaNoGoreFaturaBul(QString arananFatura);

    Liste gecerlilikSuresiGoreFaturaBul(QString arananSure, AramaTuru tur);

    void faturaSil(QString faturaAdi);

    void kaydet(QDataStream &kaydedici);

    void yukle(QDataStream &kaydedici);

private:

    Liste u_Faturalar;
};

#endif // FATURAVERIERISIMI_H
