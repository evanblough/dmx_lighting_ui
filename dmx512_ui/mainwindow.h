#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#define NUM_LIGHTS 2
#define LIGHTNAME_LEN 10

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
