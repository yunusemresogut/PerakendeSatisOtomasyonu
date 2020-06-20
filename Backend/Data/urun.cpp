#include "urun.h"

Urun::Urun()
{

}

QString Urun::getGrubu() const
{
    return u_strGrubu;
}

void Urun::setGrubu(const QString &value)
{
    u_strGrubu = value;
}

UrunBilgileri &Urun::getUrunBilgileri()
{
    return u_UrunBilgileri;
}

QVector<shared_ptr<Stok> > &Urun::getStoklar()
{
    //return u_Stoklar;
}
