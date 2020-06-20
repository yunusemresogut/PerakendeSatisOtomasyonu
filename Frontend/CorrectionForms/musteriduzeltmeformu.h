#ifndef MUSTERIDUZELTMEFORMU_H
#define MUSTERIDUZELTMEFORMU_H

#include <QWidget>
#include <QObject>
#include "Frontend/musteribilgileriformu.h"

class MusteriDuzeltmeFormu : public MusteriBilgileriFormu
{
    Q_OBJECT
public:
    explicit MusteriDuzeltmeFormu(QWidget *parent = nullptr);

    void musteriGoster(QString musteriSoyadi);

signals:

public slots:

    virtual void accept();
};

#endif // MUSTERIDUZELTMEFORMU_H
