/********************************************************************************
** Form generated from reading UI file 'histogramme.ui'
**
** Created by: Qt User Interface Compiler version 6.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HISTOGRAMME_H
#define UI_HISTOGRAMME_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_histogramme
{
public:
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout_3;
    QLabel *label_2;
    QLabel *LBLpost;
    QGraphicsView *pre;
    QLabel *label;
    QLabel *LBLpre;
    QGraphicsView *post;
    QLabel *label_3;
    QLabel *label_4;

    void setupUi(QDialog *histogramme)
    {
        if (histogramme->objectName().isEmpty())
            histogramme->setObjectName("histogramme");
        histogramme->resize(1500, 691);
        QIcon icon;
        icon.addFile(QString::fromUtf8("UniversImple.png"), QSize(), QIcon::Normal, QIcon::Off);
        histogramme->setWindowIcon(icon);
        gridLayout_2 = new QGridLayout(histogramme);
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName("gridLayout_3");
        label_2 = new QLabel(histogramme);
        label_2->setObjectName("label_2");
        QFont font;
        font.setPointSize(12);
        label_2->setFont(font);

        gridLayout_3->addWidget(label_2, 0, 0, 1, 1, Qt::AlignHCenter|Qt::AlignVCenter);

        LBLpost = new QLabel(histogramme);
        LBLpost->setObjectName("LBLpost");
        LBLpost->setMinimumSize(QSize(1, 1));
        LBLpost->setFont(font);

        gridLayout_3->addWidget(LBLpost, 3, 0, 1, 1);

        pre = new QGraphicsView(histogramme);
        pre->setObjectName("pre");
        pre->setMinimumSize(QSize(0, 0));
        pre->setSizeIncrement(QSize(0, 0));
        pre->setBaseSize(QSize(0, 0));
        pre->setInteractive(true);

        gridLayout_3->addWidget(pre, 1, 1, 1, 1);

        label = new QLabel(histogramme);
        label->setObjectName("label");
        label->setFont(font);

        gridLayout_3->addWidget(label, 0, 1, 1, 1, Qt::AlignHCenter|Qt::AlignVCenter);

        LBLpre = new QLabel(histogramme);
        LBLpre->setObjectName("LBLpre");
        LBLpre->setMinimumSize(QSize(1, 1));

        gridLayout_3->addWidget(LBLpre, 1, 0, 1, 1);

        post = new QGraphicsView(histogramme);
        post->setObjectName("post");

        gridLayout_3->addWidget(post, 3, 1, 1, 1);

        label_3 = new QLabel(histogramme);
        label_3->setObjectName("label_3");
        label_3->setFont(font);

        gridLayout_3->addWidget(label_3, 2, 0, 1, 1, Qt::AlignHCenter|Qt::AlignVCenter);

        label_4 = new QLabel(histogramme);
        label_4->setObjectName("label_4");
        label_4->setFont(font);

        gridLayout_3->addWidget(label_4, 2, 1, 1, 1, Qt::AlignHCenter|Qt::AlignVCenter);


        gridLayout_2->addLayout(gridLayout_3, 0, 0, 1, 1);


        retranslateUi(histogramme);

        QMetaObject::connectSlotsByName(histogramme);
    } // setupUi

    void retranslateUi(QDialog *histogramme)
    {
        histogramme->setWindowTitle(QCoreApplication::translate("histogramme", "Histogramme", nullptr));
        label_2->setText(QCoreApplication::translate("histogramme", "Image pr\303\251-traitement", nullptr));
        LBLpost->setText(QCoreApplication::translate("histogramme", "txtxtxtx", nullptr));
        label->setText(QCoreApplication::translate("histogramme", "Histogramme pr\303\251-traitement", nullptr));
        LBLpre->setText(QCoreApplication::translate("histogramme", "TextLabel", nullptr));
        label_3->setText(QCoreApplication::translate("histogramme", "Image post-traitement", nullptr));
        label_4->setText(QCoreApplication::translate("histogramme", "Histogramme post-traitement", nullptr));
    } // retranslateUi

};

namespace Ui {
    class histogramme: public Ui_histogramme {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HISTOGRAMME_H
