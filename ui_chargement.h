/********************************************************************************
** Form generated from reading UI file 'chargement.ui'
**
** Created by: Qt User Interface Compiler version 6.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHARGEMENT_H
#define UI_CHARGEMENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QProgressBar>

QT_BEGIN_NAMESPACE

class Ui_chargement
{
public:
    QProgressBar *barre;

    void setupUi(QDialog *chargement)
    {
        if (chargement->objectName().isEmpty())
            chargement->setObjectName("chargement");
        chargement->resize(857, 592);
        barre = new QProgressBar(chargement);
        barre->setObjectName("barre");
        barre->setGeometry(QRect(90, 120, 551, 141));
        barre->setValue(24);

        retranslateUi(chargement);

        QMetaObject::connectSlotsByName(chargement);
    } // setupUi

    void retranslateUi(QDialog *chargement)
    {
        chargement->setWindowTitle(QCoreApplication::translate("chargement", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class chargement: public Ui_chargement {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHARGEMENT_H
