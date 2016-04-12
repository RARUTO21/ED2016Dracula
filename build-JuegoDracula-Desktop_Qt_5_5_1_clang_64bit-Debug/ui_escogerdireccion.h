/********************************************************************************
** Form generated from reading UI file 'escogerdireccion.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ESCOGERDIRECCION_H
#define UI_ESCOGERDIRECCION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_EscogerDireccion
{
public:
    QLabel *lblHorizontal;
    QLabel *lblVertical;
    QPushButton *btnHorizontal;
    QPushButton *btnVertical;

    void setupUi(QDialog *EscogerDireccion)
    {
        if (EscogerDireccion->objectName().isEmpty())
            EscogerDireccion->setObjectName(QStringLiteral("EscogerDireccion"));
        EscogerDireccion->resize(640, 480);
        EscogerDireccion->setStyleSheet(QStringLiteral("background-image: url(:/other/cards/background.jpg);"));
        lblHorizontal = new QLabel(EscogerDireccion);
        lblHorizontal->setObjectName(QStringLiteral("lblHorizontal"));
        lblHorizontal->setGeometry(QRect(140, 150, 81, 21));
        lblVertical = new QLabel(EscogerDireccion);
        lblVertical->setObjectName(QStringLiteral("lblVertical"));
        lblVertical->setGeometry(QRect(420, 150, 61, 21));
        btnHorizontal = new QPushButton(EscogerDireccion);
        btnHorizontal->setObjectName(QStringLiteral("btnHorizontal"));
        btnHorizontal->setGeometry(QRect(140, 190, 81, 111));
        btnHorizontal->setAutoFillBackground(false);
        btnHorizontal->setStyleSheet(QStringLiteral(""));
        QIcon icon;
        icon.addFile(QStringLiteral(":/cards/cards/q_corazones.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnHorizontal->setIcon(icon);
        btnHorizontal->setIconSize(QSize(90, 90));
        btnHorizontal->setFlat(false);
        btnVertical = new QPushButton(EscogerDireccion);
        btnVertical->setObjectName(QStringLiteral("btnVertical"));
        btnVertical->setGeometry(QRect(410, 190, 81, 111));
        btnVertical->setAutoFillBackground(false);
        btnVertical->setStyleSheet(QStringLiteral(""));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/cards/cards/k_corazones.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnVertical->setIcon(icon1);
        btnVertical->setIconSize(QSize(90, 90));
        btnVertical->setFlat(false);

        retranslateUi(EscogerDireccion);

        QMetaObject::connectSlotsByName(EscogerDireccion);
    } // setupUi

    void retranslateUi(QDialog *EscogerDireccion)
    {
        EscogerDireccion->setWindowTitle(QApplication::translate("EscogerDireccion", "Dr\303\241cula - Orientaci\303\263n", 0));
        lblHorizontal->setText(QApplication::translate("EscogerDireccion", "<html><head/><body><p><span style=\" font-size:18pt; color:#ffffff;\">Horizontal</span></p></body></html>", 0));
        lblVertical->setText(QApplication::translate("EscogerDireccion", "<html><head/><body><p><span style=\" font-size:18pt; color:#ffffff;\">Vertical</span></p></body></html>", 0));
        btnHorizontal->setText(QString());
        btnVertical->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class EscogerDireccion: public Ui_EscogerDireccion {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ESCOGERDIRECCION_H
