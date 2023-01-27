/********************************************************************************
** Form generated from reading UI file 'apropos.ui'
**
** Created by: Qt User Interface Compiler version 6.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_APROPOS_H
#define UI_APROPOS_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_apropos
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;

    void setupUi(QDialog *apropos)
    {
        if (apropos->objectName().isEmpty())
            apropos->setObjectName("apropos");
        apropos->resize(400, 300);
        QIcon icon;
        icon.addFile(QString::fromUtf8("UniversImple.png"), QSize(), QIcon::Normal, QIcon::Off);
        apropos->setWindowIcon(icon);
        verticalLayout = new QVBoxLayout(apropos);
        verticalLayout->setObjectName("verticalLayout");
        label = new QLabel(apropos);
        label->setObjectName("label");
        QFont font;
        font.setPointSize(18);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);


        retranslateUi(apropos);

        QMetaObject::connectSlotsByName(apropos);
    } // setupUi

    void retranslateUi(QDialog *apropos)
    {
        apropos->setWindowTitle(QCoreApplication::translate("apropos", "A propos", nullptr));
        label->setText(QCoreApplication::translate("apropos", "Cette application permet \n"
"de traiter des images\n"
" Pour l'utilisation\n"
" reportez-vous au\n"
" manuel fourni", nullptr));
    } // retranslateUi

};

namespace Ui {
    class apropos: public Ui_apropos {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_APROPOS_H
