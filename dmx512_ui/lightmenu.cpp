#include "lightmenu.h"
#include "ui_lightmenu.h"
#include "channelslider.h"

#define RED_CHANNEL 1
#define GREEN_CHANNEL 2
#define BLUE_CHANNEL 3
#define MAX_NUM_SLIDERS 4

LightMenu::LightMenu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LightMenu)
{
    ui->setupUi(this);
    offset = 0;
    slider_layout = new QHBoxLayout;
    //Init channels and channel names
    for(int i = 0; i < NUM_CHANNELS; i++){
        channel_vals[i] = 0;
        channel_names[i][0] = '\0';
        channels_cache[i] = -1;
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
    strcpy(channel_names[8], "GOBO INDEX");
    strcpy(channel_names[9], "PRISM");
    strcpy(channel_names[10], "SHUTTER STROBE");
    strcpy(channel_names[11], "DIMMER");
    strcpy(channel_names[12], "MVMT SPEED");
    strcpy(channel_names[13], "RESETS");
    //Signals / Slots
    QObject::connect(ui->Back, &QPushButton::clicked, this, &LightMenu::decrement_offset);
    QObject::connect(ui->Forward, &QPushButton::clicked, this, &LightMenu::increment_offset);
    curr_lframe.start = 0;
    curr_lframe.end = 0;
}

LightMenu::~LightMenu()
{
    delete ui;
}

void LightMenu::clearChannelDisplay(){
    clearLayout(slider_layout);
}

void LightMenu::increment_offset(bool checked){
    offset++;
    clearChannelDisplay();
    showFrame(curr_lframe);
}
void LightMenu::decrement_offset(bool checked){
    offset--;
    if(offset < 0) offset = 0;
    clearChannelDisplay();
    showFrame(curr_lframe);
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
    curr_lframe = lframe;
    short end = (lframe.end < lframe.start+offset*4+MAX_NUM_SLIDERS) ? lframe.end : lframe.start+offset*4+MAX_NUM_SLIDERS;
    for(short i = lframe.start+offset*4; i < end; i++){
        ChannelSlider *cs = new ChannelSlider;
        cs->setInfo(i, channel_names[i]);
        cs->setChannels(channel_vals);
        slider_layout->addWidget(cs);
        QObject::connect(cs, &ChannelSlider::channel_changed, this, &LightMenu::channel_updated);
    }
    ui->Channels->setLayout(slider_layout);
}
