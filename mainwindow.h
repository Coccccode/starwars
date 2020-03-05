#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "unit.h"
#include <QMainWindow>
#include <QPainter>
#include <QResizeEvent>
#include <QDebug>
#include "player.h"
#define Width 30
#define Height 30
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    void ChangeBackground(const QString filename);
    ~MainWindow();
protected:
    void paintEvent(QPaintEvent *);
    void resizeEvent(QResizeEvent *);
    void mousePressEvent(QMouseEvent *);
private:
    Ui::MainWindow *ui;
    QString bg_filename;
    int gridWidth;
    tank a;
    miner b;
    player playman;
    int gridHeight,startX,startY;
    chessData chessd[31][31];
    QPainter *painter;//画背景图
    void cntnum();
    int time;
    void drawUnit(int x,int y,QString Unit);
    void Init();
};

#endif // MAINWINDOW_H
