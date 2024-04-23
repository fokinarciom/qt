#ifndef FERNLEAF_H
#define FERNLEAF_H

#include <QWidget>
#include <QPainter>

QT_BEGIN_NAMESPACE
namespace Ui {
class FernLeaf;
}
QT_END_NAMESPACE

class FernLeaf : public QWidget
{
    Q_OBJECT

public:
    FernLeaf(QWidget *parent = nullptr);
    ~FernLeaf();
protected:
    void paintEvent(QPaintEvent *event) override;
private:
    Ui::FernLeaf *ui;
};
#endif // FERNLEAF_H
