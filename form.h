#ifndef FORM_H
#define FORM_H

#include <QWidget>
#include <QVBoxLayout>
#include "unit.h"
#include <QMainWindow>
#include <QPainter>
#include <QResizeEvent>
#include <QDebug>
#include "player.h"
#define Width 30
#define Height 30
extern int mark1;
extern    chessData chessd[31][31];
namespace Ui {
class Form;
}

class Form : public QWidget
{
    Q_OBJECT

public:
    explicit Form(QWidget *parent = nullptr);
    void ChangeBackground(const QString filename);
    AI *Aplayer=new AI(2);
    ~Form();
protected:
    void paintEvent(QPaintEvent *);
    void resizeEvent(QResizeEvent *);
    void mousePressEvent(QMouseEvent *);
    void timerEvent(QTimerEvent *);
private:
    Ui::Form *ui;
    QString bg_filename;
    int gridWidth;
    tank a;
    miner b;
    player playman;
    int gridHeight,startX,startY;
    QPainter *painter;//画背景图
    void cntnum();
    int time;
    void drawUnit(int x,int y,QString Unit);
    void Init();
private:
   Ui::Form *u;
};

#endif // FORM_H
