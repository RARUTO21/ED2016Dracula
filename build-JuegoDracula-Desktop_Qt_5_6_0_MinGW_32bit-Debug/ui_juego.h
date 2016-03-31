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
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Juego
{
public:
    QWidget *centralWidget;
    QPushButton *pushButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Juego)
    {
        if (Juego->objectName().isEmpty())
            Juego->setObjectName(QStringLiteral("Juego"));
        Juego->resize(400, 300);
        centralWidget = new QWidget(Juego);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(140, 120, 113, 32));
        Juego->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Juego);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 22));
        Juego->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Juego);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        Juego->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(Juego);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        Juego->setStatusBar(statusBar);

        retranslateUi(Juego);

        QMetaObject::connectSlotsByName(Juego);
    } // setupUi

    void retranslateUi(QMainWindow *Juego)
    {
        Juego->setWindowTitle(QApplication::translate("Juego", "Juego", 0));
        pushButton->setText(QApplication::translate("Juego", "PushButton", 0));
    } // retranslateUi

};

namespace Ui {
    class Juego: public Ui_Juego {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_JUEGO_H
