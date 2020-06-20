#ifndef URUN_H
#define URUN_H

#include <QString>
#include <memory>
#include "urunbilgileri.h"
#include "stok.h"

using namespace std;

class Urun
{
public:
    Urun();

    QString getGrubu() const;
    void setGrubu(const QString &value);

    UrunBilgileri &getUrunBilgileri();

    QVector<shared_ptr<Stok> >& getStoklar();

private:
    QString u_strGrubu;
    UrunBilgileri u_UrunBilgileri;

    friend class UrunVeriErisimi;
};

#endif // URUN_H
