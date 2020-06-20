#ifndef FATURABILGILERIFORMU_H
#define FATURABILGILERIFORMU_H

#include <QDialog>

#include "Backend/DataAccess/faturaverierisimi.h"

namespace Ui {
class FaturaBilgileriFormu;
}

class FaturaBilgileriFormu : public QDialog
{
    Q_OBJECT

public:
    explicit FaturaBilgileriFormu(QWidget *parent = 0);
    ~FaturaBilgileriFormu();

    void gorselGuncelle();

    void veriGuncelle();

public slots:
    void degisiklikvar();

    virtual void accept();
    virtual void reject();

private slots:
    void on_pb_TTemizle_clicked();

protected:
    Ui::FaturaBilgileriFormu *ui;

    FaturaVeriErisimi::Pointer u_ptrFatura;

    bool u_bDegisiklikVarMi;
};

#endif // FATURABILGILERIFORMU_H
