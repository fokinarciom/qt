#ifndef DESERVEDCLICKER_H
#define DESERVEDCLICKER_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class DeservedClicker;
}
QT_END_NAMESPACE

class DeservedClicker : public QWidget
{
    Q_OBJECT

public:
    DeservedClicker(QWidget *parent = nullptr);
    ~DeservedClicker();
private slots:
    void on_pushButton_clicked();
    void on_spinBox_valueChanged(int arg1);
private:
    Ui::DeservedClicker *ui;
};
#endif // DESERVEDCLICKER_H
