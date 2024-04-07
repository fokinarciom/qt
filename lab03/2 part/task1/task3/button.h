#ifndef BUTTON_H
#define BUTTON_H

#include <QWidget>
#include <QPushButton>
#include <QMouseEvent>
#include <QRandomGenerator>


class Button : public QPushButton
{
public:
    Button(QWidget *parent = nullptr);
protected:
    void enterEvent(QEvent *event) override;

private slots:
    void changeColor();

private:
    QString generateRandomStyle();
    QString getRandomColor();
    void moveButton();
};

#endif // BUTTON_H
