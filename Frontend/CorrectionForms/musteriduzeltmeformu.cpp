#include "musteriduzeltmeformu.h"
#include "ui_musteribilgileriformu.h"

#include "Backend/veritabani.h"

MusteriDuzeltmeFormu::MusteriDuzeltmeFormu(QWidget *parent) : MusteriBilgileriFormu(parent)
{

}

void MusteriDuzeltmeFormu::musteriGoster(QString musteriSoyadi)
{
    //u_ptrMusteri = VeriTabani::getNesne()->getMusteriErisim().soyadGoreMusteriBul(musteriSoyadi);

    gorselGuncelle();

    ui->lineEdit->setReadOnly(true);
}

void MusteriDuzeltmeFormu::accept()
{
    veriGuncelle();
    QDialog::accept();
}
