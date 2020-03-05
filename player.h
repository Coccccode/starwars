#ifndef PLAYER_H
#define PLAYER_H
#include <unit.h>
#include <qmath.h>
#include <QMessageBox>
extern int qsmark;
class player{
public:
    player(){
        memset(wood,0,sizeof(wood));
        memset(gold,0,sizeof(gold));
        memset(count,0,sizeof(count));
    }
    virtual void buildMiner(int fl,chessData d){
    }
   int wood[5],gold[5];
   int count[5];//矿工进入数量
   int flag;
};
class AI:public player{
public:
    AI(int fl){
        memset(wood,0,sizeof(wood));
        memset(gold,0,sizeof(gold));
        memset(count,0,sizeof(count));
        minp=0x3f3f3f3f;
        flag=fl;
        mark=0;
        minx=0;
        miny=0;
    }
    void buildMiner(int fl,chessData d[31][31]){
        qDebug()<<fl;
        if(fl==1){
            if(d[1][2].prority=="NULL"){
                d[1][2].prority="miner";
                d[1][2].flag=fl;
                d[1][2].vis=false;
            }
            else if(d[2][1].prority=="NULL"){
                d[2][1].prority="miner";
                d[2][1].flag=fl;
                d[2][1].vis=false;
            }
            else if (d[2][2].prority=="NULL") {
                d[2][2].prority="miner";
                d[2][2].flag=fl;
                d[2][2].vis=false;
            }
        if(fl==2){
            if(d[1][28].prority=="NULL"){
                d[1][28].prority="miner";
                d[1][28].flag=fl;
                d[1][28].vis=false;
            }
            else if(d[2][28].prority=="NULL"){
                d[2][28].prority="miner";
                d[2][28].flag=fl;
                d[2][28].vis=false;
            }
            else if (d[2][29].prority=="NULL") {
                d[2][29].prority="miner";
                d[2][29].flag=fl;
                d[2][29].vis=false;
            }
        }
        else if(fl==3){
            if(d[30][28].prority=="NULL"){
                d[30][28].prority="miner";
                d[30][28].flag=fl;
                d[30][28].vis=false;
            }
            else if(d[29][28].prority=="NULL"){
                d[29][28].prority="miner";
                d[29][28].flag=fl;
                d[29][28].vis=false;
            }
            else if (d[29][29].prority=="NULL") {
                d[29][29].prority="miner";
                d[29][29].flag=fl;
                d[29][29].vis=false;
            }
        }
        else if(fl==4){
            if(d[30][2].prority=="NULL"){
                d[30][2].prority="miner";
                d[30][2].flag=fl;
                d[30][2].vis=false;
            }
            else if(d[29][2].prority=="NULL"){
                d[29][2].prority="miner";
                 d[29][2].flag=fl;
                 d[29][2].vis=false;
            }
            else if (d[29][1].prority=="NULL") {
                d[29][1].prority="miner";
                d[29][1].flag=fl;
                d[29][1].vis=false;
            }
        }
        }
    }
    void buildTank(int fl,chessData d[31][31]){
        if(fl==1){
            if(d[1][2].prority=="NULL"){
                d[1][2].prority="tank";
                d[1][2].flag=fl;
                d[1][2].vis=false;
            }
            else if(d[2][1].prority=="NULL"){
                d[2][1].prority="tank";
                d[2][1].flag=fl;
                d[2][1].vis=false;
            }
            else if (d[2][2].prority=="NULL") {
                d[2][2].prority="tank";
                d[2][2].flag=fl;
                d[2][2].vis=false;
            }
        }
        if(fl==2){
            if(d[1][28].prority=="NULL"){
                d[1][28].prority="tank";
                d[1][28].flag=fl;
                d[1][28].vis=false;
            }
            else if(d[2][28].prority=="NULL"){
                d[2][28].prority="tank";
                d[2][28].flag=fl;
                d[2][28].vis=false;
            }
            else if (d[2][29].prority=="NULL") {
                d[2][29].prority="tank";
                d[2][29].flag=fl;
                d[2][29].vis=false;
            }
        }
        else if(fl==3){
            if(d[30][28].prority=="NULL"){
                d[30][28].prority="tank";
                d[30][28].flag=fl;
                d[30][28].vis=false;
            }
            else if(d[29][28].prority=="NULL"){
                d[29][28].prority="tank";
                d[29][28].flag=fl;
                d[29][28].vis=false;
            }
            else if (d[29][29].prority=="NULL") {
                d[29][29].prority="tank";
                d[29][29].flag=fl;
                d[29][29].vis=false;
            }
        }
        else if(fl==4){
            if(d[30][2].prority=="NULL"){
                d[30][2].prority="tank";
                d[30][2].flag=fl;
                d[30][2].vis=false;
            }
            else if(d[29][2].prority=="NULL"){
                d[29][2].prority="tank";
                 d[29][2].flag=fl;
                 d[29][2].vis=false;
            }
            else if (d[29][1].prority=="NULL") {
                d[29][1].prority="tank";
                d[29][1].flag=fl;
                d[29][1].vis=false;
            }
        }
    }
    int min(double a,double b){
        if(a>b)
            return b;
        else
            return a;
    }
   int mark=0;
   bool vis[5];
   double minp;
   int minx,miny,dis;
   tank a;
   bool judge(int p,int q,chessData ch[31][31])
   {
       if(ch[p][q].prority!="obstacle"&&ch[p][q].prority!="miner"
              &&ch[p][q].prority!="basement" &&ch[p][q].prority!="tank"&&ch[p][q].prority!="source"&&p>=1&&p<=30&&q>=1&&q<=29)
           return true;
       else
           return false;
   }
   bool attackTest(int p,int q,chessData ch[31][31]){
       if(q+1<=29&&(ch[p][q+1].prority=="tank"||ch[p][q+1].prority=="basement")&&ch[p][q+1].flag!=ch[p][q].flag){
           a.attack(p,q,p,q+1,ch);
           if(ch[p][q+1].prority=="basement")
               vis[ch[p][q+1].flag]=true;
           return true;
       }
       else if(q-1>=1&&(ch[p][q-1].prority=="tank"||ch[p][q-1].prority=="basement")&&ch[p][q-1].flag!=ch[p][q].flag){
           a.attack(p,q,p,q-1,ch);
           return true;
       }
       else if(p+1<=30&&(ch[p+1][q].prority=="tank"||ch[p+1][q].prority=="basement")&&ch[p+1][q].flag!=ch[p][q].flag){
           a.attack(p,q,p+1,q,ch);
           return true;
       }
       else if(p-1>=1&&(ch[p-1][q].prority=="tank")&&ch[p-1][q].flag!=ch[p][q].flag){
           a.attack(p,q,p-1,q,ch);
           return true;
       }
       else {
           return false;
       }
   }
   void movetoNearestSource(int flag,int p,int q,chessData ch[31][31]){
       minp=0x3f3f3f;
       QString w="miner";
       for(int i=1;i<=30;i++){
           for(int j=1;j<=29;j++){
                if(ch[i][j].prority=="source"&&(i!=p||j!=q)){
                    if(sqrt((p-i)*(p-i)+(q-j)*(q-j))<minp){
                        mark=1;
                        minp=sqrt((p-i)*(p-i)+(q-j)*(q-j));
                        miny=i;
                        minx=j;
                    }
                }
           }
       }
       if(p-miny>0){
           if(q-minx>0){
           if(judge(p,q-1,ch))
               a.left(p,q,ch,w);
           else if(judge(p-1,q,ch))
               a.up(p,q,ch,w);
           else  if(judge(p+1,q,ch))
               a.down(p,q,ch,w);
           else if(judge(p,q+1,ch))
               a.right(p,q,ch,w);
           }
           else if(q-minx==0){
               if(judge(p-1,q,ch))
                   a.up(p,q,ch,w);
               else if(judge(p,q-1,ch))
                   a.left(p,q,ch,w);
               else if(judge(p,q+1,ch))
                   a.right(p,q,ch,w);
               else if(judge(p+1,q,ch))
                   a.down(p,q,ch,w);
           }
           else if(q-minx<0){
               if(judge(p-1,q,ch))
                   a.up(p,q,ch,w);
               else if(judge(p,q+1,ch))
                   a.right(p,q,ch,w);
               else if(judge(p,q-1,ch))
                   a.left(p,q,ch,w);
               else if(judge(p+1,q,ch))
                   a.down(p,q,ch,w);
           }
       }
       else if(p-miny==0){
           if(q-minx>0){
           if(judge(p,q-1,ch))
               a.left(p,q,ch,w);
           else if(judge(p-1,q,ch))
               a.up(p,q,ch,w);
           else  if(judge(p+1,q,ch))
               a.down(p,q,ch,w);
           else if(judge(p,q+1,ch))
               a.right(p,q,ch,w);
           }
           else if(q-minx<0){
               if(judge(p,q+1,ch))
                     a.right(p,q,ch,w);
               else if(judge(p-1,q,ch))
                   a.up(p,q,ch,w);
               else if(judge(p+1,q,ch))
                   a.down(p,q,ch,w);
               else if(judge(p,q-1,ch))
                   a.left(p,q,ch,w);
           }
       }
       else if(p-miny<0){
           if(q-minx>0){
           if(judge(p,q-1,ch))
               a.left(p,q,ch,w);
           else  if(judge(p+1,q,ch))
               a.down(p,q,ch,w);
           else if(judge(p-1,q,ch))
               a.up(p,q,ch,w);
           else if(judge(p,q+1,ch))
               a.right(p,q,ch,w);
           }
           else if(q-minx==0){
               if(judge(p+1,q,ch))
                   a.down(p,q,ch,w);
               else if(judge(p,q+1,ch))
                   a.right(p,q,ch,w);
               else if(judge(p,q-1,ch))
                   a.left(p,q,ch,w);
               else if(judge(p-1,q,ch))
                   a.up(p,q,ch,w);

           }
           else if(q-minx<0){
               if(judge(p+1,q,ch))
                   a.down(p,q,ch,w);
               else if(judge(p,q+1,ch))
                   a.right(p,q,ch,w);
               else if(judge(p,q-1,ch))
                   a.left(p,q,ch,w);
               else if(judge(p-1,q,ch))
                   a.up(p,q,ch,w);
           }
       }
   }
   void movetoNearest(int flag,int p,int q,chessData ch[31][31]){
       minp=0x3f3f3f;
       QString w="tank";
       int qmark=0;
       for(int i=1;i<=30;i++){
           for(int j=1;j<=29;j++){
                if(ch[i][j].flag!=flag&&(ch[i][j].prority=="tank"||ch[i][j].prority=="basement")&&(i!=p||j!=q)){
                    if(abs(p-miny)+abs(q-minx)<minp){
                        mark=1;
                        minp=sqrt((p-i)*(p-i)+(q-j)*(q-j));
                        miny=i;
                        minx=j;
                    }
                }
           }
       }
       if(ch[1][1].prority=="basement")
       {
           qmark++;
       }
       if(ch[1][29].prority=="basement"){
           qmark++;
       }
       if(ch[30][1].prority=="basement"){
           qmark++;
       }
       if(ch[30][29].prority=="basement"){
           qmark++;
       }
       if(mark!=1||qmark==1)
       {
           //QMessageBox::about(new QWidget,"信息",QString("player %1 赢了").arg(flag));
        }
       if(p-miny>0){
           if(q-minx>0){
            if(judge(p-1,q,ch))
               a.up(p,q,ch,w);
          else if(judge(p,q-1,ch))
               a.left(p,q,ch,w);
           else  if(judge(p+1,q,ch))
               a.down(p,q,ch,w);
           else if(judge(p,q+1,ch))
               a.right(p,q,ch,w);
           }
           else if(q-minx==0){
               if(judge(p-1,q,ch))
                   a.up(p,q,ch,w);
               else if(judge(p,q-1,ch))
                   a.left(p,q,ch,w);
               else if(judge(p,q+1,ch))
                   a.right(p,q,ch,w);
               else if(judge(p+1,q,ch))
                   a.down(p,q,ch,w);
           }
           else if(q-minx<0){
               if(judge(p-1,q,ch))
                   a.up(p,q,ch,w);
               else if(judge(p,q+1,ch))
                   a.right(p,q,ch,w);
               else if(judge(p,q-1,ch))
                   a.left(p,q,ch,w);
               else if(judge(p+1,q,ch))
                   a.down(p,q,ch,w);
           }
       }
       else if(p-miny==0){
           if(q-minx>0){
           if(judge(p,q-1,ch))
               a.left(p,q,ch,w);
           else if(judge(p-1,q,ch))
               a.up(p,q,ch,w);
           else  if(judge(p+1,q,ch))
               a.down(p,q,ch,w);
           else if(judge(p,q+1,ch))
               a.right(p,q,ch,w);
           }
           else if(q-minx<0){
               if(judge(p,q+1,ch))
                     a.right(p,q,ch,w);
               else if(judge(p-1,q,ch))
                   a.up(p,q,ch,w);
               else if(judge(p+1,q,ch))
                   a.down(p,q,ch,w);
               else if(judge(p,q-1,ch))
                   a.left(p,q,ch,w);
           }
       }
       else if(p-miny<0){
           if(q-minx>0){
           if(judge(p,q-1,ch))
               a.left(p,q,ch,w);
           else  if(judge(p+1,q,ch))
               a.down(p,q,ch,w);
           else if(judge(p-1,q,ch))
               a.up(p,q,ch,w);
           else if(judge(p,q+1,ch))
               a.right(p,q,ch,w);
           }
           else if(q-minx==0){
               if(judge(p+1,q,ch))
                   a.down(p,q,ch,w);
               else if(judge(p,q+1,ch))
                   a.right(p,q,ch,w);
               else if(judge(p,q-1,ch))
                   a.left(p,q,ch,w);
               else if(judge(p-1,q,ch))
                   a.up(p,q,ch,w);

           }
           else if(q-minx<0){

               if(judge(p,q+1,ch))
                   a.right(p,q,ch,w);
               else if(judge(p+1,q,ch))
                   a.down(p,q,ch,w);
               else if(judge(p-1,q,ch))
                   a.up(p,q,ch,w);
               else if(judge(p,q-1,ch))
                   a.left(p,q,ch,w);
           }
       }
       mark=0;
       qmark=0;
}
   void attacktoAnime(int p,int q,chessData ch[31][31]){
       if(mark==0&&abs(p-minx)<=1&&q==miny||(p==miny&&abs(q-miny)<=1)&&ch[p][q].flag!=ch[miny][minx].flag){
           a.attack(p,q,minx,miny,ch);
           mark=1;
       }
 }
  int
  sourceTest(int p,int q,chessData ch[31][31]){
      int fl;//记录是那个的资源+1
       if(q+1<=29&&ch[p][q+1].prority=="source"){
           ch[p][q].prority="NULL";
           qDebug()<<1;
           fl=ch[p][q].flag;
           ch[p][q].flag=0;
           return fl;
       }
       else if(q-1>=1&&ch[p][q-1].prority=="source"){
           ch[p][q].prority="NULL";
           fl=ch[p][q].flag;
           ch[p][q].flag=0;
           qDebug()<<2;
           return fl;
       }
       else if(p+1<=30&&ch[p+1][q].prority=="source"){
           ch[p][q].prority="NULL";
           fl=ch[p][q].flag;
           ch[p][q].flag=0;
           qDebug()<<3;
           return fl;
       }
       else if(p-1>=1&&ch[p-1][q].prority=="source"){
           ch[p][q].prority="NULL";
           fl=ch[p][q].flag;
           qDebug()<<4;
           ch[p][q].flag=0;
           return fl;
       }
       else {
           return false;
       }
   }
};

#endif // PLAYER_H
