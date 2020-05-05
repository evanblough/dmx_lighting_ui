#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QComboBox>
#include <QObject>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //Init Display
    const char names[NUM_LIGHTS][LIGHTNAME_LEN] = {"Light1", "Light2"};
    for(int i = 0;i < NUM_LIGHTS; i++){
        ui->LightNames->addItem(names[i], 0);
    }
    ui->lMenu->showFrame(lframes[0]);
    //Map Signals and Slots
    QObject::connect(ui->LightNames, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &MainWindow::changed_light);
   ui->lMenu->remote_conn = &remote_sock;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::changed_light(int index)
{
    if(index != -1){
        ui->lMenu->clearChannelDisplay();
        ui->lMenu->showFrame(lframes[index]);
    }
}

