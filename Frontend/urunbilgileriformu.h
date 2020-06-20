#ifndef URUNBILGILERIFORMU_H
#define URUNBILGILERIFORMU_H

#include <QDialog>

namespace Ui {
class UrunBilgileriFormu;
}

class UrunBilgileriFormu : public QDialog
{
    Q_OBJECT

public:
    explicit UrunBilgileriFormu(QWidget *parent = 0);
    ~UrunBilgileriFormu();

    virtual void accept();

    virtual void reject();

public slots:

    void degisiklikyapildi();

private slots:
    void on_pb_TTemizle_clicked();

private:
    Ui::UrunBilgileriFormu *ui;

    bool u_bDegisiklikVarMi;
};

#endif // URUNBILGILERIFORMU_H
