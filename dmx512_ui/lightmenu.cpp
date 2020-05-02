#include "lightmenu.h"
#include "ui_lightmenu.h"

LightMenu::LightMenu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LightMenu)
{
    ui->setupUi(this);
}

LightMenu::~LightMenu()
{
    delete ui;
}
