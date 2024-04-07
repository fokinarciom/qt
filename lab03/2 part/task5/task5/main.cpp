#include "deservedclicker.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DeservedClicker w;
    w.show();
    return a.exec();
}
