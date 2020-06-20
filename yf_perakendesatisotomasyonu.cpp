#include "yf_perakendesatisotomasyonu.h"
#include "ui_yf_perakendesatisotomasyonu.h"

#include "Backend/veritabani.h"
#include "Frontend/urunbilgileriformu.h"
#include "Frontend/stokbilgileriformu.h"
#include "Frontend/hakkimizda.h"
#include "Frontend/yardim.h"
#include "Frontend/faturabilgileriformu.h"
#include "Frontend/musteribilgileriformu.h"

#include "Frontend/SearchForms/stokaramaformu.h"
#include "Frontend/SearchForms/musteriaramaformu.h"
#include "Frontend/SearchForms/faturaaramaformu.h"

#include <QMessageBox>

YF_PerakendeSatisOtomasyonu::YF_PerakendeSatisOtomasyonu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::YF_PerakendeSatisOtomasyonu)
{
    ui->setupUi(this);
    VeriTabani::getNesne()->yukle();
}

YF_PerakendeSatisOtomasyonu::~YF_PerakendeSatisOtomasyonu()
{
    delete ui;
    VeriTabani::getNesne()->sakla();
}

void YF_PerakendeSatisOtomasyonu::on_action_r_n_Bilgilerini_G_ncelle_triggered()
{
    UrunBilgileriFormu form;
    form.exec();
}

void YF_PerakendeSatisOtomasyonu::on_actionStok_Ekle_triggered()
{
    StokBilgileriFormu form;
    form.exec();
}

void YF_PerakendeSatisOtomasyonu::on_actionStok_Arama_triggered()
{
    StokAramaFormu form;
    form.exec();
}

void YF_PerakendeSatisOtomasyonu::on_actionHakk_m_zda_triggered()
{
    Hakkimizda form;
    form.exec();
}

void YF_PerakendeSatisOtomasyonu::on_actionYard_m_triggered()
{
    Yardim form;
    form.exec();
}

void YF_PerakendeSatisOtomasyonu::on_actionM_steri_Arama_triggered()
{
    MusteriAramaFormu form;
    form.exec();
}

void YF_PerakendeSatisOtomasyonu::on_actionFatura_Arama_triggered()
{
    FaturaAramaFormu form;
    form.exec();
}

void YF_PerakendeSatisOtomasyonu::on_actionFatura_Ekle_triggered()
{
    FaturaBilgileriFormu form;
    form.exec();
}

void YF_PerakendeSatisOtomasyonu::on_actionM_steri_Ekle_triggered()
{
    MusteriBilgileriFormu form;
    form.exec();
}
