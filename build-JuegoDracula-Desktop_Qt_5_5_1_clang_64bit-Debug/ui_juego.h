/********************************************************************************
** Form generated from reading UI file 'juego.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
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
    QLabel *lblDuracion;
    QLabel *lblTiempo;
    QPushButton *pushButton;
    QPushButton *btnCarta4Jugador2;
    QPushButton *btnCarta3Jugador2;
    QPushButton *btnCarta1Jugador2;
    QPushButton *btnCarta2Jugador2;
    QLabel *lblJugador1;
    QLabel *lblJugador2;
    QLabel *lblScoreColumn0;
    QLabel *lblScoreColumn1;
    QLabel *lblScoreColumn2;
    QLabel *lblScoreRow2;
    QLabel *lblScoreRow1;
    QLabel *lblScoreRow0;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;

    void setupUi(QMainWindow *Juego)
    {
        if (Juego->objectName().isEmpty())
            Juego->setObjectName(QStringLiteral("Juego"));
        Juego->setEnabled(true);
        Juego->resize(992, 723);
        Juego->setMinimumSize(QSize(992, 723));
        Juego->setMaximumSize(QSize(992, 723));
        Juego->setLayoutDirection(Qt::LeftToRight);
        Juego->setStyleSheet(QLatin1String("background-image: url(:/other/cards/background.jpg);\n"
""));
        centralWidget = new QWidget(Juego);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        btnMatriz1 = new QPushButton(centralWidget);
        btnMatriz1->setObjectName(QStringLiteral("btnMatriz1"));
        btnMatriz1->setGeometry(QRect(330, 10, 81, 111));
        QIcon icon;
        icon.addFile(QStringLiteral(":/cards/cards/no.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnMatriz1->setIcon(icon);
        btnMatriz1->setIconSize(QSize(90, 90));
        btnMatriz1->setFlat(false);
        btnMatriz2 = new QPushButton(centralWidget);
        btnMatriz2->setObjectName(QStringLiteral("btnMatriz2"));
        btnMatriz2->setGeometry(QRect(450, 10, 81, 111));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/cards/cards/ok.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnMatriz2->setIcon(icon1);
        btnMatriz2->setIconSize(QSize(90, 90));
        btnMatriz2->setFlat(false);
        btnMatriz3 = new QPushButton(centralWidget);
        btnMatriz3->setObjectName(QStringLiteral("btnMatriz3"));
        btnMatriz3->setGeometry(QRect(570, 10, 81, 111));
        btnMatriz3->setIcon(icon);
        btnMatriz3->setIconSize(QSize(90, 90));
        btnMatriz3->setFlat(false);
        btnMatriz5 = new QPushButton(centralWidget);
        btnMatriz5->setObjectName(QStringLiteral("btnMatriz5"));
        btnMatriz5->setEnabled(true);
        btnMatriz5->setGeometry(QRect(450, 160, 81, 111));
        btnMatriz5->setIconSize(QSize(90, 90));
        btnMatriz5->setFlat(false);
        btnMatriz6 = new QPushButton(centralWidget);
        btnMatriz6->setObjectName(QStringLiteral("btnMatriz6"));
        btnMatriz6->setGeometry(QRect(570, 160, 81, 111));
        btnMatriz6->setIcon(icon1);
        btnMatriz6->setIconSize(QSize(90, 90));
        btnMatriz6->setFlat(false);
        btnMatriz4 = new QPushButton(centralWidget);
        btnMatriz4->setObjectName(QStringLiteral("btnMatriz4"));
        btnMatriz4->setGeometry(QRect(330, 160, 81, 111));
        btnMatriz4->setIcon(icon1);
        btnMatriz4->setIconSize(QSize(90, 90));
        btnMatriz4->setFlat(false);
        btnMatriz8 = new QPushButton(centralWidget);
        btnMatriz8->setObjectName(QStringLiteral("btnMatriz8"));
        btnMatriz8->setGeometry(QRect(450, 310, 81, 111));
        btnMatriz8->setIcon(icon1);
        btnMatriz8->setIconSize(QSize(90, 90));
        btnMatriz8->setFlat(false);
        btnMatriz9 = new QPushButton(centralWidget);
        btnMatriz9->setObjectName(QStringLiteral("btnMatriz9"));
        btnMatriz9->setGeometry(QRect(570, 310, 81, 111));
        btnMatriz9->setIcon(icon);
        btnMatriz9->setIconSize(QSize(90, 90));
        btnMatriz9->setFlat(false);
        btnMatriz7 = new QPushButton(centralWidget);
        btnMatriz7->setObjectName(QStringLiteral("btnMatriz7"));
        btnMatriz7->setGeometry(QRect(330, 310, 81, 111));
        btnMatriz7->setIcon(icon);
        btnMatriz7->setIconSize(QSize(90, 90));
        btnMatriz7->setFlat(false);
        btnMazo = new QPushButton(centralWidget);
        btnMazo->setObjectName(QStringLiteral("btnMazo"));
        btnMazo->setGeometry(QRect(900, 350, 81, 111));
        btnMazo->setLayoutDirection(Qt::LeftToRight);
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/cards/cards/back.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnMazo->setIcon(icon2);
        btnMazo->setIconSize(QSize(100, 100));
        btnMazo->setFlat(false);
        btnCarta3Jugador1 = new QPushButton(centralWidget);
        btnCarta3Jugador1->setObjectName(QStringLiteral("btnCarta3Jugador1"));
        btnCarta3Jugador1->setGeometry(QRect(230, 550, 81, 111));
        btnCarta3Jugador1->setIconSize(QSize(90, 90));
        btnCarta3Jugador1->setFlat(false);
        btnCarta1Jugador1 = new QPushButton(centralWidget);
        btnCarta1Jugador1->setObjectName(QStringLiteral("btnCarta1Jugador1"));
        btnCarta1Jugador1->setGeometry(QRect(10, 550, 81, 111));
        btnCarta1Jugador1->setIconSize(QSize(90, 90));
        btnCarta1Jugador1->setFlat(false);
        btnCarta2Jugador1 = new QPushButton(centralWidget);
        btnCarta2Jugador1->setObjectName(QStringLiteral("btnCarta2Jugador1"));
        btnCarta2Jugador1->setGeometry(QRect(120, 550, 81, 111));
        btnCarta2Jugador1->setIconSize(QSize(90, 90));
        btnCarta2Jugador1->setFlat(false);
        btnCarta4Jugador1 = new QPushButton(centralWidget);
        btnCarta4Jugador1->setObjectName(QStringLiteral("btnCarta4Jugador1"));
        btnCarta4Jugador1->setGeometry(QRect(340, 550, 81, 111));
        btnCarta4Jugador1->setIconSize(QSize(90, 90));
        btnCarta4Jugador1->setFlat(false);
        lblDuracion = new QLabel(centralWidget);
        lblDuracion->setObjectName(QStringLiteral("lblDuracion"));
        lblDuracion->setGeometry(QRect(20, 10, 161, 51));
        QFont font;
        font.setFamily(QStringLiteral("Arial"));
        font.setPointSize(36);
        font.setBold(true);
        font.setWeight(75);
        lblDuracion->setFont(font);
        lblDuracion->setScaledContents(false);
        lblTiempo = new QLabel(centralWidget);
        lblTiempo->setObjectName(QStringLiteral("lblTiempo"));
        lblTiempo->setGeometry(QRect(20, 70, 161, 61));
        QFont font1;
        font1.setFamily(QStringLiteral("Arial"));
        font1.setPointSize(24);
        lblTiempo->setFont(font1);
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(850, 10, 131, 41));
        QPalette palette;
        QBrush brush(QColor(177, 177, 177, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(50, 50, 50, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        QBrush brush2(QColor(64, 64, 64, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        pushButton->setPalette(palette);
        QFont font2;
        pushButton->setFont(font2);
        pushButton->setAutoFillBackground(false);
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/other/cards/undo.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon3);
        pushButton->setIconSize(QSize(20, 50));
        btnCarta4Jugador2 = new QPushButton(centralWidget);
        btnCarta4Jugador2->setObjectName(QStringLiteral("btnCarta4Jugador2"));
        btnCarta4Jugador2->setGeometry(QRect(900, 550, 81, 111));
        btnCarta4Jugador2->setIconSize(QSize(90, 90));
        btnCarta4Jugador2->setFlat(false);
        btnCarta3Jugador2 = new QPushButton(centralWidget);
        btnCarta3Jugador2->setObjectName(QStringLiteral("btnCarta3Jugador2"));
        btnCarta3Jugador2->setGeometry(QRect(790, 550, 81, 111));
        btnCarta3Jugador2->setIconSize(QSize(90, 90));
        btnCarta3Jugador2->setFlat(false);
        btnCarta1Jugador2 = new QPushButton(centralWidget);
        btnCarta1Jugador2->setObjectName(QStringLiteral("btnCarta1Jugador2"));
        btnCarta1Jugador2->setGeometry(QRect(570, 550, 81, 111));
        btnCarta1Jugador2->setIconSize(QSize(90, 90));
        btnCarta1Jugador2->setFlat(false);
        btnCarta2Jugador2 = new QPushButton(centralWidget);
        btnCarta2Jugador2->setObjectName(QStringLiteral("btnCarta2Jugador2"));
        btnCarta2Jugador2->setGeometry(QRect(680, 550, 81, 111));
        btnCarta2Jugador2->setIconSize(QSize(90, 90));
        btnCarta2Jugador2->setFlat(false);
        lblJugador1 = new QLabel(centralWidget);
        lblJugador1->setObjectName(QStringLiteral("lblJugador1"));
        lblJugador1->setGeometry(QRect(10, 510, 111, 31));
        lblJugador2 = new QLabel(centralWidget);
        lblJugador2->setObjectName(QStringLiteral("lblJugador2"));
        lblJugador2->setGeometry(QRect(870, 510, 111, 31));
        lblScoreColumn0 = new QLabel(centralWidget);
        lblScoreColumn0->setObjectName(QStringLiteral("lblScoreColumn0"));
        lblScoreColumn0->setGeometry(QRect(340, 440, 59, 21));
        lblScoreColumn1 = new QLabel(centralWidget);
        lblScoreColumn1->setObjectName(QStringLiteral("lblScoreColumn1"));
        lblScoreColumn1->setGeometry(QRect(460, 440, 59, 21));
        lblScoreColumn2 = new QLabel(centralWidget);
        lblScoreColumn2->setObjectName(QStringLiteral("lblScoreColumn2"));
        lblScoreColumn2->setGeometry(QRect(580, 440, 59, 21));
        lblScoreRow2 = new QLabel(centralWidget);
        lblScoreRow2->setObjectName(QStringLiteral("lblScoreRow2"));
        lblScoreRow2->setGeometry(QRect(670, 350, 59, 21));
        lblScoreRow1 = new QLabel(centralWidget);
        lblScoreRow1->setObjectName(QStringLiteral("lblScoreRow1"));
        lblScoreRow1->setGeometry(QRect(670, 200, 59, 21));
        lblScoreRow0 = new QLabel(centralWidget);
        lblScoreRow0->setObjectName(QStringLiteral("lblScoreRow0"));
        lblScoreRow0->setGeometry(QRect(670, 50, 59, 21));
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
        Juego->setWindowTitle(QApplication::translate("Juego", "Dr\303\241cula - Juego", 0));
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
        lblDuracion->setText(QApplication::translate("Juego", "<html><head/><body><p><span style=\" color:#ffffff;\">Duraci\303\263n</span></p></body></html>", 0));
        lblTiempo->setText(QApplication::translate("Juego", "<html><head/><body><p><br/></p></body></html>", 0));
        pushButton->setText(QApplication::translate("Juego", "Deshacer", 0));
        btnCarta4Jugador2->setText(QString());
        btnCarta3Jugador2->setText(QString());
        btnCarta1Jugador2->setText(QString());
        btnCarta2Jugador2->setText(QString());
        lblJugador1->setText(QApplication::translate("Juego", "<html><head/><body><p><span style=\" font-size:18pt; color:#ffffff;\">Jugador 1</span></p></body></html>", 0));
        lblJugador2->setText(QApplication::translate("Juego", "<html><head/><body><p><span style=\" font-size:18pt; color:#ffffff;\">Jugador 2</span></p></body></html>", 0));
        lblScoreColumn0->setText(QApplication::translate("Juego", "<html><head/><body><p><span style=\" font-size:18pt; color:#ffffff;\">0</span></p></body></html>", 0));
        lblScoreColumn1->setText(QApplication::translate("Juego", "<html><head/><body><p><span style=\" font-size:18pt; color:#ffffff;\">0</span></p></body></html>", 0));
        lblScoreColumn2->setText(QApplication::translate("Juego", "<html><head/><body><p><span style=\" font-size:18pt; color:#ffffff;\">0</span></p></body></html>", 0));
        lblScoreRow2->setText(QApplication::translate("Juego", "<html><head/><body><p><span style=\" font-size:18pt; color:#ffffff;\">0</span></p></body></html>", 0));
        lblScoreRow1->setText(QApplication::translate("Juego", "<html><head/><body><p><span style=\" font-size:18pt; color:#ffffff;\">0</span></p></body></html>", 0));
        lblScoreRow0->setText(QApplication::translate("Juego", "<html><head/><body><p><span style=\" font-size:18pt; color:#ffffff;\">0</span></p></body></html>", 0));
    } // retranslateUi

};

namespace Ui {
    class Juego: public Ui_Juego {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_JUEGO_H
