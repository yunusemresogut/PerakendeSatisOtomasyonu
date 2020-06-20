#ifndef MUSTERIBILGILERI_H
#define MUSTERIBILGILERI_H

#include <QDialog>

namespace Ui {
class MusteriBilgileri;
}

class MusteriBilgileri : public QDialog
{
    Q_OBJECT

public:
    explicit MusteriBilgileri(QWidget *parent = 0);
    ~MusteriBilgileri();

private:
    Ui::MusteriBilgileri *ui;
};

#endif // MUSTERIBILGILERI_H
