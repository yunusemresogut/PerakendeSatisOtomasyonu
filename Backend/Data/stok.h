#ifndef STOK_H
#define STOK_H

#include <QString>
#include "urunbilgileri.h"

class Stok
{
public:
    Stok();

    QString getStokKodu() const;
    void setStokKodu(const QString &value);

    QString getStokAdi() const;
    void setStokAdi(const QString &value);

    UrunBilgileri &getUrunBilgileri();

private:
    QString u_strStokKodu;
    QString u_strStokAdi;
    UrunBilgileri u_UrunBilgileri;
};

#endif // STOK_H
