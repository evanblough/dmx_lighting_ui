#ifndef LIGHTMENU_H
#define LIGHTMENU_H

#include <QWidget>

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

private:
    Ui::LightMenu *ui;
};

#endif // LIGHTMENU_H
