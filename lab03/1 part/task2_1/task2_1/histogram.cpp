#include "histogram.h"
#include "ui_histogram.h"


Histogram::Histogram(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Histogram)
{
    ui->setupUi(this);
    int amountOfElements = QRandomGenerator::global()->bounded(20);
    collection.resize(amountOfElements);
    for(size_t i = 0; i != amountOfElements; ++i){
        collection[i] = QRandomGenerator::global()->bounded(1, 500);
    }



    QPalette pal;// = QPalette();
    QColor color;
    color.setRgb(QRandomGenerator::global()->bounded(147, 247), QRandomGenerator::global()->bounded(147, 247), QRandomGenerator::global()->bounded(147, 247));
    pal.setColor(QPalette::Window, color);

    this->setAutoFillBackground(true);
    this->setPalette(pal);


}

void Histogram::paintEvent(QPaintEvent *event){
    Q_UNUSED(event);
    QPainter qp(this);
    qp.fillRect(rect(), Qt::Dense7Pattern);
    drawHistogram(&qp);
}
Histogram::~Histogram()
{
    delete ui;
}

void Histogram::drawHistogram(QPainter *qp){
    //QRect rect(100, 100, 50, 20);
    //qp->fillRect(rect, Qt::blue);

    int width = (this->x())/(collection.size());
    int X = this->x()/(collection.size()-1) ;
    int curX = 0;
    int Y = *(std::max_element(begin(collection), end(collection))) + 10;
    for(int i = 0; i != collection.size(); ++i){

        //QRect* rect = new QRect(curX, Y, width, -collection[i]);
        QRect rect(curX, Y, width, -collection[i]);

        QColor color;
        color.setRgb(QRandomGenerator::global()->bounded(256), QRandomGenerator::global()->bounded(256), QRandomGenerator::global()->bounded(256));
        qp->fillRect(rect, color);
        QLabel* label = new QLabel(QString::number(collection[i]), this);
        label->resize(width/2, width/3);
        label->adjustSize();
        label->move(rect.center().x() - label->width() / 2, Y);
        label->show();
        curX += X;
    }


    //this->setFixedWidth(curX);
    this->setMaximumWidth(curX);


}


