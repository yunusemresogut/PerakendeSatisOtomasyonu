#ifndef URUNVERIERISIMI_H
#define URUNVERIERISIMI_H

#include <memory>
#include <QVector>
#include "Backend/Data/urun.h"

using namespace std;

class UrunVeriErisimi
{
public:
    UrunVeriErisimi();

    shared_ptr <Urun> Urunum();

    void yukle(QDataStream &kaydedici);

    void kaydet(QDataStream &kaydedici);

private:
    shared_ptr <Urun> u_ptrUrun;
};

#endif // URUNVERIERISIMI_H
