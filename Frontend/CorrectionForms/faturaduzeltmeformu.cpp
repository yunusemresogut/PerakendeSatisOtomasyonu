#include "faturaduzeltmeformu.h"
#include "ui_faturabilgileriformu.h"

#include "Backend/veritabani.h"

FaturaDuzeltmeFormu::FaturaDuzeltmeFormu(QWidget *parent) : FaturaBilgileriFormu(parent)
{

}

void FaturaDuzeltmeFormu::faturaGoster(QString faturaNo)
{
    //u_ptrFatura = VeriTabani::getNesne()->getFaturaErisim().gecerlilikSuresiGoreFaturaBul(faturaNo);

    gorselGuncelle();

    ui->dateEdit->setReadOnly(true);
}

void FaturaDuzeltmeFormu::accept()
{
    veriGuncelle();
    QDialog::accept();
}
