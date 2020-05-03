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
    void setInfo(short index, const char* name);
    void setChannels(unsigned char *value);

public slots:
    void display_value(int channel_value);
signals:
    void channel_changed(short index, unsigned char value);
private:
    unsigned char* channels;
    short channel_index;
    Ui::ChannelSlider *ui;
};

#endif // CHANNELSLIDER_H
