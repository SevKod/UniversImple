/********************************************************************************
** Form generated from reading UI file 'fentr.ui'
**
** Created by: Qt User Interface Compiler version 6.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FENTR_H
#define UI_FENTR_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FenTr
{
public:
    QAction *actionTEST1;
    QWidget *centralwidget;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *FenTr)
    {
        if (FenTr->objectName().isEmpty())
            FenTr->setObjectName("FenTr");
        FenTr->resize(1085, 600);
        QIcon icon;
        icon.addFile(QString::fromUtf8("UniversImple.png"), QSize(), QIcon::Normal, QIcon::Off);
        FenTr->setWindowIcon(icon);
        actionTEST1 = new QAction(FenTr);
        actionTEST1->setObjectName("actionTEST1");
        centralwidget = new QWidget(FenTr);
        centralwidget->setObjectName("centralwidget");
        FenTr->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(FenTr);
        statusbar->setObjectName("statusbar");
        FenTr->setStatusBar(statusbar);

        retranslateUi(FenTr);

        QMetaObject::connectSlotsByName(FenTr);
    } // setupUi

    void retranslateUi(QMainWindow *FenTr)
    {
        FenTr->setWindowTitle(QCoreApplication::translate("FenTr", "Traitements", nullptr));
        actionTEST1->setText(QCoreApplication::translate("FenTr", "TEST1", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FenTr: public Ui_FenTr {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FENTR_H
