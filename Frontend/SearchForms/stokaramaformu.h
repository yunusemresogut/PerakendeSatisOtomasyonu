#ifndef STOKARAMAFORMU_H
#define STOKARAMAFORMU_H

#include <QDialog>

namespace Ui {
class StokAramaFormu;
}

class StokAramaFormu : public QDialog
{
    Q_OBJECT

public:
    explicit StokAramaFormu(QWidget *parent = 0);
    ~StokAramaFormu();

private slots:
    void on_pb_Ara_clicked();

    void on_le_AramaYeri_textChanged(const QString &arg1);

private:
    Ui::StokAramaFormu *ui;
};

#endif // STOKARAMAFORMU_H
