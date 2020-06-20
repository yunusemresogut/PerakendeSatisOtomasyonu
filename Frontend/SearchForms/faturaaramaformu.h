#ifndef FATURAARAMAFORMU_H
#define FATURAARAMAFORMU_H

#include <QDialog>

namespace Ui {
class FaturaAramaFormu;
}

class FaturaAramaFormu : public QDialog
{
    Q_OBJECT

public:
    explicit FaturaAramaFormu(QWidget *parent = 0);
    ~FaturaAramaFormu();

private slots:
    void on_pb_AraF_clicked();

    void on_le_AramaYeriF_textChanged(const QString &arg1);

private:
    Ui::FaturaAramaFormu *ui;
};

#endif // FATURAARAMAFORMU_H
