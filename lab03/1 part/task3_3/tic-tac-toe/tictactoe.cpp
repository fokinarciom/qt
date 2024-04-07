#include "tictactoe.h"
#include "ui_tictactoe.h"
#include <QPixmap>

TicTacToe::TicTacToe(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TicTacToe)
{
    ui->setupUi(this);
    buttons.resize(dim);
    for (size_t i = 0; i != dim; ++i){
        buttons[i].resize(dim);
    }
    /*buttons[0][0] = ui->pushButton;
    buttons[0][1] = ui->pushButton_2;
    buttons[0][2] = ui->pushButton_3;
    buttons[1][0] = ui->pushButton_4;
    buttons[1][1] = ui->pushButton_5;
    buttons[1][2] = ui->pushButton_6;
    buttons[2][0] = ui->pushButton_7;
    buttons[2][1] = ui->pushButton_8;
    buttons[2][2] = ui->pushButton_9;
*/




}

TicTacToe::~TicTacToe()
{
    delete ui;
}

void TicTacToe::on_pushButton_clicked()
{
    if(labelIndex){
    ui->pushButton->setStyleSheet("background-image: url(:/img/Новая папка/circle.png);");
    }else{
    ui->pushButton->setStyleSheet("background-image: url(:/img/Новая папка/cross1.png);");
    }
    //ui->pushButton->setText(labels[labelIndex]);

    buttons[0][0] = labels[labelIndex];
    ++labelIndex;
    labelIndex %= labels.size();
    ui->pushButton->setEnabled(false);
    if(isWin()){
        disableButtons();
    }

}


void TicTacToe::on_pushButton_2_clicked()
{
    if(labelIndex){
        ui->pushButton_2->setStyleSheet("background-image: url(:/img/Новая папка/circle.png);");
    }else{
        ui->pushButton_2->setStyleSheet("background-image: url(:/img/Новая папка/cross1.png);");
    }
    //ui->pushButton_2->setText(labels[labelIndex]);
    buttons[0][1] = labels[labelIndex];
    ++labelIndex;
    labelIndex %= labels.size();
    ui->pushButton_2->setEnabled(false);
    if(isWin()){
        disableButtons();
    }
}


void TicTacToe::on_pushButton_9_clicked()
{
    if(labelIndex){
        ui->pushButton_9->setStyleSheet("background-image: url(:/img/Новая папка/circle.png);");
    }else{
        ui->pushButton_9->setStyleSheet("background-image: url(:/img/Новая папка/cross1.png);");
    }
    //ui->pushButton_9->setText(labels[labelIndex]);
    buttons[2][2] = labels[labelIndex];
    ++labelIndex;
    labelIndex %= labels.size();
    ui->pushButton_9->setEnabled(false);
    if(isWin()){
        disableButtons();
    }
}


void TicTacToe::on_pushButton_3_clicked()
{
    if(labelIndex){
        ui->pushButton_3->setStyleSheet("background-image: url(:/img/Новая папка/circle.png);");
    }else{
        ui->pushButton_3->setStyleSheet("background-image: url(:/img/Новая папка/cross1.png);");
    }
    //ui->pushButton_3->setText(labels[labelIndex]);
    buttons[0][2] = labels[labelIndex];
    ++labelIndex;
    labelIndex %= labels.size();
    ui->pushButton_3->setEnabled(false);
    if(isWin()){
        disableButtons();
    }
}


void TicTacToe::on_pushButton_4_clicked()
{
    if(labelIndex){
        ui->pushButton_4->setStyleSheet("background-image: url(:/img/Новая папка/circle.png);");
    }else{
        ui->pushButton_4->setStyleSheet("background-image: url(:/img/Новая папка/cross1.png);");
    }
    //ui->pushButton_4->setText(labels[labelIndex]);
    buttons[1][0] = labels[labelIndex];
    ++labelIndex;
    labelIndex %= labels.size();
    ui->pushButton_4->setEnabled(false);
    if(isWin()){
        disableButtons();
    }
}


void TicTacToe::on_pushButton_5_clicked()
{
    if(labelIndex){
        ui->pushButton_5->setStyleSheet("background-image: url(:/img/Новая папка/circle.png);");
    }else{
        ui->pushButton_5->setStyleSheet("background-image: url(:/img/Новая папка/cross1.png);");
    }
    //ui->pushButton_5->setText(labels[labelIndex]);
    buttons[1][1] = labels[labelIndex];
    ++labelIndex;
    labelIndex %= labels.size();
    ui->pushButton_5->setEnabled(false);
    if(isWin()){
    disableButtons();
    }
}


void TicTacToe::on_pushButton_6_clicked()
{
    if(labelIndex){
        ui->pushButton_6->setStyleSheet("background-image: url(:/img/Новая папка/circle.png);");
    }else{
        ui->pushButton_6->setStyleSheet("background-image: url(:/img/Новая папка/cross1.png);");
    }
    //ui->pushButton_6->setText(labels[labelIndex]);
    buttons[1][2] = labels[labelIndex];
    ++labelIndex;
    labelIndex %= labels.size();
    ui->pushButton_6->setEnabled(false);
    if(isWin()){
        disableButtons();
    }
}


void TicTacToe::on_pushButton_7_clicked()
{
    if(labelIndex){
        ui->pushButton_7->setStyleSheet("background-image: url(:/img/Новая папка/circle.png);");
    }else{
        ui->pushButton_7->setStyleSheet("background-image: url(:/img/Новая папка/cross1.png);");
    }
    //ui->pushButton_7->setText(labels[labelIndex]);
    buttons[2][0] = labels[labelIndex];
    ++labelIndex;
    labelIndex %= labels.size();
    ui->pushButton_7->setEnabled(false);
    if(isWin()){
      disableButtons();
    }

}


void TicTacToe::on_pushButton_8_clicked()
{
    if(labelIndex){
        ui->pushButton_8->setStyleSheet("background-image: url(:/img/Новая папка/circle.png);");
    }else{
        ui->pushButton_8->setStyleSheet("background-image: url(:/img/Новая папка/cross1.png);");
    }
    //ui->pushButton_8->setText(labels[labelIndex]);
    buttons[2][1] = labels[labelIndex];
    ++labelIndex;
    labelIndex %= labels.size();
    ui->pushButton_8->setEnabled(false);
    if(isWin()){
       disableButtons();
    }
}

bool TicTacToe::isWin(){

    /*
    for (size_t i = 0; i != dim; ++i){ //rows cycle
        if(buttons[i][0]->text()!= ""){
        if(buttons[i][0]->text() == buttons[i][1]->text() && buttons[i][1]->text() ==  buttons[i][2]->text() ){
            QMessageBox::information(this, "Win",  buttons[i][0]->text() + "'s win!");
            return true;
        }
        }
    }
    for (size_t i = 0; i != dim; ++i){ //columns cycle
        if(buttons[0][i]->text()!= ""){


        if(buttons[0][i]->text() == buttons[1][i]->text() && buttons[1][i]->text() ==  buttons[2][i]->text() ){
            QMessageBox::information(this, "Win",  buttons[0][i]->text() + "'s win!");
            return true;
        }

        }
    }

     //diagonal


            if(buttons[0][0]->text()!= "" && buttons[0][0]->text() == buttons[1][1]->text() && buttons[1][1]->text() ==  buttons[2][2]->text() ){
                QMessageBox::information(this, "Win",  buttons[0][0]->text() + "'s win!");
                return true;
            }

            if(buttons[0][2]->text()!= "" && buttons[0][2]->text() == buttons[1][1]->text() && buttons[1][1]->text() ==  buttons[2][0]->text() ){
                QMessageBox::information(this, "Win",  buttons[0][2]->text() + "'s win!");
                return true;
            }
            return false;

     */


    for (size_t i = 0; i != dim; ++i){ //rows cycle
        if(buttons[i][0]!= ""){
            if(buttons[i][0] == buttons[i][1] && buttons[i][1] ==  buttons[i][2]){
                QMessageBox::information(this, "Win",  buttons[i][0] + "'s win!");
                return true;
            }
        }
    }
    for (size_t i = 0; i != dim; ++i){ //columns cycle
        if(buttons[0][i]!= ""){


            if(buttons[0][i]== buttons[1][i] && buttons[1][i] ==  buttons[2][i]){
                QMessageBox::information(this, "Win",  buttons[0][i] + "'s win!");
                return true;
            }

        }
    }

    //diagonal


    if(buttons[0][0]!= "" && buttons[0][0] == buttons[1][1] && buttons[1][1] ==  buttons[2][2] ){
        QMessageBox::information(this, "Win",  buttons[0][0] + "'s win!");
        return true;
    }

    if(buttons[0][2]!= "" && buttons[0][2] == buttons[1][1] && buttons[1][1] ==  buttons[2][0]){
        QMessageBox::information(this, "Win",  buttons[0][2] + "'s win!");
        return true;
    }
    return false;

}

void TicTacToe::disableButtons(){
    ui->pushButton->setEnabled(false);
    ui->pushButton_2->setEnabled(false);
    ui->pushButton_3->setEnabled(false);
    ui->pushButton_4->setEnabled(false);
    ui->pushButton_5->setEnabled(false);
    ui->pushButton_6->setEnabled(false);
    ui->pushButton_7->setEnabled(false);
    ui->pushButton_8->setEnabled(false);
    ui->pushButton_9->setEnabled(false);
}

void TicTacToe::on_comboBox_currentTextChanged(const QString &arg1)
{
    if(arg1 == "X"){
        labelIndex = 0;
    }else{
        labelIndex = 1;
    }
}


void TicTacToe::on_pushButton_10_clicked()
{
    this->~TicTacToe();

    TicTacToe* w1= new TicTacToe;
    w1->show();

}

