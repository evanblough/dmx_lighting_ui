#include "channelslider.h"
#include "ui_channelslider.h"

ChannelSlider::ChannelSlider(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ChannelSlider)
{
    ui->setupUi(this);
    //Setup Signal / Slot
    QObject::connect(ui->verticalSlider, &QAbstractSlider::valueChanged, this, &ChannelSlider::display_value);
}

ChannelSlider::~ChannelSlider()
{
    delete ui;
}

void ChannelSlider::setInfo(short index, const char *name)
{
    channel_index = index;
    ui->ChannelName->setText(name);
    ui->ChannelIndex->setNum(index);
}

void ChannelSlider::display_value(int channel_value)
{
    const QString val = QString::fromStdString(std::to_string(channel_value));
    ui->ChannelValue->setText(val);
    channels[channel_index] = (unsigned char) channel_value;
    //printf("Value of Channel %d is %d\n", channel_index, channels[channel_index]);
    emit channel_changed(channel_index, channel_value);
}

void ChannelSlider::setChannels(unsigned char *value)
{
    channels = value;
}
