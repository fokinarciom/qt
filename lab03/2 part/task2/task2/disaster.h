#ifndef DISASTER_H
#define DISASTER_H

#include <QWidget>
#include <QKeyEvent>
#include <QMouseEvent>
#include <QHBoxLayout>
#include <QVector>
#include <QString>

QT_BEGIN_NAMESPACE
namespace Ui {
class Disaster;
}
QT_END_NAMESPACE

class Disaster : public QWidget
{
    Q_OBJECT

public:
    Disaster(QWidget *parent = nullptr);
    ~Disaster();
private slots:
    void mousePressEvent(QMouseEvent* event) override;
    void keyPressEvent(QKeyEvent* event) override;
private:
    Ui::Disaster *ui;
    QHBoxLayout* layout;
    QVector<QString> collection;
    int pressCounter;
};
#endif // DISASTER_H
