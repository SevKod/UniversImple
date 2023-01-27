/********************************************************************************
** Form generated from reading UI file 'frequentiel.ui'
**
** Created by: Qt User Interface Compiler version 6.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FREQUENTIEL_H
#define UI_FREQUENTIEL_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_frequentiel
{
public:
    QHBoxLayout *horizontalLayout;
    QGridLayout *gridLayout_2;
    QLabel *FREQPRE;
    QLabel *FREQPOST;
    QLabel *label_5;
    QLabel *label_7;
    QLabel *IMGPRE;
    QLabel *label_6;
    QLabel *label_8;
    QLabel *IMGPOST;
    QStackedWidget *PAGE_FILTRE;
    QWidget *PB;
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBox_4;
    QVBoxLayout *verticalLayout_7;
    QLabel *label_4;
    QLabel *XPB;
    QSlider *SLIDXPB;
    QLabel *YPB;
    QSlider *SLIDYPB;
    QSlider *SLIDPB;
    QLabel *TXTSLIDPB;
    QPushButton *VALIDPB;
    QWidget *PH;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_3;
    QLabel *XPH;
    QSlider *SLIDXPH;
    QLabel *YPH;
    QSlider *SLIDYPH;
    QSlider *SLIDPH;
    QLabel *TXTRAYPH;
    QPushButton *VALIDPH;
    QWidget *PBA;
    QVBoxLayout *verticalLayout_5;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_2;
    QLabel *XPBA;
    QSlider *SLIDXPBA;
    QLabel *YPBA;
    QSlider *SLIDYPBA;
    QGridLayout *gridLayout_3;
    QSlider *SLIDRSUPPB;
    QLabel *TXTLBLSUP;
    QLabel *TXTLBLINF;
    QSlider *SLIDRINFPB;
    QPushButton *VALIDPBA;
    QWidget *CB;
    QGridLayout *gridLayout;
    QPushButton *VALIDCB;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_6;
    QLabel *label;
    QLabel *XCB;
    QSlider *SLIDXCB;
    QLabel *YCB;
    QSlider *SLIDYCB;
    QGridLayout *gridLayout_5;
    QSlider *SLIDRSUPCB;
    QSlider *SLIDRINFCB;
    QLabel *TXTLBLINFCB;
    QLabel *TXTLBLSUPCB;

    void setupUi(QDialog *frequentiel)
    {
        if (frequentiel->objectName().isEmpty())
            frequentiel->setObjectName("frequentiel");
        frequentiel->resize(936, 511);
        QIcon icon;
        icon.addFile(QString::fromUtf8("UniversImple.png"), QSize(), QIcon::Normal, QIcon::Off);
        frequentiel->setWindowIcon(icon);
        horizontalLayout = new QHBoxLayout(frequentiel);
        horizontalLayout->setObjectName("horizontalLayout");
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName("gridLayout_2");
        FREQPRE = new QLabel(frequentiel);
        FREQPRE->setObjectName("FREQPRE");
        FREQPRE->setMinimumSize(QSize(1, 1));
        FREQPRE->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(FREQPRE, 3, 2, 1, 1);

        FREQPOST = new QLabel(frequentiel);
        FREQPOST->setObjectName("FREQPOST");
        FREQPOST->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(FREQPOST, 3, 3, 1, 1);

        label_5 = new QLabel(frequentiel);
        label_5->setObjectName("label_5");
        label_5->setMaximumSize(QSize(16777215, 20));
        QFont font;
        font.setPointSize(12);
        label_5->setFont(font);
        label_5->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_5, 0, 2, 1, 1);

        label_7 = new QLabel(frequentiel);
        label_7->setObjectName("label_7");
        label_7->setMaximumSize(QSize(16777215, 20));
        label_7->setFont(font);
        label_7->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_7, 2, 2, 1, 1);

        IMGPRE = new QLabel(frequentiel);
        IMGPRE->setObjectName("IMGPRE");
        IMGPRE->setMinimumSize(QSize(1, 1));
        IMGPRE->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(IMGPRE, 1, 2, 1, 1);

        label_6 = new QLabel(frequentiel);
        label_6->setObjectName("label_6");
        label_6->setMaximumSize(QSize(16777215, 20));
        label_6->setFont(font);
        label_6->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_6, 0, 3, 1, 1);

        label_8 = new QLabel(frequentiel);
        label_8->setObjectName("label_8");
        label_8->setMaximumSize(QSize(16777215, 20));
        label_8->setFont(font);
        label_8->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_8, 2, 3, 1, 1);

        IMGPOST = new QLabel(frequentiel);
        IMGPOST->setObjectName("IMGPOST");
        IMGPOST->setMinimumSize(QSize(1, 1));
        IMGPOST->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(IMGPOST, 1, 3, 1, 1);


        horizontalLayout->addLayout(gridLayout_2);

        PAGE_FILTRE = new QStackedWidget(frequentiel);
        PAGE_FILTRE->setObjectName("PAGE_FILTRE");
        PAGE_FILTRE->setMaximumSize(QSize(250, 16777215));
        PB = new QWidget();
        PB->setObjectName("PB");
        verticalLayout_2 = new QVBoxLayout(PB);
        verticalLayout_2->setObjectName("verticalLayout_2");
        groupBox_4 = new QGroupBox(PB);
        groupBox_4->setObjectName("groupBox_4");
        verticalLayout_7 = new QVBoxLayout(groupBox_4);
        verticalLayout_7->setObjectName("verticalLayout_7");
        label_4 = new QLabel(groupBox_4);
        label_4->setObjectName("label_4");
        QFont font1;
        font1.setPointSize(11);
        label_4->setFont(font1);

        verticalLayout_7->addWidget(label_4, 0, Qt::AlignHCenter);

        XPB = new QLabel(groupBox_4);
        XPB->setObjectName("XPB");

        verticalLayout_7->addWidget(XPB);

        SLIDXPB = new QSlider(groupBox_4);
        SLIDXPB->setObjectName("SLIDXPB");
        SLIDXPB->setOrientation(Qt::Horizontal);

        verticalLayout_7->addWidget(SLIDXPB);

        YPB = new QLabel(groupBox_4);
        YPB->setObjectName("YPB");

        verticalLayout_7->addWidget(YPB);

        SLIDYPB = new QSlider(groupBox_4);
        SLIDYPB->setObjectName("SLIDYPB");
        SLIDYPB->setOrientation(Qt::Horizontal);

        verticalLayout_7->addWidget(SLIDYPB);

        SLIDPB = new QSlider(groupBox_4);
        SLIDPB->setObjectName("SLIDPB");
        SLIDPB->setOrientation(Qt::Vertical);

        verticalLayout_7->addWidget(SLIDPB, 0, Qt::AlignHCenter);

        TXTSLIDPB = new QLabel(groupBox_4);
        TXTSLIDPB->setObjectName("TXTSLIDPB");
        TXTSLIDPB->setFont(font1);
        TXTSLIDPB->setAlignment(Qt::AlignCenter);

        verticalLayout_7->addWidget(TXTSLIDPB);


        verticalLayout_2->addWidget(groupBox_4);

        VALIDPB = new QPushButton(PB);
        VALIDPB->setObjectName("VALIDPB");

        verticalLayout_2->addWidget(VALIDPB);

        PAGE_FILTRE->addWidget(PB);
        PH = new QWidget();
        PH->setObjectName("PH");
        verticalLayout = new QVBoxLayout(PH);
        verticalLayout->setObjectName("verticalLayout");
        groupBox = new QGroupBox(PH);
        groupBox->setObjectName("groupBox");
        verticalLayout_3 = new QVBoxLayout(groupBox);
        verticalLayout_3->setObjectName("verticalLayout_3");
        label_3 = new QLabel(groupBox);
        label_3->setObjectName("label_3");
        label_3->setFont(font1);

        verticalLayout_3->addWidget(label_3, 0, Qt::AlignHCenter);

        XPH = new QLabel(groupBox);
        XPH->setObjectName("XPH");

        verticalLayout_3->addWidget(XPH);

        SLIDXPH = new QSlider(groupBox);
        SLIDXPH->setObjectName("SLIDXPH");
        SLIDXPH->setOrientation(Qt::Horizontal);

        verticalLayout_3->addWidget(SLIDXPH);

        YPH = new QLabel(groupBox);
        YPH->setObjectName("YPH");

        verticalLayout_3->addWidget(YPH);

        SLIDYPH = new QSlider(groupBox);
        SLIDYPH->setObjectName("SLIDYPH");
        SLIDYPH->setOrientation(Qt::Horizontal);

        verticalLayout_3->addWidget(SLIDYPH);

        SLIDPH = new QSlider(groupBox);
        SLIDPH->setObjectName("SLIDPH");
        SLIDPH->setOrientation(Qt::Vertical);

        verticalLayout_3->addWidget(SLIDPH, 0, Qt::AlignHCenter);

        TXTRAYPH = new QLabel(groupBox);
        TXTRAYPH->setObjectName("TXTRAYPH");
        TXTRAYPH->setFont(font1);
        TXTRAYPH->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(TXTRAYPH);


        verticalLayout->addWidget(groupBox);

        VALIDPH = new QPushButton(PH);
        VALIDPH->setObjectName("VALIDPH");

        verticalLayout->addWidget(VALIDPH);

        PAGE_FILTRE->addWidget(PH);
        PBA = new QWidget();
        PBA->setObjectName("PBA");
        verticalLayout_5 = new QVBoxLayout(PBA);
        verticalLayout_5->setObjectName("verticalLayout_5");
        groupBox_2 = new QGroupBox(PBA);
        groupBox_2->setObjectName("groupBox_2");
        verticalLayout_4 = new QVBoxLayout(groupBox_2);
        verticalLayout_4->setObjectName("verticalLayout_4");
        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName("label_2");
        label_2->setFont(font1);

        verticalLayout_4->addWidget(label_2, 0, Qt::AlignHCenter);

        XPBA = new QLabel(groupBox_2);
        XPBA->setObjectName("XPBA");

        verticalLayout_4->addWidget(XPBA);

        SLIDXPBA = new QSlider(groupBox_2);
        SLIDXPBA->setObjectName("SLIDXPBA");
        SLIDXPBA->setOrientation(Qt::Horizontal);

        verticalLayout_4->addWidget(SLIDXPBA);

        YPBA = new QLabel(groupBox_2);
        YPBA->setObjectName("YPBA");

        verticalLayout_4->addWidget(YPBA);

        SLIDYPBA = new QSlider(groupBox_2);
        SLIDYPBA->setObjectName("SLIDYPBA");
        SLIDYPBA->setOrientation(Qt::Horizontal);

        verticalLayout_4->addWidget(SLIDYPBA);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName("gridLayout_3");
        SLIDRSUPPB = new QSlider(groupBox_2);
        SLIDRSUPPB->setObjectName("SLIDRSUPPB");
        SLIDRSUPPB->setOrientation(Qt::Vertical);

        gridLayout_3->addWidget(SLIDRSUPPB, 0, 2, 1, 1, Qt::AlignHCenter);

        TXTLBLSUP = new QLabel(groupBox_2);
        TXTLBLSUP->setObjectName("TXTLBLSUP");
        TXTLBLSUP->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(TXTLBLSUP, 1, 2, 1, 1);

        TXTLBLINF = new QLabel(groupBox_2);
        TXTLBLINF->setObjectName("TXTLBLINF");
        TXTLBLINF->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(TXTLBLINF, 1, 0, 1, 1);

        SLIDRINFPB = new QSlider(groupBox_2);
        SLIDRINFPB->setObjectName("SLIDRINFPB");
        SLIDRINFPB->setOrientation(Qt::Vertical);

        gridLayout_3->addWidget(SLIDRINFPB, 0, 0, 1, 1, Qt::AlignHCenter);


        verticalLayout_4->addLayout(gridLayout_3);


        verticalLayout_5->addWidget(groupBox_2);

        VALIDPBA = new QPushButton(PBA);
        VALIDPBA->setObjectName("VALIDPBA");

        verticalLayout_5->addWidget(VALIDPBA);

        PAGE_FILTRE->addWidget(PBA);
        CB = new QWidget();
        CB->setObjectName("CB");
        gridLayout = new QGridLayout(CB);
        gridLayout->setObjectName("gridLayout");
        VALIDCB = new QPushButton(CB);
        VALIDCB->setObjectName("VALIDCB");

        gridLayout->addWidget(VALIDCB, 5, 1, 1, 1);

        groupBox_3 = new QGroupBox(CB);
        groupBox_3->setObjectName("groupBox_3");
        verticalLayout_6 = new QVBoxLayout(groupBox_3);
        verticalLayout_6->setObjectName("verticalLayout_6");
        label = new QLabel(groupBox_3);
        label->setObjectName("label");
        label->setFont(font1);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout_6->addWidget(label);

        XCB = new QLabel(groupBox_3);
        XCB->setObjectName("XCB");

        verticalLayout_6->addWidget(XCB);

        SLIDXCB = new QSlider(groupBox_3);
        SLIDXCB->setObjectName("SLIDXCB");
        SLIDXCB->setOrientation(Qt::Horizontal);

        verticalLayout_6->addWidget(SLIDXCB);

        YCB = new QLabel(groupBox_3);
        YCB->setObjectName("YCB");

        verticalLayout_6->addWidget(YCB);

        SLIDYCB = new QSlider(groupBox_3);
        SLIDYCB->setObjectName("SLIDYCB");
        SLIDYCB->setOrientation(Qt::Horizontal);

        verticalLayout_6->addWidget(SLIDYCB);

        gridLayout_5 = new QGridLayout();
        gridLayout_5->setObjectName("gridLayout_5");
        SLIDRSUPCB = new QSlider(groupBox_3);
        SLIDRSUPCB->setObjectName("SLIDRSUPCB");
        SLIDRSUPCB->setOrientation(Qt::Vertical);

        gridLayout_5->addWidget(SLIDRSUPCB, 0, 1, 1, 1, Qt::AlignHCenter);

        SLIDRINFCB = new QSlider(groupBox_3);
        SLIDRINFCB->setObjectName("SLIDRINFCB");
        SLIDRINFCB->setOrientation(Qt::Vertical);

        gridLayout_5->addWidget(SLIDRINFCB, 0, 0, 1, 1, Qt::AlignHCenter);

        TXTLBLINFCB = new QLabel(groupBox_3);
        TXTLBLINFCB->setObjectName("TXTLBLINFCB");
        TXTLBLINFCB->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(TXTLBLINFCB, 1, 0, 1, 1);

        TXTLBLSUPCB = new QLabel(groupBox_3);
        TXTLBLSUPCB->setObjectName("TXTLBLSUPCB");
        TXTLBLSUPCB->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(TXTLBLSUPCB, 1, 1, 1, 1);


        verticalLayout_6->addLayout(gridLayout_5);


        gridLayout->addWidget(groupBox_3, 0, 1, 1, 1);

        PAGE_FILTRE->addWidget(CB);

        horizontalLayout->addWidget(PAGE_FILTRE);


        retranslateUi(frequentiel);

        PAGE_FILTRE->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(frequentiel);
    } // setupUi

    void retranslateUi(QDialog *frequentiel)
    {
        frequentiel->setWindowTitle(QCoreApplication::translate("frequentiel", "Filtrage fr\303\251quentiel", nullptr));
        FREQPRE->setText(QCoreApplication::translate("frequentiel", "TextLabel", nullptr));
        FREQPOST->setText(QCoreApplication::translate("frequentiel", "TextLabel", nullptr));
        label_5->setText(QCoreApplication::translate("frequentiel", "Image pr\303\251-traitement", nullptr));
        label_7->setText(QCoreApplication::translate("frequentiel", "Fr\303\251quentiel pr\303\251-traitement", nullptr));
        IMGPRE->setText(QCoreApplication::translate("frequentiel", "TextLabel", nullptr));
        label_6->setText(QCoreApplication::translate("frequentiel", "Image post-traitement", nullptr));
        label_8->setText(QCoreApplication::translate("frequentiel", "Fr\303\251quentiel post-traitement", nullptr));
        IMGPOST->setText(QCoreApplication::translate("frequentiel", "TextLabel", nullptr));
        groupBox_4->setTitle(QString());
        label_4->setText(QCoreApplication::translate("frequentiel", "Centre :", nullptr));
        XPB->setText(QCoreApplication::translate("frequentiel", "Y : 0", nullptr));
        YPB->setText(QCoreApplication::translate("frequentiel", "X : 0", nullptr));
        TXTSLIDPB->setText(QCoreApplication::translate("frequentiel", "Rayon : 0", nullptr));
        VALIDPB->setText(QCoreApplication::translate("frequentiel", "Valider", nullptr));
        groupBox->setTitle(QString());
        label_3->setText(QCoreApplication::translate("frequentiel", "Centre : ", nullptr));
        XPH->setText(QCoreApplication::translate("frequentiel", "Y : 0", nullptr));
        YPH->setText(QCoreApplication::translate("frequentiel", "X : 0", nullptr));
        TXTRAYPH->setText(QCoreApplication::translate("frequentiel", "Rayon : 0", nullptr));
        VALIDPH->setText(QCoreApplication::translate("frequentiel", "Valider", nullptr));
        groupBox_2->setTitle(QString());
        label_2->setText(QCoreApplication::translate("frequentiel", "Centre :", nullptr));
        XPBA->setText(QCoreApplication::translate("frequentiel", "Y : 0", nullptr));
        YPBA->setText(QCoreApplication::translate("frequentiel", "X : 0", nullptr));
        TXTLBLSUP->setText(QCoreApplication::translate("frequentiel", "Rayon Sup. : 0", nullptr));
        TXTLBLINF->setText(QCoreApplication::translate("frequentiel", "Rayon Inf. : 0", nullptr));
        VALIDPBA->setText(QCoreApplication::translate("frequentiel", "Valider", nullptr));
        VALIDCB->setText(QCoreApplication::translate("frequentiel", "Valider", nullptr));
        groupBox_3->setTitle(QString());
        label->setText(QCoreApplication::translate("frequentiel", "Centre : ", nullptr));
        XCB->setText(QCoreApplication::translate("frequentiel", "Y : 0", nullptr));
        YCB->setText(QCoreApplication::translate("frequentiel", "X : 0", nullptr));
        TXTLBLINFCB->setText(QCoreApplication::translate("frequentiel", "Rayon Inf. : 0", nullptr));
        TXTLBLSUPCB->setText(QCoreApplication::translate("frequentiel", "Rayon Sup. : 0", nullptr));
    } // retranslateUi

};

namespace Ui {
    class frequentiel: public Ui_frequentiel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FREQUENTIEL_H
