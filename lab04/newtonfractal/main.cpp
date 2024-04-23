#include "newtonfractal.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    NewtonFractal w;
    w.show();
    return a.exec();
}
