#ifndef MUSTERIVERIERISIMI_H
#define MUSTERIVERIERISIMI_H

#include "Backend/Data/musteribilgileri.h"
#include <QVector>
#include <memory>

#include <QDataStream>

using namespace std;

class MusteriVeriErisimi
{
public:
    typedef MusteriBilgileri Veri;

    typedef shared_ptr <Veri> Pointer;

    typedef QVector <Pointer> Liste;

    typedef enum { IleBaslayan = 1, IleBiten = 2, Iceren = 3 } AramaTuru;

    MusteriVeriErisimi();

    Pointer yeniMusteri();

    void listeyeEkle(Pointer musteri);

    Pointer adaGoreMusteriBul(QString arananAd);

    Liste soyadGoreMusteriBul(QString arananSoyad, AramaTuru tur);

    void musteriSil(QString musteriAdi);

    void kaydet(QDataStream &kaydedici);

    void yukle(QDataStream &kaydedici);

private:

    Liste u_Musteriler;
};

#endif // MUSTERIVERIERISIMI_H
