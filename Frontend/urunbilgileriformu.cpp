  #include "urunbilgileriformu.h"
#include "ui_urunbilgileriformu.h"

#include "Backend/veritabani.h"

#include <QMessageBox>

UrunBilgileriFormu::UrunBilgileriFormu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UrunBilgileriFormu)
{
    ui->setupUi(this);

    auto urun = VeriTabani::getNesne()->getUrunErisim().Urunum();

    ui->le_Adeti->setText(urun->getUrunBilgileri().getAdeti());
    ui->le_Adi->setText(urun->getGrubu());
    ui->le_Fiyati->setText(urun->getUrunBilgileri().getFiyati());
    ui->le_Kodu->setText(urun->getUrunBilgileri().getKodu());
    ui->de_Tarihi->setDate(urun->getUrunBilgileri().getTarihi());

    u_bDegisiklikVarMi = false;
}

UrunBilgileriFormu::~UrunBilgileriFormu()
{
    delete ui;
}

void UrunBilgileriFormu::accept()
{
    auto urun = VeriTabani::getNesne()->getUrunErisim().Urunum();

    urun->setGrubu(ui->le_Adi->text());
    urun->getUrunBilgileri().setAdeti(ui->le_Adeti->text());
    urun->getUrunBilgileri().setFiyati(ui->le_Fiyati->text());
    urun->getUrunBilgileri().setKodu(ui->le_Kodu->text());
    urun->getUrunBilgileri().setTarihi(ui->de_Tarihi->date());

    QDialog::accept();
}

void UrunBilgileriFormu::reject()
{
    QMessageBox soru;

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
    }
}

void UrunBilgileriFormu::degisiklikyapildi()
{
    u_bDegisiklikVarMi = true;
}

void UrunBilgileriFormu::on_pb_TTemizle_clicked()
{
    ui->de_Tarihi->clear();
    ui->le_Adeti->clear();
    ui->le_Adi->clear();
    ui->le_Fiyati->clear();
    ui->le_Kodu->clear();

    u_bDegisiklikVarMi = false;

    ui->le_Adi->setFocus();
}
