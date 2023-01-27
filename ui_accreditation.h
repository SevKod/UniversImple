/********************************************************************************
** Form generated from reading UI file 'accreditation.ui'
**
** Created by: Qt User Interface Compiler version 6.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ACCREDITATION_H
#define UI_ACCREDITATION_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Accreditation
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *LABid;
    QLineEdit *code;
    QPushButton *Valider_Accred;
    QPushButton *Annuler_Accred;

    void setupUi(QDialog *Accreditation)
    {
        if (Accreditation->objectName().isEmpty())
            Accreditation->setObjectName("Accreditation");
        Accreditation->resize(416, 128);
        QIcon icon;
        icon.addFile(QString::fromUtf8("UniversImple.png"), QSize(), QIcon::Normal, QIcon::Off);
        Accreditation->setWindowIcon(icon);
        verticalLayout = new QVBoxLayout(Accreditation);
        verticalLayout->setObjectName("verticalLayout");
        LABid = new QLabel(Accreditation);
        LABid->setObjectName("LABid");
        LABid->setMaximumSize(QSize(16777215, 1000));

        verticalLayout->addWidget(LABid, 0, Qt::AlignHCenter|Qt::AlignBottom);

        code = new QLineEdit(Accreditation);
        code->setObjectName("code");

        verticalLayout->addWidget(code);

        Valider_Accred = new QPushButton(Accreditation);
        Valider_Accred->setObjectName("Valider_Accred");

        verticalLayout->addWidget(Valider_Accred);

        Annuler_Accred = new QPushButton(Accreditation);
        Annuler_Accred->setObjectName("Annuler_Accred");

        verticalLayout->addWidget(Annuler_Accred);


        retranslateUi(Accreditation);

        QMetaObject::connectSlotsByName(Accreditation);
    } // setupUi

    void retranslateUi(QDialog *Accreditation)
    {
        Accreditation->setWindowTitle(QCoreApplication::translate("Accreditation", "Login", nullptr));
        LABid->setText(QCoreApplication::translate("Accreditation", "Veuillez entrer votre code identifiant : ", nullptr));
        Valider_Accred->setText(QCoreApplication::translate("Accreditation", "Valider", nullptr));
        Annuler_Accred->setText(QCoreApplication::translate("Accreditation", "Annuler", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Accreditation: public Ui_Accreditation {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ACCREDITATION_H
