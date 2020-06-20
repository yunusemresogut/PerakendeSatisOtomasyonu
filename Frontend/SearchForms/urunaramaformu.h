#ifndef URUNARAMAFORMU_H
#define URUNARAMAFORMU_H

#include <QDialog>

namespace Ui {
class UrunAramaFormu;
}

class UrunAramaFormu : public QDialog
{
    Q_OBJECT

public:
    explicit UrunAramaFormu(QWidget *parent = 0);
    ~UrunAramaFormu();

private:
    Ui::UrunAramaFormu *ui;
};

#endif // URUNARAMAFORMU_H
