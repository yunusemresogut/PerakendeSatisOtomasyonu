#include "yf_perakendesatisotomasyonu.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    YF_PerakendeSatisOtomasyonu w;
    w.show();

    return a.exec();
}
