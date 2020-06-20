#include "musteribilgileri.h"

MusteriBilgileri::MusteriBilgileri()
{

}

QString MusteriBilgileri::getMAdi() const
{
    return u_strMAdi;
}

void MusteriBilgileri::setMAdi(const QString &value)
{
    u_strMAdi = value;
}

QString MusteriBilgileri::getMSoyadi() const
{
    return u_strMSoyadi;
}

void MusteriBilgileri::setMSoyadi(const QString &value)
{
    u_strMSoyadi = value;
}

QString MusteriBilgileri::getMTC() const
{
    return u_strMTC;
}

void MusteriBilgileri::setMTC(const QString &value)
{
    u_strMTC = value;
}

QString MusteriBilgileri::getTelNo() const
{
    return u_strTelNo;
}

void MusteriBilgileri::setTelNo(const QString &value)
{
    u_strTelNo = value;
}

QString MusteriBilgileri::getTahsilat() const
{
    return u_strTahsilat;
}

void MusteriBilgileri::setTahsilat(const QString &value)
{
    u_strTahsilat = value;
}
