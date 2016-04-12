/********************************************************************************
** Form generated from reading UI file 'pantallainicio.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PANTALLAINICIO_H
#define UI_PANTALLAINICIO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PantallaInicio
{
public:
    QPushButton *pushButton;

    void setupUi(QWidget *PantallaInicio)
    {
        if (PantallaInicio->objectName().isEmpty())
            PantallaInicio->setObjectName(QStringLiteral("PantallaInicio"));
        PantallaInicio->resize(640, 480);
        pushButton = new QPushButton(PantallaInicio);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(280, 280, 80, 24));

        retranslateUi(PantallaInicio);

        QMetaObject::connectSlotsByName(PantallaInicio);
    } // setupUi

    void retranslateUi(QWidget *PantallaInicio)
    {
        PantallaInicio->setWindowTitle(QApplication::translate("PantallaInicio", "Form", 0));
        pushButton->setText(QApplication::translate("PantallaInicio", "PushButton", 0));
    } // retranslateUi

};

namespace Ui {
    class PantallaInicio: public Ui_PantallaInicio {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PANTALLAINICIO_H
