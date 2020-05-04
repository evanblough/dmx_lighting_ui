/********************************************************************************
** Form generated from reading UI file 'channelslider.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHANNELSLIDER_H
#define UI_CHANNELSLIDER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSlider>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChannelSlider
{
public:
    QGridLayout *gridLayout;
    QSlider *verticalSlider;
    QLabel *label;
    QLabel *ChannelName;
    QTextEdit *ChannelValue;
    QLabel *ChannelIndex;

    void setupUi(QWidget *ChannelSlider)
    {
        if (ChannelSlider->objectName().isEmpty())
            ChannelSlider->setObjectName(QStringLiteral("ChannelSlider"));
        ChannelSlider->resize(100, 315);
        ChannelSlider->setMaximumSize(QSize(150, 16777215));
        gridLayout = new QGridLayout(ChannelSlider);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(-1, 0, -1, 0);
        verticalSlider = new QSlider(ChannelSlider);
        verticalSlider->setObjectName(QStringLiteral("verticalSlider"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(verticalSlider->sizePolicy().hasHeightForWidth());
        verticalSlider->setSizePolicy(sizePolicy);
        verticalSlider->setMaximumSize(QSize(200, 16777215));
        verticalSlider->setStyleSheet(QStringLiteral(""));
        verticalSlider->setMaximum(255);
        verticalSlider->setOrientation(Qt::Vertical);

        gridLayout->addWidget(verticalSlider, 2, 0, 1, 1);

        label = new QLabel(ChannelSlider);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        label->setFrameShape(QFrame::Box);
        label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label, 3, 0, 1, 1);

        ChannelName = new QLabel(ChannelSlider);
        ChannelName->setObjectName(QStringLiteral("ChannelName"));
        ChannelName->setFont(font);
        ChannelName->setFrameShape(QFrame::Box);
        ChannelName->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(ChannelName, 0, 0, 1, 1);

        ChannelValue = new QTextEdit(ChannelSlider);
        ChannelValue->setObjectName(QStringLiteral("ChannelValue"));
        sizePolicy.setHeightForWidth(ChannelValue->sizePolicy().hasHeightForWidth());
        ChannelValue->setSizePolicy(sizePolicy);
        ChannelValue->setMaximumSize(QSize(16777215, 30));
        ChannelValue->setFrameShape(QFrame::Box);
        ChannelValue->setFrameShadow(QFrame::Plain);

        gridLayout->addWidget(ChannelValue, 4, 0, 1, 1);

        ChannelIndex = new QLabel(ChannelSlider);
        ChannelIndex->setObjectName(QStringLiteral("ChannelIndex"));
        ChannelIndex->setFrameShape(QFrame::Box);
        ChannelIndex->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(ChannelIndex, 1, 0, 1, 1);


        retranslateUi(ChannelSlider);

        QMetaObject::connectSlotsByName(ChannelSlider);
    } // setupUi

    void retranslateUi(QWidget *ChannelSlider)
    {
        ChannelSlider->setWindowTitle(QApplication::translate("ChannelSlider", "Form", Q_NULLPTR));
        label->setText(QApplication::translate("ChannelSlider", "Value", Q_NULLPTR));
        ChannelName->setText(QApplication::translate("ChannelSlider", "TextLabel", Q_NULLPTR));
        ChannelIndex->setText(QApplication::translate("ChannelSlider", "TextLabel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ChannelSlider: public Ui_ChannelSlider {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHANNELSLIDER_H
