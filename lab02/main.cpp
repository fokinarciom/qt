#include <QCoreApplication>
#include <QString>
#include <QSet>
#include <QTextStream>
#include <QMap>
#include <QSet>
#include <QChar>
#include <algorithm>
#include "Command.h"
#include "Invoker.h"


int main(int argc, char *argv[])
{

    QTextStream out(stdout);
    QTextStream in(stdin);


    QVector<int> vec {174, 186, 198};
    Invoker inv(vec);
    inv.executeTask();


 }



