/********************************************************************************
** Form generated from reading UI file 'bibliotheque.ui'
**
** Created by: Qt User Interface Compiler version 6.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BIBLIOTHEQUE_H
#define UI_BIBLIOTHEQUE_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Bibliotheque
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QStackedWidget *SWIMGBIB;
    QWidget *LBLIMG;
    QVBoxLayout *verticalLayout_3;
    QLabel *LBLimg;
    QWidget *LBLBIB;
    QGridLayout *gridLayout_4;
    QListWidget *LBLbib;
    QWidget *LBLTAB;
    QVBoxLayout *verticalLayout_4;
    QTableWidget *LBLtab;
    QPushButton *STAT;
    QStackedWidget *SWBIB;
    QWidget *BIB;
    QGridLayout *gridLayout_2;
    QGridLayout *Choix_BIB;
    QPushButton *BDD;
    QPushButton *ADD;
    QPushButton *TTT;
    QPushButton *Retour_2;
    QWidget *ADDBIB;
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_7;
    QLabel *NOMIMG;
    QLineEdit *EDITNOM;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_8;
    QLabel *PRIXIMG;
    QLineEdit *EDITPRIX;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_9;
    QLabel *CONTIMG;
    QLineEdit *EDITCONT;
    QGroupBox *groupBox_4;
    QVBoxLayout *verticalLayout_10;
    QLabel *ACCRIMG;
    QHBoxLayout *horizontalLayout_2;
    QRadioButton *AC0;
    QRadioButton *AC1;
    QGroupBox *groupBox_5;
    QVBoxLayout *verticalLayout_11;
    QLabel *SOURCEIMG;
    QLineEdit *EDITSOURCE;
    QPushButton *VALID;
    QPushButton *ANL;
    QWidget *BDDBIB;
    QGridLayout *gridLayout_3;
    QPushButton *ANL_2;
    QGridLayout *Choix_IMG;
    QGroupBox *groupBox_11;
    QVBoxLayout *verticalLayout_17;
    QPushButton *MODIFSUPPB;
    QPushButton *BDD_3;
    QWidget *BIBMODIF;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QGroupBox *groupBox_8;
    QVBoxLayout *verticalLayout_14;
    QGroupBox *groupBox_9;
    QVBoxLayout *verticalLayout_15;
    QLabel *TXTLBL;
    QLineEdit *NOMMODIF;
    QLabel *ModifCarc;
    QRadioButton *COUTMODIF;
    QLabel *label;
    QHBoxLayout *horizontalLayout_3;
    QRadioButton *A0;
    QRadioButton *A1;
    QRadioButton *SOURCEMODIF;
    QRadioButton *CONTMODIF;
    QLineEdit *TXTMODIF;
    QPushButton *MODIFBUTTON;
    QGroupBox *groupBox_10;
    QVBoxLayout *verticalLayout_16;
    QLabel *NomSupp;
    QLineEdit *NOMSUPP;
    QPushButton *SUPPIMG;
    QPushButton *RETOURMODIF;
    QWidget *BIBDISPLAY;
    QVBoxLayout *verticalLayout_5;
    QPushButton *pushButton;
    QPushButton *PrixImg;
    QLabel *label_2;
    QPushButton *FREE;
    QPushButton *M10;
    QPushButton *M100;
    QPushButton *P100;
    QGroupBox *groupBox_7;
    QVBoxLayout *verticalLayout_13;
    QGridLayout *gridLayout_5;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_3;
    QLabel *label_5;
    QHBoxLayout *horizontalLayout_4;
    QLineEdit *SLPmin;
    QLineEdit *SLPmax;
    QPushButton *SLIP;
    QGroupBox *groupBox_6;
    QVBoxLayout *verticalLayout_12;
    QLabel *label_4;
    QLineEdit *SLC;
    QPushButton *TPC;
    QPushButton *Reset;
    QPushButton *VLDBIB;
    QPushButton *ANLBIB;
    QWidget *STATISTIK;
    QVBoxLayout *verticalLayout_6;
    QLabel *Pokemon;
    QPushButton *RetourK;

    void setupUi(QMainWindow *Bibliotheque)
    {
        if (Bibliotheque->objectName().isEmpty())
            Bibliotheque->setObjectName("Bibliotheque");
        Bibliotheque->resize(1102, 636);
        QIcon icon;
        icon.addFile(QString::fromUtf8("UniversImple.png"), QSize(), QIcon::Normal, QIcon::Off);
        Bibliotheque->setWindowIcon(icon);
        centralwidget = new QWidget(Bibliotheque);
        centralwidget->setObjectName("centralwidget");
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName("horizontalLayout");
        SWIMGBIB = new QStackedWidget(centralwidget);
        SWIMGBIB->setObjectName("SWIMGBIB");
        LBLIMG = new QWidget();
        LBLIMG->setObjectName("LBLIMG");
        verticalLayout_3 = new QVBoxLayout(LBLIMG);
        verticalLayout_3->setObjectName("verticalLayout_3");
        LBLimg = new QLabel(LBLIMG);
        LBLimg->setObjectName("LBLimg");
        LBLimg->setMinimumSize(QSize(1, 1));
        LBLimg->setSizeIncrement(QSize(1, 1));
        LBLimg->setBaseSize(QSize(1, 1));
        QFont font;
        font.setPointSize(11);
        LBLimg->setFont(font);
        LBLimg->setLayoutDirection(Qt::LeftToRight);
        LBLimg->setAutoFillBackground(true);
        LBLimg->setScaledContents(false);
        LBLimg->setAlignment(Qt::AlignCenter);
        LBLimg->setWordWrap(true);

        verticalLayout_3->addWidget(LBLimg);

        SWIMGBIB->addWidget(LBLIMG);
        LBLBIB = new QWidget();
        LBLBIB->setObjectName("LBLBIB");
        gridLayout_4 = new QGridLayout(LBLBIB);
        gridLayout_4->setObjectName("gridLayout_4");
        LBLbib = new QListWidget(LBLBIB);
        LBLbib->setObjectName("LBLbib");

        gridLayout_4->addWidget(LBLbib, 0, 0, 1, 1);

        SWIMGBIB->addWidget(LBLBIB);
        LBLTAB = new QWidget();
        LBLTAB->setObjectName("LBLTAB");
        verticalLayout_4 = new QVBoxLayout(LBLTAB);
        verticalLayout_4->setObjectName("verticalLayout_4");
        LBLtab = new QTableWidget(LBLTAB);
        LBLtab->setObjectName("LBLtab");
        LBLtab->setMinimumSize(QSize(1, 1));

        verticalLayout_4->addWidget(LBLtab);

        STAT = new QPushButton(LBLTAB);
        STAT->setObjectName("STAT");

        verticalLayout_4->addWidget(STAT);

        SWIMGBIB->addWidget(LBLTAB);

        horizontalLayout->addWidget(SWIMGBIB);

        SWBIB = new QStackedWidget(centralwidget);
        SWBIB->setObjectName("SWBIB");
        SWBIB->setEnabled(true);
        SWBIB->setMinimumSize(QSize(260, 0));
        SWBIB->setMaximumSize(QSize(260, 1000));
        BIB = new QWidget();
        BIB->setObjectName("BIB");
        gridLayout_2 = new QGridLayout(BIB);
        gridLayout_2->setObjectName("gridLayout_2");
        Choix_BIB = new QGridLayout();
        Choix_BIB->setSpacing(6);
        Choix_BIB->setObjectName("Choix_BIB");
        Choix_BIB->setContentsMargins(-1, 0, -1, -1);
        BDD = new QPushButton(BIB);
        BDD->setObjectName("BDD");
        BDD->setMinimumSize(QSize(1, 1));
        BDD->setMaximumSize(QSize(16777215, 1000));

        Choix_BIB->addWidget(BDD, 2, 0, 1, 1);

        ADD = new QPushButton(BIB);
        ADD->setObjectName("ADD");
        ADD->setMinimumSize(QSize(1, 1));
        ADD->setMaximumSize(QSize(16777215, 1000));

        Choix_BIB->addWidget(ADD, 0, 0, 1, 1);

        TTT = new QPushButton(BIB);
        TTT->setObjectName("TTT");
        TTT->setMaximumSize(QSize(16777215, 1000));

        Choix_BIB->addWidget(TTT, 1, 0, 1, 1);


        gridLayout_2->addLayout(Choix_BIB, 0, 0, 1, 1);

        Retour_2 = new QPushButton(BIB);
        Retour_2->setObjectName("Retour_2");

        gridLayout_2->addWidget(Retour_2, 2, 0, 1, 1);

        SWBIB->addWidget(BIB);
        ADDBIB = new QWidget();
        ADDBIB->setObjectName("ADDBIB");
        verticalLayout_2 = new QVBoxLayout(ADDBIB);
        verticalLayout_2->setObjectName("verticalLayout_2");
        groupBox = new QGroupBox(ADDBIB);
        groupBox->setObjectName("groupBox");
        verticalLayout_7 = new QVBoxLayout(groupBox);
        verticalLayout_7->setObjectName("verticalLayout_7");
        NOMIMG = new QLabel(groupBox);
        NOMIMG->setObjectName("NOMIMG");

        verticalLayout_7->addWidget(NOMIMG);

        EDITNOM = new QLineEdit(groupBox);
        EDITNOM->setObjectName("EDITNOM");

        verticalLayout_7->addWidget(EDITNOM);


        verticalLayout_2->addWidget(groupBox);

        groupBox_2 = new QGroupBox(ADDBIB);
        groupBox_2->setObjectName("groupBox_2");
        verticalLayout_8 = new QVBoxLayout(groupBox_2);
        verticalLayout_8->setObjectName("verticalLayout_8");
        PRIXIMG = new QLabel(groupBox_2);
        PRIXIMG->setObjectName("PRIXIMG");

        verticalLayout_8->addWidget(PRIXIMG);

        EDITPRIX = new QLineEdit(groupBox_2);
        EDITPRIX->setObjectName("EDITPRIX");

        verticalLayout_8->addWidget(EDITPRIX);


        verticalLayout_2->addWidget(groupBox_2);

        groupBox_3 = new QGroupBox(ADDBIB);
        groupBox_3->setObjectName("groupBox_3");
        verticalLayout_9 = new QVBoxLayout(groupBox_3);
        verticalLayout_9->setObjectName("verticalLayout_9");
        CONTIMG = new QLabel(groupBox_3);
        CONTIMG->setObjectName("CONTIMG");

        verticalLayout_9->addWidget(CONTIMG);

        EDITCONT = new QLineEdit(groupBox_3);
        EDITCONT->setObjectName("EDITCONT");

        verticalLayout_9->addWidget(EDITCONT);


        verticalLayout_2->addWidget(groupBox_3);

        groupBox_4 = new QGroupBox(ADDBIB);
        groupBox_4->setObjectName("groupBox_4");
        verticalLayout_10 = new QVBoxLayout(groupBox_4);
        verticalLayout_10->setObjectName("verticalLayout_10");
        ACCRIMG = new QLabel(groupBox_4);
        ACCRIMG->setObjectName("ACCRIMG");

        verticalLayout_10->addWidget(ACCRIMG);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        AC0 = new QRadioButton(groupBox_4);
        AC0->setObjectName("AC0");
        AC0->setMaximumSize(QSize(35, 16777215));

        horizontalLayout_2->addWidget(AC0);

        AC1 = new QRadioButton(groupBox_4);
        AC1->setObjectName("AC1");
        AC1->setMaximumSize(QSize(35, 16777215));
        AC1->setChecked(true);

        horizontalLayout_2->addWidget(AC1);


        verticalLayout_10->addLayout(horizontalLayout_2);


        verticalLayout_2->addWidget(groupBox_4);

        groupBox_5 = new QGroupBox(ADDBIB);
        groupBox_5->setObjectName("groupBox_5");
        verticalLayout_11 = new QVBoxLayout(groupBox_5);
        verticalLayout_11->setObjectName("verticalLayout_11");
        SOURCEIMG = new QLabel(groupBox_5);
        SOURCEIMG->setObjectName("SOURCEIMG");

        verticalLayout_11->addWidget(SOURCEIMG);

        EDITSOURCE = new QLineEdit(groupBox_5);
        EDITSOURCE->setObjectName("EDITSOURCE");

        verticalLayout_11->addWidget(EDITSOURCE);


        verticalLayout_2->addWidget(groupBox_5);

        VALID = new QPushButton(ADDBIB);
        VALID->setObjectName("VALID");

        verticalLayout_2->addWidget(VALID);

        ANL = new QPushButton(ADDBIB);
        ANL->setObjectName("ANL");

        verticalLayout_2->addWidget(ANL);

        SWBIB->addWidget(ADDBIB);
        BDDBIB = new QWidget();
        BDDBIB->setObjectName("BDDBIB");
        gridLayout_3 = new QGridLayout(BDDBIB);
        gridLayout_3->setObjectName("gridLayout_3");
        ANL_2 = new QPushButton(BDDBIB);
        ANL_2->setObjectName("ANL_2");

        gridLayout_3->addWidget(ANL_2, 1, 0, 1, 1);

        Choix_IMG = new QGridLayout();
        Choix_IMG->setSpacing(6);
        Choix_IMG->setObjectName("Choix_IMG");
        Choix_IMG->setContentsMargins(-1, 0, -1, -1);
        groupBox_11 = new QGroupBox(BDDBIB);
        groupBox_11->setObjectName("groupBox_11");
        verticalLayout_17 = new QVBoxLayout(groupBox_11);
        verticalLayout_17->setObjectName("verticalLayout_17");
        MODIFSUPPB = new QPushButton(groupBox_11);
        MODIFSUPPB->setObjectName("MODIFSUPPB");
        MODIFSUPPB->setMinimumSize(QSize(1, 1));
        MODIFSUPPB->setMaximumSize(QSize(16777215, 1000));

        verticalLayout_17->addWidget(MODIFSUPPB);

        BDD_3 = new QPushButton(groupBox_11);
        BDD_3->setObjectName("BDD_3");
        BDD_3->setMinimumSize(QSize(1, 1));
        BDD_3->setMaximumSize(QSize(16777215, 1000));

        verticalLayout_17->addWidget(BDD_3);


        Choix_IMG->addWidget(groupBox_11, 0, 0, 1, 1);


        gridLayout_3->addLayout(Choix_IMG, 0, 0, 1, 1);

        SWBIB->addWidget(BDDBIB);
        BIBMODIF = new QWidget();
        BIBMODIF->setObjectName("BIBMODIF");
        verticalLayout = new QVBoxLayout(BIBMODIF);
        verticalLayout->setObjectName("verticalLayout");
        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        groupBox_8 = new QGroupBox(BIBMODIF);
        groupBox_8->setObjectName("groupBox_8");
        groupBox_8->setMaximumSize(QSize(16777215, 1000));
        verticalLayout_14 = new QVBoxLayout(groupBox_8);
        verticalLayout_14->setObjectName("verticalLayout_14");
        groupBox_9 = new QGroupBox(groupBox_8);
        groupBox_9->setObjectName("groupBox_9");
        verticalLayout_15 = new QVBoxLayout(groupBox_9);
        verticalLayout_15->setObjectName("verticalLayout_15");
        TXTLBL = new QLabel(groupBox_9);
        TXTLBL->setObjectName("TXTLBL");
        TXTLBL->setMaximumSize(QSize(16777215, 600));

        verticalLayout_15->addWidget(TXTLBL);

        NOMMODIF = new QLineEdit(groupBox_9);
        NOMMODIF->setObjectName("NOMMODIF");

        verticalLayout_15->addWidget(NOMMODIF);


        verticalLayout_14->addWidget(groupBox_9);

        ModifCarc = new QLabel(groupBox_8);
        ModifCarc->setObjectName("ModifCarc");

        verticalLayout_14->addWidget(ModifCarc);

        COUTMODIF = new QRadioButton(groupBox_8);
        COUTMODIF->setObjectName("COUTMODIF");

        verticalLayout_14->addWidget(COUTMODIF);

        label = new QLabel(groupBox_8);
        label->setObjectName("label");

        verticalLayout_14->addWidget(label);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        A0 = new QRadioButton(groupBox_8);
        A0->setObjectName("A0");
        A0->setMaximumSize(QSize(35, 16777215));

        horizontalLayout_3->addWidget(A0);

        A1 = new QRadioButton(groupBox_8);
        A1->setObjectName("A1");
        A1->setMaximumSize(QSize(35, 16777215));
        A1->setChecked(true);

        horizontalLayout_3->addWidget(A1);


        verticalLayout_14->addLayout(horizontalLayout_3);

        SOURCEMODIF = new QRadioButton(groupBox_8);
        SOURCEMODIF->setObjectName("SOURCEMODIF");

        verticalLayout_14->addWidget(SOURCEMODIF);

        CONTMODIF = new QRadioButton(groupBox_8);
        CONTMODIF->setObjectName("CONTMODIF");

        verticalLayout_14->addWidget(CONTMODIF);

        TXTMODIF = new QLineEdit(groupBox_8);
        TXTMODIF->setObjectName("TXTMODIF");

        verticalLayout_14->addWidget(TXTMODIF);

        MODIFBUTTON = new QPushButton(groupBox_8);
        MODIFBUTTON->setObjectName("MODIFBUTTON");

        verticalLayout_14->addWidget(MODIFBUTTON);


        gridLayout->addWidget(groupBox_8, 1, 0, 2, 1);


        verticalLayout->addLayout(gridLayout);

        groupBox_10 = new QGroupBox(BIBMODIF);
        groupBox_10->setObjectName("groupBox_10");
        groupBox_10->setMaximumSize(QSize(16777215, 1000));
        verticalLayout_16 = new QVBoxLayout(groupBox_10);
        verticalLayout_16->setObjectName("verticalLayout_16");
        NomSupp = new QLabel(groupBox_10);
        NomSupp->setObjectName("NomSupp");

        verticalLayout_16->addWidget(NomSupp);

        NOMSUPP = new QLineEdit(groupBox_10);
        NOMSUPP->setObjectName("NOMSUPP");

        verticalLayout_16->addWidget(NOMSUPP);


        verticalLayout->addWidget(groupBox_10);

        SUPPIMG = new QPushButton(BIBMODIF);
        SUPPIMG->setObjectName("SUPPIMG");

        verticalLayout->addWidget(SUPPIMG);

        RETOURMODIF = new QPushButton(BIBMODIF);
        RETOURMODIF->setObjectName("RETOURMODIF");

        verticalLayout->addWidget(RETOURMODIF);

        SWBIB->addWidget(BIBMODIF);
        BIBDISPLAY = new QWidget();
        BIBDISPLAY->setObjectName("BIBDISPLAY");
        verticalLayout_5 = new QVBoxLayout(BIBDISPLAY);
        verticalLayout_5->setObjectName("verticalLayout_5");
        pushButton = new QPushButton(BIBDISPLAY);
        pushButton->setObjectName("pushButton");
        pushButton->setMaximumSize(QSize(16777215, 1000));

        verticalLayout_5->addWidget(pushButton);

        PrixImg = new QPushButton(BIBDISPLAY);
        PrixImg->setObjectName("PrixImg");

        verticalLayout_5->addWidget(PrixImg);

        label_2 = new QLabel(BIBDISPLAY);
        label_2->setObjectName("label_2");

        verticalLayout_5->addWidget(label_2);

        FREE = new QPushButton(BIBDISPLAY);
        FREE->setObjectName("FREE");

        verticalLayout_5->addWidget(FREE);

        M10 = new QPushButton(BIBDISPLAY);
        M10->setObjectName("M10");

        verticalLayout_5->addWidget(M10);

        M100 = new QPushButton(BIBDISPLAY);
        M100->setObjectName("M100");

        verticalLayout_5->addWidget(M100);

        P100 = new QPushButton(BIBDISPLAY);
        P100->setObjectName("P100");

        verticalLayout_5->addWidget(P100);

        groupBox_7 = new QGroupBox(BIBDISPLAY);
        groupBox_7->setObjectName("groupBox_7");
        verticalLayout_13 = new QVBoxLayout(groupBox_7);
        verticalLayout_13->setObjectName("verticalLayout_13");
        gridLayout_5 = new QGridLayout();
        gridLayout_5->setObjectName("gridLayout_5");
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        label_3 = new QLabel(groupBox_7);
        label_3->setObjectName("label_3");

        horizontalLayout_5->addWidget(label_3);

        label_5 = new QLabel(groupBox_7);
        label_5->setObjectName("label_5");

        horizontalLayout_5->addWidget(label_5);


        gridLayout_5->addLayout(horizontalLayout_5, 0, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        SLPmin = new QLineEdit(groupBox_7);
        SLPmin->setObjectName("SLPmin");

        horizontalLayout_4->addWidget(SLPmin);

        SLPmax = new QLineEdit(groupBox_7);
        SLPmax->setObjectName("SLPmax");

        horizontalLayout_4->addWidget(SLPmax);


        gridLayout_5->addLayout(horizontalLayout_4, 1, 0, 1, 1);


        verticalLayout_13->addLayout(gridLayout_5);

        SLIP = new QPushButton(groupBox_7);
        SLIP->setObjectName("SLIP");

        verticalLayout_13->addWidget(SLIP);


        verticalLayout_5->addWidget(groupBox_7);

        groupBox_6 = new QGroupBox(BIBDISPLAY);
        groupBox_6->setObjectName("groupBox_6");
        verticalLayout_12 = new QVBoxLayout(groupBox_6);
        verticalLayout_12->setObjectName("verticalLayout_12");
        label_4 = new QLabel(groupBox_6);
        label_4->setObjectName("label_4");

        verticalLayout_12->addWidget(label_4);

        SLC = new QLineEdit(groupBox_6);
        SLC->setObjectName("SLC");

        verticalLayout_12->addWidget(SLC);

        TPC = new QPushButton(groupBox_6);
        TPC->setObjectName("TPC");

        verticalLayout_12->addWidget(TPC);


        verticalLayout_5->addWidget(groupBox_6);

        Reset = new QPushButton(BIBDISPLAY);
        Reset->setObjectName("Reset");

        verticalLayout_5->addWidget(Reset);

        VLDBIB = new QPushButton(BIBDISPLAY);
        VLDBIB->setObjectName("VLDBIB");
        VLDBIB->setMaximumSize(QSize(16777215, 1000));

        verticalLayout_5->addWidget(VLDBIB);

        ANLBIB = new QPushButton(BIBDISPLAY);
        ANLBIB->setObjectName("ANLBIB");
        ANLBIB->setMaximumSize(QSize(16777215, 16777215));

        verticalLayout_5->addWidget(ANLBIB);

        SWBIB->addWidget(BIBDISPLAY);
        STATISTIK = new QWidget();
        STATISTIK->setObjectName("STATISTIK");
        verticalLayout_6 = new QVBoxLayout(STATISTIK);
        verticalLayout_6->setObjectName("verticalLayout_6");
        Pokemon = new QLabel(STATISTIK);
        Pokemon->setObjectName("Pokemon");

        verticalLayout_6->addWidget(Pokemon);

        RetourK = new QPushButton(STATISTIK);
        RetourK->setObjectName("RetourK");

        verticalLayout_6->addWidget(RetourK);

        SWBIB->addWidget(STATISTIK);

        horizontalLayout->addWidget(SWBIB);

        Bibliotheque->setCentralWidget(centralwidget);

        retranslateUi(Bibliotheque);

        SWIMGBIB->setCurrentIndex(2);
        SWBIB->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Bibliotheque);
    } // setupUi

    void retranslateUi(QMainWindow *Bibliotheque)
    {
        Bibliotheque->setWindowTitle(QCoreApplication::translate("Bibliotheque", "Bibliotheque", nullptr));
        LBLimg->setText(QString());
        STAT->setText(QCoreApplication::translate("Bibliotheque", "Statistiques", nullptr));
        BDD->setText(QCoreApplication::translate("Bibliotheque", "Biblioth\303\250que\n"
"d'images", nullptr));
        ADD->setText(QCoreApplication::translate("Bibliotheque", "Ajouter une image\n"
"\303\240 la biblioth\303\250que", nullptr));
        TTT->setText(QCoreApplication::translate("Bibliotheque", "Traitement", nullptr));
        Retour_2->setText(QCoreApplication::translate("Bibliotheque", "Retour au \n"
" Menu Principal", nullptr));
        groupBox->setTitle(QString());
        NOMIMG->setText(QCoreApplication::translate("Bibliotheque", "Nom de l'image :", nullptr));
        groupBox_2->setTitle(QString());
        PRIXIMG->setText(QCoreApplication::translate("Bibliotheque", "Prix :", nullptr));
        groupBox_3->setTitle(QString());
        CONTIMG->setText(QCoreApplication::translate("Bibliotheque", "Contenu :", nullptr));
        groupBox_4->setTitle(QString());
        ACCRIMG->setText(QCoreApplication::translate("Bibliotheque", "Num\303\251ro d'accr\303\251ditation :", nullptr));
        AC0->setText(QCoreApplication::translate("Bibliotheque", "N", nullptr));
        AC1->setText(QCoreApplication::translate("Bibliotheque", "A", nullptr));
        groupBox_5->setTitle(QString());
        SOURCEIMG->setText(QCoreApplication::translate("Bibliotheque", "Source :", nullptr));
        VALID->setText(QCoreApplication::translate("Bibliotheque", "Valider", nullptr));
        ANL->setText(QCoreApplication::translate("Bibliotheque", "Annuler", nullptr));
        ANL_2->setText(QCoreApplication::translate("Bibliotheque", "Valider", nullptr));
        groupBox_11->setTitle(QString());
        MODIFSUPPB->setText(QCoreApplication::translate("Bibliotheque", "Modification\n"
"et/ou\n"
"Suppression", nullptr));
        BDD_3->setText(QCoreApplication::translate("Bibliotheque", "Visualiser la\n"
"biblioth\303\250que", nullptr));
        groupBox_8->setTitle(QString());
        groupBox_9->setTitle(QString());
        TXTLBL->setText(QCoreApplication::translate("Bibliotheque", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Modifier une image</p></body></html>", nullptr));
        ModifCarc->setText(QCoreApplication::translate("Bibliotheque", "<html><head/><body><p align=\"center\">Modification d'une</p><p align=\"center\">caract\303\251ristique :</p></body></html>", nullptr));
        COUTMODIF->setText(QCoreApplication::translate("Bibliotheque", "Cout", nullptr));
        label->setText(QCoreApplication::translate("Bibliotheque", "Accr\303\251ditation :", nullptr));
        A0->setText(QCoreApplication::translate("Bibliotheque", "N", nullptr));
        A1->setText(QCoreApplication::translate("Bibliotheque", "A", nullptr));
        SOURCEMODIF->setText(QCoreApplication::translate("Bibliotheque", "Source", nullptr));
        CONTMODIF->setText(QCoreApplication::translate("Bibliotheque", "Contenu", nullptr));
        MODIFBUTTON->setText(QCoreApplication::translate("Bibliotheque", "Modifier", nullptr));
        groupBox_10->setTitle(QString());
        NomSupp->setText(QCoreApplication::translate("Bibliotheque", "<html><head/><body><p align=\"center\">Supprimer une image</p></body></html>", nullptr));
        SUPPIMG->setText(QCoreApplication::translate("Bibliotheque", "Supprimer", nullptr));
        RETOURMODIF->setText(QCoreApplication::translate("Bibliotheque", "Annuler", nullptr));
        pushButton->setText(QCoreApplication::translate("Bibliotheque", "Modification de la\n"
"biblioth\303\250que", nullptr));
        PrixImg->setText(QCoreApplication::translate("Bibliotheque", "Prix", nullptr));
        label_2->setText(QCoreApplication::translate("Bibliotheque", "Sous liste de prix :", nullptr));
        FREE->setText(QCoreApplication::translate("Bibliotheque", "Gratuit", nullptr));
        M10->setText(QCoreApplication::translate("Bibliotheque", "Co\303\273t < 10", nullptr));
        M100->setText(QCoreApplication::translate("Bibliotheque", "10 < Co\303\273t < 100", nullptr));
        P100->setText(QCoreApplication::translate("Bibliotheque", "Co\303\273t > 100", nullptr));
        groupBox_7->setTitle(QString());
        label_3->setText(QCoreApplication::translate("Bibliotheque", "Min", nullptr));
        label_5->setText(QCoreApplication::translate("Bibliotheque", "Max", nullptr));
        SLIP->setText(QCoreApplication::translate("Bibliotheque", "Tri par plage de prix", nullptr));
        groupBox_6->setTitle(QString());
        label_4->setText(QCoreApplication::translate("Bibliotheque", "Sous liste de contenu :", nullptr));
        TPC->setText(QCoreApplication::translate("Bibliotheque", "Tri par contenu", nullptr));
        Reset->setText(QCoreApplication::translate("Bibliotheque", "R\303\251initialiser", nullptr));
        VLDBIB->setText(QCoreApplication::translate("Bibliotheque", "Ouvrir une image", nullptr));
        ANLBIB->setText(QCoreApplication::translate("Bibliotheque", "Annuler", nullptr));
        Pokemon->setText(QCoreApplication::translate("Bibliotheque", "TextLabel", nullptr));
        RetourK->setText(QCoreApplication::translate("Bibliotheque", "Retour", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Bibliotheque: public Ui_Bibliotheque {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BIBLIOTHEQUE_H
