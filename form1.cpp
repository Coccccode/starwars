
#include "form1.h"
#include "ui_form1.h"
int qsmark=0;
extern int wood[5],gold[5],count[5];
Form1::Form1(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form1)
{
    ui->setupUi(this);
    startTimer(300);
    memset(wood,0,sizeof(wood));
    memset(gold,0,sizeof(gold));
}
Form1::~Form1()
{
    delete ui;
}
void Form1::timerEvent(QTimerEvent *event){
        this->ui->label->setText(QString("wood:%1 gold: %2").arg(wood[1]).arg(gold[1]));
        this->ui->label_5->setText(QString("wood:%1 gold: %2").arg(wood[2]).arg(gold[2]));
        this->ui->label_8->setText(QString("wood:%1 gold: %2").arg(wood[3]).arg(gold[3]));
        this->ui->label_11->setText(QString("wood:%1 gold: %2").arg(wood[4]).arg(gold[4]));
    this->ui->label_2->setText("player 1");
    this->ui->label_4->setText("player 2");
    this->ui->label_7->setText("player 3");
    this->ui->label_10->setText("player 4");
}
void Form1::on_pushButton_clicked()
{
    if(wood[1]>=100&&gold[1]>=100){
    if(chessd[1][2].prority=="NULL"){
        chessd[1][2].prority="tank";
        chessd[2][2].flag=1;
    }
    else if(chessd[2][1].prority=="NULL"){
        chessd[2][1].prority="tank";
        chessd[2][2].flag=1;
    }
    else if (chessd[2][2].prority=="NULL") {
        chessd[2][2].prority="tank";
        chessd[2][2].flag=1;
    }
    wood[1]-=100;
    gold[1]-=100;
    }
}

void Form1::on_pushButton_9_clicked()
{
    qsmark=1;
}

void Form1::on_pushButton_2_clicked()
{
    if(wood[1]>=100&&gold[1]>=50){
    if(chessd[1][2].prority=="NULL"){
        chessd[1][2].prority="miner";
        chessd[2][2].flag=1;
    }
    else if(chessd[2][1].prority=="NULL"){
        chessd[2][1].prority="miner";
        chessd[2][2].flag=1;
    }
    else if (chessd[2][2].prority=="NULL") {
        chessd[2][2].prority="miner";
        chessd[2][2].flag=1;
    }
    wood[1]-=100;
    gold[1]-=50;
    }
}

void Form1::on_pushButton_10_clicked()
{
    if(this->ui->pushButton_10->text()=="auto"){
    qsmark=3;
    this->ui->pushButton_10->setText("stop");
    }
    else {
        if(this->ui->pushButton_10->text()=="stop"){
            qsmark=1;
            this->ui->pushButton_10->setText("auto");
            }
    }
}
