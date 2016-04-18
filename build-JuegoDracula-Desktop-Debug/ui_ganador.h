/********************************************************************************
** Form generated from reading UI file 'ganador.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GANADOR_H
#define UI_GANADOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_Ganador
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QLabel *label_2;

    void setupUi(QDialog *Ganador)
    {
        if (Ganador->objectName().isEmpty())
            Ganador->setObjectName(QStringLiteral("Ganador"));
        Ganador->resize(400, 300);
        buttonBox = new QDialogButtonBox(Ganador);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(40, 260, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label = new QLabel(Ganador);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(80, 10, 231, 31));
        label_2 = new QLabel(Ganador);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(-10, 50, 391, 211));
        label_2->setPixmap(QPixmap(QString::fromUtf8("logo.png")));
        label_2->setScaledContents(true);

        retranslateUi(Ganador);
        QObject::connect(buttonBox, SIGNAL(accepted()), Ganador, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Ganador, SLOT(reject()));

        QMetaObject::connectSlotsByName(Ganador);
    } // setupUi

    void retranslateUi(QDialog *Ganador)
    {
        Ganador->setWindowTitle(QApplication::translate("Ganador", "Dialog", 0));
        label->setText(QString());
        label_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Ganador: public Ui_Ganador {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GANADOR_H
