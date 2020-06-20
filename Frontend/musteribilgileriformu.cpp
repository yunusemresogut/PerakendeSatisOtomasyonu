#include "musteribilgileriformu.h"
#include "ui_musteribilgileriformu.h"

#include <QMessageBox>

#include "Backend/veritabani.h"

MusteriBilgileriFormu::MusteriBilgileriFormu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MusteriBilgileriFormu)
{
    ui->setupUi(this);

    gorselGuncelle();
}

MusteriBilgileriFormu::~MusteriBilgileriFormu()
{
    delete ui;
}

void MusteriBilgileriFormu::gorselGuncelle()
{
    u_ptrMusteri = VeriTabani::getNesne()->getMusteriErisim().yeniMusteri();

    ui->le_Adi->setText(u_ptrMusteri->getMAdi());
    ui->le_Kodu->setText(u_ptrMusteri->getMSoyadi());
    ui->lineEdit->setText(u_ptrMusteri->getMTC());
    ui->lineEdit_2->setText(u_ptrMusteri->getTelNo());
    ui->lineEdit_3->setText(u_ptrMusteri->getTahsilat());

    u_bDegisiklikVarMi = false;
}

void MusteriBilgileriFormu::veriGuncelle()
{
    u_ptrMusteri->setMAdi(ui->le_Adi->text());
    u_ptrMusteri->setMSoyadi(ui->le_Kodu->text());
    u_ptrMusteri->setMTC(ui->lineEdit->text());
    u_ptrMusteri->setTelNo(ui->lineEdit_2->text());
    u_ptrMusteri->setTahsilat(ui->lineEdit_3->text());
}

void MusteriBilgileriFormu::degisiklikvar()
{
    u_bDegisiklikVarMi = true;
}

void MusteriBilgileriFormu::accept()
{
    veriGuncelle();

    try{
        VeriTabani::getNesne()->getMusteriErisim().listeyeEkle(u_ptrMusteri);

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

void MusteriBilgileriFormu::reject()
{
    degisiklikvar();

    if (u_bDegisiklikVarMi == true){
        QMessageBox soru;

        soru.setText("Değişiklikleri Kaydetmeden Çıkmak İstediğinize Emin Misiniz?");
        soru.setStandardButtons(QMessageBox::Yes|QMessageBox::No);

        soru.setIcon(QMessageBox::Information);
        soru.exec();

        soru.setButtonText(QMessageBox::Yes, tr("Evet"));
        soru.setButtonText(QMessageBox::No, tr("Hayır"));

        soru.setInformativeText(tr("(Bu Soruya Evet cevabı verirseniz yaptığınız değişiklikler kalıcı olarak silinecektir.)"));

        if (soru.exec() == QMessageBox::Yes){
            QDialog::reject();
        }
    }
    else {
        QDialog::reject();
}
}

void MusteriBilgileriFormu::on_pb_TTemizle_clicked()
{
    ui->le_Adi->clear();
    ui->le_Kodu->clear();
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();

    u_bDegisiklikVarMi = false;

    ui->le_Adi->setFocus();
}
