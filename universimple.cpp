#include "universimple.h"
#include "ui_universimple.h"
#include "apropos.h"
#include "traitement.h"
//#include "ui_traitement.h"
#include "fentr.h"
//#include "ui_fentr.h"
#include "bibliotheque.h"
//#include "ui_bibliotheque.h"
#include "accreditation.h"

UniversImple::UniversImple(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::UniversImple)
{
    ui->setupUi(this);
}

UniversImple::~UniversImple()
{
    this->setAttribute(Qt::WA_DeleteOnClose, true);
    delete ui;
}

void UniversImple::SetAdr(QString adresse)
{
    adr = adresse;
}

void UniversImple::SetIm(QImage image)
{
    img = image;
}

void UniversImple::AffIm()
{
    QImage image;
    image.load(adr);
    image = image.scaledToWidth(ui->LBL->width(),Qt::SmoothTransformation);
    image = image.scaledToHeight(ui->LBL->height(),Qt::SmoothTransformation);
    ui->LBL->setMinimumSize((int)image.width()/2, (int)image.height()/2);
    ui->LBL->setPixmap(QPixmap::fromImage(image));

}

void UniversImple::AffImageBibNDG()
{
    QImage image = img.copy();
    SetIm(image.copy());
    im_fen = image;
    image = image.scaledToWidth(ui->LBL->width(),Qt::SmoothTransformation);
    image = image.scaledToHeight(ui->LBL->height(),Qt::SmoothTransformation);

    ui->LBL->setPixmap(QPixmap::fromImage(image));
    ui->LBL->setMinimumSize((int)image.width()/2, (int)image.height()/2);

    adr = "1";
}

void UniversImple::on_APROPOS_triggered()
{
    apropos Apropos;
    Apropos.setModal(true);
    Apropos.exec();
}

void UniversImple::on_actionImporter_une_image_triggered()
{
    QString filename = QFileDialog::getOpenFileName(this,tr("Choisir une image"),"",tr("Images(*.png *.jpg *.jpeg)"));
    if (QString::compare(filename, QString()) !=0)
    {
        QImage image;
        bool charge = image.load(filename);

        SetAdr(filename);
        //SetIm(image);
        img = image.copy();
        if (charge)
        {
            image = image.scaledToWidth(ui->LBL->width(),Qt::SmoothTransformation);
            image = image.scaledToHeight(ui->LBL->height(),Qt::SmoothTransformation);
            ui->LBL->setPixmap(QPixmap::fromImage(image));
            ui->LBL->setMinimumSize((int)image.width()/2, (int)image.height()/2);
        }
        else
        {
            //Si erreur
        }
    }
}

void UniversImple::OpenTr()
{
    QPointer<Traitement> traitement = new Traitement(this);
    traitement->setAttribute(Qt::WA_DeleteOnClose);
    QPointer<FenTr> fenTR = new FenTr();
    fenTR->setAttribute(Qt::WA_DeleteOnClose);

    traitement->SetAdr(adr);
    fenTR->setCentralWidget(traitement);
    fenTR->show();
    traitement->SetFen(fenTR);
    traitement->AffImage();
    close();
}

void UniversImple::on_traitements_clicked()
{
    QPointer<Traitement> traitement = new Traitement(this);
    traitement->setAttribute(Qt::WA_DeleteOnClose);
    QPointer<FenTr> fenTR = new FenTr();
    fenTR->setAttribute(Qt::WA_DeleteOnClose);

    traitement->SetAdr(adr);
    fenTR->setCentralWidget(traitement);
    fenTR->show();
    traitement->SetFen(fenTR);
    traitement->AffImage();
    close();
    //fenTR->setParent(nullptr);
}

void UniversImple::Retour_Traitement()
{
    show();
}

void UniversImple::resizeEvent(QResizeEvent *event)
{
    QMainWindow::resizeEvent(event);
    QImage img_out = img.copy();
    int w = ui->LBL->width();
    int h = ui->LBL->height();
    ui->LBL->setPixmap((QPixmap::fromImage(img_out).scaled(w,h,Qt::KeepAspectRatio,Qt::SmoothTransformation)));
    if (adr == "")
    {
        ui->LBL->setText("Fichier -> Importer une image ");
    }
}

void UniversImple::on_bibliotheque_clicked()
{

    //bibliotheque = new Bibliotheque();
    //FenTr *fenTR = new FenTr(this);
    //bibliotheque->SetAdr(adr);
    //fenTR->setCentralWidget(bibliotheque);
    //bibliotheque->show();
    //bibliotheque->SetFen(fenTR);
    //bibliotheque->AffImage();

    QPointer<Accreditation> accreditation = new Accreditation();
    accreditation->deleteLater();
    //Accreditation *accreditation = new Accreditation();
    accreditation->setModal(1);

    //accreditation = new Accreditation();
    if (accreditation -> exec() == 0)
    {
        int var = accreditation->numero_acces;

        if (var == 1 || var == 2)
        {
            // Acceder à la bibliothèque.
            QPointer<Bibliotheque> bibliotheque = new Bibliotheque();
            accreditation->deleteLater();
            bibliotheque->setAttribute(Qt::WA_DeleteOnClose);
            bibliotheque->RecupAccred(var);
            bibliotheque->init();
            //FenTr *fenTR = new FenTr(this);
            bibliotheque->SetAdr(adr);
            //fenTR->setCentralWidget(bibliotheque);
            bibliotheque->show();
            //bibliotheque->SetFen(fenTR);
            bibliotheque->AffImage();
            close();
        }
    }
}


void UniversImple::on_actionImporter_une_biblioth_que_triggered()
{
    QPointer<Accreditation> accreditation = new Accreditation();
    accreditation->setModal(1);

    //accreditation = new Accreditation();
    if (accreditation -> exec() == 0)
    {
        int var = accreditation->numero_acces;

        if (var == 1 || var == 2)
        {
            // Acceder à la bibliothèque.
            QPointer<Bibliotheque> bibliotheque = new Bibliotheque();
            bibliotheque->setAttribute(Qt::WA_DeleteOnClose);
            bibliotheque->RecupAccred(var);
            bibliotheque->init();
            bibliotheque->SetAdr(adr);
            bibliotheque->show();
            bibliotheque->AffImage();
            close();
        }
    }
}

