#include "hakkimizda.h"
#include "ui_hakkimizda.h"

Hakkimizda::Hakkimizda(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Hakkimizda)
{
    ui->setupUi(this);
}

Hakkimizda::~Hakkimizda()
{
    delete ui;
}
