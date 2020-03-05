#ifndef FORM2_H
#define FORM2_H

#include <QWidget>
#include "form.h"
#include "form1.h"
namespace Ui {
class Form2;
}

class Form2 : public QWidget
{
    Q_OBJECT

public:
    explicit Form2(QWidget *parent = nullptr);
    Form *f1=new Form();
    Form1 *f2=new Form1();
    ~Form2();
private:
    Ui::Form2 *ui;
    QVBoxLayout *layout=new QVBoxLayout();
    void resizeEvent(QResizeEvent *event);
};

#endif // FORM2_H
