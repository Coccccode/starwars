#ifndef FORM1_H
#define FORM1_H

#include <QWidget>
#include "mainwindow.h"
#include "form.h"
namespace Ui {
class Form1;
}

class Form1 : public QWidget
{
    Q_OBJECT

public:
    explicit Form1(QWidget *parent = nullptr);
    int fl;
    Form *fr=new Form();
    ~Form1();
    void timerEvent(QTimerEvent *event);
private slots:
    void on_pushButton_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_10_clicked();

private:
    Ui::Form1 *ui;

};

#endif // FORM1_H
