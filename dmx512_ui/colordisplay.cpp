#include "colordisplay.h"
#include "ui_colordisplay.h"
#include <QPainter>
#include <QPen>
#define CIRCLE_RADIUS 50

ColorDisplay::ColorDisplay(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ColorDisplay)
{
    ui->setupUi(this);
    color = new QColor(0,0,0);
}

void ColorDisplay::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    QPen pen(*color);
    pen.setWidth(2);
    painter.setPen(pen);
    int x = this->rect().width()/4;
    int y = this->rect().height()/4;
    for(int i = 0; i < CIRCLE_RADIUS; i++) painter.drawEllipse(x+i/2,y+i/2,CIRCLE_RADIUS-i,CIRCLE_RADIUS-i);
}

ColorDisplay::~ColorDisplay()
{
    delete ui;
}
