#include "musteribilgileri.h"
#include "ui_musteribilgileri.h"

MusteriBilgileri::MusteriBilgileri(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MusteriBilgileri)
{
    ui->setupUi(this);
}

MusteriBilgileri::~MusteriBilgileri()
{
    delete ui;
}
