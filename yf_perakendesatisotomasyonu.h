#ifndef YF_PERAKENDESATISOTOMASYONU_H
#define YF_PERAKENDESATISOTOMASYONU_H

#include <QMainWindow>

namespace Ui {
class YF_PerakendeSatisOtomasyonu;
}

class YF_PerakendeSatisOtomasyonu : public QMainWindow
{
    Q_OBJECT

public:
    explicit YF_PerakendeSatisOtomasyonu(QWidget *parent = 0);
    ~YF_PerakendeSatisOtomasyonu();

private slots:
    void on_action_r_n_Bilgilerini_G_ncelle_triggered();

    void on_actionStok_Ekle_triggered();

    void on_actionStok_Arama_triggered();

    void on_actionHakk_m_zda_triggered();

    void on_actionYard_m_triggered();

    void on_actionM_steri_Arama_triggered();

    void on_actionFatura_Arama_triggered();

    void on_actionFatura_Ekle_triggered();

    void on_actionM_steri_Ekle_triggered();

private:
    Ui::YF_PerakendeSatisOtomasyonu *ui;
};

#endif // YF_PERAKENDESATISOTOMASYONU_H
