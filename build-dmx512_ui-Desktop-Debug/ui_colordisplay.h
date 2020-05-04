/********************************************************************************
** Form generated from reading UI file 'colordisplay.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COLORDISPLAY_H
#define UI_COLORDISPLAY_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ColorDisplay
{
public:

    void setupUi(QWidget *ColorDisplay)
    {
        if (ColorDisplay->objectName().isEmpty())
            ColorDisplay->setObjectName(QStringLiteral("ColorDisplay"));
        ColorDisplay->resize(400, 300);

        retranslateUi(ColorDisplay);

        QMetaObject::connectSlotsByName(ColorDisplay);
    } // setupUi

    void retranslateUi(QWidget *ColorDisplay)
    {
        ColorDisplay->setWindowTitle(QApplication::translate("ColorDisplay", "Form", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ColorDisplay: public Ui_ColorDisplay {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COLORDISPLAY_H
