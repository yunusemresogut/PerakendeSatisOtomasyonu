#include "faturaaramaformu.h"
#include "ui_faturaaramaformu.h"

#include "Backend/veritabani.h"

#include <QTableWidgetItem>
#include <QPushButton>
#include <QMessageBox>

#include "Frontend/CorrectionForms/faturaduzeltmeformu.h"

FaturaAramaFormu::FaturaAramaFormu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FaturaAramaFormu)
{
    ui->setupUi(this);

    ui->pb_AraF->click();
}

FaturaAramaFormu::~FaturaAramaFormu()
{
    delete ui;
}

void FaturaAramaFormu::on_pb_AraF_clicked()
{
    FaturaVeriErisimi::AramaTuru tur;
    if (ui->rb_IleBaslayanF->isChecked()){
        tur = FaturaVeriErisimi::IleBaslayan;
    }
    if (ui->rb_IcerenF->isChecked()){
        tur = FaturaVeriErisimi::Iceren;
    }
    if (ui->rb_IleBitenF->isChecked()){
        tur = FaturaVeriErisimi::IleBiten;
    }
    auto faturaListesi = VeriTabani::getNesne()->getFaturaErisim().gecerlilikSuresiGoreFaturaBul(ui->le_AramaYeriF->text(), tur);

    ui->tableWidget->setRowCount(faturaListesi.size());

    int satir = 0;

    for (auto fatura : faturaListesi){
        QString faturaNo = fatura->getFaturaNo();
        QString gecerlilikSuresi = fatura->getGecerlilikSuresi();
        QDate tarih = fatura->getTarih();

        QTableWidgetItem *faturaHucresi = new QTableWidgetItem;
        faturaHucresi->setText(faturaNo);
        ui->tableWidget->setItem(satir, 0, faturaHucresi);

        QTableWidgetItem *sureHucresi = new QTableWidgetItem;
        sureHucresi->setText(gecerlilikSuresi);
        ui->tableWidget->setItem(satir, 1, sureHucresi);

        QTableWidgetItem *tarihHucresi = new QTableWidgetItem;
        tarihHucresi->setText(tarih.toString());
        ui->tableWidget->setItem(satir, 2, tarihHucresi);

        QPushButton *silmeButonu = new QPushButton(ui->tableWidget);
        silmeButonu->setText(tr("Fatura Sil"));

        ui->tableWidget->setCellWidget(satir, 3, silmeButonu);

        auto silmeButonuFonksiyonu = [this, faturaNo, gecerlilikSuresi](){
            auto cevap = QMessageBox::question(this, tr("Uyarı"), tr("'%1' adındaki Fatura silme işlemini gerçekleştirmek ister misiniz?").arg(faturaNo));
            if (cevap == QMessageBox::Yes){
                VeriTabani::getNesne()->getFaturaErisim().faturaSil(faturaNo);
                this->ui->pb_AraF->click();
            }
        };

        connect(silmeButonu, &QPushButton::clicked, silmeButonuFonksiyonu);

        QPushButton *duzenleButonu = new QPushButton(ui->tableWidget);
        duzenleButonu->setText(tr("Fatura Düzelt"));

        ui->tableWidget->setCellWidget(satir, 4, duzenleButonu);

        auto duzeltmeButonuFonksiyonu = [gecerlilikSuresi, this](){
            FaturaDuzeltmeFormu form;

            form.faturaGoster(gecerlilikSuresi);

            auto sonuc = form.exec();

            if (sonuc == QDialog::Accepted){
                this->ui->pb_AraF->click();
            }
        };

        connect(duzenleButonu, &QPushButton::clicked, duzeltmeButonuFonksiyonu);

        satir++;


    }

}

void FaturaAramaFormu::on_le_AramaYeriF_textChanged(const QString &arg1)
{
    if (ui->cb_YazarkenAraF->isChecked()){
        ui->pb_AraF->click();
    }
}
