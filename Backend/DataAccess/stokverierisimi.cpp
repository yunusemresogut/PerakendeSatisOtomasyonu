#include "stokverierisimi.h"

#include <exception>

#include <QDataStream>

StokVeriErisimi::StokVeriErisimi()
{

}

StokVeriErisimi::Pointer StokVeriErisimi::yeniStok()
{
    return make_shared <Veri>();
}

void StokVeriErisimi::listeyeEkle(StokVeriErisimi::Pointer stok)
{
    for (auto stok_i : u_Stoklar){
        if (stok->getStokKodu() == stok_i->getStokKodu()){
            throw invalid_argument("Aynı Ada veya Koda sahip başka bir Ürün var!");
        }
    }
    u_Stoklar.push_back(stok);
}

StokVeriErisimi::Pointer StokVeriErisimi::kodaGoreStokBul(QString arananKod)
{
    Pointer sonuc(nullptr);
    for (auto stok_i : u_Stoklar){
        if (arananKod == stok_i->getStokKodu()){
            sonuc = stok_i;
            break;
        }
    }
    return sonuc;
}

StokVeriErisimi::Liste StokVeriErisimi::adaGoreStokBul(QString arananAd, StokVeriErisimi::AramaTuru tur)
{
    Liste sonuc;
    for (auto stok_i : u_Stoklar){
        if (tur == Iceren && stok_i->getStokAdi().contains(arananAd)){
            sonuc.push_back(stok_i);
        }
        if (tur == IleBaslayan && stok_i->getStokAdi().startsWith(arananAd)){
            sonuc.push_back(stok_i);
        }
        if (tur == IleBiten && stok_i->getStokAdi().endsWith(arananAd)){
            sonuc.push_back(stok_i);
        }

    }
    return sonuc;
}

void StokVeriErisimi::stokSil(QString stokKodu)
{
    Pointer silinecek;
    for (auto stok_i : u_Stoklar){
        if (stokKodu == stok_i->getStokKodu()){
            silinecek = stok_i;
            u_Stoklar.removeOne(silinecek);
            break;
        }
    }
}

void StokVeriErisimi::kaydet(QDataStream &kaydedici)
{
    int elemanSayisi = u_Stoklar.size();
    kaydedici << elemanSayisi;

    for (auto stok_i : u_Stoklar){
        kaydedici << stok_i->getStokKodu()
                  << stok_i->getStokAdi()
                  << stok_i->getUrunBilgileri().getAdeti()
                  << stok_i->getUrunBilgileri().getAdi()
                  << stok_i->getUrunBilgileri().getFiyati()
                  << stok_i->getUrunBilgileri().getKodu()
                  << stok_i->getUrunBilgileri().getTarihi();
    }
}

void StokVeriErisimi::yukle(QDataStream &kaydedici)
{
    QString stokKodu, stokAdi, adeti, adi, fiyati, kodu;
    QDate tarihi;

    int stokSayisi;
    kaydedici >> stokSayisi;

    for (int i=0; i<stokSayisi; i++){
        kaydedici >> stokKodu >> stokAdi >> adeti >> adi >> fiyati >> kodu >> tarihi;

        auto yeniStok = this->yeniStok();
        yeniStok->setStokKodu(stokKodu);
        yeniStok->setStokAdi(stokAdi);
        yeniStok->getUrunBilgileri().setAdeti(adeti);
        yeniStok->getUrunBilgileri().setAdi(adi);
        yeniStok->getUrunBilgileri().setFiyati(fiyati);
        yeniStok->getUrunBilgileri().setKodu(kodu);
        yeniStok->getUrunBilgileri().setTarihi(tarihi);

        listeyeEkle(yeniStok);
    }

}
