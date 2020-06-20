#ifndef MUSTERIARAMAFORMU_H
#define MUSTERIARAMAFORMU_H

#include <QDialog>

namespace Ui {
class MusteriAramaFormu;
}

class MusteriAramaFormu : public QDialog
{
    Q_OBJECT

public:
    explicit MusteriAramaFormu(QWidget *parent = 0);
    ~MusteriAramaFormu();

private slots:
    void on_pb_AraM_clicked();

    void on_le_AramaYeriM_textChanged(const QString &arg1);

private:
    Ui::MusteriAramaFormu *ui;
};

#endif // MUSTERIARAMAFORMU_H
