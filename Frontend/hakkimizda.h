#ifndef HAKKIMIZDA_H
#define HAKKIMIZDA_H

#include <QDialog>

namespace Ui {
class Hakkimizda;
}

class Hakkimizda : public QDialog
{
    Q_OBJECT

public:
    explicit Hakkimizda(QWidget *parent = 0);
    ~Hakkimizda();

private:
    Ui::Hakkimizda *ui;
};

#endif // HAKKIMIZDA_H
