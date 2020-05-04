#ifndef COLORDISPLAY_H
#define COLORDISPLAY_H

#include <QWidget>
#include <QColor>

namespace Ui {
class ColorDisplay;
}

class ColorDisplay : public QWidget
{
    Q_OBJECT

public:
    explicit ColorDisplay(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event);
    ~ColorDisplay();

private:
    Ui::ColorDisplay *ui;
    QColor *color;
};

#endif // COLORDISPLAY_H
