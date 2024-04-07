#include "disaster.h"
#include "ui_disaster.h"
#include <QLabel>

Disaster::Disaster(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Disaster),  pressCounter(0)
{
    layout = new QHBoxLayout;
    ui->setupUi(this);
    collection.push_back("click");
    collection.push_back("oops");

}

Disaster::~Disaster()
{
    delete ui;
}

void Disaster::mousePressEvent(QMouseEvent *event){
    QLabel * label = new QLabel;
    label->setText(collection[pressCounter]);
    layout->addWidget(label);
    this->setLayout(layout);


}

void Disaster::keyPressEvent(QKeyEvent *event){
    if(event->key() == Qt::Key_Space){
        ++pressCounter;
        pressCounter %= 2;
        for(int i = 0; i < layout->count(); ++i){
            QLabel * label = qobject_cast<QLabel*>(layout->itemAt(i)->widget());
            if(label){
                label->setText(collection[pressCounter]);
            }
        }
    }
}
