#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    const char names[NUM_LIGHTS][LIGHTNAME_LEN] = {"Light1", "Light2"};
    for(int i = 0;i < NUM_LIGHTS; i++){
        ui->LightNames->addItem(names[i], 0);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

