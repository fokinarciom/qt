#include "fernleaf.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    FernLeaf w;
    w.show();
    return a.exec();
}
