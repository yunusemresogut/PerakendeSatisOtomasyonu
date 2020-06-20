#include "stokbilgileriformu.h"
#include "ui_stokbilgileriformu.h"

#include <QMessageBox>

#include "Backend/veritabani.h"

void StokBilgileriFormu::gorselGuncelle()
{
    u_ptrStok = VeriTabani::getNesne()->getStokErisim().yeniStok();

    ui->le_Adi->setText(u_ptrStok->getStokAdi());
    ui->le_Kodu->setText(u_ptrStok->getStokKodu());
    ui->lineEdit->setText(u_ptrStok->getUrunBilgileri().getAdeti());
    ui->lineEdit_2->setText(u_ptrStok->getUrunBilgileri().getFiyati());
    ui->dateEdit->setDate(u_ptrStok->getUrunBilgileri().getTarihi());

    u_bDegisiklikVarMi = false;
}

StokBilgileriFormu::StokBilgileriFormu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StokBilgileriFormu)
{
    ui->setupUi(this);

    gorselGuncelle();
}

StokBilgileriFormu::~StokBilgileriFormu()
{
    delete ui;
}

void StokBilgileriFormu::degisiklikvar()
{
    if(ui->le_Adi->text().isEmpty()==true){
        u_bDegisiklikVarMi=false;
    }
    else {
        u_bDegisiklikVarMi=true;
    }
    //u_bDegisiklikVarMi = true;
}

void StokBilgileriFormu::veriGuncelle()
{
    u_ptrStok->setStokAdi(ui->le_Adi->text());
    u_ptrStok->setStokKodu(ui->le_Kodu->text());
    u_ptrStok->getUrunBilgileri().setAdeti(ui->lineEdit->text());
    u_ptrStok->getUrunBilgileri().setFiyati(ui->lineEdit_2->text());
    u_ptrStok->getUrunBilgileri().setTarihi(ui->dateEdit->date());
}

void StokBilgileriFormu::accept()
{
    veriGuncelle();

    try{
        VeriTabani::getNesne()->getStokErisim().listeyeEkle(u_ptrStok);

        QDialog::accept();
    }catch (invalid_argument hata){
        QMessageBox sorucuk;

        sorucuk.setText(hata.what());
        sorucuk.setStandardButtons(QMessageBox::Ok);

        sorucuk.setButtonText(QMessageBox::Ok, tr("Tamam"));

        sorucuk.setIcon(QMessageBox::Warning);

        sorucuk.exec();

        ui->le_Adi->setFocus();
        ui->le_Adi->selectAll();
    }
}

void StokBilgileriFormu::reject()
{
    degisiklikvar();

    if(u_bDegisiklikVarMi==true){
     QMessageBox soru;

     soru.setText(tr("Değişiklikleri kaydetmeden çıkmak istediğinizden emin misiniz?"));
     soru.setStandardButtons(QMessageBox::Yes|QMessageBox::No);

     soru.setIcon(QMessageBox::Warning);
     soru.exec();

     soru.setButtonText(QMessageBox::Yes, tr("Evet"));
     soru.setButtonText(QMessageBox::No, tr("Hayır"));

     soru.setInformativeText(tr("Bu soruya evet cevabı verirsnizyaptığınız değişiklikler kalıcı olarak silinecektir."));

     if(soru.exec()==QMessageBox::Yes){
         QDialog::reject();
     }
 }
    else {
        QDialog::reject();
    }
    /*QMessageBox soru;

    soru.setText("Değişiklikleri Kaydetmeden Çıkmak İstediğinize Emin Misiniz?");
    soru.setStandardButtons(QMessageBox::Yes|QMessageBox::No);

    soru.setButtonText(QMessageBox::Yes, tr("Evet"));
    soru.setButtonText(QMessageBox::No, tr("Hayır"));

    soru.setIcon(QMessageBox::Information);

    soru.setInformativeText(tr("(Bu Soruya Evet cevabı verirseniz yaptığınız değişiklikler kalıcı olarak silinecektir.)"));

    if (u_bDegisiklikVarMi == true){
        if (soru.exec() == QMessageBox::Yes){
            QDialog::reject();
        }
    }*/
}

void StokBilgileriFormu::on_pb_TTemizle_clicked()
{
    ui->le_Adi->clear();
    ui->le_Kodu->clear();
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->dateEdit->clear();

    u_bDegisiklikVarMi = false;

    ui->le_Adi->setFocus();
}
