#ifndef APP_H
#define APP_H

#include <QMainWindow>
#include <QMessageBox>
#include <QInputDialog>
//#include <QGraphicsScene>
//#include <QGraphicsLineItem>
#include <QMouseEvent>
#include <QtMath>
#include <QPainter>
#include <QMenu>
#include <QMenuBar>
#include <QAction>


QT_BEGIN_NAMESPACE
namespace Ui {
class App;
}
QT_END_NAMESPACE

class App : public QMainWindow
{
    Q_OBJECT

public:
    App(QWidget *parent = nullptr);
    ~App();
private slots:
    void on_actionAbout_triggered();
    void mousePressEvent(QMouseEvent* event);

    void on_textEdit_textChanged();

    void on_textEdit_2_textChanged();

    void on_textEdit_3_textChanged();

    void on_textEdit_4_textChanged();

    void on_spinBox_valueChanged(int arg1);

    void paintEvent(QPaintEvent *event);

    void on_pushButton_pressed();

    void on_radioButton_pressed();

    void on_radioButton_2_pressed();

    void on_radioButton_3_pressed();


private:
    Ui::App *ui;
    QPoint centerOfCircle_;
    QPoint firstPointOfSegment_;
    QPoint secondPointOfSegment_;
    int radius_ = 0;
    QBrush colorOfPen_ = Qt::black;
    QBrush colorOfFill_ = Qt::red;
    void drawLine(QPainter*);
    void drawCircle(QPainter *);
    void findIntersections(const QLine &, const QPoint &, int);
    void getColor();
};
#endif // APP_H
