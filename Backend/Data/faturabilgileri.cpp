#include "faturabilgileri.h"

FaturaBilgileri::FaturaBilgileri()
{

}

QString FaturaBilgileri::getFaturaNo() const
{
    return u_strFaturaNo;
}

void FaturaBilgileri::setFaturaNo(const QString &value)
{
    u_strFaturaNo = value;
}

QString FaturaBilgileri::getGecerlilikSuresi() const
{
    return u_strGecerlilikSuresi;
}

void FaturaBilgileri::setGecerlilikSuresi(const QString &value)
{
    u_strGecerlilikSuresi = value;
}

QDate FaturaBilgileri::getTarih() const
{
    return u_tarTarih;
}

void FaturaBilgileri::setTarih(const QDate &value)
{
    u_tarTarih = value;
}
