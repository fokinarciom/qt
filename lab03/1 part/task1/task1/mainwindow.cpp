#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::convert);
    //this->resize(300, 300);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::convert(){
    comboBoxResult1 = ui->comboBox->currentText();
    comboBoxResult2 = ui->comboBox_2->currentText();


    int baseInitial = comboBoxResult1.toInt();
    int baseResult = comboBoxResult2.toInt();

    bool isOk;

    QString input = ui->lineEdit->text();
    long n = input.toLong(&isOk, baseInitial);

    ui->lineEdit_2->setText(QString::number(n, baseResult));

}
