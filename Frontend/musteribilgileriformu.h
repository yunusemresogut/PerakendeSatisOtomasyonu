#ifndef MUSTERIBILGILERIFORMU_H
#define MUSTERIBILGILERIFORMU_H

#include <QDialog>

#include "Backend/DataAccess/musteriverierisimi.h"

namespace Ui {
class MusteriBilgileriFormu;
}

class MusteriBilgileriFormu : public QDialog
{
    Q_OBJECT

public:
    explicit MusteriBilgileriFormu(QWidget *parent = 0);
    ~MusteriBilgileriFormu();

    void gorselGuncelle();

    void veriGuncelle();

public slots:
    void degisiklikvar();

    virtual void accept();
    virtual void reject();

private slots:
    void on_pb_TTemizle_clicked();

protected:
    Ui::MusteriBilgileriFormu *ui;

    MusteriVeriErisimi::Pointer u_ptrMusteri;

    bool u_bDegisiklikVarMi;
};

#endif // MUSTERIBILGILERIFORMU_H
