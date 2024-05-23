#include "app.h"
#include "ui_app.h"

App::App(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::App)
{
    ui->setupUi(this);
    this->resize(1920, 1080);

    QMenu* file;
    file = menuBar()->addMenu("&File");
    QAction * about = new QAction("&About", this);
    file->addAction(about);
    connect(about, &QAction::triggered, this, &App::on_actionAbout_triggered);
    QAction * color = new QAction("&Select Color", this);
    file->addAction(color);
    connect(color, &QAction::triggered, this, &App::getColor);
    QAction * quit = new QAction("&Quit", this);
    file->addAction(quit);
    connect(quit, &QAction::triggered, qApp, QApplication::quit);
    //ui->graphicsView->lower();
    //ui->graphicsView->setEnabled(false);
    ui->radioButton->setChecked(true);
    ui->frame->resize(400, 1080);

}


void App::mousePressEvent(QMouseEvent* event){
    //centerOfCircle_ = event->globalPos();
    centerOfCircle_ = QPoint(event->x() - 400, event->y());

}


App::~App()
{
    delete ui;
}

void App::on_actionAbout_triggered()
{
    QMessageBox::information(this, "О проекте", "Фокин Артём, 11 вариант");
}


void App::on_textEdit_textChanged()
{


    firstPointOfSegment_.setX(ui->textEdit->toPlainText().toInt());
    //ui->textEdit->setEnabled(false);
}


void App::on_textEdit_2_textChanged()
{


    firstPointOfSegment_.setY(ui->textEdit_2->toPlainText().toInt());
    //ui->textEdit_2->setEnabled(false);
}


void App::on_textEdit_3_textChanged()
{
    secondPointOfSegment_.setX(ui->textEdit_3->toPlainText().toInt());
    //ui->textEdit_3->setEnabled(false);
}


void App::on_textEdit_4_textChanged()
{


    secondPointOfSegment_.setY(ui->textEdit_4->toPlainText().toInt());
    //ui->textEdit_4->setEnabled(false);
}


void App::on_spinBox_valueChanged(int arg1)
{
    radius_ = arg1;
}


void App::paintEvent(QPaintEvent *event){
    Q_UNUSED(event);
    QPainter qp(this);
    qp.translate(400, 0);

    qp.fillRect(0, 0, 1520, 1080, QGradient::CleanMirror);

    drawLine(&qp);
    drawCircle(&qp);

}

void App::drawLine(QPainter *qp){
    QString tmp = ui->comboBox->currentText();
    QString str = "";

    for  (auto i : tmp){
        if(i.isDigit()){
            str += i;
        }else{
            break;
        }
    }
    qp->setPen(QPen(colorOfPen_, str.toInt(), Qt::SolidLine, Qt::RoundCap));


    qp->drawLine(firstPointOfSegment_, secondPointOfSegment_);

}
void App::drawCircle(QPainter *qp){

    qp->setBrush(colorOfFill_);


    qp->drawEllipse(centerOfCircle_, radius_, radius_);
}

void App::on_pushButton_pressed()
{
    update();
    //analyseInterposition(QLineF(firstPointOfSegment_, secondPointOfSegment_), centerOfCircle_, radius_);
    findIntersections(QLine(firstPointOfSegment_, secondPointOfSegment_), centerOfCircle_, radius_);
}


void App::getColor() {


    QString colorOfPen = QInputDialog::getText(this, tr("Enter the color"),
                                         tr("Color:"), QLineEdit::Normal,
                                         "");

    if(colorOfPen == "red"){
        colorOfPen_ = Qt::red;
   } else if(colorOfPen == "green"){
        colorOfPen_ = Qt::green;
   }else if(colorOfPen == "blue"){
          colorOfPen_ = Qt::blue;
    }else if(colorOfPen == "yellow"){
         colorOfPen_ = Qt::yellow;
    }else{
        colorOfPen_ = Qt::black;
    }

}

void App::on_radioButton_pressed()
{
    colorOfFill_ = Qt::red;
}


void App::on_radioButton_2_pressed()
{
    colorOfFill_ = Qt::blue;
}


void App::on_radioButton_3_pressed()
{
    colorOfFill_ = Qt::yellow;
}



void App::findIntersections(const QLine &line, const QPoint &center, int radius)
{
    double dx = line.dx();
    double dy = line.dy();


    double A = dy;
    double B = -dx;
    double C = dx * line.y1() - dy * line.x1();

    double h = center.x();
    double k = center.y();
    double r = radius;


    double distance = qAbs(A * h + B * k + C) / qSqrt(A * A + B * B);


    double d1 = qSqrt(qPow(line.x1() - h, 2) + qPow(line.y1() - k, 2));
    double d2 = qSqrt(qPow(line.x2() - h, 2) + qPow(line.y2() - k, 2));


    if (distance <= r)
    {

        if (d1 <= r && d2 <= r)
        {
            QMessageBox::information(this, "Info about interposition", "The line is inside the circle.");
        }

        else {
            bool flag = true;




            if( ((line.y1() < k and   line.y2() < k) or (line.y1() > k and   line.y2() > k)) or
                 ((line.x1() < h and   line.x2() < h) or (line.x1() > h and   line.x2() > h)) ){
                //QMessageBox::information(this, "Info about interposition", "The line and the circle do not intersect.");
                flag = false;
                if((((line.x1() - h) * (line.x1() - h) + (line.y1() - k) * (line.y1() - k) <= r * r ) or ((line.x2() - h) * (line.x2() - h) + (line.y2() - k) * (line.y2() - k) <= r * r ))){
                    flag =true;
}

            }
            if(flag){
                   QMessageBox::information(this, "Info about interposition", "There is(are) intersection(s).");
            }else{
                QMessageBox::information(this, "Info about interposition", "The line and the circle do not intersect.");

            }

    }
    }else
    {
        QMessageBox::information(this, "Info about interposition", "The line and the circle do not intersect.");
    }
}








