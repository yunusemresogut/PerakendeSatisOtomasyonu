#ifndef STOKDUZELTMEFORMU_H
#define STOKDUZELTMEFORMU_H

#include <QWidget>
#include <QObject>
#include "Frontend/stokbilgileriformu.h"

class StokDuzeltmeFormu : public StokBilgileriFormu
{
    Q_OBJECT
public:
    explicit StokDuzeltmeFormu(QWidget *parent = nullptr);

    void stokGoster(QString stokKodu);

signals:

public slots:

    virtual void accept();
};

#endif // STOKDUZELTMEFORMU_H
