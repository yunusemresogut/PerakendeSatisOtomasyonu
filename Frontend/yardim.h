#ifndef YARDIM_H
#define YARDIM_H

#include <QDialog>

namespace Ui {
class Yardim;
}

class Yardim : public QDialog
{
    Q_OBJECT

public:
    explicit Yardim(QWidget *parent = 0);
    ~Yardim();

private:
    Ui::Yardim *ui;
};

#endif // YARDIM_H
