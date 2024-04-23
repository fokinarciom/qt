#ifndef FRACTAL_H
#define FRACTAL_H

#include <QWidget>
#include <QVector>
#include <QColor>
#include <QtCore>
#include <QPainter>

QT_BEGIN_NAMESPACE
namespace Ui {
class Fractal;
}
QT_END_NAMESPACE

class Fractal : public QWidget
{
    Q_OBJECT

public:
    Fractal(QWidget *parent = nullptr);
    ~Fractal();
private slots:
    void paintEvent (QPaintEvent * );
private:
    Ui::Fractal *ui;
    int dots_;
    void dotsColorInit();
    void fillPlazma(int&, int&, int&, int&);
    int delta = 100;
    QVector<QVector<QColor>> plazma_;
};
#endif // FRACTAL_H
