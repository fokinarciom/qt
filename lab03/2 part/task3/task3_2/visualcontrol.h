#ifndef VISUALCONTROL_H
#define VISUALCONTROL_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class VisualControl;
}
QT_END_NAMESPACE

class VisualControl : public QWidget
{
    Q_OBJECT

public:
    VisualControl(QWidget *parent = nullptr);
    ~VisualControl();
private slots:
    void on_checkBox_toggled(bool checked);
    void on_checkBox_2_toggled(bool checked);
    void on_checkBox_3_toggled(bool checked);
    void on_checkBox_4_toggled(bool checked);
    void on_checkBox_5_toggled(bool checked);

private:
    Ui::VisualControl *ui;
};
#endif // VISUALCONTROL_H
