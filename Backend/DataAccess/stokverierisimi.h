#ifndef STOKVERIERISIMI_H
#define STOKVERIERISIMI_H

#include "Backend/Data/stok.h"
#include <memory>
#include <QVector>

#include <QDataStream>

using namespace std;

class StokVeriErisimi
{
public:
    typedef Stok Veri;

    typedef shared_ptr <Veri> Pointer;

    typedef QVector <Pointer> Liste;

    typedef enum { IleBaslayan = 1, IleBiten = 2, Iceren = 3 } AramaTuru;

    StokVeriErisimi();

    Pointer yeniStok();

    void listeyeEkle(Pointer stok);

    Pointer kodaGoreStokBul(QString arananKod);

    Liste adaGoreStokBul(QString arananAd, AramaTuru tur);

    void stokSil(QString stokKodu);

    void kaydet(QDataStream &kaydedici);

    void yukle(QDataStream &kaydedici);

private:
    Liste u_Stoklar;
};

#endif // STOKVERIERISIMI_H
