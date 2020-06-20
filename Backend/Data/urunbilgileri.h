#ifndef URUNBILGILERI_H
#define URUNBILGILERI_H

#include <QString>
#include <QDate>

class UrunBilgileri
{
public:
    UrunBilgileri();

    QString getAdi() const;
    void setAdi(const QString &value);

    QString getKodu() const;
    void setKodu(const QString &value);

    QString getAdeti() const;
    void setAdeti(const QString &value);

    QString getFiyati() const;
    void setFiyati(const QString &value);

    QDate getTarihi() const;
    void setTarihi(const QDate &value);

private:
    QString u_strAdi;
    QString u_strKodu;
    QString u_strAdeti;
    QString u_strFiyati;
    QDate u_tarTarihi;
};

#endif // URUNBILGILERI_H
