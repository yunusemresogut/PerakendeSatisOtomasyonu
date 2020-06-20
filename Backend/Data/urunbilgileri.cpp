#include "urunbilgileri.h"

UrunBilgileri::UrunBilgileri()
{

}

QString UrunBilgileri::getAdi() const
{
    return u_strAdi;
}

void UrunBilgileri::setAdi(const QString &value)
{
    u_strAdi = value;
}

QString UrunBilgileri::getKodu() const
{
    return u_strKodu;
}

void UrunBilgileri::setKodu(const QString &value)
{
    u_strKodu = value;
}

QString UrunBilgileri::getAdeti() const
{
    return u_strAdeti;
}

void UrunBilgileri::setAdeti(const QString &value)
{
    u_strAdeti = value;
}

QString UrunBilgileri::getFiyati() const
{
    return u_strFiyati;
}

void UrunBilgileri::setFiyati(const QString &value)
{
    u_strFiyati = value;
}

QDate UrunBilgileri::getTarihi() const
{
    return u_tarTarihi;
}

void UrunBilgileri::setTarihi(const QDate &value)
{
    u_tarTarihi = value;
}
