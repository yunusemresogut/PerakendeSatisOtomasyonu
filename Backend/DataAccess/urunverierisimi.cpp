#include "urunverierisimi.h"

UrunVeriErisimi::UrunVeriErisimi()
{

}

shared_ptr<Urun> UrunVeriErisimi::Urunum()
{
    if (u_ptrUrun.get() == nullptr){
        u_ptrUrun = make_shared<Urun>();
    }
    return u_ptrUrun;
}

void UrunVeriErisimi::yukle(QDataStream &kaydedici)
{
    QString urunGrubu, adeti, adi, fiyati, kodu;
    QDate tarihi;
    kaydedici >> urunGrubu
              >> adeti
              >> adi
              >> fiyati
              >> kodu
              >> tarihi;
    auto urn = Urunum();

    urn->setGrubu(urunGrubu);
    urn->getUrunBilgileri().setAdeti(adeti);
    urn->getUrunBilgileri().setAdi(adi);
    urn->getUrunBilgileri().setFiyati(fiyati);
    urn->getUrunBilgileri().setKodu(kodu);
    urn->getUrunBilgileri().setTarihi(tarihi);
}

void UrunVeriErisimi::kaydet(QDataStream &kaydedici)
{
    kaydedici << u_ptrUrun->getGrubu()
              <<u_ptrUrun->getUrunBilgileri().getAdeti()
              <<u_ptrUrun->getUrunBilgileri().getAdi()
              <<u_ptrUrun->getUrunBilgileri().getFiyati()
              <<u_ptrUrun->getUrunBilgileri().getKodu()
              <<u_ptrUrun->getUrunBilgileri().getTarihi();
}

