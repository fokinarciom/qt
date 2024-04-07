#include "button.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QWidget window;
    window.resize(400, 300);

    Button *button = new Button(&window);
    button->setText("Press Me");
    button->resize(100, 50);
    button->move(150, 100);

    window.show();
    return a.exec();
}
