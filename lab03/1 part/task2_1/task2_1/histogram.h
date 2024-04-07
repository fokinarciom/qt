#ifndef HISTOGRAM_H
#define HISTOGRAM_H

#include <QWidget>
#include <QPainter>
#include <QLabel>
#include <vector>
#include <algorithm>
#include <QRect>
#include <QRandomGenerator>

QT_BEGIN_NAMESPACE
namespace Ui {
class Histogram;
}
QT_END_NAMESPACE

class Histogram : public QWidget
{
    Q_OBJECT

public:
    Histogram(QWidget *parent = nullptr);
    ~Histogram();
protected:
    void paintEvent(QPaintEvent *event);
    void drawHistogram(QPainter* qp);
private:
    Ui::Histogram *ui;
    //QVector<int> collection;
    std::vector<int> collection;
    //QPainter qp;
};
#endif // HISTOGRAM_H
