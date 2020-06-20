#include "musteriaramaformu.h"
#include "ui_musteriaramaformu.h"

#include "Backend/veritabani.h"

#include <QTableWidgetItem>
#include <QPushButton>
#include <QMessageBox>

#include "Frontend/CorrectionForms/musteriduzeltmeformu.h"


MusteriAramaFormu::MusteriAramaFormu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MusteriAramaFormu)
{
    ui->setupUi(this);

    ui->pb_AraM->click();
}

MusteriAramaFormu::~MusteriAramaFormu()
{
    delete ui;
}

void MusteriAramaFormu::on_pb_AraM_clicked()
{
    MusteriVeriErisimi::AramaTuru tur;
    if (ui->rb_IleBaslayanM->isChecked()){
        tur = MusteriVeriErisimi::IleBaslayan;
    }
    if (ui->rb_IcerenM->isChecked()){
        tur = MusteriVeriErisimi::Iceren;
    }
    if (ui->rb_IleBitenM->isChecked()){
        tur = MusteriVeriErisimi::IleBiten;
    }
    auto musteriListesi = VeriTabani::getNesne()->getMusteriErisim().soyadGoreMusteriBul(ui->le_AramaYeriM->text(), tur);

    ui->tableWidget->setRowCount(musteriListesi.size());

    int satir = 0;

    for (auto musteri : musteriListesi){
        QString musteriAdi = musteri->getMAdi();
        QString musteriSoyadi = musteri->getMSoyadi();
        QString musteriTC = musteri->getMTC();
        QString musteriTelNo = musteri->getTelNo();
        QString musteriTahsilat = musteri->getTahsilat();

        QTableWidgetItem *adHucresi = new QTableWidgetItem;
        adHucresi->setText(musteriAdi);
        ui->tableWidget->setItem(satir, 0, adHucresi);

        QTableWidgetItem *soyadHucresi = new QTableWidgetItem;
        soyadHucresi->setText(musteriSoyadi);
        ui->tableWidget->setItem(satir, 1, soyadHucresi);

        QTableWidgetItem *tcHucresi = new QTableWidgetItem;
        tcHucresi->setText(musteriTC);
        ui->tableWidget->setItem(satir, 2, tcHucresi);

        QTableWidgetItem *telNoHucresi = new QTableWidgetItem;
        telNoHucresi->setText(musteriTelNo);
        ui->tableWidget->setItem(satir, 3, telNoHucresi);

        QTableWidgetItem *tahsilatHucresi = new QTableWidgetItem;
        tahsilatHucresi->setText(musteriTahsilat);
        ui->tableWidget->setItem(satir, 4, tahsilatHucresi);

        QPushButton *silmeButonu = new QPushButton(ui->tableWidget);
        silmeButonu->setText(tr("Müşteri Sil"));

        ui->tableWidget->setCellWidget(satir, 5, silmeButonu);

        auto silmeButonuFonksiyonu = [this, musteriAdi, musteriSoyadi](){
            auto cevap = QMessageBox::question(this, tr("Uyarı"), tr("'%1' adındaki Müşteri silme işlemini gerçekleştirmek ister misiniz?").arg(musteriAdi));
            if (cevap == QMessageBox::Yes){
                VeriTabani::getNesne()->getMusteriErisim().musteriSil(musteriAdi);
                this->ui->pb_AraM->click();
            }
        };

        connect(silmeButonu, &QPushButton::clicked, silmeButonuFonksiyonu);

        QPushButton *duzenleButonu = new QPushButton(ui->tableWidget);
        duzenleButonu->setText(tr("Müşteri Düzelt"));

        ui->tableWidget->setCellWidget(satir, 6, duzenleButonu);

        auto duzeltmeButonuFonksiyonu = [musteriTC, this](){
            MusteriDuzeltmeFormu form;

            form.musteriGoster(musteriTC);

            auto sonuc = form.exec();

            if (sonuc == QDialog::Accepted){
                this->ui->pb_AraM->click();
            }
        };

        connect(duzenleButonu, &QPushButton::clicked, duzeltmeButonuFonksiyonu);

        satir++;


    }
}

void MusteriAramaFormu::on_le_AramaYeriM_textChanged(const QString &arg1)
{
    if (ui->cb_YazarkenAraM->isChecked()){
        ui->pb_AraM->click();
    }
}
