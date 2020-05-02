#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    char *channels = new char[512];
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
