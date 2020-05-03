#ifndef LIGHTMENU_H
#define LIGHTMENU_H

#include <QWidget>
#include <QHBoxLayout>

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
    void addChannelSlider(short index, const char* name);

private:
    Ui::LightMenu *ui;
    QHBoxLayout *slider_layout;
};

#endif // LIGHTMENU_H
