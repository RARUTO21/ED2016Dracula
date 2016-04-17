/********************************************************************************
** Form generated from reading UI file 'escogerjugador.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ESCOGERJUGADOR_H
#define UI_ESCOGERJUGADOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_EscogerJugador
{
public:
    QPushButton *btnJugador1;
    QPushButton *btnJugador2;
    QPushButton *btnMazo;
    QLabel *lblJugador1;
    QLabel *lblJugador2;

    void setupUi(QDialog *EscogerJugador)
    {
        if (EscogerJugador->objectName().isEmpty())
            EscogerJugador->setObjectName(QStringLiteral("EscogerJugador"));
        EscogerJugador->resize(640, 480);
        EscogerJugador->setStyleSheet(QStringLiteral("background-image: url(:/other/cards/background.jpg);"));
        btnJugador1 = new QPushButton(EscogerJugador);
        btnJugador1->setObjectName(QStringLiteral("btnJugador1"));
        btnJugador1->setEnabled(true);
        btnJugador1->setGeometry(QRect(390, 90, 81, 111));
        btnJugador1->setAutoFillBackground(false);
        btnJugador1->setStyleSheet(QStringLiteral(""));
        btnJugador1->setIconSize(QSize(90, 90));
        btnJugador1->setFlat(false);
        btnJugador2 = new QPushButton(EscogerJugador);
        btnJugador2->setObjectName(QStringLiteral("btnJugador2"));
        btnJugador2->setEnabled(false);
        btnJugador2->setGeometry(QRect(390, 300, 81, 111));
        btnJugador2->setStyleSheet(QStringLiteral(""));
        btnJugador2->setIconSize(QSize(90, 90));
        btnJugador2->setFlat(false);
        btnMazo = new QPushButton(EscogerJugador);
        btnMazo->setObjectName(QStringLiteral("btnMazo"));
        btnMazo->setGeometry(QRect(130, 170, 81, 111));
        btnMazo->setLayoutDirection(Qt::LeftToRight);
        QIcon icon;
        icon.addFile(QStringLiteral(":/cards/cards/back.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnMazo->setIcon(icon);
        btnMazo->setIconSize(QSize(100, 100));
        btnMazo->setFlat(false);
        lblJugador1 = new QLabel(EscogerJugador);
        lblJugador1->setObjectName(QStringLiteral("lblJugador1"));
        lblJugador1->setGeometry(QRect(390, 60, 91, 20));
        QFont font;
        font.setFamily(QStringLiteral("Arial"));
        font.setPointSize(18);
        lblJugador1->setFont(font);
        lblJugador2 = new QLabel(EscogerJugador);
        lblJugador2->setObjectName(QStringLiteral("lblJugador2"));
        lblJugador2->setGeometry(QRect(390, 270, 91, 21));

        retranslateUi(EscogerJugador);

        QMetaObject::connectSlotsByName(EscogerJugador);
    } // setupUi

    void retranslateUi(QDialog *EscogerJugador)
    {
        EscogerJugador->setWindowTitle(QApplication::translate("EscogerJugador", "Dr\303\241cula - Inicio", 0));
        btnJugador1->setText(QString());
        btnJugador2->setText(QString());
        btnMazo->setText(QString());
        lblJugador1->setText(QApplication::translate("EscogerJugador", "<html><head/><body><p><span style=\" color:#ffffff;\">Jugador 1</span></p></body></html>", 0));
        lblJugador2->setText(QApplication::translate("EscogerJugador", "<html><head/><body><p><span style=\" font-size:18pt; color:#ffffff;\">Jugador 2</span></p></body></html>", 0));
    } // retranslateUi

};

namespace Ui {
    class EscogerJugador: public Ui_EscogerJugador {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ESCOGERJUGADOR_H
