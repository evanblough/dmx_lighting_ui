#include "mainwindow.h"

#include <QApplication>
#include <QPalette>
#include <QColor>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    QColor light(192,255,44);
    QColor mid(84,201,87);
    QColor dark(27,38,20);
    QColor text(206,250,207);
    QPalette color_scheme(light,dark,light,dark,mid,text,dark);
    w.setPalette(color_scheme);
    w.show();
    return a.exec();
}
