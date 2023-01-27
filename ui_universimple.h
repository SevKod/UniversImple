/********************************************************************************
** Form generated from reading UI file 'universimple.ui'
**
** Created by: Qt User Interface Compiler version 6.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UNIVERSIMPLE_H
#define UI_UNIVERSIMPLE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UniversImple
{
public:
    QAction *actionFermer;
    QAction *APROPOS;
    QAction *actionImporter_une_image;
    QAction *actionImporter_une_biblioth_que;
    QWidget *Fen_Princ;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *Aff_Image;
    QLabel *LBL;
    QGridLayout *Choix_Mode;
    QPushButton *bibliotheque;
    QPushButton *traitements;
    QMenuBar *menubar;
    QMenu *menuFichier;
    QMenu *menuA_propos;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *UniversImple)
    {
        if (UniversImple->objectName().isEmpty())
            UniversImple->setObjectName("UniversImple");
        UniversImple->resize(1477, 645);
        QIcon icon;
        icon.addFile(QString::fromUtf8("UniversImple.png"), QSize(), QIcon::Normal, QIcon::Off);
        UniversImple->setWindowIcon(icon);
        actionFermer = new QAction(UniversImple);
        actionFermer->setObjectName("actionFermer");
        APROPOS = new QAction(UniversImple);
        APROPOS->setObjectName("APROPOS");
        actionImporter_une_image = new QAction(UniversImple);
        actionImporter_une_image->setObjectName("actionImporter_une_image");
        actionImporter_une_biblioth_que = new QAction(UniversImple);
        actionImporter_une_biblioth_que->setObjectName("actionImporter_une_biblioth_que");
        Fen_Princ = new QWidget(UniversImple);
        Fen_Princ->setObjectName("Fen_Princ");
        horizontalLayout = new QHBoxLayout(Fen_Princ);
        horizontalLayout->setObjectName("horizontalLayout");
        Aff_Image = new QVBoxLayout();
        Aff_Image->setObjectName("Aff_Image");
        LBL = new QLabel(Fen_Princ);
        LBL->setObjectName("LBL");
        LBL->setMinimumSize(QSize(100, 100));
        LBL->setSizeIncrement(QSize(1, 1));
        LBL->setBaseSize(QSize(1, 1));
        QFont font;
        font.setPointSize(14);
        LBL->setFont(font);
        LBL->setAlignment(Qt::AlignCenter);
        LBL->setWordWrap(true);

        Aff_Image->addWidget(LBL);


        horizontalLayout->addLayout(Aff_Image);

        Choix_Mode = new QGridLayout();
        Choix_Mode->setObjectName("Choix_Mode");
        bibliotheque = new QPushButton(Fen_Princ);
        bibliotheque->setObjectName("bibliotheque");
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(bibliotheque->sizePolicy().hasHeightForWidth());
        bibliotheque->setSizePolicy(sizePolicy);
        bibliotheque->setMinimumSize(QSize(500, 0));
        bibliotheque->setMaximumSize(QSize(16777215, 1000));
        bibliotheque->setSizeIncrement(QSize(0, 0));
        QFont font1;
        font1.setPointSize(13);
        bibliotheque->setFont(font1);

        Choix_Mode->addWidget(bibliotheque, 1, 0, 1, 1);

        traitements = new QPushButton(Fen_Princ);
        traitements->setObjectName("traitements");
        traitements->setMinimumSize(QSize(500, 0));
        traitements->setMaximumSize(QSize(16777215, 1000));
        traitements->setFont(font1);

        Choix_Mode->addWidget(traitements, 0, 0, 1, 1);


        horizontalLayout->addLayout(Choix_Mode);

        UniversImple->setCentralWidget(Fen_Princ);
        menubar = new QMenuBar(UniversImple);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1477, 22));
        menuFichier = new QMenu(menubar);
        menuFichier->setObjectName("menuFichier");
        menuA_propos = new QMenu(menubar);
        menuA_propos->setObjectName("menuA_propos");
        UniversImple->setMenuBar(menubar);
        statusbar = new QStatusBar(UniversImple);
        statusbar->setObjectName("statusbar");
        UniversImple->setStatusBar(statusbar);

        menubar->addAction(menuFichier->menuAction());
        menubar->addAction(menuA_propos->menuAction());
        menuFichier->addAction(actionImporter_une_image);
        menuFichier->addAction(actionImporter_une_biblioth_que);
        menuFichier->addAction(actionFermer);
        menuA_propos->addAction(APROPOS);

        retranslateUi(UniversImple);
        QObject::connect(actionFermer, &QAction::triggered, UniversImple, qOverload<>(&QMainWindow::close));
        QObject::connect(APROPOS, &QAction::triggered, UniversImple, qOverload<>(&QMainWindow::show));

        QMetaObject::connectSlotsByName(UniversImple);
    } // setupUi

    void retranslateUi(QMainWindow *UniversImple)
    {
        UniversImple->setWindowTitle(QCoreApplication::translate("UniversImple", "UniversImple", nullptr));
        actionFermer->setText(QCoreApplication::translate("UniversImple", "Fermer", nullptr));
        APROPOS->setText(QCoreApplication::translate("UniversImple", "A propos", nullptr));
        actionImporter_une_image->setText(QCoreApplication::translate("UniversImple", "Importer une image", nullptr));
#if QT_CONFIG(shortcut)
        actionImporter_une_image->setShortcut(QCoreApplication::translate("UniversImple", "Ctrl+N", nullptr));
#endif // QT_CONFIG(shortcut)
        actionImporter_une_biblioth_que->setText(QCoreApplication::translate("UniversImple", "Importer une biblioth\303\250que", nullptr));
#if QT_CONFIG(shortcut)
        actionImporter_une_biblioth_que->setShortcut(QCoreApplication::translate("UniversImple", "Ctrl+B", nullptr));
#endif // QT_CONFIG(shortcut)
        LBL->setText(QCoreApplication::translate("UniversImple", "Fichier -> Importer une image ", nullptr));
        bibliotheque->setText(QCoreApplication::translate("UniversImple", "Acceder \303\240 la \n"
" biblioth\303\250que", nullptr));
        traitements->setText(QCoreApplication::translate("UniversImple", "Traitements", nullptr));
        menuFichier->setTitle(QCoreApplication::translate("UniversImple", "Fichier", nullptr));
        menuA_propos->setTitle(QCoreApplication::translate("UniversImple", "Aide", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UniversImple: public Ui_UniversImple {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UNIVERSIMPLE_H
