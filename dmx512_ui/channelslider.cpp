#include "channelslider.h"
#include "ui_channelslider.h"
#include <QTextCursor>

ChannelSlider::ChannelSlider(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ChannelSlider)
{
    ui->setupUi(this);
    //Setup Signal / Slot
    QObject::connect(ui->verticalSlider, &QAbstractSlider::valueChanged, this, &ChannelSlider::display_value);
    QObject::connect(ui->ChannelValue, &QTextEdit::textChanged, this, &ChannelSlider::update_slider);
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
    emit channel_changed(channel_index, channel_value);
}

void ChannelSlider::update_slider()
{
    QString val_str = ui->ChannelValue->toPlainText();
    unsigned char val = val_str.toInt();
    ui->verticalSlider->setValue(val);
    //Move cursor to the end why this wasn't the default idkg
    ui->ChannelValue->moveCursor(QTextCursor::End, QTextCursor::MoveAnchor);
}

void ChannelSlider::setChannels(unsigned char *value)
{
    channels = value;
}
