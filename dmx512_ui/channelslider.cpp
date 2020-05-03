#include "channelslider.h"
#include "ui_channelslider.h"

ChannelSlider::ChannelSlider(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ChannelSlider)
{
    ui->setupUi(this);
}

ChannelSlider::~ChannelSlider()
{
    delete ui;
}
