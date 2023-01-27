/********************************************************************************
** Form generated from reading UI file 'traitement.ui'
**
** Created by: Qt User Interface Compiler version 6.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRAITEMENT_H
#define UI_TRAITEMENT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Traitement
{
public:
    QAction *actionSAVE;
    QAction *actionImporter;
    QMenuBar *menubar;
    QMenu *menuTEST;
    QVBoxLayout *verticalLayout_9;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *Fen_Principale;
    QStackedWidget *SWTRCLR;
    QWidget *LBLTR_NORM;
    QVBoxLayout *verticalLayout_3;
    QLabel *LBLtr;
    QWidget *LBLtrCAN;
    QHBoxLayout *horizontalLayout_4;
    QHBoxLayout *CANAUX;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_5;
    QLabel *LBLTRCLR;
    QGridLayout *gridLayout_5;
    QLabel *label_3;
    QLabel *R;
    QLabel *label_4;
    QLabel *V;
    QLabel *B;
    QLabel *label_2;
    QWidget *PGFREQ;
    QVBoxLayout *verticalLayout_7;
    QLabel *label;
    QLabel *LBLFREQ;
    QStackedWidget *SWTR;
    QWidget *NDGCLR;
    QGridLayout *gridLayout_2;
    QGridLayout *Choix_TR;
    QGroupBox *groupBox_9;
    QVBoxLayout *verticalLayout_19;
    QPushButton *NDG;
    QPushButton *CLR;
    QPushButton *Retour;
    QWidget *TRNDG;
    QGridLayout *gridLayout_3;
    QGridLayout *MANIPS;
    QGroupBox *groupBox_4;
    QVBoxLayout *verticalLayout_14;
    QPushButton *H;
    QPushButton *FL;
    QPushButton *AT;
    QPushButton *FF;
    QPushButton *Annuler;
    QPushButton *REN;
    QGroupBox *groupBox_5;
    QVBoxLayout *verticalLayout_15;
    QPushButton *histogramme;
    QPushButton *AFFICH_FREQ;
    QWidget *TRNDGLIN;
    QVBoxLayout *verticalLayout;
    QGridLayout *FILT_LIN;
    QGroupBox *groupBox_6;
    QVBoxLayout *verticalLayout_16;
    QPushButton *FG;
    QPushButton *FM;
    QPushButton *FL8;
    QGridLayout *gridLayout_6;
    QRadioButton *HCON;
    QRadioButton *QCON;
    QPushButton *FPY;
    QGridLayout *gridLayout_7;
    QRadioButton *HPREW;
    QRadioButton *VPREW;
    QPushButton *FSY;
    QGridLayout *gridLayout_4;
    QRadioButton *HSOB;
    QRadioButton *VSOB;
    QPushButton *valider;
    QPushButton *AnnulerFL;
    QWidget *TRCLR;
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBox_7;
    QVBoxLayout *verticalLayout_17;
    QPushButton *SEGCLR;
    QPushButton *NEGCLR;
    QPushButton *FGCLR;
    QPushButton *FMCLR;
    QPushButton *MED_MARG;
    QLabel *LBLORDSEG;
    QSlider *SLIDORDSEG;
    QPushButton *RVB;
    QPushButton *Annuler_2;
    QWidget *SEGCLRTR;
    QVBoxLayout *verticalLayout_8;
    QGroupBox *groupBox_8;
    QVBoxLayout *verticalLayout_18;
    QLabel *TXTRSEG;
    QGridLayout *R_SEG;
    QSlider *BS2;
    QSlider *BS1;
    QFrame *line;
    QLabel *TXTVSEG;
    QGridLayout *V_SEG;
    QSlider *VS1;
    QSlider *VS2;
    QFrame *line_2;
    QLabel *TXTBSEG;
    QGridLayout *B_SEG;
    QSlider *RS1;
    QSlider *RS2;
    QFrame *line_3;
    QPushButton *VALIDERSEG;
    QPushButton *AnnulerSEGCLR;
    QWidget *manipH;
    QVBoxLayout *verticalLayout_6;
    QGridLayout *gridLayout;
    QGroupBox *groupBox_10;
    QVBoxLayout *verticalLayout_20;
    QPushButton *normal;
    QPushButton *egal;
    QPushButton *His;
    QPushButton *ValiderH;
    QPushButton *Annuler_H;
    QWidget *AT_2;
    QVBoxLayout *verticalLayout_5;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_11;
    QPushButton *NEG;
    QPushButton *DOG;
    QPushButton *RC;
    QPushButton *KM;
    QLabel *CLAS;
    QSlider *SLIDKM;
    QPushButton *FMED;
    QLabel *LBLORD;
    QSlider *SLIDORD;
    QLabel *SEUILB;
    QSlider *SLIDSEUIL;
    QLabel *label_6;
    QLabel *VAR;
    QSlider *SLIDVAR;
    QLabel *lblPS;
    QSlider *BI_CURS;
    QPushButton *VALIDAT;
    QPushButton *ANLAT;
    QWidget *PAGE_FREQ;
    QVBoxLayout *verticalLayout_10;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_12;
    QLabel *label_7;
    QPushButton *PH;
    QPushButton *PB;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_13;
    QLabel *label_8;
    QPushButton *PBA;
    QPushButton *CB;
    QPushButton *VAL_FREQ;
    QPushButton *ANN_FREQ;

    void setupUi(QDialog *Traitement)
    {
        if (Traitement->objectName().isEmpty())
            Traitement->setObjectName("Traitement");
        Traitement->resize(1094, 624);
        actionSAVE = new QAction(Traitement);
        actionSAVE->setObjectName("actionSAVE");
        actionImporter = new QAction(Traitement);
        actionImporter->setObjectName("actionImporter");
        menubar = new QMenuBar(Traitement);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1085, 22));
        menuTEST = new QMenu(menubar);
        menuTEST->setObjectName("menuTEST");
        verticalLayout_9 = new QVBoxLayout(Traitement);
        verticalLayout_9->setObjectName("verticalLayout_9");
        verticalSpacer = new QSpacerItem(10, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        verticalLayout_9->addItem(verticalSpacer);

        Fen_Principale = new QHBoxLayout();
        Fen_Principale->setObjectName("Fen_Principale");
        SWTRCLR = new QStackedWidget(Traitement);
        SWTRCLR->setObjectName("SWTRCLR");
        LBLTR_NORM = new QWidget();
        LBLTR_NORM->setObjectName("LBLTR_NORM");
        verticalLayout_3 = new QVBoxLayout(LBLTR_NORM);
        verticalLayout_3->setObjectName("verticalLayout_3");
        LBLtr = new QLabel(LBLTR_NORM);
        LBLtr->setObjectName("LBLtr");
        LBLtr->setMinimumSize(QSize(1, 1));
        LBLtr->setSizeIncrement(QSize(1, 1));
        LBLtr->setBaseSize(QSize(1, 1));
        QFont font;
        font.setPointSize(11);
        LBLtr->setFont(font);
        LBLtr->setLayoutDirection(Qt::LeftToRight);
        LBLtr->setAutoFillBackground(true);
        LBLtr->setScaledContents(false);
        LBLtr->setAlignment(Qt::AlignCenter);
        LBLtr->setWordWrap(true);

        verticalLayout_3->addWidget(LBLtr);

        SWTRCLR->addWidget(LBLTR_NORM);
        LBLtrCAN = new QWidget();
        LBLtrCAN->setObjectName("LBLtrCAN");
        horizontalLayout_4 = new QHBoxLayout(LBLtrCAN);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        CANAUX = new QHBoxLayout();
        CANAUX->setObjectName("CANAUX");
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName("verticalLayout_4");
        label_5 = new QLabel(LBLtrCAN);
        label_5->setObjectName("label_5");
        label_5->setMaximumSize(QSize(16777215, 25));
        QFont font1;
        font1.setPointSize(12);
        label_5->setFont(font1);
        label_5->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(label_5);

        LBLTRCLR = new QLabel(LBLtrCAN);
        LBLTRCLR->setObjectName("LBLTRCLR");
        LBLTRCLR->setMinimumSize(QSize(1, 1));
        LBLTRCLR->setScaledContents(false);
        LBLTRCLR->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(LBLTRCLR);

        gridLayout_5 = new QGridLayout();
        gridLayout_5->setObjectName("gridLayout_5");
        label_3 = new QLabel(LBLtrCAN);
        label_3->setObjectName("label_3");
        label_3->setMaximumSize(QSize(16777215, 20));
        label_3->setFont(font1);
        label_3->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(label_3, 1, 1, 1, 1);

        R = new QLabel(LBLtrCAN);
        R->setObjectName("R");
        R->setMinimumSize(QSize(1, 1));
        R->setScaledContents(false);
        R->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(R, 0, 0, 1, 1);

        label_4 = new QLabel(LBLtrCAN);
        label_4->setObjectName("label_4");
        label_4->setMinimumSize(QSize(0, 0));
        label_4->setMaximumSize(QSize(16777215, 20));
        label_4->setFont(font1);
        label_4->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(label_4, 1, 2, 1, 1);

        V = new QLabel(LBLtrCAN);
        V->setObjectName("V");
        V->setMinimumSize(QSize(1, 1));
        V->setScaledContents(false);
        V->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(V, 0, 1, 1, 1);

        B = new QLabel(LBLtrCAN);
        B->setObjectName("B");
        B->setMinimumSize(QSize(1, 1));
        B->setScaledContents(false);
        B->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(B, 0, 2, 1, 1);

        label_2 = new QLabel(LBLtrCAN);
        label_2->setObjectName("label_2");
        label_2->setMaximumSize(QSize(16777215, 20));
        label_2->setFont(font1);
        label_2->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(label_2, 1, 0, 1, 1);


        verticalLayout_4->addLayout(gridLayout_5);


        CANAUX->addLayout(verticalLayout_4);


        horizontalLayout_4->addLayout(CANAUX);

        SWTRCLR->addWidget(LBLtrCAN);
        PGFREQ = new QWidget();
        PGFREQ->setObjectName("PGFREQ");
        verticalLayout_7 = new QVBoxLayout(PGFREQ);
        verticalLayout_7->setObjectName("verticalLayout_7");
        label = new QLabel(PGFREQ);
        label->setObjectName("label");
        label->setMaximumSize(QSize(16777215, 25));
        label->setFont(font1);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout_7->addWidget(label);

        LBLFREQ = new QLabel(PGFREQ);
        LBLFREQ->setObjectName("LBLFREQ");
        LBLFREQ->setMinimumSize(QSize(1, 1));
        LBLFREQ->setAlignment(Qt::AlignCenter);

        verticalLayout_7->addWidget(LBLFREQ);

        SWTRCLR->addWidget(PGFREQ);

        Fen_Principale->addWidget(SWTRCLR);

        SWTR = new QStackedWidget(Traitement);
        SWTR->setObjectName("SWTR");
        SWTR->setEnabled(true);
        SWTR->setMinimumSize(QSize(260, 0));
        SWTR->setMaximumSize(QSize(260, 1000));
        NDGCLR = new QWidget();
        NDGCLR->setObjectName("NDGCLR");
        gridLayout_2 = new QGridLayout(NDGCLR);
        gridLayout_2->setObjectName("gridLayout_2");
        Choix_TR = new QGridLayout();
        Choix_TR->setSpacing(6);
        Choix_TR->setObjectName("Choix_TR");
        Choix_TR->setContentsMargins(-1, 0, -1, -1);
        groupBox_9 = new QGroupBox(NDGCLR);
        groupBox_9->setObjectName("groupBox_9");
        verticalLayout_19 = new QVBoxLayout(groupBox_9);
        verticalLayout_19->setObjectName("verticalLayout_19");
        NDG = new QPushButton(groupBox_9);
        NDG->setObjectName("NDG");
        NDG->setMinimumSize(QSize(1, 1));
        NDG->setMaximumSize(QSize(16777215, 1000));

        verticalLayout_19->addWidget(NDG);

        CLR = new QPushButton(groupBox_9);
        CLR->setObjectName("CLR");
        CLR->setMinimumSize(QSize(1, 1));
        CLR->setMaximumSize(QSize(16777215, 1000));

        verticalLayout_19->addWidget(CLR);


        Choix_TR->addWidget(groupBox_9, 0, 0, 1, 1);


        gridLayout_2->addLayout(Choix_TR, 0, 0, 1, 1);

        Retour = new QPushButton(NDGCLR);
        Retour->setObjectName("Retour");

        gridLayout_2->addWidget(Retour, 2, 0, 1, 1);

        SWTR->addWidget(NDGCLR);
        TRNDG = new QWidget();
        TRNDG->setObjectName("TRNDG");
        gridLayout_3 = new QGridLayout(TRNDG);
        gridLayout_3->setObjectName("gridLayout_3");
        MANIPS = new QGridLayout();
        MANIPS->setObjectName("MANIPS");
        groupBox_4 = new QGroupBox(TRNDG);
        groupBox_4->setObjectName("groupBox_4");
        verticalLayout_14 = new QVBoxLayout(groupBox_4);
        verticalLayout_14->setObjectName("verticalLayout_14");
        H = new QPushButton(groupBox_4);
        H->setObjectName("H");
        H->setMinimumSize(QSize(0, 50));
        H->setMaximumSize(QSize(16777215, 500));

        verticalLayout_14->addWidget(H);

        FL = new QPushButton(groupBox_4);
        FL->setObjectName("FL");
        FL->setMinimumSize(QSize(0, 50));
        FL->setMaximumSize(QSize(16777215, 500));

        verticalLayout_14->addWidget(FL);

        AT = new QPushButton(groupBox_4);
        AT->setObjectName("AT");
        AT->setMinimumSize(QSize(0, 50));
        AT->setMaximumSize(QSize(16777215, 500));

        verticalLayout_14->addWidget(AT);

        FF = new QPushButton(groupBox_4);
        FF->setObjectName("FF");
        FF->setMinimumSize(QSize(0, 50));
        FF->setMaximumSize(QSize(16777215, 500));

        verticalLayout_14->addWidget(FF);


        MANIPS->addWidget(groupBox_4, 0, 0, 1, 1);


        gridLayout_3->addLayout(MANIPS, 0, 0, 1, 1);

        Annuler = new QPushButton(TRNDG);
        Annuler->setObjectName("Annuler");
        Annuler->setEnabled(true);

        gridLayout_3->addWidget(Annuler, 11, 0, 1, 1);

        REN = new QPushButton(TRNDG);
        REN->setObjectName("REN");

        gridLayout_3->addWidget(REN, 2, 0, 1, 1);

        groupBox_5 = new QGroupBox(TRNDG);
        groupBox_5->setObjectName("groupBox_5");
        groupBox_5->setMaximumSize(QSize(16777215, 85));
        verticalLayout_15 = new QVBoxLayout(groupBox_5);
        verticalLayout_15->setObjectName("verticalLayout_15");
        histogramme = new QPushButton(groupBox_5);
        histogramme->setObjectName("histogramme");

        verticalLayout_15->addWidget(histogramme);

        AFFICH_FREQ = new QPushButton(groupBox_5);
        AFFICH_FREQ->setObjectName("AFFICH_FREQ");

        verticalLayout_15->addWidget(AFFICH_FREQ);


        gridLayout_3->addWidget(groupBox_5, 1, 0, 1, 1);

        SWTR->addWidget(TRNDG);
        TRNDGLIN = new QWidget();
        TRNDGLIN->setObjectName("TRNDGLIN");
        verticalLayout = new QVBoxLayout(TRNDGLIN);
        verticalLayout->setObjectName("verticalLayout");
        FILT_LIN = new QGridLayout();
        FILT_LIN->setObjectName("FILT_LIN");
        groupBox_6 = new QGroupBox(TRNDGLIN);
        groupBox_6->setObjectName("groupBox_6");
        verticalLayout_16 = new QVBoxLayout(groupBox_6);
        verticalLayout_16->setObjectName("verticalLayout_16");
        FG = new QPushButton(groupBox_6);
        FG->setObjectName("FG");
        FG->setMaximumSize(QSize(16777215, 1000));

        verticalLayout_16->addWidget(FG);

        FM = new QPushButton(groupBox_6);
        FM->setObjectName("FM");
        FM->setMaximumSize(QSize(16777215, 1000));

        verticalLayout_16->addWidget(FM);

        FL8 = new QPushButton(groupBox_6);
        FL8->setObjectName("FL8");
        FL8->setMaximumSize(QSize(16777215, 1000));

        verticalLayout_16->addWidget(FL8);

        gridLayout_6 = new QGridLayout();
        gridLayout_6->setObjectName("gridLayout_6");
        HCON = new QRadioButton(groupBox_6);
        HCON->setObjectName("HCON");

        gridLayout_6->addWidget(HCON, 0, 1, 1, 1, Qt::AlignHCenter);

        QCON = new QRadioButton(groupBox_6);
        QCON->setObjectName("QCON");

        gridLayout_6->addWidget(QCON, 0, 0, 1, 1, Qt::AlignHCenter);


        verticalLayout_16->addLayout(gridLayout_6);

        FPY = new QPushButton(groupBox_6);
        FPY->setObjectName("FPY");
        FPY->setMaximumSize(QSize(16777215, 1000));

        verticalLayout_16->addWidget(FPY);

        gridLayout_7 = new QGridLayout();
        gridLayout_7->setObjectName("gridLayout_7");
        HPREW = new QRadioButton(groupBox_6);
        HPREW->setObjectName("HPREW");

        gridLayout_7->addWidget(HPREW, 0, 0, 1, 1, Qt::AlignHCenter);

        VPREW = new QRadioButton(groupBox_6);
        VPREW->setObjectName("VPREW");

        gridLayout_7->addWidget(VPREW, 0, 1, 1, 1, Qt::AlignHCenter);


        verticalLayout_16->addLayout(gridLayout_7);

        FSY = new QPushButton(groupBox_6);
        FSY->setObjectName("FSY");
        FSY->setMaximumSize(QSize(16777215, 1000));

        verticalLayout_16->addWidget(FSY);

        gridLayout_4 = new QGridLayout();
        gridLayout_4->setObjectName("gridLayout_4");
        HSOB = new QRadioButton(groupBox_6);
        HSOB->setObjectName("HSOB");

        gridLayout_4->addWidget(HSOB, 0, 0, 1, 1, Qt::AlignHCenter);

        VSOB = new QRadioButton(groupBox_6);
        VSOB->setObjectName("VSOB");

        gridLayout_4->addWidget(VSOB, 0, 1, 1, 1, Qt::AlignHCenter);


        verticalLayout_16->addLayout(gridLayout_4);


        FILT_LIN->addWidget(groupBox_6, 0, 0, 1, 1);


        verticalLayout->addLayout(FILT_LIN);

        valider = new QPushButton(TRNDGLIN);
        valider->setObjectName("valider");

        verticalLayout->addWidget(valider);

        AnnulerFL = new QPushButton(TRNDGLIN);
        AnnulerFL->setObjectName("AnnulerFL");

        verticalLayout->addWidget(AnnulerFL);

        SWTR->addWidget(TRNDGLIN);
        TRCLR = new QWidget();
        TRCLR->setObjectName("TRCLR");
        verticalLayout_2 = new QVBoxLayout(TRCLR);
        verticalLayout_2->setObjectName("verticalLayout_2");
        groupBox_7 = new QGroupBox(TRCLR);
        groupBox_7->setObjectName("groupBox_7");
        verticalLayout_17 = new QVBoxLayout(groupBox_7);
        verticalLayout_17->setObjectName("verticalLayout_17");
        SEGCLR = new QPushButton(groupBox_7);
        SEGCLR->setObjectName("SEGCLR");
        SEGCLR->setMaximumSize(QSize(16777215, 1000));

        verticalLayout_17->addWidget(SEGCLR);

        NEGCLR = new QPushButton(groupBox_7);
        NEGCLR->setObjectName("NEGCLR");
        NEGCLR->setMaximumSize(QSize(16777215, 1000));

        verticalLayout_17->addWidget(NEGCLR);

        FGCLR = new QPushButton(groupBox_7);
        FGCLR->setObjectName("FGCLR");
        FGCLR->setMaximumSize(QSize(16777215, 1000));

        verticalLayout_17->addWidget(FGCLR);

        FMCLR = new QPushButton(groupBox_7);
        FMCLR->setObjectName("FMCLR");
        FMCLR->setMaximumSize(QSize(16777215, 1000));

        verticalLayout_17->addWidget(FMCLR);

        MED_MARG = new QPushButton(groupBox_7);
        MED_MARG->setObjectName("MED_MARG");
        MED_MARG->setMaximumSize(QSize(16777215, 1000));

        verticalLayout_17->addWidget(MED_MARG);

        LBLORDSEG = new QLabel(groupBox_7);
        LBLORDSEG->setObjectName("LBLORDSEG");
        LBLORDSEG->setMaximumSize(QSize(16777215, 20));
        LBLORDSEG->setAlignment(Qt::AlignCenter);

        verticalLayout_17->addWidget(LBLORDSEG);

        SLIDORDSEG = new QSlider(groupBox_7);
        SLIDORDSEG->setObjectName("SLIDORDSEG");
        SLIDORDSEG->setOrientation(Qt::Horizontal);

        verticalLayout_17->addWidget(SLIDORDSEG);

        RVB = new QPushButton(groupBox_7);
        RVB->setObjectName("RVB");
        RVB->setMaximumSize(QSize(16777215, 50));

        verticalLayout_17->addWidget(RVB);


        verticalLayout_2->addWidget(groupBox_7);

        Annuler_2 = new QPushButton(TRCLR);
        Annuler_2->setObjectName("Annuler_2");

        verticalLayout_2->addWidget(Annuler_2);

        SWTR->addWidget(TRCLR);
        SEGCLRTR = new QWidget();
        SEGCLRTR->setObjectName("SEGCLRTR");
        verticalLayout_8 = new QVBoxLayout(SEGCLRTR);
        verticalLayout_8->setObjectName("verticalLayout_8");
        groupBox_8 = new QGroupBox(SEGCLRTR);
        groupBox_8->setObjectName("groupBox_8");
        verticalLayout_18 = new QVBoxLayout(groupBox_8);
        verticalLayout_18->setObjectName("verticalLayout_18");
        TXTRSEG = new QLabel(groupBox_8);
        TXTRSEG->setObjectName("TXTRSEG");
        TXTRSEG->setMaximumSize(QSize(16777215, 20));
        TXTRSEG->setAlignment(Qt::AlignCenter);

        verticalLayout_18->addWidget(TXTRSEG);

        R_SEG = new QGridLayout();
        R_SEG->setObjectName("R_SEG");
        R_SEG->setContentsMargins(-1, 0, -1, -1);
        BS2 = new QSlider(groupBox_8);
        BS2->setObjectName("BS2");
        BS2->setMaximum(255);
        BS2->setOrientation(Qt::Vertical);
        BS2->setInvertedAppearance(false);

        R_SEG->addWidget(BS2, 0, 1, 1, 1);

        BS1 = new QSlider(groupBox_8);
        BS1->setObjectName("BS1");
        BS1->setMaximum(255);
        BS1->setOrientation(Qt::Vertical);

        R_SEG->addWidget(BS1, 0, 0, 1, 1);


        verticalLayout_18->addLayout(R_SEG);

        line = new QFrame(groupBox_8);
        line->setObjectName("line");
        line->setFrameShadow(QFrame::Plain);
        line->setLineWidth(1);
        line->setMidLineWidth(1);
        line->setFrameShape(QFrame::HLine);

        verticalLayout_18->addWidget(line);

        TXTVSEG = new QLabel(groupBox_8);
        TXTVSEG->setObjectName("TXTVSEG");
        TXTVSEG->setMaximumSize(QSize(16777215, 20));
        TXTVSEG->setAlignment(Qt::AlignCenter);

        verticalLayout_18->addWidget(TXTVSEG);

        V_SEG = new QGridLayout();
        V_SEG->setObjectName("V_SEG");
        V_SEG->setContentsMargins(-1, 0, -1, -1);
        VS1 = new QSlider(groupBox_8);
        VS1->setObjectName("VS1");
        VS1->setMaximum(255);
        VS1->setOrientation(Qt::Vertical);

        V_SEG->addWidget(VS1, 0, 0, 1, 1);

        VS2 = new QSlider(groupBox_8);
        VS2->setObjectName("VS2");
        VS2->setMaximum(255);
        VS2->setOrientation(Qt::Vertical);
        VS2->setInvertedAppearance(false);

        V_SEG->addWidget(VS2, 0, 1, 1, 1);


        verticalLayout_18->addLayout(V_SEG);

        line_2 = new QFrame(groupBox_8);
        line_2->setObjectName("line_2");
        line_2->setFrameShadow(QFrame::Plain);
        line_2->setLineWidth(1);
        line_2->setMidLineWidth(1);
        line_2->setFrameShape(QFrame::HLine);

        verticalLayout_18->addWidget(line_2);

        TXTBSEG = new QLabel(groupBox_8);
        TXTBSEG->setObjectName("TXTBSEG");
        TXTBSEG->setMaximumSize(QSize(16777215, 20));
        TXTBSEG->setAlignment(Qt::AlignCenter);

        verticalLayout_18->addWidget(TXTBSEG);

        B_SEG = new QGridLayout();
        B_SEG->setObjectName("B_SEG");
        B_SEG->setHorizontalSpacing(6);
        RS1 = new QSlider(groupBox_8);
        RS1->setObjectName("RS1");
        RS1->setMaximum(255);
        RS1->setPageStep(1);
        RS1->setOrientation(Qt::Vertical);

        B_SEG->addWidget(RS1, 0, 0, 1, 1);

        RS2 = new QSlider(groupBox_8);
        RS2->setObjectName("RS2");
        RS2->setMaximum(255);
        RS2->setOrientation(Qt::Vertical);
        RS2->setInvertedAppearance(false);

        B_SEG->addWidget(RS2, 0, 3, 1, 1);


        verticalLayout_18->addLayout(B_SEG);

        line_3 = new QFrame(groupBox_8);
        line_3->setObjectName("line_3");
        line_3->setFrameShadow(QFrame::Plain);
        line_3->setMidLineWidth(1);
        line_3->setFrameShape(QFrame::HLine);

        verticalLayout_18->addWidget(line_3);


        verticalLayout_8->addWidget(groupBox_8);

        VALIDERSEG = new QPushButton(SEGCLRTR);
        VALIDERSEG->setObjectName("VALIDERSEG");

        verticalLayout_8->addWidget(VALIDERSEG);

        AnnulerSEGCLR = new QPushButton(SEGCLRTR);
        AnnulerSEGCLR->setObjectName("AnnulerSEGCLR");

        verticalLayout_8->addWidget(AnnulerSEGCLR);

        SWTR->addWidget(SEGCLRTR);
        manipH = new QWidget();
        manipH->setObjectName("manipH");
        verticalLayout_6 = new QVBoxLayout(manipH);
        verticalLayout_6->setObjectName("verticalLayout_6");
        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        groupBox_10 = new QGroupBox(manipH);
        groupBox_10->setObjectName("groupBox_10");
        verticalLayout_20 = new QVBoxLayout(groupBox_10);
        verticalLayout_20->setObjectName("verticalLayout_20");
        normal = new QPushButton(groupBox_10);
        normal->setObjectName("normal");
        normal->setMaximumSize(QSize(16777215, 1000));

        verticalLayout_20->addWidget(normal);

        egal = new QPushButton(groupBox_10);
        egal->setObjectName("egal");
        egal->setMaximumSize(QSize(16777215, 1000));

        verticalLayout_20->addWidget(egal);

        His = new QPushButton(groupBox_10);
        His->setObjectName("His");

        verticalLayout_20->addWidget(His);


        gridLayout->addWidget(groupBox_10, 0, 0, 1, 1);


        verticalLayout_6->addLayout(gridLayout);

        ValiderH = new QPushButton(manipH);
        ValiderH->setObjectName("ValiderH");

        verticalLayout_6->addWidget(ValiderH);

        Annuler_H = new QPushButton(manipH);
        Annuler_H->setObjectName("Annuler_H");

        verticalLayout_6->addWidget(Annuler_H);

        SWTR->addWidget(manipH);
        AT_2 = new QWidget();
        AT_2->setObjectName("AT_2");
        verticalLayout_5 = new QVBoxLayout(AT_2);
        verticalLayout_5->setObjectName("verticalLayout_5");
        groupBox = new QGroupBox(AT_2);
        groupBox->setObjectName("groupBox");
        groupBox->setMinimumSize(QSize(250, 0));
        groupBox->setMaximumSize(QSize(250, 16777215));
        verticalLayout_11 = new QVBoxLayout(groupBox);
        verticalLayout_11->setObjectName("verticalLayout_11");
        NEG = new QPushButton(groupBox);
        NEG->setObjectName("NEG");
        NEG->setMaximumSize(QSize(16777215, 1000));

        verticalLayout_11->addWidget(NEG);

        DOG = new QPushButton(groupBox);
        DOG->setObjectName("DOG");
        DOG->setMaximumSize(QSize(16777215, 1000));

        verticalLayout_11->addWidget(DOG);

        RC = new QPushButton(groupBox);
        RC->setObjectName("RC");
        RC->setMaximumSize(QSize(16777215, 1000));

        verticalLayout_11->addWidget(RC);

        KM = new QPushButton(groupBox);
        KM->setObjectName("KM");
        KM->setMaximumSize(QSize(16777215, 1000));

        verticalLayout_11->addWidget(KM);

        CLAS = new QLabel(groupBox);
        CLAS->setObjectName("CLAS");
        CLAS->setMaximumSize(QSize(16777215, 20));

        verticalLayout_11->addWidget(CLAS);

        SLIDKM = new QSlider(groupBox);
        SLIDKM->setObjectName("SLIDKM");
        SLIDKM->setMinimum(1);
        SLIDKM->setValue(2);
        SLIDKM->setOrientation(Qt::Horizontal);

        verticalLayout_11->addWidget(SLIDKM);

        FMED = new QPushButton(groupBox);
        FMED->setObjectName("FMED");
        FMED->setMinimumSize(QSize(0, 50));
        FMED->setMaximumSize(QSize(16777215, 50));

        verticalLayout_11->addWidget(FMED);

        LBLORD = new QLabel(groupBox);
        LBLORD->setObjectName("LBLORD");
        LBLORD->setMaximumSize(QSize(16777215, 12));
        LBLORD->setAlignment(Qt::AlignCenter);

        verticalLayout_11->addWidget(LBLORD);

        SLIDORD = new QSlider(groupBox);
        SLIDORD->setObjectName("SLIDORD");
        SLIDORD->setOrientation(Qt::Horizontal);

        verticalLayout_11->addWidget(SLIDORD);

        SEUILB = new QLabel(groupBox);
        SEUILB->setObjectName("SEUILB");
        SEUILB->setMaximumSize(QSize(16777215, 20));

        verticalLayout_11->addWidget(SEUILB);

        SLIDSEUIL = new QSlider(groupBox);
        SLIDSEUIL->setObjectName("SLIDSEUIL");
        SLIDSEUIL->setMinimum(1);
        SLIDSEUIL->setValue(1);
        SLIDSEUIL->setOrientation(Qt::Horizontal);

        verticalLayout_11->addWidget(SLIDSEUIL);

        label_6 = new QLabel(groupBox);
        label_6->setObjectName("label_6");
        QFont font2;
        font2.setPointSize(13);
        font2.setBold(false);
        label_6->setFont(font2);
        label_6->setAlignment(Qt::AlignCenter);

        verticalLayout_11->addWidget(label_6);

        VAR = new QLabel(groupBox);
        VAR->setObjectName("VAR");
        VAR->setMaximumSize(QSize(16777215, 20));

        verticalLayout_11->addWidget(VAR);

        SLIDVAR = new QSlider(groupBox);
        SLIDVAR->setObjectName("SLIDVAR");
        SLIDVAR->setMinimum(1);
        SLIDVAR->setValue(1);
        SLIDVAR->setOrientation(Qt::Horizontal);

        verticalLayout_11->addWidget(SLIDVAR);

        lblPS = new QLabel(groupBox);
        lblPS->setObjectName("lblPS");
        lblPS->setMaximumSize(QSize(16777215, 20));

        verticalLayout_11->addWidget(lblPS);

        BI_CURS = new QSlider(groupBox);
        BI_CURS->setObjectName("BI_CURS");
        BI_CURS->setOrientation(Qt::Horizontal);

        verticalLayout_11->addWidget(BI_CURS);


        verticalLayout_5->addWidget(groupBox);

        VALIDAT = new QPushButton(AT_2);
        VALIDAT->setObjectName("VALIDAT");

        verticalLayout_5->addWidget(VALIDAT);

        ANLAT = new QPushButton(AT_2);
        ANLAT->setObjectName("ANLAT");

        verticalLayout_5->addWidget(ANLAT);

        SWTR->addWidget(AT_2);
        PAGE_FREQ = new QWidget();
        PAGE_FREQ->setObjectName("PAGE_FREQ");
        verticalLayout_10 = new QVBoxLayout(PAGE_FREQ);
        verticalLayout_10->setObjectName("verticalLayout_10");
        groupBox_2 = new QGroupBox(PAGE_FREQ);
        groupBox_2->setObjectName("groupBox_2");
        verticalLayout_12 = new QVBoxLayout(groupBox_2);
        verticalLayout_12->setObjectName("verticalLayout_12");
        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName("label_7");
        label_7->setMaximumSize(QSize(16777215, 50));
        label_7->setFont(font1);
        label_7->setAlignment(Qt::AlignCenter);

        verticalLayout_12->addWidget(label_7);

        PH = new QPushButton(groupBox_2);
        PH->setObjectName("PH");
        PH->setMaximumSize(QSize(16777215, 1000));

        verticalLayout_12->addWidget(PH);

        PB = new QPushButton(groupBox_2);
        PB->setObjectName("PB");
        PB->setMaximumSize(QSize(16777215, 1000));

        verticalLayout_12->addWidget(PB);


        verticalLayout_10->addWidget(groupBox_2);

        groupBox_3 = new QGroupBox(PAGE_FREQ);
        groupBox_3->setObjectName("groupBox_3");
        verticalLayout_13 = new QVBoxLayout(groupBox_3);
        verticalLayout_13->setObjectName("verticalLayout_13");
        label_8 = new QLabel(groupBox_3);
        label_8->setObjectName("label_8");
        label_8->setMaximumSize(QSize(16777215, 50));
        label_8->setFont(font1);

        verticalLayout_13->addWidget(label_8);

        PBA = new QPushButton(groupBox_3);
        PBA->setObjectName("PBA");
        PBA->setMaximumSize(QSize(16777215, 1000));

        verticalLayout_13->addWidget(PBA);

        CB = new QPushButton(groupBox_3);
        CB->setObjectName("CB");
        CB->setMaximumSize(QSize(16777215, 1000));

        verticalLayout_13->addWidget(CB);


        verticalLayout_10->addWidget(groupBox_3);

        VAL_FREQ = new QPushButton(PAGE_FREQ);
        VAL_FREQ->setObjectName("VAL_FREQ");

        verticalLayout_10->addWidget(VAL_FREQ);

        ANN_FREQ = new QPushButton(PAGE_FREQ);
        ANN_FREQ->setObjectName("ANN_FREQ");

        verticalLayout_10->addWidget(ANN_FREQ);

        SWTR->addWidget(PAGE_FREQ);

        Fen_Principale->addWidget(SWTR);


        verticalLayout_9->addLayout(Fen_Principale);


        menubar->addAction(menuTEST->menuAction());
        menuTEST->addAction(actionSAVE);
        menuTEST->addAction(actionImporter);

        retranslateUi(Traitement);

        SWTRCLR->setCurrentIndex(1);
        SWTR->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(Traitement);
    } // setupUi

    void retranslateUi(QDialog *Traitement)
    {
        Traitement->setWindowTitle(QCoreApplication::translate("Traitement", "Traitements", nullptr));
        actionSAVE->setText(QCoreApplication::translate("Traitement", "Sauvegarder l'image", nullptr));
#if QT_CONFIG(shortcut)
        actionSAVE->setShortcut(QCoreApplication::translate("Traitement", "Ctrl+S", nullptr));
#endif // QT_CONFIG(shortcut)
        actionImporter->setText(QCoreApplication::translate("Traitement", "Sauvegarder dans la biblioth\303\250que", nullptr));
#if QT_CONFIG(tooltip)
        actionImporter->setToolTip(QCoreApplication::translate("Traitement", "Sauvegarder dans la biblioth\303\250que", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actionImporter->setShortcut(QCoreApplication::translate("Traitement", "Ctrl+B", nullptr));
#endif // QT_CONFIG(shortcut)
        menuTEST->setTitle(QCoreApplication::translate("Traitement", "Fichier", nullptr));
        LBLtr->setText(QString());
        label_5->setText(QCoreApplication::translate("Traitement", "Image COULEUR", nullptr));
        LBLTRCLR->setText(QString());
        label_3->setText(QCoreApplication::translate("Traitement", "Canal VERT", nullptr));
        R->setText(QCoreApplication::translate("Traitement", "TextLabel", nullptr));
        label_4->setText(QCoreApplication::translate("Traitement", "Canal BLEU", nullptr));
        V->setText(QCoreApplication::translate("Traitement", "TextLabel", nullptr));
        B->setText(QCoreApplication::translate("Traitement", "TextLabel", nullptr));
        label_2->setText(QCoreApplication::translate("Traitement", "Canal ROUGE", nullptr));
        label->setText(QCoreApplication::translate("Traitement", "Affichage Fr\303\251quentiel", nullptr));
        LBLFREQ->setText(QCoreApplication::translate("Traitement", "TextLabel", nullptr));
        groupBox_9->setTitle(QString());
        NDG->setText(QCoreApplication::translate("Traitement", "Traitements en \n"
" Niveaux de Gris", nullptr));
        CLR->setText(QCoreApplication::translate("Traitement", "Traitements \n"
" Couleurs", nullptr));
        Retour->setText(QCoreApplication::translate("Traitement", "Retour au \n"
" Menu Principal", nullptr));
        groupBox_4->setTitle(QString());
        H->setText(QCoreApplication::translate("Traitement", "Manipulations\n"
"d'histogramme", nullptr));
        FL->setText(QCoreApplication::translate("Traitement", "Filtrage lin\303\251aire", nullptr));
        AT->setText(QCoreApplication::translate("Traitement", "Algorithmes de traitement", nullptr));
        FF->setText(QCoreApplication::translate("Traitement", "Filtrage fr\303\251quentiel", nullptr));
        Annuler->setText(QCoreApplication::translate("Traitement", "Annuler", nullptr));
        REN->setText(QCoreApplication::translate("Traitement", "R\303\251initialisation", nullptr));
        groupBox_5->setTitle(QString());
        histogramme->setText(QCoreApplication::translate("Traitement", "Histogramme", nullptr));
        AFFICH_FREQ->setText(QCoreApplication::translate("Traitement", "Affichage fr\303\251quentiel", nullptr));
        groupBox_6->setTitle(QString());
        FG->setText(QCoreApplication::translate("Traitement", "Filtre Gaussien", nullptr));
        FM->setText(QCoreApplication::translate("Traitement", "Filtre Moyenneur", nullptr));
        FL8->setText(QCoreApplication::translate("Traitement", "Filtre Laplacien", nullptr));
        HCON->setText(QCoreApplication::translate("Traitement", "8 connexit\303\251s", nullptr));
        QCON->setText(QCoreApplication::translate("Traitement", "4 connexit\303\251s", nullptr));
        FPY->setText(QCoreApplication::translate("Traitement", "Filtre Prewitt", nullptr));
        HPREW->setText(QCoreApplication::translate("Traitement", "Horizontal", nullptr));
        VPREW->setText(QCoreApplication::translate("Traitement", "Vertical", nullptr));
        FSY->setText(QCoreApplication::translate("Traitement", "Filtre Sobel", nullptr));
        HSOB->setText(QCoreApplication::translate("Traitement", "Horizontal", nullptr));
        VSOB->setText(QCoreApplication::translate("Traitement", "Vertical", nullptr));
        valider->setText(QCoreApplication::translate("Traitement", "Valider", nullptr));
        AnnulerFL->setText(QCoreApplication::translate("Traitement", "Annuler", nullptr));
        groupBox_7->setTitle(QString());
        SEGCLR->setText(QCoreApplication::translate("Traitement", "Segmentation couleur", nullptr));
        NEGCLR->setText(QCoreApplication::translate("Traitement", "N\303\251gatif", nullptr));
        FGCLR->setText(QCoreApplication::translate("Traitement", "Filtre gaussien", nullptr));
        FMCLR->setText(QCoreApplication::translate("Traitement", "Filtre moyenneur", nullptr));
        MED_MARG->setText(QCoreApplication::translate("Traitement", "Filtrage m\303\251dian marginal", nullptr));
        LBLORDSEG->setText(QCoreApplication::translate("Traitement", "Taille : 3 x 3", nullptr));
        RVB->setText(QCoreApplication::translate("Traitement", "Visualisation RVB", nullptr));
        Annuler_2->setText(QCoreApplication::translate("Traitement", "Annuler", nullptr));
        groupBox_8->setTitle(QString());
        TXTRSEG->setText(QCoreApplication::translate("Traitement", "Rouge", nullptr));
        TXTVSEG->setText(QCoreApplication::translate("Traitement", "Vert", nullptr));
        TXTBSEG->setText(QCoreApplication::translate("Traitement", "Bleu", nullptr));
        VALIDERSEG->setText(QCoreApplication::translate("Traitement", "Valider", nullptr));
        AnnulerSEGCLR->setText(QCoreApplication::translate("Traitement", "Annuler", nullptr));
        groupBox_10->setTitle(QString());
        normal->setText(QCoreApplication::translate("Traitement", "Normalisation", nullptr));
        egal->setText(QCoreApplication::translate("Traitement", "Egalisation", nullptr));
        His->setText(QCoreApplication::translate("Traitement", "Afficher Histogrammes", nullptr));
        ValiderH->setText(QCoreApplication::translate("Traitement", "Valider", nullptr));
        Annuler_H->setText(QCoreApplication::translate("Traitement", "Annuler", nullptr));
        groupBox->setTitle(QString());
        NEG->setText(QCoreApplication::translate("Traitement", "N\303\251gatif", nullptr));
        DOG->setText(QCoreApplication::translate("Traitement", "D.O.G\n"
"(Differential Of Gaussian)", nullptr));
        RC->setText(QCoreApplication::translate("Traitement", "R\303\251haussement \n"
" de contours", nullptr));
        KM->setText(QCoreApplication::translate("Traitement", "Algorithme K-means", nullptr));
        CLAS->setText(QCoreApplication::translate("Traitement", "Nombre de classes : 2", nullptr));
        FMED->setText(QCoreApplication::translate("Traitement", "Filtre m\303\251dian", nullptr));
        LBLORD->setText(QCoreApplication::translate("Traitement", "Taille : 3 x 3", nullptr));
        SEUILB->setText(QCoreApplication::translate("Traitement", "Binarisation valeur du seuil : 1", nullptr));
        label_6->setText(QCoreApplication::translate("Traitement", "Bruits :", nullptr));
        VAR->setText(QCoreApplication::translate("Traitement", "Bruit Blanc Additif : Variance 1", nullptr));
        lblPS->setText(QCoreApplication::translate("Traitement", "Bruit impulsionnel : 0 %", nullptr));
        VALIDAT->setText(QCoreApplication::translate("Traitement", "Valider", nullptr));
        ANLAT->setText(QCoreApplication::translate("Traitement", "Annuler", nullptr));
        groupBox_2->setTitle(QString());
        label_7->setText(QCoreApplication::translate("Traitement", "Ordre 1", nullptr));
        PH->setText(QCoreApplication::translate("Traitement", "Passe-Bas", nullptr));
        PB->setText(QCoreApplication::translate("Traitement", "Passe-Haut", nullptr));
        groupBox_3->setTitle(QString());
        label_8->setText(QCoreApplication::translate("Traitement", "<html><head/><body><p align=\"center\">Ordre 2</p></body></html>", nullptr));
        PBA->setText(QCoreApplication::translate("Traitement", "Passe-Bande", nullptr));
        CB->setText(QCoreApplication::translate("Traitement", "Coupe-Bande", nullptr));
        VAL_FREQ->setText(QCoreApplication::translate("Traitement", "Valider", nullptr));
        ANN_FREQ->setText(QCoreApplication::translate("Traitement", "Annuler", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Traitement: public Ui_Traitement {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRAITEMENT_H
