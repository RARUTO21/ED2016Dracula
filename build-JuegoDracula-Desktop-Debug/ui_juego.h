/********************************************************************************
** Form generated from reading UI file 'juego.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_JUEGO_H
#define UI_JUEGO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Juego
{
public:
    QWidget *centralWidget;
    QPushButton *btnMatriz1;
    QPushButton *btnMatriz2;
    QPushButton *btnMatriz3;
    QPushButton *btnMatriz5;
    QPushButton *btnMatriz6;
    QPushButton *btnMatriz4;
    QPushButton *btnMatriz8;
    QPushButton *btnMatriz9;
    QPushButton *btnMatriz7;
    QPushButton *btnMazo;
    QPushButton *btnCarta3Jugador1;
    QPushButton *btnCarta1Jugador1;
    QPushButton *btnCarta2Jugador1;
    QPushButton *btnCarta4Jugador1;
    QPushButton *btnCarta4Jugador2;
    QPushButton *btnCarta1Jugador2;
    QPushButton *btnCarta2Jugador2;
    QPushButton *btnCarta3Jugador2;
    QLabel *lblDuracion;
    QLabel *lblTiempo;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;

    void setupUi(QMainWindow *Juego)
    {
        if (Juego->objectName().isEmpty())
            Juego->setObjectName(QStringLiteral("Juego"));
        Juego->resize(992, 723);
        QIcon icon;
        icon.addFile(QStringLiteral("../../hongo.ico"), QSize(), QIcon::Normal, QIcon::Off);
        Juego->setWindowIcon(icon);
        Juego->setLayoutDirection(Qt::LeftToRight);
        Juego->setStyleSheet(QLatin1String("background-image: url(:/other/cards/background.jpg);\n"
""));
        centralWidget = new QWidget(Juego);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        btnMatriz1 = new QPushButton(centralWidget);
        btnMatriz1->setObjectName(QStringLiteral("btnMatriz1"));
        btnMatriz1->setGeometry(QRect(330, 50, 81, 111));
        btnMatriz1->setIconSize(QSize(100, 105));
        btnMatriz1->setFlat(false);
        btnMatriz2 = new QPushButton(centralWidget);
        btnMatriz2->setObjectName(QStringLiteral("btnMatriz2"));
        btnMatriz2->setGeometry(QRect(450, 50, 81, 111));
        btnMatriz2->setIconSize(QSize(100, 105));
        btnMatriz2->setFlat(false);
        btnMatriz3 = new QPushButton(centralWidget);
        btnMatriz3->setObjectName(QStringLiteral("btnMatriz3"));
        btnMatriz3->setGeometry(QRect(570, 50, 81, 111));
        btnMatriz3->setIconSize(QSize(100, 105));
        btnMatriz3->setFlat(false);
        btnMatriz5 = new QPushButton(centralWidget);
        btnMatriz5->setObjectName(QStringLiteral("btnMatriz5"));
        btnMatriz5->setGeometry(QRect(450, 200, 81, 111));
        btnMatriz5->setIconSize(QSize(100, 105));
        btnMatriz5->setFlat(false);
        btnMatriz6 = new QPushButton(centralWidget);
        btnMatriz6->setObjectName(QStringLiteral("btnMatriz6"));
        btnMatriz6->setGeometry(QRect(570, 200, 81, 111));
        btnMatriz6->setIconSize(QSize(100, 105));
        btnMatriz6->setFlat(false);
        btnMatriz4 = new QPushButton(centralWidget);
        btnMatriz4->setObjectName(QStringLiteral("btnMatriz4"));
        btnMatriz4->setGeometry(QRect(330, 200, 81, 111));
        btnMatriz4->setIconSize(QSize(100, 105));
        btnMatriz4->setFlat(false);
        btnMatriz8 = new QPushButton(centralWidget);
        btnMatriz8->setObjectName(QStringLiteral("btnMatriz8"));
        btnMatriz8->setGeometry(QRect(450, 350, 81, 111));
        btnMatriz8->setIconSize(QSize(100, 105));
        btnMatriz8->setFlat(false);
        btnMatriz9 = new QPushButton(centralWidget);
        btnMatriz9->setObjectName(QStringLiteral("btnMatriz9"));
        btnMatriz9->setGeometry(QRect(570, 350, 81, 111));
        btnMatriz9->setIconSize(QSize(100, 105));
        btnMatriz9->setFlat(false);
        btnMatriz7 = new QPushButton(centralWidget);
        btnMatriz7->setObjectName(QStringLiteral("btnMatriz7"));
        btnMatriz7->setGeometry(QRect(330, 350, 81, 111));
        btnMatriz7->setIconSize(QSize(100, 105));
        btnMatriz7->setFlat(false);
        btnMazo = new QPushButton(centralWidget);
        btnMazo->setObjectName(QStringLiteral("btnMazo"));
        btnMazo->setGeometry(QRect(900, 350, 81, 111));
        btnMazo->setLayoutDirection(Qt::LeftToRight);
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/cards/cards/back.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnMazo->setIcon(icon1);
        btnMazo->setIconSize(QSize(100, 100));
        btnMazo->setFlat(false);
        btnCarta3Jugador1 = new QPushButton(centralWidget);
        btnCarta3Jugador1->setObjectName(QStringLiteral("btnCarta3Jugador1"));
        btnCarta3Jugador1->setGeometry(QRect(230, 550, 81, 111));
        btnCarta3Jugador1->setIconSize(QSize(100, 105));
        btnCarta3Jugador1->setFlat(false);
        btnCarta1Jugador1 = new QPushButton(centralWidget);
        btnCarta1Jugador1->setObjectName(QStringLiteral("btnCarta1Jugador1"));
        btnCarta1Jugador1->setGeometry(QRect(10, 550, 81, 111));
        btnCarta1Jugador1->setIconSize(QSize(100, 105));
        btnCarta1Jugador1->setFlat(false);
        btnCarta2Jugador1 = new QPushButton(centralWidget);
        btnCarta2Jugador1->setObjectName(QStringLiteral("btnCarta2Jugador1"));
        btnCarta2Jugador1->setGeometry(QRect(120, 550, 81, 111));
        btnCarta2Jugador1->setIconSize(QSize(100, 105));
        btnCarta2Jugador1->setFlat(false);
        btnCarta4Jugador1 = new QPushButton(centralWidget);
        btnCarta4Jugador1->setObjectName(QStringLiteral("btnCarta4Jugador1"));
        btnCarta4Jugador1->setGeometry(QRect(340, 550, 81, 111));
        btnCarta4Jugador1->setIconSize(QSize(100, 105));
        btnCarta4Jugador1->setFlat(false);
        btnCarta4Jugador2 = new QPushButton(centralWidget);
        btnCarta4Jugador2->setObjectName(QStringLiteral("btnCarta4Jugador2"));
        btnCarta4Jugador2->setGeometry(QRect(900, 550, 81, 111));
        btnCarta4Jugador2->setIconSize(QSize(100, 105));
        btnCarta4Jugador2->setFlat(false);
        btnCarta1Jugador2 = new QPushButton(centralWidget);
        btnCarta1Jugador2->setObjectName(QStringLiteral("btnCarta1Jugador2"));
        btnCarta1Jugador2->setGeometry(QRect(570, 550, 81, 111));
        btnCarta1Jugador2->setIconSize(QSize(100, 105));
        btnCarta1Jugador2->setFlat(false);
        btnCarta2Jugador2 = new QPushButton(centralWidget);
        btnCarta2Jugador2->setObjectName(QStringLiteral("btnCarta2Jugador2"));
        btnCarta2Jugador2->setGeometry(QRect(680, 550, 81, 111));
        btnCarta2Jugador2->setIconSize(QSize(100, 105));
        btnCarta2Jugador2->setFlat(false);
        btnCarta3Jugador2 = new QPushButton(centralWidget);
        btnCarta3Jugador2->setObjectName(QStringLiteral("btnCarta3Jugador2"));
        btnCarta3Jugador2->setGeometry(QRect(790, 550, 81, 111));
        btnCarta3Jugador2->setIconSize(QSize(100, 105));
        btnCarta3Jugador2->setFlat(false);
        lblDuracion = new QLabel(centralWidget);
        lblDuracion->setObjectName(QStringLiteral("lblDuracion"));
        lblDuracion->setGeometry(QRect(30, 50, 161, 51));
        QFont font;
        font.setFamily(QStringLiteral("Arial"));
        font.setPointSize(36);
        font.setBold(true);
        font.setWeight(75);
        lblDuracion->setFont(font);
        lblDuracion->setScaledContents(false);
        lblTiempo = new QLabel(centralWidget);
        lblTiempo->setObjectName(QStringLiteral("lblTiempo"));
        lblTiempo->setGeometry(QRect(30, 120, 161, 61));
        QFont font1;
        font1.setFamily(QStringLiteral("Arial"));
        font1.setPointSize(24);
        lblTiempo->setFont(font1);
        Juego->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Juego);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 992, 22));
        Juego->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Juego);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        Juego->addToolBar(Qt::TopToolBarArea, mainToolBar);

        retranslateUi(Juego);

        QMetaObject::connectSlotsByName(Juego);
    } // setupUi

    void retranslateUi(QMainWindow *Juego)
    {
        Juego->setWindowTitle(QApplication::translate("Juego", "Juego", 0));
        btnMatriz1->setText(QString());
        btnMatriz2->setText(QString());
        btnMatriz3->setText(QString());
        btnMatriz5->setText(QString());
        btnMatriz6->setText(QString());
        btnMatriz4->setText(QString());
        btnMatriz8->setText(QString());
        btnMatriz9->setText(QString());
        btnMatriz7->setText(QString());
        btnMazo->setText(QString());
        btnCarta3Jugador1->setText(QString());
        btnCarta1Jugador1->setText(QString());
        btnCarta2Jugador1->setText(QString());
        btnCarta4Jugador1->setText(QString());
        btnCarta4Jugador2->setText(QString());
        btnCarta1Jugador2->setText(QString());
        btnCarta2Jugador2->setText(QString());
        btnCarta3Jugador2->setText(QString());
        lblDuracion->setText(QApplication::translate("Juego", "<html><head/><body><p><span style=\" color:#ffffff;\">Duraci\303\263n</span></p></body></html>", 0));
        lblTiempo->setText(QApplication::translate("Juego", "<html><head/><body><p><span style=\" color:#ffffff; vertical-align:sub;\">00</span></p></body></html>", 0));
    } // retranslateUi

};

namespace Ui {
    class Juego: public Ui_Juego {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_JUEGO_H
