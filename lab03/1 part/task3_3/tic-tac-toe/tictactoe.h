#ifndef TICTACTOE_H
#define TICTACTOE_H

#include <QWidget>
#include <QPushButton>
#include <QMessageBox>



QT_BEGIN_NAMESPACE
namespace Ui {
class TicTacToe;
}
QT_END_NAMESPACE

class TicTacToe : public QWidget
{
    Q_OBJECT

public:
    TicTacToe(QWidget *parent = nullptr);
    ~TicTacToe();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();


    void on_comboBox_currentTextChanged(const QString &arg1);

    void on_pushButton_10_clicked();

private:
    Ui::TicTacToe *ui;
    QVector <QString> labels = {"X", "0"};
    size_t labelIndex = 0;
    //QVector<QVector<QPushButton*>>buttons;
    QVector<QVector<QString>>buttons;
    size_t dim = 3;
    void disableButtons();
    bool isWin();


};
#endif // TICTACTOE_H
