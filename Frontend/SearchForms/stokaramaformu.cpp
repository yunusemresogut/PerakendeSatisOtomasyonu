#include "stokaramaformu.h"
#include "ui_stokaramaformu.h"

#include "Backend/veritabani.h"
#include <QTableWidgetItem>

#include <QPushButton>
#include <QMessageBox>

#include "Frontend/CorrectionForms/stokduzeltmeformu.h"

StokAramaFormu::StokAramaFormu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StokAramaFormu)
{
    ui->setupUi(this);

    ui->pb_Ara->click();
}

StokAramaFormu::~StokAramaFormu()
{
    delete ui;
}

void StokAramaFormu::on_pb_Ara_clicked()
{
    StokVeriErisimi::AramaTuru tur;

    if (ui->rb_IleBaslayan->isChecked()){
        tur = StokVeriErisimi::IleBaslayan;
    }
    if (ui->rb_Iceren->isChecked()){
        tur = StokVeriErisimi::Iceren;
    }
    if (ui->rb_IleBiten->isChecked()){
        tur = StokVeriErisimi::IleBiten;
    }
    auto stokListesi = VeriTabani::getNesne()->getStokErisim().adaGoreStokBul(ui->le_AramaYeri->text(), tur);

    ui->tableWidget->setRowCount(stokListesi.size());

    int satir = 0;

    for (auto stok : stokListesi){
        QString stokAdi = stok->getStokAdi();
        QString stokKodu = stok->getStokKodu();
        QString Adeti = stok->getUrunBilgileri().getAdeti();
        QDate Tarihi = stok->getUrunBilgileri().getTarihi();
        QString Fiyati = stok->getUrunBilgileri().getFiyati();

        QTableWidgetItem *adHucresi = new QTableWidgetItem;
        adHucresi->setText(stokAdi);
        ui->tableWidget->setItem(satir, 0, adHucresi);

        QTableWidgetItem *kodHucresi = new QTableWidgetItem;
        kodHucresi->setText(stokKodu);
        ui->tableWidget->setItem(satir, 1, kodHucresi);

        QTableWidgetItem *adetHucresi = new QTableWidgetItem;
        adetHucresi->setText(Adeti);
        ui->tableWidget->setItem(satir, 2, adetHucresi);

        QTableWidgetItem *tarihHucresi = new QTableWidgetItem;
        tarihHucresi->setText(Tarihi.toString());
        ui->tableWidget->setItem(satir, 3, tarihHucresi);

        QTableWidgetItem *fiyatHucresi = new QTableWidgetItem;
        fiyatHucresi->setText(Fiyati);
        ui->tableWidget->setItem(satir, 4, fiyatHucresi);

        QPushButton *silmeButonu = new QPushButton(ui->tableWidget);
        silmeButonu->setText(tr("Ürün Sil"));

        ui->tableWidget->setCellWidget(satir, 5, silmeButonu);

        auto silmeButonuFonksiyonu = [this, stokAdi, stokKodu](){
            auto cevap = QMessageBox::question(this, tr("Uyarı"), tr("'%1' adındaki Ürün silme işlemini gerçekleştirmek ister misiniz?").arg(stokAdi));
            if (cevap == QMessageBox::Yes){
                VeriTabani::getNesne()->getStokErisim().stokSil(stokKodu);
                this->ui->pb_Ara->click();
            }
        };

        connect(silmeButonu, &QPushButton::clicked, silmeButonuFonksiyonu);

        QPushButton *duzenleButonu = new QPushButton(ui->tableWidget);
        duzenleButonu->setText(tr("Ürün Düzelt"));

        ui->tableWidget->setCellWidget(satir, 6, duzenleButonu);

        auto duzeltmeButonuFonksiyonu = [stokKodu, this](){
            StokDuzeltmeFormu form;

            form.stokGoster(stokKodu);

            auto sonuc = form.exec();

            if (sonuc == QDialog::Accepted){
                this->ui->pb_Ara->click();
            }
        };

        connect(duzenleButonu, &QPushButton::clicked, duzeltmeButonuFonksiyonu);

        satir++;


    }
}

void StokAramaFormu::on_le_AramaYeri_textChanged(const QString &arg1)
{
    if (ui->cb_YazarkenAra->isChecked()){
        ui->pb_Ara->click();
    }
}
