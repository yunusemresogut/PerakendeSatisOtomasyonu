#include "stokduzeltmeformu.h"
#include "ui_stokbilgileriformu.h"

#include "Backend/veritabani.h"

StokDuzeltmeFormu::StokDuzeltmeFormu(QWidget *parent) : StokBilgileriFormu(parent)
{

}

void StokDuzeltmeFormu::stokGoster(QString stokKodu)
{
    u_ptrStok= VeriTabani::getNesne()->getStokErisim().kodaGoreStokBul(stokKodu);

    gorselGuncelle();

    ui->le_Kodu->setReadOnly(true);
}

void StokDuzeltmeFormu::accept()
{
    veriGuncelle();
    QDialog::accept();
}
