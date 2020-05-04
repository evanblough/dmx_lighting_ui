#ifndef LIGHTMENU_H
#define LIGHTMENU_H

#include <QWidget>
#include <QHBoxLayout>

#define NUM_CHANNELS 512
#define CHANNEL_NAMELEN 12

namespace Ui {
class LightMenu;
}

struct LightMenuFrame{
    short start;
    short end;
};

class LightMenu : public QWidget
{
    Q_OBJECT

public:
    explicit LightMenu(QWidget *parent = nullptr);
    ~LightMenu();
    void showFrame(LightMenuFrame lframe);
    void clearLayout(QLayout *layout);
    void clearChannelDisplay();
public slots:
    void channel_updated(short index, unsigned char value);
    void increment_offset(bool checked);
    void decrement_offset(bool checked);

private:
    Ui::LightMenu *ui;
    QHBoxLayout *slider_layout;
    char channel_names[NUM_CHANNELS][CHANNEL_NAMELEN];
    unsigned char channel_vals[NUM_CHANNELS];
    short channels_cache[NUM_CHANNELS];
    short offset;
    LightMenuFrame curr_lframe;
};

#endif // LIGHTMENU_H
