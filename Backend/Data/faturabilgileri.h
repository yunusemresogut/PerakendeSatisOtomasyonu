#ifndef FATURABILGILERI_H
#define FATURABILGILERI_H

#include <QString>
#include <QDate>

class FaturaBilgileri
{
public:
    FaturaBilgileri();

    QString getFaturaNo() const;
    void setFaturaNo(const QString &value);

    QString getGecerlilikSuresi() const;
    void setGecerlilikSuresi(const QString &value);

    QDate getTarih() const;
    void setTarih(const QDate &value);

private:
    QString u_strFaturaNo;
    QString u_strGecerlilikSuresi;
    QDate u_tarTarih;
};

#endif // FATURABILGILERI_H
