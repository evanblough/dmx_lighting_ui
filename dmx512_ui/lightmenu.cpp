#include "lightmenu.h"
#include "ui_lightmenu.h"
#include "channelslider.h"

LightMenu::LightMenu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LightMenu)
{
    ui->setupUi(this);
    slider_layout = new QHBoxLayout;
    //Init channels and channel names
    for(int i = 0; i < NUM_CHANNELS; i++){
        channel_vals[i] = 0;
        channel_names[i][0] = '\0';
    }
    //Load Names
    strcpy(channel_names[0], "DIM/STROBE");
    strcpy(channel_names[1], "R");
    strcpy(channel_names[2], "G");
    strcpy(channel_names[3], "B");
}

LightMenu::~LightMenu()
{
    delete ui;
}

void LightMenu::clearChannelDisplay(){
    clearLayout(slider_layout);
}

void LightMenu::clearLayout(QLayout *layout){
    QLayoutItem *item;
    while((item = layout->takeAt(0))) {
        if (item->layout()) {
            clearLayout(item->layout());
            delete item->layout();
        }
        if (item->widget()) {
            delete item->widget();
        }
        delete item;
    }
}


void LightMenu::addChannelSlider(short index, const char *name)
{
    ChannelSlider *cs = new ChannelSlider;
    cs->setInfo(index, name);
    slider_layout->addWidget(cs);
    ui->Channels->setLayout(slider_layout);
}

void LightMenu::showFrame(LightMenuFrame lframe)
{
    for(short i = lframe.start; i < lframe.end; i++){
        ChannelSlider *cs = new ChannelSlider;
        cs->setInfo(i, channel_names[i]);
        slider_layout->addWidget(cs);
    }
    ui->Channels->setLayout(slider_layout);
}
