#include "urunaramaformu.h"
#include "ui_urunaramaformu.h"

UrunAramaFormu::UrunAramaFormu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UrunAramaFormu)
{
    ui->setupUi(this);
}

UrunAramaFormu::~UrunAramaFormu()
{
    delete ui;
}
