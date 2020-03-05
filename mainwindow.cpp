#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
const QString base="Basement";
const QString Tank="tank";
const QString Miner="miner";
const QString Obstacle="obstacle";
const QString Source="source";
int flag=0,mflag=0,tmpi,tmpj,mtmpi,mtmpj;

#include <bits/stdc++.h>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    this->resize(800,600);
    Init();
    ui->setupUi(this);
}
//-------------------------events---------------------------
void MainWindow::mousePressEvent(QMouseEvent *event){
    int x=event->x();
    int y=event->y();
    if(x>=startX&&x<=startX+30*gridWidth){
        if(y>=startY&&y<=startY+30*gridHeight){
            int i=0,j=0;
            i=y/gridHeight;
            j=x/gridWidth;
            painter=new QPainter(this);
            qDebug()<<i<<" "<<j<<" "<<flag;
            if (chessd[i][j].prority==Tank&&flag==0) {
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
            else if(chessd[i][j].prority=="NULL"&&chessd[tmpi][tmpj].prority==Tank&&flag==1)
            {
                a.moveto(tmpi,tmpj,i,j,chessd);
                flag=0;
            }
            if (chessd[i][j].prority==Miner&&mflag==0) {
                mtmpi=i;
                mtmpj=j;
                mflag=1;
            }
            else if(chessd[i][j].prority!="NULL"&&chessd[i][j].prority!=Source&&mflag==1){
                mflag=0;
            }
            else if(chessd[i][j].prority=="NULL"&&chessd[mtmpi][mtmpj].prority==Miner&&mflag==1)
            {
                b.moveto(mtmpi,mtmpj,i,j,chessd);
                mflag=0;
            }
            else if (chessd[i][j].prority==Source&&mflag==1) {
                   playman.count++;
                   chessd[mtmpi][mtmpj].prority="NULL";
            }
            this->repaint();
            this->update();
        }
    }
}
void MainWindow::cntnum()
{
    playman.wood=5*time*playman.count;
    playman.gold=2*time*playman.count;
}
void MainWindow::paintEvent(QPaintEvent *)
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
void MainWindow::resizeEvent(QResizeEvent *event){
    gridWidth=event->size().width()/(Width+1);
    gridHeight=event->size().height()/(Height+1);
    startX=gridWidth;
    startY=gridHeight;
    //
}
//-------------------------end_events-----------------------
//................functions...............
void MainWindow::drawUnit(int x,int y,QString Unit)
{
    painter->drawPixmap(startX+(y-1)*gridWidth,startY+(x-1)*gridHeight,startX,startY,QPixmap(QString("../starwars/image/%1.png").arg(Unit)));
    chessd[x][y].prority=Unit;

}
//private
void MainWindow::Init()
{
    bg_filename="../starwars/image/background.jpg";
    chessd[1][1].prority=base;
    chessd[1][1].flag=1;
    chessd[30][29].prority=base;
    chessd[30][1].prority=base;
    chessd[1][29].prority=base;
    chessd[1][2].prority=Tank;
    chessd[1][28].prority=Tank;
    chessd[30][28].prority=Tank;
    chessd[30][2].prority=Tank;
    chessd[2][1].prority=Miner;
    chessd[29][1].prority=Miner;
    chessd[29][29].prority=Miner;
    chessd[2][29].prority=Miner;
    chessd[1][1].flag=1;
    chessd[1][29].flag=1;
    chessd[30][1].flag=1;
    chessd[30][29].flag=1;
    chessd[10][10].prority=Tank;
    chessd[5][5].prority=Source;
    chessd[26][5].prority=Source;
    chessd[5][26].prority=Source;
    chessd[25][26].prority=Source;
}
MainWindow::~MainWindow()
{
    delete ui;
}
