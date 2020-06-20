#ifndef MUSTERIBILGILERI_H
#define MUSTERIBILGILERI_H

#include <QString>

class MusteriBilgileri
{
public:
    MusteriBilgileri();

    QString getMAdi() const;
    void setMAdi(const QString &value);

    QString getMSoyadi() const;
    void setMSoyadi(const QString &value);

    QString getMTC() const;
    void setMTC(const QString &value);

    QString getTelNo() const;
    void setTelNo(const QString &value);

    QString getTahsilat() const;
    void setTahsilat(const QString &value);

private:
    QString u_strMAdi;
    QString u_strMSoyadi;
    QString u_strMTC;
    QString u_strTelNo;
    QString u_strTahsilat;
};

#endif // MUSTERIBILGILERI_H
