#include "yardim.h"
#include "ui_yardim.h"

Yardim::Yardim(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Yardim)
{
    ui->setupUi(this);
}

Yardim::~Yardim()
{
    delete ui;
}
