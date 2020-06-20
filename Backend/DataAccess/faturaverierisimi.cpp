#include "faturaverierisimi.h"

#include <exception>

#include <QDataStream>

FaturaVeriErisimi::FaturaVeriErisimi()
{

}

FaturaVeriErisimi::Pointer FaturaVeriErisimi::yeniFatura()
{
    return make_shared <Veri>();
}

void FaturaVeriErisimi::listeyeEkle(FaturaVeriErisimi::Pointer fatura)
{
    for (auto fatura_i : u_Faturalar){
        if (fatura->getFaturaNo() == fatura_i->getFaturaNo()){
            throw invalid_argument("Aynı Fatura Numarasına sahip başka bir Fatura var");
        }
    }
    u_Faturalar.push_back(fatura);
}

FaturaVeriErisimi::Pointer FaturaVeriErisimi::faturaNoGoreFaturaBul(QString arananFatura)
{
    Pointer sonuc(nullptr);
    for (auto fatura_i : u_Faturalar){
        if (arananFatura == fatura_i->getFaturaNo()){
            sonuc = fatura_i;
            break;
        }
    }
    return sonuc;
}

FaturaVeriErisimi::Liste FaturaVeriErisimi::gecerlilikSuresiGoreFaturaBul(QString arananSure, FaturaVeriErisimi::AramaTuru tur)
{
    Liste sonuc;
    for (auto fatura_i : u_Faturalar){
        if (tur == Iceren && fatura_i->getGecerlilikSuresi().contains(arananSure)){
            sonuc.push_back(fatura_i);
        }
        if (tur == IleBaslayan && fatura_i->getGecerlilikSuresi().startsWith(arananSure)){
            sonuc.push_back(fatura_i);
        }
        if (tur == IleBiten && fatura_i->getGecerlilikSuresi().endsWith(arananSure)){
            sonuc.push_back(fatura_i);
        }

    }
    return sonuc;
}

void FaturaVeriErisimi::faturaSil(QString faturaAdi)
{
    Pointer silinecek;
    for (auto fatura_i : u_Faturalar){
        if (faturaAdi == fatura_i->getFaturaNo()){
            silinecek = fatura_i;
            u_Faturalar.removeOne(silinecek);
            break;
        }
    }
}

void FaturaVeriErisimi::kaydet(QDataStream &kaydedici)
{
    int elemanSayisi = u_Faturalar.size();
    kaydedici << elemanSayisi;

    for (auto fatura_i : u_Faturalar){
        kaydedici << fatura_i->getFaturaNo()
                  << fatura_i->getGecerlilikSuresi()
                  << fatura_i->getTarih();
    }
}

void FaturaVeriErisimi::yukle(QDataStream &kaydedici)
{
    QString faturaNo, gecerlilikSuresi, tarih;

    int faturaSayisi;
    kaydedici >> faturaSayisi;

    for (int i=0; i<faturaSayisi; i++){
        kaydedici >> faturaNo >> gecerlilikSuresi >> tarih;

        auto yeniFatura = this->yeniFatura();
        yeniFatura->setFaturaNo(faturaNo);
        yeniFatura->setGecerlilikSuresi(gecerlilikSuresi);
       // yeniFatura->setTarih(tarih);

        listeyeEkle(yeniFatura);
    }
}
