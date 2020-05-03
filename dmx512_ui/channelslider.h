#ifndef CHANNELSLIDER_H
#define CHANNELSLIDER_H

#include <QWidget>

namespace Ui {
class ChannelSlider;
}

class ChannelSlider : public QWidget
{
    Q_OBJECT

public:
    explicit ChannelSlider(QWidget *parent = nullptr);
    ~ChannelSlider();
    void setChannel(short index, QString name);

private:
    Ui::ChannelSlider *ui;
};

#endif // CHANNELSLIDER_H
