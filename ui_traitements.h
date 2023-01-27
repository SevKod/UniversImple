/********************************************************************************
** Form generated from reading UI file 'traitements.ui'
**
** Created by: Qt User Interface Compiler version 6.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRAITEMENTS_H
#define UI_TRAITEMENTS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_traitements
{
public:
    QLabel *LBLtr;
    QPushButton *pushButton;

    void setupUi(QDialog *traitements)
    {
        if (traitements->objectName().isEmpty())
            traitements->setObjectName("traitements");
        traitements->resize(832, 523);
        LBLtr = new QLabel(traitements);
        LBLtr->setObjectName("LBLtr");
        LBLtr->setGeometry(QRect(20, 10, 621, 491));
        pushButton = new QPushButton(traitements);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(690, 130, 101, 41));

        retranslateUi(traitements);

        QMetaObject::connectSlotsByName(traitements);
    } // setupUi

    void retranslateUi(QDialog *traitements)
    {
        traitements->setWindowTitle(QCoreApplication::translate("traitements", "Dialog", nullptr));
        LBLtr->setText(QString());
        pushButton->setText(QCoreApplication::translate("traitements", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class traitements: public Ui_traitements {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRAITEMENTS_H
