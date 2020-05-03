#include "lightmenu.h"
#include "ui_lightmenu.h"
#include "channelslider.h"

LightMenu::LightMenu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LightMenu)
{
    ui->setupUi(this);
    slider_layout = new QHBoxLayout;
}

LightMenu::~LightMenu()
{
    delete ui;
}

void LightMenu::addChannelSlider(short index, const char *name)
{
    ChannelSlider *cs = new ChannelSlider();
    cs->setInfo(index, name);
    slider_layout->addWidget(cs);
    ui->Channels->setLayout(slider_layout);
}
