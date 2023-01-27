#include "bibliotheque.h"
#include "ui_bibliotheque.h"
#include "universimple.h"
#include "biblio.h"
//#include "traitement.h"

#include <QDialog>
#include <QMainWindow>
#include <QMessageBox>
#include <QFileDialog>
#include <QSlider>
#include <QLCDNumber>
#include <QTableWidget>
#include <QDir>
#include <QComboBox>
#include <QFile>

#include <iostream>
#include <fstream>
#include <list>

using namespace std;

Bibliotheque::Bibliotheque(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Bibliotheque)
{
    ui->setupUi(this);
    ui->SWBIB->setCurrentIndex(0);
    ui->SWIMGBIB->setCurrentIndex(0);
    ui->TTT->setVisible(false);
}

Bibliotheque::~Bibliotheque()
{
    delete ui;
}

void Bibliotheque::RecupAccred(int accred)
{
    Accred = accred;
}

void Bibliotheque::init()
{
    string test = "/Data.txt";
    cout << std::filesystem::current_path().string() + test <<std::endl;
    string chemin = filesystem::current_path().string() + test;
    ifstream Bdd(chemin);

    if(Bdd)
    {
        string line;
        while(getline(Bdd, line))
        {
            tailleTotal++;
        }
        taille = tailleTotal;
    }
    else
    {
        QMessageBox::information(this, "ERREUR", "Impossible d'ouvrir le fichier");
    }

    Biblio ajout;

    int ajoutNum;
    string ajoutNom, ajoutCont, ajoutAccr, ajoutSource;;
    double ajoutCout, ajoutPoids;

    ifstream Bdd2("Data.txt");

    for(int i = 0; i < taille; i++)
    {
        Bdd2 >> ajoutNum; ajout.SetNum(ajoutNum);
        Bdd2 >> ajoutNom; ajout.SetNom(ajoutNom);
        Bdd2 >> ajoutCout; ajout.SetCout(ajoutCout);
        Bdd2 >> ajoutPoids; ajout.SetPoids(ajoutPoids);
        Bdd2 >> ajoutCont; ajout.SetCont(ajoutCont);
        Bdd2 >> ajoutAccr; ajout.SetAccr(ajoutAccr);
        Bdd2 >> ajoutSource; ajout.SetSource(ajoutSource);

        if(max <= ajoutNum)
        {
            max = ajoutNum;
        }

        if(ajoutAccr == "N")
        {
            NumAccred = 2;
        }
        else
        {
            NumAccred = 1;
        }

        if(Accred <= NumAccred)
        {
            tailleAccred++;
        }

        if(Accred == 2)
        {
            //ui->SUPPIMG->setVisible(false);
            ui->ADD->setEnabled(false);
            ui->pushButton->setEnabled(false);
        }
    }

    if(importer == 1)
    {
        ui->SWBIB->setCurrentIndex(1);
    }
}

// SET IMAGE

void Bibliotheque::SetAdr(QString adresse)
{
    adr = adresse;
}

void Bibliotheque::setImp(int im)
{
    importer = im;
}

void Bibliotheque::SetImg(QImage image)
{
    img = image;
}

QImage Bibliotheque::GetImage()
{
    return img;
}

void Bibliotheque::AffImageBibNDG()
{
    QImage image = img.copy();
    SetImg(image.copy());
    im_fen = image;
    image = image.scaledToWidth(ui->LBLimg->width(),Qt::SmoothTransformation);
    image = image.scaledToHeight(ui->LBLimg->height(),Qt::SmoothTransformation);
    ui->LBLimg->setPixmap(QPixmap::fromImage(image));

    ui->LBLimg->setMinimumSize((int)image.width()/2, (int)image.height()/2);

    adr = "1";
}

void Bibliotheque::AffImage()
{
    QImage image;
    bool charge = image.load(adr);
    SetImg(image.copy());
    im_fen = image;
    image = image.scaledToWidth(ui->LBLimg->width(),Qt::SmoothTransformation);
    image = image.scaledToHeight(ui->LBLimg->height(),Qt::SmoothTransformation);
    ui->LBLimg->setPixmap(QPixmap::fromImage(image));

    ui->LBLimg->setMinimumSize((int)image.width()/2, (int)image.height()/2);

    if (!charge)
    {
        ui->LBLimg->setText("Pas d'image chargée. \n Merci d'importer une image depuis la banque d'image.");
    }
}

void Bibliotheque::AffIm()
{
    QImage image;
    image.load(adr);
    image = image.scaledToWidth(ui->LBLimg->width(),Qt::SmoothTransformation);
    image = image.scaledToHeight(ui->LBLimg->height(),Qt::SmoothTransformation);
    ui->LBLimg->setMinimumSize((int)image.width()/2, (int)image.height()/2);
    ui->LBLimg->setPixmap(QPixmap::fromImage(image));

}

void Bibliotheque::resizeEvent(QResizeEvent *event)
{
    QMainWindow::resizeEvent(event);
    if (adr != "")
    {
        int w = ui->LBLimg->width();
        int h = ui->LBLimg->height();
        QImage img_out_post = im_fen.copy();
        ui->LBLimg->setPixmap(QPixmap::fromImage(img_out_post).scaled(w,h,Qt::KeepAspectRatio,Qt::SmoothTransformation));
        //Délais pour laisser le temps que l'image soit resize. Puis, on appelle la fonction d'actualisation
        if (timerId){
            killTimer(timerId);
            timerId = 0;
        }
        timerId = startTimer(1);
    }
    else
    {
        ui->LBLimg->setText("Pas d'image chargée. \n Merci d'importer une image depuis le menu principal.");
    }
}

void Bibliotheque::on_Retour_2_clicked()
{
    QPointer<UniversImple> w = new UniversImple();
    w->setAttribute(Qt::WA_DeleteOnClose);
    //UniversImple *w = new UniversImple();

    if(importer != 1)
    {
        w->SetAdr(adr);
        w->SetIm(img);
        close();
        w->show();
        if (adr !="")
        {
            w->AffIm();
        }
    }
    else
    {
        w->SetIm(img);
        close();
        w->show();
        w->AffImageBibNDG();
    }
}

void Bibliotheque::on_ADD_clicked()
{
    if(adr != ""){
        ui->SWBIB->setCurrentIndex(1);
    }
    else
    {   ui->LBLimg->setStyleSheet(QStringLiteral("QLabel{color: rgb(170, 0, 0);}"));
        ui->LBLimg->setText("Pas d'image chargée ! \n Merci d'importer une image depuis la banque d'image.");
    }
}

void Bibliotheque::on_BDD_clicked()
{
    ui->SWBIB->setCurrentIndex(4);
    ui->SWIMGBIB->setCurrentIndex(2);
    ui->LBLtab->clear();

    Biblio display;

    int suppNum;
    string suppNom, suppCont, suppAccr, suppSource;;
    double suppCout, suppPoids;

    string list;

    imgBDD.clear();

    ifstream Bdd3("Data.txt");

    ui->LBLtab->setRowCount(tailleAccred);
    ui->LBLtab->setColumnCount(7);

    QStringList hlabels;
    hlabels << "Numéro" << "Nom" << "coût (€)" << "poids (Ko)" << "Contenu" << "Accréditation" << "Source";

    ui->LBLtab->setHorizontalHeaderLabels(hlabels);
    ui->LBLtab->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->LBLtab->setSortingEnabled(true);
    ui->LBLtab->verticalHeader()->setVisible(false);
    ui->LBLtab->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->LBLtab->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->LBLtab->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    int k = 0;

    for(int i = 0; i < taille; i++)
    {
        Bdd3 >> suppNum; display.SetNum(suppNum);
        Bdd3 >> suppNom; display.SetNom(suppNom);
        Bdd3 >> suppCout; display.SetCout(suppCout);
        Bdd3 >> suppPoids; display.SetPoids(suppPoids);
        Bdd3 >> suppCont; display.SetCont(suppCont);
        Bdd3 >> suppAccr; display.SetAccr(suppAccr);
        Bdd3 >> suppSource; display.SetSource(suppSource);

        imgBDD.push_back(display);

        if(suppAccr == "A")
        {
            NumAccred = 2;
        }
        else
        {
            NumAccred = 1;
        }

        if(Accred <= NumAccred)
        {
            for(int j = 0; j < 7; j++)
            {
                QTableWidgetItem *item = new QTableWidgetItem;

                if(j == 0)
                    // item->setText(QString::fromStdString(to_string(suppNum)));
                    item->setData(Qt::DisplayRole,suppNum);
                    // item->setText(QString::number(suppNum));
                if(j == 1)
                    item->setText(QString::fromStdString(suppNom));
                if(j == 2)
                    //item->setText(QString::fromStdString(to_string(suppCout)));
                    item->setData(Qt::DisplayRole,suppCout);
                    // item->setText(QString::number(suppCout));
                if(j == 3)
                    // item->setText(QString::fromStdString(to_string(suppPoids)));
                    item->setData(Qt::DisplayRole,suppPoids);
                    // item->setText(QString::number(suppPoids));
                if(j == 4)
                    item->setText(QString::fromStdString(suppCont));
                if(j == 5)
                    item->setText(QString::fromStdString(suppAccr));
                if(j == 6)
                    item->setText(QString::fromStdString(suppSource));

                ui->LBLtab->setItem(k,j,item);
            }
            k++;
        }
    }
}

void Bibliotheque::on_ANL_clicked()
{
    ui->SWBIB->setCurrentIndex(0);
    ui->EDITCONT->setText("");
    ui->EDITPRIX->setText("");
    ui->EDITSOURCE->setText("");
    ui->EDITNOM->setText("");
    importer = 0;
}

void Bibliotheque::on_ANL_2_clicked()
{
    ui->SWBIB->setCurrentIndex(0);
}

void Bibliotheque::on_VALID_clicked()
{
    int state = 1;

    float imgPrix;
    QString Prix;
    if(Accred == 2)
    {
        Prix = "25";
        imgPrix = Prix.toFloat();
    }
    else
    {
        Prix = ui->EDITPRIX->text();
        imgPrix = Prix.toFloat();
    }

    if(ui->EDITNOM->text().isEmpty() || Prix == "" || ui->EDITSOURCE->text().isEmpty() || ui->EDITCONT->text().isEmpty())
    {
        QMessageBox::information(this,"ERREUR", "Les champs ne sont pas remplis correctement.");
    }
    else
    {
        // Récupération des caractéristiques que l'on rentre pour l'image
        QString Nom = ui->EDITNOM->text();
        string imgNom = Nom.toStdString();

        //QString Poids = ui->EDITPOIDS->text();

        //GESTION DU POIDS
        QFileInfo suf(adr);
        QString extension = suf.suffix();
        QByteArray ba;
        QBuffer buffer(&ba);
        buffer.open(QIODevice::WriteOnly);
        if (extension == "jpg")
        {
            img.save(&buffer,"jpg");
            buffer.close();
        }
        if (extension == "png")
        {
            img.save(&buffer,"png");
            buffer.close();
        }
        if (extension == "bmp")
        {
            img.save(&buffer,"bmp");
            buffer.close();
        }

        int imgPoids = ba.size()/1024; //On veut un poids en Ko

        //float imgPoids = img.sizeInBytes() / 8 ;// Poids.toFloat();

        QString Source = ui->EDITSOURCE->text();
        string imgSource = Source.toStdString();

        string imgAccreditation;
        //QString Accreditation = ui->EDITACCR->text();
        if(ui->AC0->isChecked())
        {
            QString Accreditation = "A";
            imgAccreditation = Accreditation.toStdString();
        }
        if(ui->AC1->isChecked())
        {
            QString Accreditation = "N";
            imgAccreditation = Accreditation.toStdString();
        }

        QString Contenu = ui->EDITCONT->text();
        string imgContenu = Contenu.toStdString();

        Biblio ajout;

        int ajoutNum;
        string ajoutNom, ajoutCont, ajoutAccr, ajoutSource;;
        double ajoutCout, ajoutPoids;

        imgBDD.clear();

        ifstream Bdd3("Data.txt");

        for(int i = 0; i < taille; i++)
        {
            Bdd3 >> ajoutNum; ajout.SetNum(ajoutNum);
            Bdd3 >> ajoutNom; ajout.SetNom(ajoutNom);
            if(ajoutNom == imgNom)
            {
                QMessageBox::information(this,"ERREUR", "Ce nom existe déjà, veuillez en rentrer un nouveau.");
                state = 0;
                break;
            }
            Bdd3 >> ajoutCout; ajout.SetCout(ajoutCout);
            Bdd3 >> ajoutPoids; ajout.SetPoids(ajoutPoids);
            Bdd3 >> ajoutCont; ajout.SetCont(ajoutCont);
            Bdd3 >> ajoutAccr; ajout.SetAccr(ajoutAccr);
            Bdd3 >> ajoutSource; ajout.SetSource(ajoutSource);
            imgBDD.push_back(ajout);
        }
        if(state!=0)
        {
            max++;
            ajout.SetNum(max);
            ajout.SetNom(imgNom);
            ajout.SetCout(imgPrix);
            ajout.SetPoids(imgPoids);
            ajout.SetSource(imgSource);
            ajout.SetAccr(imgAccreditation);
            ajout.SetCont(imgContenu);

            imgBDD.push_back(ajout);

            taille++;
            tailleAccred++;

            Bdd3.close();

            ofstream added("Data.txt");

            for(int i = 0; i < taille; i++)
            {
                added << imgBDD[i].GetNum() << " " << imgBDD[i].GetNom() << " " << imgBDD[i].GetCout() << " " << imgBDD[i].GetPoids() << " " << imgBDD[i].GetCont() << " " << imgBDD[i].GetAccr() << " " << imgBDD[i].GetSource() << endl;
            }

            string current = filesystem::current_path().string();
            string imgPATH = imgNom + ".jpg";
            QString IMGPATH = QString::fromStdString(imgPATH);
            QDir::setCurrent(QString::fromStdString(current) + "/Bib");
            img.save(IMGPATH);
            QString BIBOPEN = QString::fromStdString(current) + "/Bib/" + IMGPATH;
            QDir::setCurrent(BIBOPEN);
            SetAdr(BIBOPEN);
            QDir::setCurrent(QString::fromStdString(current));
        }

        ui->EDITNOM->clear();
        ui->EDITPRIX->clear();
        ui->EDITSOURCE->clear();
        ui->AC0->setChecked(false);
        ui->AC1->setChecked(false);
        ui->EDITCONT->clear();

        ui->SWBIB->setCurrentIndex(0);
        importer = 0;
    }


}

void Bibliotheque::on_MODIFSUPPB_clicked()
{
    ui->SWBIB->setCurrentIndex(4);
}

void Bibliotheque::on_SUPPIMG_clicked()
{
    int imgSUPP = -1;

    string SuppTxt = (ui->NOMSUPP->text()).toStdString();
    string SuppNbr;

    Biblio suppression;

    int suppNum;
    string suppNom, suppCont, suppAccr, suppSource, nomimgsupp;
    double suppCout, suppPoids;

    imgBDD.clear();

    ifstream Bdd3("Data.txt");

    for(int i = 0; i < taille; i++)
    {
        Bdd3 >> suppNum; suppression.SetNum(suppNum);
        Bdd3 >> suppNom; suppression.SetNom(suppNom);
        Bdd3 >> suppCout; suppression.SetCout(suppCout);
        Bdd3 >> suppPoids; suppression.SetPoids(suppPoids);
        Bdd3 >> suppCont; suppression.SetCont(suppCont);
        Bdd3 >> suppAccr; suppression.SetAccr(suppAccr);
        Bdd3 >> suppSource; suppression.SetSource(suppSource);
        imgBDD.push_back(suppression);
    }


    for(int i = 0; i < taille; i++)
    {
        SuppNbr = QString::number(imgBDD[i].GetNum()).toStdString();

        if(SuppTxt == imgBDD[i].GetNom())
        {
            imgSUPP = imgBDD[i].GetNum();
            nomimgsupp = imgBDD[i].GetNom();
        }
        if(SuppTxt == SuppNbr)
        {
            imgSUPP = imgBDD[i].GetNum();
            nomimgsupp = imgBDD[i].GetNom();
        }
    }

    if(imgSUPP == -1)
    {
        QMessageBox::information(this, "ERREUR", "L'image que vous voulez supprimer n'appartient pas à la bibliothèque.");
    }
    else
    {
        string current = filesystem::current_path().string();
        string imgPATH = nomimgsupp + ".jpg";
        QString IMGPATH = QString::fromStdString(imgPATH);
        QDir::setCurrent(QString::fromStdString(current) + "/Bib");
        QFile::remove(IMGPATH);
        QDir::setCurrent(QString::fromStdString(current));

        ofstream supp("Data.txt");

        for(int i = 0; i < taille; i++)
        {
            if(imgBDD[i].GetNum() != imgSUPP)
            {
                supp << imgBDD[i].GetNum() << " " << imgBDD[i].GetNom() << " " << imgBDD[i].GetCout() << " " << imgBDD[i].GetPoids() << " " << imgBDD[i].GetCont() << " " << imgBDD[i].GetAccr() << " " << imgBDD[i].GetSource() << endl;
            }
        }

        imgBDD.clear();

        ifstream supp2("Data.txt");

        for(int i = 0; i < taille; i++)
        {
            supp2 >> suppNum; suppression.SetNum(suppNum);
            supp2 >> suppNom; suppression.SetNom(suppNom);
            supp2 >> suppCout; suppression.SetCout(suppCout);
            supp2 >> suppPoids; suppression.SetPoids(suppPoids);
            supp2 >> suppCont; suppression.SetCont(suppCont);
            supp2 >> suppAccr; suppression.SetAccr(suppAccr);
            supp2 >> suppSource; suppression.SetSource(suppSource);
            imgBDD.push_back(suppression);
        }
        taille--;
        tailleAccred--;
    }

    ui->NOMSUPP->clear();
    //ui->SWBIB->setCurrentIndex(2);

    ui->LBLtab->sortByColumn(0,Qt::AscendingOrder);
    Biblio display;

    int suppNum2;
    string suppNom2, suppCont2, suppAccr2, suppSource2;
    double suppCout2, suppPoids2;


    string list;

    imgBDD.clear();

    ifstream Bdd32("Data.txt");

    ui->LBLtab->setColumnCount(7);

    QStringList hlabels;
    hlabels << "Numéro" << "Nom" << "coût (€)" << "poids (Ko)" << "Contenu" << "Accréditation" << "Source";

    ui->LBLtab->setHorizontalHeaderLabels(hlabels);
    ui->LBLtab->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->LBLtab->setSortingEnabled(true);
    ui->LBLtab->verticalHeader()->setVisible(false);
    ui->LBLtab->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->LBLtab->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->LBLtab->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    int k = 0;

    for(int i = 0; i < taille; i++)
    {
        Bdd32 >> suppNum2; display.SetNum(suppNum2);
        Bdd32 >> suppNom2; display.SetNom(suppNom2);
        Bdd32 >> suppCout2; display.SetCout(suppCout2);
        Bdd32 >> suppPoids2; display.SetPoids(suppPoids2);
        Bdd32 >> suppCont2; display.SetCont(suppCont2);
        Bdd32 >> suppAccr2; display.SetAccr(suppAccr2);
        Bdd32 >> suppSource2; display.SetSource(suppSource2);

        imgBDD.push_back(display);

        if(suppAccr2 == "A")
        {
            NumAccred = 2;
        }
        else
        {
            NumAccred = 1;
        }

        if(Accred <= NumAccred)
        {
            for(int j = 0; j < 7; j++)
            {
                ui->LBLtab->setRowCount(k+1);
                QTableWidgetItem *item = new QTableWidgetItem;

                if(j == 0)
                    // item->setText(QString::fromStdString(to_string(suppNum)));
                    item->setData(Qt::DisplayRole,suppNum2);
                    // item->setText(QString::number(suppNum));
                if(j == 1)
                    item->setText(QString::fromStdString(suppNom2));
                if(j == 2)
                    // item->setText(QString::fromStdString(to_string(suppCout)));
                    item->setData(Qt::DisplayRole,suppCout2);
                    // item->setText(QString::number(suppCout));
                if(j == 3)
                    // item->setText(QString::fromStdString(to_string(suppPoids)));
                    item->setData(Qt::DisplayRole,suppPoids2);
                    // item->setText(QString::number(suppPoids));
                if(j == 4)
                    item->setText(QString::fromStdString(suppCont2));
                if(j == 5)
                    item->setText(QString::fromStdString(suppAccr2));
                if(j == 6)
                    item->setText(QString::fromStdString(suppSource2));

                ui->LBLtab->setItem(k,j,item);
            }
            k++;
        }
    }
}

void Bibliotheque::on_MODIFBUTTON_clicked()
{
    int imgSUPP = -1;
    string SuppTxt = (ui->NOMMODIF->text()).toStdString();
    string SuppNbr;

    Biblio modification;

    int ajoutNum;
    string ajoutNom, ajoutCont, ajoutAccr,ajoutSource;
    double ajoutCout, ajoutPoids;

    ifstream modif("Data.txt");

    for(int i = 0; i < taille; i++)
    {
        modif >> ajoutNum; modification.SetNum(ajoutNum);
        modif >> ajoutNom; modification.SetNom(ajoutNom);
        modif >> ajoutCout; modification.SetCout(ajoutCout);
        modif >> ajoutPoids; modification.SetPoids(ajoutPoids);
        modif >> ajoutCont; modification.SetCont(ajoutCont);
        modif >> ajoutAccr; modification.SetAccr(ajoutAccr);
        modif >> ajoutSource; modification.SetSource(ajoutSource);
        imgBDD.push_back(modification);
    }

    for(int i = 0; i < taille; i++)
    {
        SuppNbr = QString::number(imgBDD[i].GetNum()).toStdString();

        if(SuppTxt == imgBDD[i].GetNom())
        {
            imgSUPP = imgBDD[i].GetNum();
            /*if(imgBDD[i].GetAccr() != "A")
            {
                imgSUPP = -2;
            }*/
        }
        if(SuppTxt == SuppNbr)
        {
            imgSUPP = imgBDD[i].GetNum();
            /*if(imgBDD[i].GetAccr() != "A")
            {
                imgSUPP = -2;
            }*/
        }
    }

    QString txtmodifie = ui->TXTMODIF->text();

    if(imgSUPP == -1)
    {
        QMessageBox::information(this, "ERREUR", "L'image que vous voulez modifier n'appartient pas à la bibliothèque.");
    }
    /*if(imgSUPP == -2)
    {
        QMessageBox::information(this, "ERREUR", "Alors, ça t'as pas le droit déjà !");
    }*/
    else
    {
        ofstream supp("Data.txt");

        for(int i = 0; i < taille; i++)
        {
            if(imgBDD[i].GetNum() == imgSUPP)
            {
                if(ui->COUTMODIF->isChecked())
                {
                        double MODIF = txtmodifie.toDouble();
                        imgBDD[i].SetCout(MODIF);
                        ui->COUTMODIF->setChecked(false);
                }
                if(ui->CONTMODIF->isChecked())
                {
                        string MODIF = txtmodifie.toStdString();
                        imgBDD[i].SetCont(MODIF);
                        ui->CONTMODIF->setChecked(false);
                }
                if(ui->A0->isChecked())
                {
                        string MODIF = "N"; //txtmodifie.toInt();
                        imgBDD[i].SetAccr(MODIF);
                        ui->A0->setChecked(false);
                }
                if(ui->A1->isChecked())
                {
                        string MODIF = "A"; //txtmodifie.toInt();
                        imgBDD[i].SetAccr(MODIF);
                        ui->A1->setChecked(false);
                }
                if(ui->SOURCEMODIF->isChecked())
                {
                        string MODIF = txtmodifie.toStdString();
                        imgBDD[i].SetSource(MODIF);
                        ui->SOURCEMODIF->setChecked(false);
                }

                supp << imgBDD[i].GetNum() << " " << imgBDD[i].GetNom() << " " << imgBDD[i].GetCout() << " " << imgBDD[i].GetPoids() << " " << imgBDD[i].GetCont() << " " << imgBDD[i].GetAccr() << " " << imgBDD[i].GetSource() << endl;
            }
        }
    }

    ofstream modifEND("Data.txt");

    for(int i = 0; i < taille; i++)
    {
        modifEND << imgBDD[i].GetNum() << " " << imgBDD[i].GetNom() << " " << imgBDD[i].GetCout() << " " << imgBDD[i].GetPoids() << " " << imgBDD[i].GetCont() << " " << imgBDD[i].GetAccr() << " " << imgBDD[i].GetSource() << endl;
    }

    ui->TXTMODIF->clear();
    ui->NOMMODIF->clear();

    if(ui->COUTMODIF->isChecked())
    {
        ui->COUTMODIF->setChecked(false);
    }
    if(ui->CONTMODIF->isChecked())
    {
        ui->CONTMODIF->setChecked(false);
    }
    if(ui->A0->isChecked())
    {
        ui->A0->setChecked(false);
    }
    if(ui->A1->isChecked())
    {
        ui->A1->setChecked(false);
    }
    if(ui->SOURCEMODIF->isChecked())
    {
        ui->SOURCEMODIF->setChecked(false);
    }

    ui->LBLtab->sortByColumn(0,Qt::AscendingOrder);

    Biblio display;

    int suppNum;
    string suppNom, suppCont, suppAccr, suppSource, list;
    double suppCout, suppPoids;

    imgBDD.clear();

    ifstream Bdd3("Data.txt");

    ui->LBLtab->setColumnCount(7);

    QStringList hlabels;
    hlabels << "Numéro" << "Nom" << "coût (€)" << "poids (Ko)" << "Contenu" << "Accréditation" << "Source";

    ui->LBLtab->setHorizontalHeaderLabels(hlabels);
    ui->LBLtab->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->LBLtab->setSortingEnabled(true);
    ui->LBLtab->verticalHeader()->setVisible(false);
    ui->LBLtab->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->LBLtab->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->LBLtab->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    int k = 0;

    for(int i = 0; i < taille; i++)
    {
        Bdd3 >> suppNum; display.SetNum(suppNum);
        Bdd3 >> suppNom; display.SetNom(suppNom);
        Bdd3 >> suppCout; display.SetCout(suppCout);
        Bdd3 >> suppPoids; display.SetPoids(suppPoids);
        Bdd3 >> suppCont; display.SetCont(suppCont);
        Bdd3 >> suppAccr; display.SetAccr(suppAccr);
        Bdd3 >> suppSource; display.SetSource(suppSource);

        imgBDD.push_back(display);

        if(suppAccr == "A")
        {
            NumAccred = 2;
        }
        else
        {
            NumAccred = 1;
        }

        if(Accred <= NumAccred)
        {
            for(int j = 0; j < 7; j++)
            {
                ui->LBLtab->setRowCount(k+1);
                QTableWidgetItem *item = new QTableWidgetItem;

                if(j == 0)
                    // item->setText(QString::fromStdString(to_string(suppNum)));
                    item->setData(Qt::DisplayRole,suppNum);
                    // item->setText(QString::number(suppNum));
                if(j == 1)
                    item->setText(QString::fromStdString(suppNom));
                if(j == 2)
                    // item->setText(QString::fromStdString(to_string(suppCout)));
                    item->setData(Qt::DisplayRole,suppCout);
                    // item->setText(QString::number(suppCout));
                if(j == 3)
                    // item->setText(QString::fromStdString(to_string(suppPoids)));
                    item->setData(Qt::DisplayRole,suppPoids);
                    // item->setText(QString::number(suppPoids));
                if(j == 4)
                    item->setText(QString::fromStdString(suppCont));
                if(j == 5)
                    item->setText(QString::fromStdString(suppAccr));
                if(j == 6)
                    item->setText(QString::fromStdString(suppSource));

                ui->LBLtab->setItem(k,j,item);
            }
            k++;
        }
    }
}

void Bibliotheque::on_RETOURMODIF_clicked()
{
    if(ui->COUTMODIF->isChecked())
    {
        ui->COUTMODIF->setChecked(false);
    }
    if(ui->CONTMODIF->isChecked())
    {
        ui->CONTMODIF->setChecked(false);
    }
    if(ui->A0->isChecked())
    {
        ui->A0->setChecked(false);
    }
    if(ui->A1->isChecked())
    {
        ui->A1->setChecked(false);
    }
    if(ui->SOURCEMODIF->isChecked())
    {
        ui->SOURCEMODIF->setChecked(false);
    }
    ui->TXTMODIF->setText("");
    ui->NOMMODIF->setText("");
    ui->NOMSUPP->setText("");
    ui->SWBIB->setCurrentIndex(4);
}


void Bibliotheque::on_ANLBIB_clicked()
{
    ui->SLC->setText("");
    ui->SLPmax->setText("");
    ui->SLPmin->setText("");
    ui->SWBIB->setCurrentIndex(0);
    ui->SWIMGBIB->setCurrentIndex(0);
}


void Bibliotheque::on_VLDBIB_clicked()
{
    int GoNoGo = 1;
    QString imgTxt;
    int CurrentRowImg = ui->LBLtab->currentRow();

    if(CurrentRowImg == -1){
        GoNoGo = 0;
    }

    if(GoNoGo == 1)
    {
        QTableWidgetItem *NumImg = ui->LBLtab->item(CurrentRowImg,0);
        imgTxt = NumImg->text();
        string m = imgTxt.toStdString();

        Biblio modification;

        int ajoutNum;
        string ajoutNom, ajoutCont, ajoutAccr, ajoutSource, SuppNbr, imgSUPP;
        double ajoutCout, ajoutPoids;

        ifstream modif("Data.txt");

        for(int i = 0; i < taille; i++)
        {
            modif >> ajoutNum; modification.SetNum(ajoutNum);
            modif >> ajoutNom; modification.SetNom(ajoutNom);
            modif >> ajoutCout; modification.SetCout(ajoutCout);
            modif >> ajoutPoids; modification.SetPoids(ajoutPoids);
            modif >> ajoutCont; modification.SetCont(ajoutCont);
            modif >> ajoutAccr; modification.SetAccr(ajoutAccr);
            modif >> ajoutSource; modification.SetSource(ajoutSource);
            imgBDD.push_back(modification);
        }

        for(int i = 0; i < taille; i++)
        {
            SuppNbr = QString::number(imgBDD[i].GetNum()).toStdString();

            if(m == SuppNbr)
            {
                imgSUPP = imgBDD[i].GetNom();
            }
        }

        string current = filesystem::current_path().string();
        string imgPATH = imgSUPP + ".jpg";
        QString IMGPATH = QString::fromStdString(imgPATH);
        QString BIBOPEN = QString::fromStdString(current) + "/Bib/" + IMGPATH;
        QDir::setCurrent(BIBOPEN);

        if (QString::compare(BIBOPEN, QString()) !=0)
        {
            QImage image;
            bool charge = image.load(BIBOPEN);

            SetAdr(BIBOPEN);
            img = image.copy();
            if (charge)
            {
                image = image.scaledToWidth(ui->LBLimg->width(),Qt::SmoothTransformation);
                image = image.scaledToHeight(ui->LBLimg->height(),Qt::SmoothTransformation);
                ui->LBLimg->setPixmap(QPixmap::fromImage(image));
                ui->LBLimg->setMinimumSize((int)image.width()/2, (int)image.height()/2);

                ui->SWIMGBIB->setCurrentIndex(0);
                ui->SWBIB->setCurrentIndex(0);
            }
            else
            {
                QMessageBox::information(this, "ERREUR", "Hmm... Cette image n'est pas repertoriée !");
            }
        }

        QDir::setCurrent(QString::fromStdString(current));
        ui->TTT->setVisible(true);
        ui->ADD->setVisible(false);
        importer = 0;

    }
    else
    {
        QMessageBox::information(this, "ERREUR", "Veuillez sélectionner une image avant de vouloir l'ouvrir !!!");
    }
}


void Bibliotheque::on_PrixImg_clicked()
{
    int GoNoGo = 1;
    QString imgTxt;
    int CurrentRowImg = ui->LBLtab->currentRow();


    if(CurrentRowImg == -1){
        GoNoGo = 0;
    }

    if(GoNoGo == 1)
    {
        QTableWidgetItem *NumImg = ui->LBLtab->item(CurrentRowImg,0);
        imgTxt = NumImg->text();
        string m = imgTxt.toStdString();

        Biblio modification;

        int ajoutNum;
        string ajoutNom, ajoutCont, ajoutAccr, ajoutSource, SuppNbr;
        double ajoutCout, ajoutPoids, imgSUPP;

        ifstream modif("Data.txt");

        for(int i = 0; i < taille; i++)
        {
            modif >> ajoutNum; modification.SetNum(ajoutNum);
            modif >> ajoutNom; modification.SetNom(ajoutNom);
            modif >> ajoutCout; modification.SetCout(ajoutCout);
            modif >> ajoutPoids; modification.SetPoids(ajoutPoids);
            modif >> ajoutCont; modification.SetCont(ajoutCont);
            modif >> ajoutAccr; modification.SetAccr(ajoutAccr);
            modif >> ajoutSource; modification.SetSource(ajoutSource);
            imgBDD.push_back(modification);
        }

        for(int i = 0; i < taille; i++)
        {
            SuppNbr = QString::number(imgBDD[i].GetNum()).toStdString();

            if(m == SuppNbr)
            {
                imgSUPP = imgBDD[i].GetCout();
            }
        }

        QString ImgPrix = QString("Votre image coût (€)e : %1").arg(imgSUPP,0,'f',2);
        QMessageBox::information(this, "Le prix de votre image", ImgPrix);
    }
    else
    {
        QMessageBox::information(this, "ERREUR", "Veuillez sélectionner une image avant de vouloir savoir combienne elle coût (€)e !!!");
    }
}

void Bibliotheque::on_BDD_3_clicked()
{
    ui->SWBIB->setCurrentIndex(4);
    ui->SWIMGBIB->setCurrentIndex(2);
    ui->LBLtab->clear();
    Biblio display;

    int suppNum;
    string suppNom, suppCont, suppAccr, suppSource, list;
    double suppCout, suppPoids;

    imgBDD.clear();

    ifstream Bdd3("Data.txt");

    ui->LBLtab->setRowCount(tailleAccred);
    ui->LBLtab->setColumnCount(7);

    QStringList hlabels;
    hlabels << "Numéro" << "Nom" << "coût (€)" << "poids (Ko)" << "Contenu" << "Accréditation" << "Source";

    ui->LBLtab->setHorizontalHeaderLabels(hlabels);
    ui->LBLtab->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->LBLtab->setSortingEnabled(true);
    ui->LBLtab->verticalHeader()->setVisible(false);
    ui->LBLtab->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->LBLtab->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->LBLtab->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    int k = 0;

    for(int i = 0; i < taille; i++)
    {
        Bdd3 >> suppNum; display.SetNum(suppNum);
        Bdd3 >> suppNom; display.SetNom(suppNom);
        Bdd3 >> suppCout; display.SetCout(suppCout);
        Bdd3 >> suppPoids; display.SetPoids(suppPoids);
        Bdd3 >> suppCont; display.SetCont(suppCont);
        Bdd3 >> suppAccr; display.SetAccr(suppAccr);
        Bdd3 >> suppSource; display.SetSource(suppSource);

        imgBDD.push_back(display);

        if(suppAccr == "A")
        {
            NumAccred = 2;
        }
        else
        {
            NumAccred = 1;
        }

        if(Accred <= NumAccred)
        {
            for(int j = 0; j < 7; j++)
            {
                QTableWidgetItem *item = new QTableWidgetItem;

                if(j == 0)
                    // item->setText(QString::fromStdString(to_string(suppNum)));
                    item->setData(Qt::DisplayRole,suppNum);
                    // item->setText(QString::number(suppNum));
                if(j == 1)
                    item->setText(QString::fromStdString(suppNom));
                if(j == 2)
                    //item->setText(QString::fromStdString(to_string(suppCout)));
                    item->setData(Qt::DisplayRole,suppCout);
                    // item->setText(QString::number(suppCout));
                if(j == 3)
                    // item->setText(QString::fromStdString(to_string(suppPoids)));
                    item->setData(Qt::DisplayRole,suppPoids);
                    // item->setText(QString::number(suppPoids));
                if(j == 4)
                    item->setText(QString::fromStdString(suppCont));
                if(j == 5)
                    item->setText(QString::fromStdString(suppAccr));
                if(j == 6)
                    item->setText(QString::fromStdString(suppSource));

                ui->LBLtab->setItem(k,j,item);
            }
            k++;
        }
    }
}

void Bibliotheque::on_SLIP_clicked()
{

    double Max, Min;

    if(ui->SLPmin->text().isEmpty() && ui->SLPmax->text().isEmpty())
    {
        QMessageBox::information(this, "ERREUR", "Veuillez entrer le contenu dont vous souhaitez une sous liste.");
    }
    else{

        Biblio display;

        int suppNum;
        string suppNom, suppCont, suppAccr, suppSource, list;
        double suppCout, suppPoids;

        imgBDD.clear();

        ifstream Bdd3("Data.txt");

        ui->LBLtab->setColumnCount(7);

        QStringList hlabels;
        hlabels << "Numéro" << "Nom" << "coût (€)" << "poids (Ko)" << "Contenu" << "Accréditation" << "Source";

        ui->LBLtab->setHorizontalHeaderLabels(hlabels);
        ui->LBLtab->setSelectionBehavior(QAbstractItemView::SelectRows);
        ui->LBLtab->setSortingEnabled(true);
        ui->LBLtab->verticalHeader()->setVisible(false);
        ui->LBLtab->setEditTriggers(QAbstractItemView::NoEditTriggers);
        ui->LBLtab->setSelectionMode(QAbstractItemView::SingleSelection);
        ui->LBLtab->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

        QString SLcontmin, SLcontmax;

        if(ui->SLPmin->text().isEmpty())
        {
            Min = 0;
        }
        else
        {
            SLcontmin = ui->SLPmin->text();
            Min = SLcontmin.toDouble();
        }

        if(ui->SLPmax->text().isEmpty())
        {
            Max = 99999;
        }
        else
        {
            SLcontmax = ui->SLPmax->text();
            Max = SLcontmax.toDouble();
        }

        int k = 0, kk = 0;

        for(int i = 0; i < taille; i++)
        {
            Bdd3 >> suppNum; display.SetNum(suppNum);
            Bdd3 >> suppNom; display.SetNom(suppNom);
            Bdd3 >> suppCout; display.SetCout(suppCout);
            Bdd3 >> suppPoids; display.SetPoids(suppPoids);
            Bdd3 >> suppCont; display.SetCont(suppCont);
            Bdd3 >> suppAccr; display.SetAccr(suppAccr);
            Bdd3 >> suppSource; display.SetSource(suppSource);

            imgBDD.push_back(display);

            if(suppAccr == "A")
            {
                NumAccred = 2;
            }
            else
            {
                NumAccred = 1;
            }

            if(Accred <= NumAccred)
            {
                if(Min <= suppCout && suppCout <= Max)
                {
                    for(int j = 0; j < 7; j++)
                    {
                        ui->LBLtab->setRowCount(k+1);
                        QTableWidgetItem *item = new QTableWidgetItem;

                        if(j == 0)
                            //item->setText(QString::fromStdString(to_string(suppNum)));
                            item->setData(Qt::DisplayRole,suppNum);
                        if(j == 1)
                            item->setText(QString::fromStdString(suppNom));
                        if(j == 2)
                            // item->setText(QString::fromStdString(to_string(suppCout)));
                            item->setData(Qt::DisplayRole,suppCout);
                        if(j == 3)
                            // item->setText(QString::fromStdString(to_string(suppPoids)));
                            item->setData(Qt::DisplayRole,suppPoids);
                        if(j == 4)
                            item->setText(QString::fromStdString(suppCont));
                        if(j == 5)
                            item->setText(QString::fromStdString(suppAccr));
                        if(j == 6)
                            item->setText(QString::fromStdString(suppSource));

                        ui->LBLtab->setItem(k,j,item);
                    }
                    k++;
                    kk++;
                }
            }
        }
        if(kk == 0)
        {
            QMessageBox::information(this, "ERREUR", "Veuillez vérifier que vous avez bien rentrer des valeurs numériques !.");
        }
    }
}

void Bibliotheque::on_TPC_clicked()
{
    if(ui->SLC->text().isEmpty())
    {
        QMessageBox::information(this, "ERREUR", "Veuillez entrer le contenu dont vous souhaitez une sous liste.");
    }
    else
    {
        Biblio display;

        int suppNum;
        string suppNom, suppCont, suppAccr, suppSource, list;
        double suppCout, suppPoids;

        imgBDD.clear();

        ifstream Bdd3("Data.txt");

        ui->LBLtab->setColumnCount(7);

        QStringList hlabels;
        hlabels << "Numéro" << "Nom" << "coût (€)" << "poids (Ko)" << "Contenu" << "Accréditation" << "Source";

        ui->LBLtab->setHorizontalHeaderLabels(hlabels);
        ui->LBLtab->setSelectionBehavior(QAbstractItemView::SelectRows);
        ui->LBLtab->setSortingEnabled(true);
        ui->LBLtab->verticalHeader()->setVisible(false);
        ui->LBLtab->setEditTriggers(QAbstractItemView::NoEditTriggers);
        ui->LBLtab->setSelectionMode(QAbstractItemView::SingleSelection);
        ui->LBLtab->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

        QString SLcont = ui->SLC->text();

        int k = 0, kk = 0;

        for(int i = 0; i < taille; i++)
        {
            Bdd3 >> suppNum; display.SetNum(suppNum);
            Bdd3 >> suppNom; display.SetNom(suppNom);
            Bdd3 >> suppCout; display.SetCout(suppCout);
            Bdd3 >> suppPoids; display.SetPoids(suppPoids);
            Bdd3 >> suppCont; display.SetCont(suppCont);
            Bdd3 >> suppAccr; display.SetAccr(suppAccr);
            Bdd3 >> suppSource; display.SetSource(suppSource);

            imgBDD.push_back(display);

            if(suppAccr == "A")
            {
                NumAccred = 2;
            }
            else
            {
                NumAccred = 1;
            }

            if(Accred <= NumAccred)
            {
                if(SLcont.toStdString() == suppCont)
                {
                    for(int j = 0; j < 7; j++)
                    {
                        ui->LBLtab->setRowCount(k+1);
                        QTableWidgetItem *item = new QTableWidgetItem;

                        if(j == 0)
                            // item->setText(QString::fromStdString(to_string(suppNum)));
                            item->setData(Qt::DisplayRole,suppNum);
                        if(j == 1)
                            item->setText(QString::fromStdString(suppNom));
                        if(j == 2)
                            // item->setText(QString::fromStdString(to_string(suppCout)));
                            item->setData(Qt::DisplayRole,suppCout);
                        if(j == 3)
                            // item->setText(QString::fromStdString(to_string(suppPoids)));
                            item->setData(Qt::DisplayRole,suppPoids);
                        if(j == 4)
                            item->setText(QString::fromStdString(suppCont));
                        if(j == 5)
                            item->setText(QString::fromStdString(suppAccr));
                        if(j == 6)
                            item->setText(QString::fromStdString(suppSource));

                        ui->LBLtab->setItem(k,j,item);
                    }
                    k++;
                    kk++;
                }
            }
        }
        if(kk == 0)
        {
            QMessageBox::information(this, "ERREUR", "Veuillez vérifier l'orthographe du contenu souhaité.");
        }

    }
}

void Bibliotheque::on_Reset_clicked()
{

    ui->LBLtab->sortByColumn(0,Qt::AscendingOrder);
    ui->SLC->clear();
    ui->SLPmax->clear();
    ui->SLPmin->clear();
    Biblio display;

    int suppNum;
    string suppNom, suppCont, suppAccr, suppSource, list;
    double suppCout, suppPoids;

    imgBDD.clear();

    ifstream Bdd3("Data.txt");

    ui->LBLtab->setColumnCount(7);

    QStringList hlabels;
    hlabels << "Numéro" << "Nom" << "coût (€)" << "poids (Ko)" << "Contenu" << "Accréditation" << "Source";

    ui->LBLtab->setHorizontalHeaderLabels(hlabels);
    ui->LBLtab->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->LBLtab->setSortingEnabled(true);
    ui->LBLtab->verticalHeader()->setVisible(false);
    ui->LBLtab->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->LBLtab->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->LBLtab->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    int k = 0;

    for(int i = 0; i < taille; i++)
    {
        Bdd3 >> suppNum; display.SetNum(suppNum);
        Bdd3 >> suppNom; display.SetNom(suppNom);
        Bdd3 >> suppCout; display.SetCout(suppCout);
        Bdd3 >> suppPoids; display.SetPoids(suppPoids);
        Bdd3 >> suppCont; display.SetCont(suppCont);
        Bdd3 >> suppAccr; display.SetAccr(suppAccr);
        Bdd3 >> suppSource; display.SetSource(suppSource);

        imgBDD.push_back(display);

        if(suppAccr == "A")
        {
            NumAccred = 2;
        }
        else
        {
            NumAccred = 1;
        }

        if(Accred <= NumAccred)
        {
            for(int j = 0; j < 7; j++)
            {
                ui->LBLtab->setRowCount(k+1);
                QTableWidgetItem *item = new QTableWidgetItem;

                if(j == 0)
                    // item->setText(QString::fromStdString(to_string(suppNum)));
                    item->setData(Qt::DisplayRole,suppNum);
                    // item->setText(QString::number(suppNum));
                if(j == 1)
                    item->setText(QString::fromStdString(suppNom));
                if(j == 2)
                    // item->setText(QString::fromStdString(to_string(suppCout)));
                    item->setData(Qt::DisplayRole,suppCout);
                    // item->setText(QString::number(suppCout));
                if(j == 3)
                    // item->setText(QString::fromStdString(to_string(suppPoids)));
                    item->setData(Qt::DisplayRole,suppPoids);
                    // item->setText(QString::number(suppPoids));
                if(j == 4)
                    item->setText(QString::fromStdString(suppCont));
                if(j == 5)
                    item->setText(QString::fromStdString(suppAccr));
                if(j == 6)
                    item->setText(QString::fromStdString(suppSource));

                ui->LBLtab->setItem(k,j,item);
            }
            k++;
        }
    }
}

void Bibliotheque::on_pushButton_clicked()
{
    ui->SWBIB->setCurrentIndex(3);
}

void Bibliotheque::on_FREE_clicked()
{
    Biblio display;

    int suppNum;
    string suppNom, suppCont, suppAccr, suppSource, list;
    double suppCout, suppPoids;

    imgBDD.clear();

    ifstream Bdd3("Data.txt");

    ui->LBLtab->setColumnCount(7);

    QStringList hlabels;
    hlabels << "Numéro" << "Nom" << "coût (€)" << "poids (Ko)" << "Contenu" << "Accréditation" << "Source";

    ui->LBLtab->setHorizontalHeaderLabels(hlabels);
    ui->LBLtab->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->LBLtab->setSortingEnabled(true);
    ui->LBLtab->verticalHeader()->setVisible(false);
    ui->LBLtab->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->LBLtab->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->LBLtab->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    int k = 0, kk = 0;

    for(int i = 0; i < taille; i++)
    {
        Bdd3 >> suppNum; display.SetNum(suppNum);
        Bdd3 >> suppNom; display.SetNom(suppNom);
        Bdd3 >> suppCout; display.SetCout(suppCout);
        Bdd3 >> suppPoids; display.SetPoids(suppPoids);
        Bdd3 >> suppCont; display.SetCont(suppCont);
        Bdd3 >> suppAccr; display.SetAccr(suppAccr);
        Bdd3 >> suppSource; display.SetSource(suppSource);

        imgBDD.push_back(display);

        if(suppAccr == "A")
        {
            NumAccred = 2;
        }
        else
        {
            NumAccred = 1;
        }

        if(Accred <= NumAccred)
        {
            if(suppCout == 0)
            {
                for(int j = 0; j < 7; j++)
                {
                    ui->LBLtab->setRowCount(k+1);
                    QTableWidgetItem *item = new QTableWidgetItem;

                    if(j == 0)
                        //item->setText(QString::fromStdString(to_string(suppNum)));
                        item->setData(Qt::DisplayRole,suppNum);
                    if(j == 1)
                        item->setText(QString::fromStdString(suppNom));
                    if(j == 2)
                        // item->setText(QString::fromStdString(to_string(suppCout)));
                        item->setData(Qt::DisplayRole,suppCout);
                    if(j == 3)
                        // item->setText(QString::fromStdString(to_string(suppPoids)));
                        item->setData(Qt::DisplayRole,suppPoids);
                    if(j == 4)
                        item->setText(QString::fromStdString(suppCont));
                    if(j == 5)
                        item->setText(QString::fromStdString(suppAccr));
                    if(j == 6)
                        item->setText(QString::fromStdString(suppSource));

                    ui->LBLtab->setItem(k,j,item);
                }
                k++;kk++;
            }
        }
    }

    if(kk == 0)
    {
        QMessageBox::information(this, "ERREUR", "Pas de chance, il n'y a pas d'image gratuite.");

    }
}

void Bibliotheque::on_M10_clicked()
{
    Biblio display;

    int suppNum;
    string suppNom, suppCont, suppAccr, suppSource, list;
    double suppCout, suppPoids;

    imgBDD.clear();

    ifstream Bdd3("Data.txt");

    ui->LBLtab->setColumnCount(7);

    QStringList hlabels;
    hlabels << "Numéro" << "Nom" << "coût (€)" << "poids (Ko)" << "Contenu" << "Accréditation" << "Source";

    ui->LBLtab->setHorizontalHeaderLabels(hlabels);
    ui->LBLtab->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->LBLtab->setSortingEnabled(true);
    ui->LBLtab->verticalHeader()->setVisible(false);
    ui->LBLtab->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->LBLtab->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->LBLtab->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    int k = 0;

    for(int i = 0; i < taille; i++)
    {
        Bdd3 >> suppNum; display.SetNum(suppNum);
        Bdd3 >> suppNom; display.SetNom(suppNom);
        Bdd3 >> suppCout; display.SetCout(suppCout);
        Bdd3 >> suppPoids; display.SetPoids(suppPoids);
        Bdd3 >> suppCont; display.SetCont(suppCont);
        Bdd3 >> suppAccr; display.SetAccr(suppAccr);
        Bdd3 >> suppSource; display.SetSource(suppSource);

        imgBDD.push_back(display);

        if(suppAccr == "A")
        {
            NumAccred = 2;
        }
        else
        {
            NumAccred = 1;
        }

        if(Accred <= NumAccred)
        {
            if(suppCout <= 10)
            {
                for(int j = 0; j < 7; j++)
                {
                    ui->LBLtab->setRowCount(k+1);
                    QTableWidgetItem *item = new QTableWidgetItem;

                    if(j == 0)
                        //item->setText(QString::fromStdString(to_string(suppNum)));
                        item->setData(Qt::DisplayRole,suppNum);
                    if(j == 1)
                        item->setText(QString::fromStdString(suppNom));
                    if(j == 2)
                        // item->setText(QString::fromStdString(to_string(suppCout)));
                        item->setData(Qt::DisplayRole,suppCout);
                    if(j == 3)
                        // item->setText(QString::fromStdString(to_string(suppPoids)));
                        item->setData(Qt::DisplayRole,suppPoids);
                    if(j == 4)
                        item->setText(QString::fromStdString(suppCont));
                    if(j == 5)
                        item->setText(QString::fromStdString(suppAccr));
                    if(j == 6)
                        item->setText(QString::fromStdString(suppSource));

                    ui->LBLtab->setItem(k,j,item);
                }
                k++;
            }
        }
    }
}

void Bibliotheque::on_M100_clicked()
{
    Biblio display;

    int suppNum;
    string suppNom, suppCont, suppAccr, suppSource, list;
    double suppCout, suppPoids;

    imgBDD.clear();

    ifstream Bdd3("Data.txt");

    ui->LBLtab->setColumnCount(7);

    QStringList hlabels;
    hlabels << "Numéro" << "Nom" << "coût (€)" << "poids (Ko)" << "Contenu" << "Accréditation" << "Source";

    ui->LBLtab->setHorizontalHeaderLabels(hlabels);
    ui->LBLtab->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->LBLtab->setSortingEnabled(true);
    ui->LBLtab->verticalHeader()->setVisible(false);
    ui->LBLtab->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->LBLtab->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->LBLtab->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    int k = 0;

    for(int i = 0; i < taille; i++)
    {
        Bdd3 >> suppNum; display.SetNum(suppNum);
        Bdd3 >> suppNom; display.SetNom(suppNom);
        Bdd3 >> suppCout; display.SetCout(suppCout);
        Bdd3 >> suppPoids; display.SetPoids(suppPoids);
        Bdd3 >> suppCont; display.SetCont(suppCont);
        Bdd3 >> suppAccr; display.SetAccr(suppAccr);
        Bdd3 >> suppSource; display.SetSource(suppSource);

        imgBDD.push_back(display);

        if(suppAccr == "A")
        {
            NumAccred = 2;
        }
        else
        {
            NumAccred = 1;
        }

        if(Accred <= NumAccred)
        {
            if(suppCout >= 10 && suppCout < 100)
            {
                for(int j = 0; j < 7; j++)
                {
                    ui->LBLtab->setRowCount(k+1);
                    QTableWidgetItem *item = new QTableWidgetItem;

                    if(j == 0)
                        //item->setText(QString::fromStdString(to_string(suppNum)));
                        item->setData(Qt::DisplayRole,suppNum);
                    if(j == 1)
                        item->setText(QString::fromStdString(suppNom));
                    if(j == 2)
                        // item->setText(QString::fromStdString(to_string(suppCout)));
                        item->setData(Qt::DisplayRole,suppCout);
                    if(j == 3)
                        // item->setText(QString::fromStdString(to_string(suppPoids)));
                        item->setData(Qt::DisplayRole,suppPoids);
                    if(j == 4)
                        item->setText(QString::fromStdString(suppCont));
                    if(j == 5)
                        item->setText(QString::fromStdString(suppAccr));
                    if(j == 6)
                        item->setText(QString::fromStdString(suppSource));

                    ui->LBLtab->setItem(k,j,item);
                }
                k++;
            }
        }
    }
}

void Bibliotheque::on_P100_clicked()
{
    Biblio display;

    int suppNum;
    string suppNom, suppCont, suppAccr, suppSource, list;
    double suppCout, suppPoids;

    imgBDD.clear();

    ifstream Bdd3("Data.txt");

    ui->LBLtab->setColumnCount(7);

    QStringList hlabels;
    hlabels << "Numéro" << "Nom" << "coût (€)" << "poids (Ko)" << "Contenu" << "Accréditation" << "Source";

    ui->LBLtab->setHorizontalHeaderLabels(hlabels);
    ui->LBLtab->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->LBLtab->setSortingEnabled(true);
    ui->LBLtab->verticalHeader()->setVisible(false);
    ui->LBLtab->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->LBLtab->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->LBLtab->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    int k = 0;

    for(int i = 0; i < taille; i++)
    {
        Bdd3 >> suppNum; display.SetNum(suppNum);
        Bdd3 >> suppNom; display.SetNom(suppNom);
        Bdd3 >> suppCout; display.SetCout(suppCout);
        Bdd3 >> suppPoids; display.SetPoids(suppPoids);
        Bdd3 >> suppCont; display.SetCont(suppCont);
        Bdd3 >> suppAccr; display.SetAccr(suppAccr);
        Bdd3 >> suppSource; display.SetSource(suppSource);

        imgBDD.push_back(display);

        if(suppAccr == "A")
        {
            NumAccred = 2;
        }
        else
        {
            NumAccred = 1;
        }

        if(Accred <= NumAccred)
        {
            if(suppCout >= 100)
            {
                for(int j = 0; j < 7; j++)
                {
                    ui->LBLtab->setRowCount(k+1);
                    QTableWidgetItem *item = new QTableWidgetItem;

                    if(j == 0)
                        //item->setText(QString::fromStdString(to_string(suppNum)));
                        item->setData(Qt::DisplayRole,suppNum);
                    if(j == 1)
                        item->setText(QString::fromStdString(suppNom));
                    if(j == 2)
                        // item->setText(QString::fromStdString(to_string(suppCout)));
                        item->setData(Qt::DisplayRole,suppCout);
                    if(j == 3)
                        // item->setText(QString::fromStdString(to_string(suppPoids)));
                        item->setData(Qt::DisplayRole,suppPoids);
                    if(j == 4)
                        item->setText(QString::fromStdString(suppCont));
                    if(j == 5)
                        item->setText(QString::fromStdString(suppAccr));
                    if(j == 6)
                        item->setText(QString::fromStdString(suppSource));

                    ui->LBLtab->setItem(k,j,item);
                }
                k++;
            }
        }
    }
}

void Bibliotheque::on_STAT_clicked()
{
    Biblio display;

    int suppNum;
    string suppNom, suppCont, suppAccr, suppSource, list;
    double suppCout, suppPoids, mean = 0, min, max = 0;

    imgBDD.clear();

    ifstream Bdd3("Data.txt");

    ui->SWBIB->setCurrentIndex(5);

    int k=0;

    for(int i = 0; i < taille; i++)
    {
        Bdd3 >> suppNum; display.SetNum(suppNum);
        Bdd3 >> suppNom; display.SetNom(suppNom);
        Bdd3 >> suppCout; display.SetCout(suppCout);
        Bdd3 >> suppPoids; display.SetPoids(suppPoids);
        Bdd3 >> suppCont; display.SetCont(suppCont);
        Bdd3 >> suppAccr; display.SetAccr(suppAccr);
        Bdd3 >> suppSource; display.SetSource(suppSource);
        imgBDD.push_back(display);
        if(suppAccr == "A")
        {
            NumAccred = 2;
        }
        else
        {
            NumAccred = 1;
        }
        if(Accred <= NumAccred)
        {
            if(k==0)
            {
                min = suppCout;
                k++;
            }
            if(suppCout < min)
            {
                min = suppCout;
            }
            if(suppCout > max)
            {
                max = suppCout;
            }
            mean = mean + suppCout;
        }
    }

    mean = mean/tailleAccred;

    QString TXTStat = QString("Bonjour,\nvous pouvez voir :\n- %1 image(s)\npour un total  de :\n- %2 images.\nLe prix minimum est de :\n- %3€.\nLe prix maximal est de :\n- %4€.\nLa moyenne est de :\n- %5€").arg(tailleAccred).arg(taille).arg(min).arg(max).arg(mean);

    ui->Pokemon->setText(TXTStat);
    ui->STAT->setVisible(false);
}

void Bibliotheque::on_RetourK_clicked()
{
    ui->SWBIB->setCurrentIndex(4);
    ui->STAT->setVisible(true);
}

void Bibliotheque::on_TTT_clicked()
{
    QPointer<UniversImple> univ = new UniversImple();
    univ->setAttribute(Qt::WA_DeleteOnClose);
    univ->SetAdr(adr);
    univ->SetIm(img);
    univ->OpenTr();
    close();
}

