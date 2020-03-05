#ifndef UNIT_H
#define UNIT_H
#include <QString>
#include <QDebug>
class  unit{
public:
    int flag;
    int count;
    virtual void attack(int x,int y){

    }
    virtual void moveto(int x,int y){

    }
};
class chessData{
public:
    QString prority;
    int flag;
    bool vis;
    chessData(QString p,int f)
    {
        prority=p;
        flag=f;
    }
    chessData()
    {
        prority="NULL";
        flag=0;
        vis=false;
    }
};
class tank:public unit
{
public:
    void  draw(int i,int j,int fl,chessData ches[31][31]){
        ches[i][j].prority="tank";
        flag=fl;
    }
    void attack(int i,int j,int c,int d,chessData ches[31][31]){
        if(abs(i-c)<=1&&j==d||(abs(j-d)<=1&&i==c)&&ches[i][j].flag!=ches[c][d].flag){
            ches[c][d].prority="NULL";
            ches[c][d].flag=0;
        }
    }
    void moveto(int i,int j,int c,int d,chessData ches[31][31])
    {
        if((abs(i-c)<=1&&j==d)||(abs(j-d)<=1&&i==c)){
            ches[i][j].prority="NULL";
            ches[c][d].prority="tank";
            ches[c][d].flag=ches[i][j].flag;
            ches[i][j].flag=0;
        }
    }
    void left(int i,int j,chessData ches[31][31],QString prio){
        ches[i][j].prority="NULL";
        ches[i][j-1].vis=true;
        ches[i][j-1].prority=prio;
        ches[i][j-1].flag=ches[i][j].flag;
        ches[i][j].flag=0;
    }
    void right(int i,int j,chessData ches[31][31],QString prio){
        ches[i][j].prority="NULL";
        ches[i][j+1].prority=prio;
        ches[i][j+1].vis=true;
        ches[i][j+1].flag=ches[i][j].flag;
        ches[i][j].flag=0;
    }
    void up(int i,int j,chessData ches[31][31],QString prio){
        qDebug()<<i<<" "<<j;
        ches[i][j].prority="NULL";
        ches[i-1][j].prority=prio;
        ches[i-1][j].vis=true;
        ches[i-1][j].flag=ches[i][j].flag;
        ches[i][j].flag=0;
    }
    void down(int i,int j,chessData ches[31][31],QString prio){
            ches[i][j].prority="NULL";
            ches[i+1][j].prority=prio;
            ches[i+1][j].vis=true;
            ches[i+1][j].flag=ches[i][j].flag;
            ches[i][j].flag=0;

    }
};
class miner:public unit{
public:
    void  draw(int i,int j,int fl,chessData ches[31][31])
    {
        ches[i][j].prority="miner";
        flag=fl;
    }
    void moveto(int i,int j,int c,int d,chessData ches[31][31])
    {
        if(abs(i-c)<=1&&j==d||(abs(j-d)<=1&&i==c)){
            ches[i][j].prority="NULL";
            ches[c][d].flag=ches[i][j].flag;
            ches[i][j].flag=0;
            ches[c][d].prority="miner";
        }
    }
};


#endif // UNIT_H
