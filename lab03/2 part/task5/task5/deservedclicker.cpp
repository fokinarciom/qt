#include "deservedclicker.h"
#include "ui_deservedclicker.h"

DeservedClicker::DeservedClicker(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::DeservedClicker)
{
    ui->setupUi(this);
    ui->pushButton->setEnabled(false);
}

DeservedClicker::~DeservedClicker()
{
    delete ui;
}


void DeservedClicker::on_pushButton_clicked(){
    if(ui->progressBar->value() == 0){
        ui->progressBar->setMaximum(ui->spinBox->value());
        ui->spinBox->setEnabled(false);
    }
    ui->progressBar->setValue(ui->progressBar->value()+1);
}
void DeservedClicker::on_spinBox_valueChanged(int arg1){
    if(ui->spinBox==0){
        ui->pushButton->setEnabled((false));
    }else{
        ui->pushButton->setEnabled((true));
    }
}
