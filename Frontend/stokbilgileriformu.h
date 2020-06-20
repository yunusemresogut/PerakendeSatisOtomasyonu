#ifndef STOKBILGILERIFORMU_H
#define STOKBILGILERIFORMU_H

#include <QDialog>

#include "Backend/DataAccess/stokverierisimi.h"

namespace Ui {
class StokBilgileriFormu;
}

class StokBilgileriFormu : public QDialog
{
    Q_OBJECT

public:
    explicit StokBilgileriFormu(QWidget *parent = 0);
    ~StokBilgileriFormu();

    void gorselGuncelle();
    
    void veriGuncelle();

public slots:
    void degisiklikvar();

    virtual void accept();
    virtual void reject();

private slots:
    void on_pb_TTemizle_clicked();

protected:
    Ui::StokBilgileriFormu *ui;

    StokVeriErisimi::Pointer u_ptrStok;

    bool u_bDegisiklikVarMi;
};

#endif // STOKBILGILERIFORMU_H
