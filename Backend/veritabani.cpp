#include "veritabani.h"

#include <QStandardPaths>
#include <QFile>
#include <QDataStream>

VeriTabani *VeriTabani::u_ptrNesne = nullptr;

VeriTabani::VeriTabani()
{

}

FaturaVeriErisimi &VeriTabani::getFaturaErisim()
{
    return u_FaturaErisim;
}

MusteriVeriErisimi &VeriTabani::getMusteriErisim()
{
    return u_MusteriErisim;
}

StokVeriErisimi &VeriTabani::getStokErisim()
{
    return u_StokErisim;
}

void VeriTabani::yukle()
{
    QString dosyaYolu = QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation);
    QString dosyaTamAdi = dosyaYolu+"/yfsatis.data";

    QFile veriDosyasi(dosyaTamAdi);

    if (veriDosyasi.open(QIODevice::ReadOnly)){
        QDataStream kaydedici(&veriDosyasi);

        u_UrunErisim.yukle(kaydedici);
        u_StokErisim.yukle(kaydedici);
        u_MusteriErisim.yukle(kaydedici);

        veriDosyasi.close();
    }
}

void VeriTabani::sakla()
{
    QString dosyaYolu = QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation);
    QString dosyaTamAdi = dosyaYolu+"/yfsatis.data";

    QFile veriDosyasi(dosyaTamAdi);

    if (veriDosyasi.open(QIODevice::WriteOnly)){
        QDataStream kaydedici(&veriDosyasi);

        u_UrunErisim.kaydet(kaydedici);
        u_StokErisim.kaydet(kaydedici);
        u_MusteriErisim.kaydet(kaydedici);

        veriDosyasi.close();
    }
}

UrunVeriErisimi &VeriTabani::getUrunErisim()
{
    return u_UrunErisim;
}

VeriTabani *VeriTabani::getNesne()
{
    if (u_ptrNesne == nullptr){
        u_ptrNesne = new VeriTabani;
    }
    return u_ptrNesne;
}
