#ifndef VERITABANI_H
#define VERITABANI_H

#include "DataAccess/urunverierisimi.h"
#include "DataAccess/stokverierisimi.h"
#include "DataAccess/musteriverierisimi.h"
#include "DataAccess/faturaverierisimi.h"

class VeriTabani
{
public:
    static VeriTabani *getNesne();

    UrunVeriErisimi &getUrunErisim();

    StokVeriErisimi &getStokErisim();

    MusteriVeriErisimi &getMusteriErisim();

    FaturaVeriErisimi &getFaturaErisim();

    void yukle();

    void sakla();

private:
    VeriTabani();

    static VeriTabani *u_ptrNesne;

    UrunVeriErisimi u_UrunErisim;

    StokVeriErisimi u_StokErisim;

    MusteriVeriErisimi u_MusteriErisim;

    FaturaVeriErisimi u_FaturaErisim;



};

#endif // VERITABANI_H
