 #include "button.h"
#include <QRandomGenerator>
void Button::changeColor(){
    QString randomStyle = generateRandomStyle();
    setStyleSheet(randomStyle);
}
QString Button::generateRandomStyle() {
    // Example: Random background color and text color
    QString styleSheet = "background-color: " + getRandomColor() + "; color: " + getRandomColor() + ";";

    return styleSheet;
}

QString Button::getRandomColor() {
    // Generate a random RGB color
    return QString("rgb(%1, %2, %3)").arg(QRandomGenerator::global()->bounded(256))
        .arg(QRandomGenerator::global()->bounded(256))
        .arg(QRandomGenerator::global()->bounded(256));
}


void Button::moveButton()
{
    int maxX = parentWidget()->width() - width();
    int maxY = parentWidget()->height() - height();

    int newX = QRandomGenerator::global()->bounded(maxX);
    int newY = QRandomGenerator::global()->bounded(maxY);

    move(newX, newY);
}

void Button::enterEvent(QEvent *event)
{
    moveButton();
}


Button::Button(QWidget *parent) : QPushButton(parent)
{
    setMouseTracking(true); // Enable tracking for mouse move events
    connect(this, &QPushButton::clicked, this, &Button::changeColor);
}
