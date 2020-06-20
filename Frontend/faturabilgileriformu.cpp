#include "faturabilgileriformu.h"
#include "ui_faturabilgileriformu.h"

#include <QMessageBox>

#include "Backend/veritabani.h"

FaturaBilgileriFormu::FaturaBilgileriFormu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FaturaBilgileriFormu)
{
    ui->setupUi(this);

    gorselGuncelle();
}

FaturaBilgileriFormu::~FaturaBilgileriFormu()
{
    delete ui;
}

void FaturaBilgileriFormu::gorselGuncelle()
{
    u_ptrFatura = VeriTabani::getNesne()->getFaturaErisim().yeniFatura();

    ui->le_Adi->setText(u_ptrFatura->getFaturaNo());
    ui->le_Kodu->setText(u_ptrFatura->getGecerlilikSuresi());
    ui->dateEdit->setDate(u_ptrFatura->getTarih());

    u_bDegisiklikVarMi = false;
}

void FaturaBilgileriFormu::veriGuncelle()
{
    u_ptrFatura->setFaturaNo(ui->le_Adi->text());
    u_ptrFatura->setGecerlilikSuresi(ui->le_Kodu->text());
    u_ptrFatura->setTarih(ui->dateEdit->date());
}

void FaturaBilgileriFormu::degisiklikvar()
{
    u_bDegisiklikVarMi = true;
}

void FaturaBilgileriFormu::accept()
{
    veriGuncelle();

    try{
        VeriTabani::getNesne()->getFaturaErisim().listeyeEkle(u_ptrFatura);

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

void FaturaBilgileriFormu::reject()
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


void FaturaBilgileriFormu::on_pb_TTemizle_clicked()
{
    ui->le_Adi->clear();
    ui->le_Kodu->clear();
    ui->dateEdit->clear();

    u_bDegisiklikVarMi = false;

    ui->le_Adi->setFocus();
}
