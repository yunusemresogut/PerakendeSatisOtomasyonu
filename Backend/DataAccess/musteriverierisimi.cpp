#include "musteriverierisimi.h"

#include <exception>

#include <QDataStream>

MusteriVeriErisimi::MusteriVeriErisimi()
{

}

MusteriVeriErisimi::Pointer MusteriVeriErisimi::yeniMusteri()
{
    return make_shared <Veri>();
}

void MusteriVeriErisimi::listeyeEkle(MusteriVeriErisimi::Pointer musteri)
{
    for (auto musteri_i : u_Musteriler){
        if (musteri->getMTC() == musteri_i->getMTC()){
            throw invalid_argument("Aynı TC Kimlik Numarasına sahip başka bir Müşteri var!");
        }
    }
    u_Musteriler.push_back(musteri);
}

MusteriVeriErisimi::Pointer MusteriVeriErisimi::adaGoreMusteriBul(QString arananAd)
{
    Pointer sonuc(nullptr);
    for (auto musteri_i : u_Musteriler){
        if (arananAd == musteri_i->getMTC()){
            sonuc = musteri_i;
            break;
        }
    }
    return sonuc;
}

void MusteriVeriErisimi::musteriSil(QString musteriAdi)
{
    Pointer silinecek;
    for (auto musteri_i : u_Musteriler){
        if (musteriAdi == musteri_i->getMTC()){
            silinecek = musteri_i;
            u_Musteriler.removeOne(silinecek);
            break;
        }
    }
}

void MusteriVeriErisimi::kaydet(QDataStream &kaydedici)
{
    int elemanSayisi = u_Musteriler.size();
    kaydedici << elemanSayisi;

    for (auto musteri_i : u_Musteriler){
        kaydedici << musteri_i->getMAdi()
                  << musteri_i->getMSoyadi()
                  << musteri_i->getMTC()
                  << musteri_i->getTelNo()
                  << musteri_i->getTahsilat();
    }
}

void MusteriVeriErisimi::yukle(QDataStream &kaydedici)
{
    QString musteriAdi, musteriSoyadi, musteriTC, musteriTelNo, musteriTahsilat;

    int musteriSayisi;
    kaydedici >> musteriSayisi;

    for (int i=0; i<musteriSayisi; i++){
        kaydedici >> musteriAdi >> musteriSoyadi >> musteriTC >> musteriTelNo >> musteriTahsilat;

        auto yeniMusteri = this->yeniMusteri();
        yeniMusteri->setMAdi(musteriAdi);
        yeniMusteri->setMSoyadi(musteriSoyadi);
        yeniMusteri->setMTC(musteriTC);
        yeniMusteri->setTelNo(musteriTelNo);
        yeniMusteri->setTahsilat(musteriTahsilat);

        listeyeEkle(yeniMusteri);
    }
}

MusteriVeriErisimi::Liste MusteriVeriErisimi::soyadGoreMusteriBul(QString arananSoyad, MusteriVeriErisimi::AramaTuru tur)
{
    Liste sonuc;
    for (auto musteri_i : u_Musteriler){
        if (tur == Iceren && musteri_i->getMSoyadi().contains(arananSoyad)){
            sonuc.push_back(musteri_i);
        }
        if (tur == IleBaslayan && musteri_i->getMSoyadi().startsWith(arananSoyad)){
            sonuc.push_back(musteri_i);
        }
        if (tur == IleBiten && musteri_i->getMSoyadi().endsWith(arananSoyad)){
            sonuc.push_back(musteri_i);
        }

    }
    return sonuc;
}
