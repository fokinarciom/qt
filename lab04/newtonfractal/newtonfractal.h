#ifndef NEWTONFRACTAL_H
#define NEWTONFRACTAL_H

#include <QMainWindow>
#include <QPainter>
#include <complex>


QT_BEGIN_NAMESPACE
namespace Ui {
class NewtonFractal;
}
QT_END_NAMESPACE

class NewtonFractal : public QMainWindow
{
    Q_OBJECT

public:
    NewtonFractal(QWidget *parent = nullptr);
    ~NewtonFractal();
protected:
    void paintEvent(QPaintEvent *event) override;
private:
    Ui::NewtonFractal *ui;
};
#endif // NEWTONFRACTAL_H




