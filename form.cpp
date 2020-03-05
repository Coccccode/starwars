#include "form.h"
#include "ui_form.h"
#include "mainwindow.h"
#include "form1.h"
#include <QDebug>
#include <QVector>
#include <QTime>
const QString base="basement";
const QString Tank="tank";
const QString Miner="miner";
const QString Obstacle="obstacle";
const QString Source="source";
int wood[5],gold[5],count[5];
int flag=0,mflag=0,tmpi,tmpj,mtmpi,mtmpj;
chessData chessd[31][31];
int mark1=0;
int tim=0;
int random=4;
Form::Form(QWidget *parent):
    QWidget(parent),
    ui(new Ui::Form)
{
    this->resize(800,3000);
    Init();
    memset(Aplayer->vis,0,sizeof(Aplayer->vis));
    startTimer(10);
    ui->setupUi(this);
}
//-------------------------events---------------------------
void Form::timerEvent(QTimerEvent *event){
    int a,b,fla,f,ms=0;
    if(chessd[1][1].prority!="basement"){
        wood[1]=0;
        gold[1]=0;
        f=1;
        ms++;
    }
    if(chessd[1][29].prority!="basement"){
        wood[2]=0;
        gold[2]=0;
        f=2;
        ms++;
    }
    if(chessd[30][29].prority!="basement"){
        wood[3]=0;
        gold[3]=0;
        f=3;
        ms++;
    }
    if(chessd[30][1].prority!="basement"){
        wood[4]=0;
        gold[4]=0;
        f=4;
        ms++;
    }
    if(ms==3&&mark1!=2){
        QMessageBox::about(this,"提示",QString("player %1赢了").arg(ms));
        mark1=2;
    }
    if(event->timerId()==1) //判断定时器的句柄
    {
        if(((qsmark==1&&tim%4+1!=1)||qsmark==3)){
            cntnum();
        if(wood[tim%4+1]>=30&&gold[tim%4+1]>=15&&random>0){
                Aplayer->buildMiner(tim%4+1,chessd);
                wood[tim%4+1]-=30;
                gold[tim%4+1]-=15;
                Aplayer->wood[tim%4+1]=wood[tim%4+1];
                Aplayer->gold[tim%4+1]=gold[tim%4+1];
                random--;
                qDebug()<<random;
        }
        else if(wood[tim%4+1]>=30&&gold[tim%4+1]>=30&&random<=0){
            Aplayer->buildTank(tim%4+1,chessd);
            wood[tim%4+1]-=30;
            gold[tim%4+1]-=30;
            Aplayer->wood[tim%4+1]=wood[tim%4+1];
            Aplayer->gold[tim%4+1]=gold[tim%4+1];
        }
        for(int i=1;i<=30;i++)
            for(int j=1;j<=29;j++){
                if(chessd[i][j].flag==tim%4+1&&chessd[i][j].prority==Tank&&
                        !chessd[i][j].vis)
                 {
                    if(Aplayer->attackTest(i,j,chessd)){
                        continue;
                     }
                    Aplayer->movetoNearest(chessd[i][j].flag,i,j,chessd);
                }
                else if(chessd[i][j].flag==tim%4+1&&chessd[i][j].prority==Miner&&
                        !chessd[i][j].vis)
                 {
                    if((fla=Aplayer->sourceTest(i,j,chessd))){
                        Aplayer->count[fla]++;
                        count[fla]++;
                        continue;
                    }
                    Aplayer->movetoNearestSource(chessd[i][j].flag,i,j,chessd);

                }
            }
        tim++;
        }
        else if(tim%4+1==1){
            qsmark=0;
            cntnum();
            tim++;
        }
        for(int i=1;i<=30;i++)
            for(int j=1;j<=29;j++)
                chessd[i][j].vis=false;
    }
    this->update();
    this->repaint();
}
void Form::mousePressEvent(QMouseEvent *event){
    int x=event->x();
    int y=event->y();
    if(x>=startX&&x<=startX+30*gridWidth){
        if(y>=startY&&y<=startY+30*gridHeight){
            int i=0,j=0;
            i=y/gridHeight;
            j=x/gridWidth;
            painter=new QPainter(this);
            qDebug()<<i<<" "<<j<<" "<<flag;
            if (chessd[i][j].prority==Tank&&flag==0&&chessd[i][j].flag==1) {
                tmpi=i;
                tmpj=j;
                flag=1;
            }
            else if(chessd[i][j].prority==Tank&&flag==1){
                if(tmpi!=i||tmpj!=j&&chessd[i][j].flag==chessd[tmpi][tmpj].flag
                        )
                a.attack(tmpi,tmpj,i,j,chessd);
                flag=0;
            }
            else if(chessd[i][j].prority=="NULL"&&chessd[tmpi][tmpj].flag==1&&chessd[tmpi][tmpj].prority==Tank&&flag==1)
            {
                a.moveto(tmpi,tmpj,i,j,chessd);
                flag=0;
            }
            if (chessd[i][j].prority==Miner&&mflag==0&&chessd[i][j].flag==1) {
                mtmpi=i;
                mtmpj=j;
                mflag=1;
            }
            else if(chessd[i][j].prority!="NULL"&&chessd[i][j].prority!=Source&&mflag==1){
                mflag=0;
            }
            else if(chessd[i][j].prority=="NULL"&&chessd[mtmpi][mtmpj].flag==1&&chessd[mtmpi][mtmpj].prority==Miner&&mflag==1)
            {
                b.moveto(mtmpi,mtmpj,i,j,chessd);
                mflag=0;
            }
            else if (chessd[i][j].prority==Source&&mflag==1&&chessd[mtmpi][mtmpj].flag==1) {
                   Aplayer->count[1]++;
                   chessd[mtmpi][mtmpj].prority="NULL";
            }
            this->update();
        }
    }
}
void Form::cntnum()
{
    wood[tim%4+1]+=Aplayer->count[tim%4+1]*4;
    gold[tim%4+1]+=Aplayer->count[tim%4+1]*1;
    Aplayer->wood[tim%4+1]=wood[tim%4+1];
    Aplayer->gold[tim%4+1]=gold[tim%4+1];

}
void Form::paintEvent(QPaintEvent *)
{
    painter=new QPainter(this);
    QRect rec;
    rec.setTopLeft(QPoint(0,0));
    rec.setBottomRight(QPoint(this->width(),this->height()));
    QPixmap pix;
    pix.load(bg_filename);
    painter->drawPixmap(rec,pix);
    QPen pen1;//画线
    pen1.setColor(Qt::black);
    pen1.setStyle(Qt::SolidLine);
    pen1.setWidth(1);
    painter->setPen(pen1);
    for(int i=0;i<=Width-1;i++){
        painter->drawLine(startX,startY+gridHeight*i,Width*gridWidth,startY+i*gridHeight);
    }
    for(int i=0;i<=Height-1;i++){
        painter->drawLine(startX+gridWidth*i,startY,startX+i*gridWidth,Height*gridWidth);
        for(int i=1;i<=30;i++){
            for(int j=1;j<=29;j++)
                if(chessd[i][j].prority==Tank){
                    drawUnit(i,j,Tank);
                }
                else if(chessd[i][j].prority==Miner){
                    drawUnit(i,j,Miner);
                }
                else if(chessd[i][j].prority==base){
                    drawUnit(i,j,base);
                }
                else if(chessd[i][j].prority==Obstacle){
                    drawUnit(i,j,Obstacle);
                }
                else if(chessd[i][j].prority==Source){
                    drawUnit(i,j,Source);
                }
                else if(chessd[i][j].prority=="NULL"){

                }
        }
}
}
void Form::resizeEvent(QResizeEvent *event){
    gridWidth=event->size().width()/(Width+1);
    gridHeight=event->size().height()/(Height+1);
    startX=gridWidth;
    startY=gridHeight;
    //
}
//-------------------------end_events-----------------------
//................functions...............
void Form::drawUnit(int x,int y,QString Unit)
{
    QString a;
    if(chessd[x][y].flag==1&&Unit=="tank"){
        a=Unit+"1";
    }
    else
    a=Unit;
    painter->drawPixmap(startX+(y-1)*gridWidth,startY+(x-1)*gridHeight,startX,startY,QPixmap(QString("../starwars/image/%1.png").arg(a)));
    chessd[x][y].prority=Unit;

}
//private
void Form::Init()
{
    bg_filename="../starwars/image/background.jpg";
    chessd[1][1].prority=base;
    chessd[4][8].prority=Obstacle;
    chessd[3][21].prority=Obstacle;
    chessd[2][21].prority=Obstacle;
    chessd[4][9].prority=Obstacle;
    chessd[3][8].prority=Obstacle;
    chessd[8][11].prority=Obstacle;
    chessd[9][11].prority=Obstacle;
    chessd[9][10].prority=Obstacle;
    chessd[10][10].prority=Obstacle;
    chessd[16][20].prority=Obstacle;
    chessd[16][21].prority=Obstacle;
    chessd[17][21].prority=Obstacle;
    chessd[17][22].prority=Obstacle;
    chessd[14][8].prority=Obstacle;
    chessd[15][8].prority=Obstacle;
    chessd[15][7].prority=Obstacle;
    chessd[15][7].prority=Obstacle;
    chessd[1][1].flag=1;
    chessd[30][29].prority=base;
    chessd[30][29].flag=3;
    chessd[30][1].prority=base;
    chessd[30][1].flag=4;
    chessd[1][29].prority=base;
    chessd[1][29].flag=2;
    chessd[1][28].prority=Tank;
    chessd[1][28].flag=2;
    chessd[30][28].prority=Tank;
    chessd[30][28].flag=3;
    chessd[1][2].prority=Tank;
    chessd[1][2].flag=1;
    chessd[30][2].prority=Tank;
    chessd[30][2].flag=4;
    chessd[2][1].prority=Miner;
    chessd[2][1].flag=1;
    chessd[29][1].prority=Miner;
    chessd[29][1].flag=4;
    chessd[29][29].prority=Miner;
    chessd[29][29].flag=3;
    chessd[2][29].prority=Miner;
    chessd[2][29].flag=2;
    chessd[5][23].prority=Source;
    chessd[15][23].prority=Source;
    chessd[25][5].prority=Source;
    chessd[5][13].prority=Source;
    chessd[25][11].prority=Source;
}
Form::~Form()
{
    delete u;
}
