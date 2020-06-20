#include "stok.h"

Stok::Stok()
{

}

QString Stok::getStokKodu() const
{
    return u_strStokKodu;
}

void Stok::setStokKodu(const QString &value)
{
    u_strStokKodu = value;
}

QString Stok::getStokAdi() const
{
    return u_strStokAdi;
}

void Stok::setStokAdi(const QString &value)
{
    u_strStokAdi = value;
}

UrunBilgileri &Stok::getUrunBilgileri()
{
    return u_UrunBilgileri;
}
