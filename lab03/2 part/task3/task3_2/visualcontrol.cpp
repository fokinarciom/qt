#include "visualcontrol.h"
#include "ui_visualcontrol.h"

VisualControl::VisualControl(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::VisualControl)
{
    ui->setupUi(this);
}

VisualControl::~VisualControl()
{
    delete ui;
}

void VisualControl::on_checkBox_toggled(bool checked){
    if(checked){
        ui->pushButton->hide();
    }else{
        ui->pushButton->show();
    }
}

void VisualControl::on_checkBox_2_toggled(bool checked){
    if(checked){
        ui->pushButton_2->hide();
    }else{
        ui->pushButton_2->show();
    }
}
void VisualControl::on_checkBox_3_toggled(bool checked){
    if(checked){
        ui->pushButton_3->hide();
    }else{
        ui->pushButton_3->show();
    }
}

void VisualControl::on_checkBox_4_toggled(bool checked){
    if(checked){
        ui->pushButton_4->hide();
    }else{
        ui->pushButton_4->show();
    }
}


void VisualControl::on_checkBox_5_toggled(bool checked){
    if(checked){
        ui->pushButton_5->hide();
    }else{
        ui->pushButton_5->show();
    }
}

