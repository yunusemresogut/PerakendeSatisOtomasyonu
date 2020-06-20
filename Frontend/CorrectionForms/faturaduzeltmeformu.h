#ifndef FATURADUZELTMEFORMU_H
#define FATURADUZELTMEFORMU_H

#include <QWidget>
#include <QObject>
#include "Frontend/faturabilgileriformu.h"

class FaturaDuzeltmeFormu : public FaturaBilgileriFormu
{
    Q_OBJECT
public:
    explicit FaturaDuzeltmeFormu(QWidget *parent = nullptr);

    void faturaGoster(QString faturaNo);

signals:

public slots:

    virtual void accept();
};

#endif // FATURADUZELTMEFORMU_H
