/********************************************************************************
** Form generated from reading UI file 'lightmenu.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LIGHTMENU_H
#define UI_LIGHTMENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>
#include "colordisplay.h"

QT_BEGIN_NAMESPACE

class Ui_LightMenu
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QWidget *ColorWheel;
    QLabel *label_2;
    QWidget *Channels;
    QLabel *label_3;
    ColorDisplay *CurrColor;

    void setupUi(QWidget *LightMenu)
    {
        if (LightMenu->objectName().isEmpty())
            LightMenu->setObjectName(QStringLiteral("LightMenu"));
        LightMenu->resize(847, 580);
        gridLayout = new QGridLayout(LightMenu);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(LightMenu);
        label->setObjectName(QStringLiteral("label"));
        label->setMaximumSize(QSize(16777215, 20));
        QFont font;
        font.setFamily(QStringLiteral("Ubuntu"));
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        ColorWheel = new QWidget(LightMenu);
        ColorWheel->setObjectName(QStringLiteral("ColorWheel"));

        gridLayout->addWidget(ColorWheel, 3, 0, 1, 1);

        label_2 = new QLabel(LightMenu);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMaximumSize(QSize(16777215, 20));
        QFont font1;
        font1.setBold(true);
        font1.setWeight(75);
        label_2->setFont(font1);
        label_2->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        Channels = new QWidget(LightMenu);
        Channels->setObjectName(QStringLiteral("Channels"));

        gridLayout->addWidget(Channels, 1, 1, 3, 1);

        label_3 = new QLabel(LightMenu);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font1);
        label_3->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_3, 0, 1, 1, 1);

        CurrColor = new ColorDisplay(LightMenu);
        CurrColor->setObjectName(QStringLiteral("CurrColor"));
        CurrColor->setMaximumSize(QSize(300, 16777215));

        gridLayout->addWidget(CurrColor, 1, 0, 1, 1);


        retranslateUi(LightMenu);

        QMetaObject::connectSlotsByName(LightMenu);
    } // setupUi

    void retranslateUi(QWidget *LightMenu)
    {
        LightMenu->setWindowTitle(QApplication::translate("LightMenu", "Form", Q_NULLPTR));
        label->setText(QApplication::translate("LightMenu", "Current Color", Q_NULLPTR));
        label_2->setText(QApplication::translate("LightMenu", "Color Wheel", Q_NULLPTR));
        label_3->setText(QApplication::translate("LightMenu", "Channels", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class LightMenu: public Ui_LightMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LIGHTMENU_H
