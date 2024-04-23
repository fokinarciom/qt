#include "snowflake.h"
#include "ui_snowflake.h"
#include <QtMath>

Snowflake::Snowflake(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Snowflake)
{
    ui->setupUi(this);
    this->resize(400, 400);
}

Snowflake::~Snowflake()
{
    delete ui;
}


void Snowflake::drawKochSnowflake(QPainter &painter, const QPoint &p1, const QPoint &p2, int depth) {
    if (depth == 0) {
        painter.drawLine(p1, p2);
        return;
    }

    QPoint p3 = p1 + (p2 - p1) / 3;
    QPoint p5 = p1 + 2 * (p2 - p1) / 3;

    // Calculate the third point of the equilateral triangle
    double angle = M_PI / 3;
    QPoint p4 = p3 + QPoint((p5.x() - p3.x()) * cos(angle) - (p5.y() - p3.y()) * sin(angle),
                            (p5.x() - p3.x()) * sin(angle) + (p5.y() - p3.y()) * cos(angle));

    // Recursively draw the sub-segments
    drawKochSnowflake(painter, p1, p3, depth - 1);
    drawKochSnowflake(painter, p3, p4, depth - 1);
    drawKochSnowflake(painter, p4, p5, depth - 1);
    drawKochSnowflake(painter, p5, p2, depth - 1);
}

void Snowflake::paintEvent(QPaintEvent *event){
    Q_UNUSED(event);

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    // Define the triangle points
    int side = qMin(width(), height()) * 0.8; // Use 80% of the minimum dimension
    int heightOffset = height() / 2 + sqrt(3) * side / 6;
    QPoint p1(width() / 2, height() / 2 - side / 2);
    QPoint p2(width() / 2 - side / 2, heightOffset);
    QPoint p3(width() / 2 + side / 2, heightOffset);

    // Draw the Koch snowflake
    drawKochSnowflake(painter, p1, p2, 5);
    drawKochSnowflake(painter, p2, p3, 5);
    drawKochSnowflake(painter, p3, p1, 5);
}
