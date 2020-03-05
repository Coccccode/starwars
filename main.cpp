#include "mainwindow.h"
#include <QApplication>
#include "form2.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Form2 c;
    c.show();
    return a.exec();
}
