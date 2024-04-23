#ifndef SNOWFLAKE_H
#define SNOWFLAKE_H

#include <QMainWindow>
#include <QPainter>

QT_BEGIN_NAMESPACE
namespace Ui {
class Snowflake;
}
QT_END_NAMESPACE

class Snowflake : public QMainWindow
{
    Q_OBJECT

public:
    Snowflake(QWidget *parent = nullptr);
    ~Snowflake();

protected:
    void paintEvent(QPaintEvent *event) override;


private:
    Ui::Snowflake *ui;
    void drawKochSnowflake(QPainter &painter, const QPoint &p1, const QPoint &p2, int depth);
};
#endif // SNOWFLAKE_H




