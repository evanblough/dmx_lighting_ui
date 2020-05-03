#include "channelslider.h"
#include "ui_channelslider.h"
#include <stdlib.h>
#include <unistd.h>


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
