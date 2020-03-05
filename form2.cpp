#include "form2.h"
#include "ui_form2.h"

Form2::Form2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form2)
{
    ui->setupUi(this);
    layout->addWidget(f1);
    layout->addWidget(f2);
    this->setLayout(layout);
    layout->setStretchFactor(f1, 3.5);
    layout->setStretchFactor(f2, 1);
}
void Form2::resizeEvent(QResizeEvent *event){
    int x=event->size().width();
    int y=event->size().height();
    this->resize(x,y);
}

Form2::~Form2()
{
    delete ui;
}
