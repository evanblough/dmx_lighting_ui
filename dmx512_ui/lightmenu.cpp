#include "lightmenu.h"
#include "ui_lightmenu.h"
#include "channelslider.h"

#define RED_CHANNEL 1
#define GREEN_CHANNEL 2
#define BLUE_CHANNEL 3

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
    //Look at manual for these
    strcpy(channel_names[4], "PAN");
    strcpy(channel_names[5], "TILT");
    strcpy(channel_names[6], "COLORS");
    strcpy(channel_names[7], "GOBOS");
    strcpy(channel_names[8], "GOBO INDEX ROT");
    strcpy(channel_names[9], "ROTATING PRISM");
    strcpy(channel_names[10], "GOBO INDEX_ROT");
    strcpy(channel_names[11], "SHUTTER STROBE");
    strcpy(channel_names[12], "DIMMER");
    strcpy(channel_names[13], "MVMT SPEED");
    strcpy(channel_names[14], "RESETS");
}

LightMenu::~LightMenu()
{
    delete ui;
}

void LightMenu::clearChannelDisplay(){
    clearLayout(slider_layout);
}

void LightMenu::channel_updated(short index, unsigned char value)
{
       if(index == RED_CHANNEL || index == BLUE_CHANNEL || index == GREEN_CHANNEL){
           unsigned char r = channel_vals[RED_CHANNEL];
           unsigned char b = channel_vals[BLUE_CHANNEL];
           unsigned char g = channel_vals[GREEN_CHANNEL];
           ui->CurrColor->update_color(r,g,b);
       }
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

void LightMenu::showFrame(LightMenuFrame lframe)
{
    for(short i = lframe.start; i < lframe.end; i++){
        ChannelSlider *cs = new ChannelSlider;
        cs->setInfo(i, channel_names[i]);
        cs->setChannels(channel_vals);
        slider_layout->addWidget(cs);
        QObject::connect(cs, &ChannelSlider::channel_changed, this, &LightMenu::channel_updated);
    }
    ui->Channels->setLayout(slider_layout);
}
