#include "traitement.h"
#include "frequentiel.h"
#include "ui_traitement.h"
#include "universimple.h"
#include "fonctions.h"
#include "fentr.h"
#include "histogramme.h"
#include "accreditation.h"
#include "bibliotheque.h"



Traitement::Traitement(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Traitement)
{
    ui->setupUi(this);
    this->setAttribute(Qt::WA_DeleteOnClose, true);
    ui->SWTR->setCurrentIndex(0);
    ui->SWTRCLR->setCurrentIndex(0);
}

Traitement::~Traitement()
{
    this->setAttribute(Qt::WA_DeleteOnClose, true);
    delete ui;
}

void Traitement::SetAdr(QString adresse)
{
    adr = adresse;
}

//PARTIE COULEUR

void Traitement::SetImg(QImage image)
{
    img = image;
}

void Traitement::SetImgMat(Mat MatIm)
{
    imgMat = MatIm;
}

void Traitement::SetImgMatTr(Mat MatImTr)
{
    imgMatTr = MatImTr;
}

//PARTIE NdG

void Traitement::SetImgNdG(QImage image)
{
    imgNdG = image;
}

void Traitement::SetImgMatNdG(cv::Mat MatIm)
{
    imgMatNdG = MatIm;
}

void Traitement::SetImgMatTrNdG(cv::Mat MatImTr)
{
    imgMatTrNdG = MatImTr;
}

void Traitement::SetFen(FenTr *fen)
{
    fenetre_traitement = fen;
}

void Traitement::AffImage()
{
    QImage image;
    bool charge = image.load(adr);
    SetImg(image.copy());
    SetImgNdG(image.copy());
    im_fen = image;
    image = image.scaledToWidth(ui->LBLtr->width(),Qt::SmoothTransformation);
    image = image.scaledToHeight(ui->LBLtr->height(),Qt::SmoothTransformation);
    ui->LBLtr->setPixmap(QPixmap::fromImage(image));

    ui->LBLtr->setMinimumSize((int)image.width()/2, (int)image.height()/2);

    if (!charge)
    {
        ui->LBLtr->setText("Pas d'image chargée. \n Merci d'importer une image depuis le menu principal.");
    }

    QSize taille = this->size();
    //int hauteur = taille.height();
    int largeur = taille.width();
    ui->menubar->setMinimumSize(largeur, 22);
}

void Traitement::AffImageBibNDG()
{
    QImage image = img.copy();
    SetImg(image.copy());
    im_fen = image;
    image = image.scaledToWidth(ui->LBLtr->width(),Qt::SmoothTransformation);
    image = image.scaledToHeight(ui->LBLtr->height(),Qt::SmoothTransformation);
    ui->LBLtr->setPixmap(QPixmap::fromImage(image));

    ui->LBLtr->setMinimumSize((int)image.width()/2, (int)image.height()/2);

    adr = "1";
}

void Traitement::on_NDG_clicked()
{
    if(adr != "")
    {
        //
        ui->SWTR->setCurrentIndex(1);
        PAGE = 1;

        Mat img_mat;
        imgNdG = imgNdG.convertToFormat(QImage::Format_RGB888, Qt::ColorOnly).rgbSwapped();
        img_mat = Mat(imgNdG.height(), imgNdG.width(), CV_8UC3, imgNdG.bits(), imgNdG.bytesPerLine()).clone();

        //APPEL DES FONCTIONS PRE-DEFINIS
        //Conversion en NdG
        cvtColor(img_mat, img_mat, COLOR_BGR2GRAY);

        QImage img_out(img_mat.data,img_mat.cols, img_mat.rows,static_cast<int>(img_mat.step),QImage::Format_Grayscale8);

        //Actualisation de l'image convertit
        //
        //Remplissage de la classe traitement avec les variables en NdG
        SetImgNdG(img_out.copy());
        SetImgMatNdG(img_mat.clone());
        ReinitialiserTraitement();

        im_fen = imgNdG.copy();

        //Affichage
        img_out = img_out.scaledToWidth(ui->LBLtr->width(), Qt::SmoothTransformation);
        img_out = img_out.scaledToHeight(ui->LBLtr->height(), Qt::SmoothTransformation);
        ui->LBLtr->setPixmap(QPixmap::fromImage(img_out));
        ui->SLIDORD->setRange(3,15);

        ui->SWTRCLR->setCurrentIndex(0);
        QString text = QString("Affichage fréquentiel");
        ui->AFFICH_FREQ->setText(text);
        ui->H->setEnabled(true);
        ui->FL->setEnabled(true);
        ui->AT->setEnabled(true);
        ui->FMED->setEnabled(true);
        ui->FF->setEnabled(true);
        ui->REN->setEnabled(true);


    }
    else
    {   ui->LBLtr->setStyleSheet(QStringLiteral("QLabel{color: rgb(170, 0, 0);}"));
        ui->LBLtr->setText("Pas d'image chargée ! \n Merci d'importer une image depuis le menu principal.");
    }



}

void Traitement::on_Retour_clicked()
{
    QPointer<UniversImple> w = new UniversImple();
    w->setAttribute(Qt::WA_DeleteOnClose);
    w->SetAdr(adr);
    w->SetIm(img);
    fenetre_traitement->close();
    //this->fenetre_traitement->setAttribute(Qt::WA_DeleteOnClose, true);
    //fenetre_traitement->setAttribute(Qt::WA_DeleteOnClose, true);
    w->show();
    if (adr !="")
    {
        w->AffIm();
    }
}

void Traitement::ReinitialiserTraitement()
{
    imgMatTrNdG = imgMatNdG.clone();
    imgNdGTr = imgNdG.copy();
}

void Traitement::on_FMED_clicked()
{
    Mat img_mat;
    img_mat = imgMatTrNdG.clone();

    //Traitement
    img_mat = med_filter(img_mat, curseur_ordre_med);
    imgMatTrNdG = img_mat.clone();

    //

    //imgMatTrNdG = img_mat; //Set de la matrice image traitée

    QImage img_out(img_mat.data, img_mat.cols, img_mat.rows, static_cast<int>(img_mat.step), QImage::Format_Grayscale8); //Conversion mat->QImage (img_out en sortie)
    imgNdGTr = img_out.copy(); //Set de la QIMAGE traitée
    //imgNdGTrF = img_out;
    im_fen = img_out.copy();;

    //Affichage
    img_out = img_out.scaledToWidth(ui->LBLtr->width(), Qt::SmoothTransformation);
    img_out = img_out.scaledToHeight(ui->LBLtr->height(), Qt::SmoothTransformation);
    ui->LBLtr->setPixmap(QPixmap::fromImage(img_out));



}


void Traitement::on_Annuler_clicked()
{
    QImage img_retour = img.copy();
    im_fen = img_retour;
    img_retour = img_retour.scaledToWidth(ui->LBLtr->width(), Qt::SmoothTransformation);
    img_retour = img_retour.scaledToHeight(ui->LBLtr->height(), Qt::SmoothTransformation);
    ui->LBLtr->setPixmap(QPixmap::fromImage(img_retour));

    ui->SWTR->setCurrentIndex(0);
    ui->SWTRCLR->setCurrentIndex(0);
    passage_freq = 1;

}

void Traitement::on_SLIDORD_sliderMoved(int position)
{
    QString text = QString("");
    if (position%2 !=0)
    {
        text = QString("Taille : %1 x %1").arg(position);
        ui->LBLORD->setText(text);
    }
    else
    {
        position = position + 1;
        ui->SLIDORD->setValue(position);
        text = QString("Taille : %1 x %1").arg(position);
        ui->LBLORD->setText(text);
    }

    curseur_ordre_med = position;
}

//taskkill /IM UniversImple1_3_1.exe /F

void Traitement::on_histogramme_clicked()
{
    QPointer<histogramme> hist = new histogramme(this);
    hist->setAttribute(Qt::WA_DeleteOnClose);
    Mat IM_MAT = imgMatNdG.clone();
    Mat IM_MAT_TR = imgMatTrNdG.clone();
    hist->setWindowFlags(Qt::Window);
    hist->activateWindow();
    hist->hist_pre(IM_MAT,imgNdG);
    hist->hist_post(IM_MAT_TR,imgNdGTr);
    hist->setModal(1);
    hist->show();
}

/*void Traitement::actualiserNDG()
{
    if (adr != "")
        {
            int w = ui->LBLtr->width();
            int h = ui->LBLtr->height();
            QImage img_out_post = im_fen.copy();
            img_out_post = img_out_post.scaledToWidth(ui->LBLtr->width(), Qt::SmoothTransformation);
            img_out_post = img_out_post.scaledToHeight(ui->LBLtr->height(), Qt::SmoothTransformation);

        }
        else
        {
            ui->LBLtr->setText("Pas d'image chargée. \n Merci d'importer une image depuis le menu principal.");
        }
}
*/

void Traitement::on_REN_clicked()
{
    QImage img_retour = imgNdG.copy();
    imgNdGTr = imgNdG.copy();
    imgMatTrNdG = imgMatNdG.clone();
    im_fen = img_retour;
    img_retour = img_retour.scaledToWidth(ui->LBLtr->width(), Qt::SmoothTransformation);
    img_retour = img_retour.scaledToHeight(ui->LBLtr->height(), Qt::SmoothTransformation);
    ui->LBLtr->setPixmap(QPixmap::fromImage(img_retour));

    ui->SWTR->setCurrentIndex(1);
}




void Traitement::on_CLR_clicked()
{
    if (adr == "")
    {
        ui->LBLtr->setStyleSheet(QStringLiteral("QLabel{color: rgb(170, 0, 0);}"));
        ui->LBLtr->setText("Pas d'image chargée ! \n Merci d'importer une image depuis le menu principal.");
    }
    else
    {
        ui->SWTR->setCurrentIndex(3);
        PAGE = 2;
        imgTr = img.copy(); //Setup de l'image traitée

        QImage img_to_mat = imgTr.copy(); //Conversion du format image au format MAT par une variable de passage
        img_to_mat = img_to_mat.convertToFormat(QImage::Format_RGB888, Qt::ColorOnly);
        imgMatTr = Mat(img_to_mat.height(), img_to_mat.width(), CV_8UC3, img_to_mat.bits(), img_to_mat.bytesPerLine()).clone();


        //CONVERSION MAT TR -> QImage TR
        //QImage imgIn= QImage((uchar*) imgMatTr.data, imgMatTr.cols, imgMatTr.rows, imgMatTr.step, QImage::Format_RGB888);
        QImage img_out = imgTr.copy();
        img_out = img_out.scaledToWidth(ui->LBLtr->width(), Qt::SmoothTransformation);
        img_out = img_out.scaledToHeight(ui->LBLtr->height(), Qt::SmoothTransformation);
        ui->LBLtr->setPixmap(QPixmap::fromImage(img_out));
        ui->LBLtr->setMinimumSize((int)img_out.width()/2, (int)img_out.height()/2);
        canaux = 0;
    }

    ui->SLIDORDSEG->setRange(3,15);

}


void Traitement::on_Annuler_2_clicked()
{
    QImage img_retour = img.copy();
    im_fen = img_retour;
    img_retour = img_retour.scaledToWidth(ui->LBLtr->width(), Qt::SmoothTransformation);
    img_retour = img_retour.scaledToHeight(ui->LBLtr->height(), Qt::SmoothTransformation);
    ui->LBLtr->setPixmap(QPixmap::fromImage(img_retour));

    ui->SWTR->setCurrentIndex(0);
    ui->SWTRCLR->setCurrentIndex(0);
    canaux = 0;
    ui->RVB->setText("Visualisation RVB");
}

void Traitement::on_RVB_clicked()
{
    if (canaux == 0)
    {
        ui->SWTRCLR->setCurrentIndex(1);
        ui->RVB->setText("Visualisation image");
        canaux = 1;

        QImage img_clr = imgTr.copy();
        im_fen_RVB = img_clr;
        int w = ui->LBLTRCLR->width();
        int h = ui->LBLTRCLR->height();
        ui->LBLTRCLR->setPixmap(QPixmap::fromImage(img_clr).scaled(w,h,Qt::KeepAspectRatio,Qt::SmoothTransformation));

        //img_clr = img_clr.scaledToWidth(ui->LBLTRCLR->width(), Qt::SmoothTransformation);
        //img_clr = img_clr.scaledToHeight(ui->LBLTRCLR->height(), Qt::SmoothTransformation);
        //ui->LBLTRCLR->setPixmap(QPixmap::fromImage(img_clr));

        //Canal ROUGE

        MatR = visualiser_canal(imgMatTr, 1, 0, 0);
        QImage imgR = QImage((uchar*) MatR.data, MatR.cols, MatR.rows, MatR.step, QImage::Format_BGR888);
        im_fenR = imgR;
        w = ui->R->width();
        h = ui->R->height();
        ui->R->setPixmap(QPixmap::fromImage(imgR).scaled(w,h,Qt::KeepAspectRatio,Qt::SmoothTransformation));


        //imgR = imgR.scaledToWidth(ui->R->width(), Qt::SmoothTransformation);
        //imgR = imgR.scaledToHeight(ui->R->height(), Qt::SmoothTransformation);
        //ui->R->setPixmap(QPixmap::fromImage(imgR));

        //Canal VERT

        MatV = visualiser_canal(imgMatTr, 0, 1, 0);
        QImage imgV = QImage((uchar*) MatV.data, MatV.cols, MatV.rows, MatV.step, QImage::Format_BGR888);
        im_fenV = imgV;
        w = ui->V->width();
        h = ui->V->height();
        ui->V->setPixmap(QPixmap::fromImage(imgV).scaled(w,h,Qt::KeepAspectRatio,Qt::SmoothTransformation));


        //imgV = imgV.scaledToWidth(ui->V->width(), Qt::SmoothTransformation);
        //imgV = imgV.scaledToHeight(ui->V->height(), Qt::SmoothTransformation);
        //ui->V->setPixmap(QPixmap::fromImage(imgV));

        //Canal BLEU

        MatB = visualiser_canal(imgMatTr, 0, 0, 1);
        QImage imgB = QImage((uchar*) MatB.data, MatB.cols, MatB.rows, MatB.step, QImage::Format_BGR888);
        im_fenB = imgB;
        w = ui->B->width();
        h = ui->B->height();
        ui->B->setPixmap(QPixmap::fromImage(imgB).scaled(w,h,Qt::KeepAspectRatio,Qt::SmoothTransformation));


        //imgB = imgB.scaledToWidth(ui->B->width(), Qt::SmoothTransformation);
        //imgB = imgB.scaledToHeight(ui->B->height(), Qt::SmoothTransformation);
        //ui->B->setPixmap(QPixmap::fromImage(imgB));
        //this->resize(this->height(),this->width());

    }
    else
    {
        ui->SWTRCLR->setCurrentIndex(0);
        ui->RVB->setText("Visualisation RVB");
        canaux = 0;
        VisuCanal();
        VisuImage();
    }
}

void Traitement::resizeEvent(QResizeEvent *event)
{
    QDialog::resizeEvent(event);
    if (adr != "")
    {
        int w = ui->LBLtr->width();
        int h = ui->LBLtr->height();
        QImage img_out_post = im_fen.copy();
        ui->LBLtr->setPixmap(QPixmap::fromImage(img_out_post).scaled(w,h,Qt::KeepAspectRatio,Qt::SmoothTransformation));

        w = ui->R->width();
        h = ui->R->height();
        img_out_post = im_fenR.copy();
        ui->R->setPixmap(QPixmap::fromImage(img_out_post).scaled(w,h,Qt::KeepAspectRatio,Qt::SmoothTransformation));

        w = ui->V->width();
        h = ui->V->height();
        img_out_post = im_fenV.copy();
        ui->V->setPixmap(QPixmap::fromImage(img_out_post).scaled(w,h,Qt::KeepAspectRatio,Qt::SmoothTransformation));

        w = ui->B->width();
        h = ui->B->height();
        img_out_post = im_fenB.copy();
        ui->B->setPixmap(QPixmap::fromImage(img_out_post).scaled(w,h,Qt::KeepAspectRatio,Qt::SmoothTransformation));

        w = ui->LBLTRCLR->width();
        h = ui->LBLTRCLR->height();
        img_out_post = im_fen_RVB.copy();
        ui->LBLTRCLR->setPixmap(QPixmap::fromImage(img_out_post).scaled(w,h,Qt::KeepAspectRatio,Qt::SmoothTransformation));

        w = ui->LBLFREQ->width();
        h = ui->LBLFREQ->height();
        img_out_post = im_fen_freq.copy();
        ui->LBLFREQ->setPixmap(QPixmap::fromImage(img_out_post).scaled(w,h,Qt::KeepAspectRatio,Qt::SmoothTransformation));


        //Délais pour laisser le temps que l'image soit resize. Puis, on appelle la fonction d'actualisation
        if (timerId){
            killTimer(timerId);
            timerId = 0;
        }
        timerId = startTimer(1);
    }
    else
    {
        ui->LBLtr->setText("Pas d'image chargée. \n Merci d'importer une image depuis le menu principal.");
    }
    QSize taille = this->size();
    //int hauteur = taille.height();
    int largeur = taille.width();
    ui->menubar->setMinimumSize(largeur, 22);
}


void Traitement::timerEvent(QTimerEvent *te){
    //actualiserNDG();
    killTimer(te->timerId());
    timerId = 0;
}


void Traitement::on_SEGCLR_clicked()
{
    imgCLRAnnuler = imgTr.copy();
    imgMatCLRAnnuler = imgMatTr.clone();

    imgTrSEG = imgTr.copy();
    imgMatTrSEG = imgMatTr.clone();

    ui->SWTR->setCurrentIndex(4);
    //Set des positions
    PRS1 = 0;
    PRS2 = 255;
    ui->RS1->setValue(PRS1);
    ui->RS2->setValue(PRS2);

    PVS1 = 0;
    PVS2 = 255;
    ui->VS1->setValue(PVS1);
    ui->VS2->setValue(PVS2);

    PBS1 = 0;
    PBS2 = 255;
    ui->BS1->setValue(PBS1);
    ui->BS2->setValue(PBS2);

}


void Traitement::on_AnnulerSEGCLR_clicked()
{
    ui->SWTR->setCurrentIndex(3);
    imgTr = imgCLRAnnuler.copy();
    imgMatTr = imgMatCLRAnnuler.clone();
    VisuCanal();
    VisuImage();
}


void Traitement::on_BS1_sliderMoved(int position)
{
    imgTr = imgTrSEG.copy();
    imgMatTr = imgMatTrSEG.clone();
    if (position >= ui->BS2->value())
    {
        ui->BS2->setValue(position);
        ui->BS1->setValue(position);
    }
    else
    {
        ui->BS1->setValue(position);
    }
    Mat mat_seuil = seuillage_canal(imgMatTr,ui->RS1->value(),ui->RS2->value(),ui->VS1->value(),ui->VS2->value(),ui->BS1->value(),ui->BS2->value());
    QImage img_out = QImage((uchar*) mat_seuil.data, mat_seuil.cols, mat_seuil.rows, mat_seuil.step, QImage::Format_RGB888);

    imgTr = img_out.copy();
    imgMatTr = mat_seuil.clone();
    VisuImage();
    VisuCanal();
}



void Traitement::on_BS2_sliderMoved(int position)
{
    imgTr = imgTrSEG.copy();
    imgMatTr = imgMatTrSEG.clone();
    if (position <= ui->BS1->value())
    {
        ui->BS2->setValue(position);
        ui->BS1->setValue(position);
    }
    else
    {
        ui->BS2->setValue(position);
    }
    Mat mat_seuil = seuillage_canal(imgMatTr,ui->RS1->value(),ui->RS2->value(),ui->VS1->value(),ui->VS2->value(),ui->BS1->value(),ui->BS2->value());
    QImage img_out = QImage((uchar*) mat_seuil.data, mat_seuil.cols, mat_seuil.rows, mat_seuil.step, QImage::Format_RGB888);

    imgTr = img_out.copy();
    imgMatTr = mat_seuil.clone();
    VisuImage();
    VisuCanal();
}


void Traitement::on_VS1_sliderMoved(int position)
{
    imgTr = imgTrSEG.copy();
    imgMatTr = imgMatTrSEG.clone();
    if (position >= ui->VS2->value())
    {
        ui->VS2->setValue(position);
        ui->VS1->setValue(position);
    }
    else
    {
        ui->VS1->setValue(position);
    }
    Mat mat_seuil = seuillage_canal(imgMatTr,ui->RS1->value(),ui->RS2->value(),ui->VS1->value(),ui->VS2->value(),ui->BS1->value(),ui->BS2->value());
    QImage img_out = QImage((uchar*) mat_seuil.data, mat_seuil.cols, mat_seuil.rows, mat_seuil.step, QImage::Format_RGB888);

    imgTr = img_out.copy();
    imgMatTr = mat_seuil.clone();
    VisuImage();
    VisuCanal();
}


void Traitement::on_VS2_sliderMoved(int position)
{
    imgTr = imgTrSEG.copy();
    imgMatTr = imgMatTrSEG.clone();
    if (position <= ui->VS1->value())
    {
        ui->VS2->setValue(position);
        ui->VS1->setValue(position);
    }
    else
    {
        ui->VS2->setValue(position);
    }
    Mat mat_seuil = seuillage_canal(imgMatTr,ui->RS1->value(),ui->RS2->value(),ui->VS1->value(),ui->VS2->value(),ui->BS1->value(),ui->BS2->value());
    QImage img_out = QImage((uchar*) mat_seuil.data, mat_seuil.cols, mat_seuil.rows, mat_seuil.step, QImage::Format_RGB888);

    imgTr = img_out.copy();
    imgMatTr = mat_seuil.clone();
    VisuImage();
    VisuCanal();
}

void Traitement::on_RS2_sliderMoved(int position)
{
    imgTr = imgTrSEG.copy();
    imgMatTr = imgMatTrSEG.clone();
    if (position <= ui->RS1->value())
    {
        ui->RS2->setValue(position);
        ui->RS1->setValue(position);
    }
    else
    {
        ui->RS2->setValue(position);
    }
    Mat mat_seuil = seuillage_canal(imgMatTr,ui->RS1->value(),ui->RS2->value(),ui->VS1->value(),ui->VS2->value(),ui->BS1->value(),ui->BS2->value());
    QImage img_out = QImage((uchar*) mat_seuil.data, mat_seuil.cols, mat_seuil.rows, mat_seuil.step, QImage::Format_RGB888);

    imgTr = img_out.copy();
    imgMatTr = mat_seuil.clone();
    VisuImage();
    VisuCanal();
}


void Traitement::on_RS1_sliderMoved(int position)
{
    imgTr = imgTrSEG.copy();
    imgMatTr = imgMatTrSEG.clone();

    if (position >= ui->RS2->value())
    {
        ui->RS2->setValue(position);
        ui->RS1->setValue(position);
    }
    else
    {
        ui->RS1->setValue(position);
    }

    Mat mat_seuil = seuillage_canal(imgMatTr,ui->RS1->value(),ui->RS2->value(),ui->VS1->value(),ui->VS2->value(),ui->BS1->value(),ui->BS2->value());
    QImage img_out = QImage((uchar*) mat_seuil.data, mat_seuil.cols, mat_seuil.rows, mat_seuil.step, QImage::Format_RGB888);

    imgTr = img_out.copy();
    imgMatTr = mat_seuil.clone();
    VisuImage();
    VisuCanal();


}

void Traitement::VisuImage()
{
    int w = ui->LBLtr->width();
    int h = ui->LBLtr->height();
    QImage img_clr = imgTr.copy();
    im_fen = img_clr;
    ui->LBLtr->setPixmap(QPixmap::fromImage(img_clr).scaled(w,h,Qt::KeepAspectRatio,Qt::SmoothTransformation));
}

void Traitement ::VisuCanal()
{
    int w = ui->LBLTRCLR->width();
    int h = ui->LBLTRCLR->height();
    QImage img_clr = imgTr.copy();
    im_fen_RVB = img_clr;
    ui->LBLTRCLR->setPixmap(QPixmap::fromImage(img_clr).scaled(w,h,Qt::KeepAspectRatio,Qt::SmoothTransformation));

    //Canal ROUGE

    w = ui->R->width();
    h = ui->R->height();
    MatR = visualiser_canal(imgMatTr, 1, 0, 0);
    QImage imgR = QImage((uchar*) MatR.data, MatR.cols, MatR.rows, MatR.step, QImage::Format_BGR888);
    im_fenR = imgR;
    ui->R->setPixmap(QPixmap::fromImage(imgR).scaled(w,h,Qt::KeepAspectRatio,Qt::SmoothTransformation));

    //Canal VERT

    w = ui->V->width();
    h = ui->V->height();
    MatV = visualiser_canal(imgMatTr, 0, 1, 0);
    QImage imgV = QImage((uchar*) MatV.data, MatV.cols, MatV.rows, MatV.step, QImage::Format_BGR888);
    im_fenV = imgV;
    ui->V->setPixmap(QPixmap::fromImage(imgV).scaled(w,h,Qt::KeepAspectRatio,Qt::SmoothTransformation));

    //Canal BLEU

    w = ui->B->width();
    h = ui->B->height();
    MatB = visualiser_canal(imgMatTr, 0, 0, 1);
    QImage imgB = QImage((uchar*) MatB.data, MatB.cols, MatB.rows, MatB.step, QImage::Format_BGR888);
    im_fenB = imgB;
    ui->B->setPixmap(QPixmap::fromImage(imgB).scaled(w,h,Qt::KeepAspectRatio,Qt::SmoothTransformation));
}


void Traitement::on_VALIDERSEG_clicked()
{
    QImage img_retour = imgTr.copy();
    VisuImage();
    VisuCanal();
    ui->SWTR->setCurrentIndex(3);
}

void Traitement::on_SLIDORDSEG_sliderMoved(int position)
{
    QString text = QString("");
    if (position%2 !=0)
    {
        text = QString("Taille : %1 x %1").arg(position);
        ui->LBLORDSEG->setText(text);
    }
    else
    {
        position = position + 1;
        ui->SLIDORDSEG->setValue(position);
        text = QString("Taille : %1 x %1").arg(position);
        ui->LBLORDSEG->setText(text);
    }

    curseur_ordre_med = position;
}


void Traitement::on_MED_MARG_clicked()
{
    Mat img_mat = imgMatTr.clone();
    vector<Mat> channels;
    Mat MedMatCLR;
    Mat MR;
    Mat MV;
    Mat MB;

    extractChannel(img_mat, MB, 0);
    extractChannel(img_mat, MV, 1);
    extractChannel(img_mat, MR, 2);

    MB = med_filter(MB, curseur_ordre_med);
    MV = med_filter(MV, curseur_ordre_med);
    MR = med_filter(MR, curseur_ordre_med);

    channels.push_back(MB);
    channels.push_back(MV);
    channels.push_back(MR);

    merge(channels, MedMatCLR);

    imgMatTr = MedMatCLR.clone();
    QImage img_out = QImage((uchar*) MedMatCLR.data, MedMatCLR.cols, MedMatCLR.rows, MedMatCLR.step, QImage::Format_RGB888);
    imgTr = img_out.copy();

    VisuCanal();
    VisuImage();
}

// Page Filtrage NdG

void Traitement::on_FL_clicked()
{
    imgNdGAnnuler = imgNdGTr.copy();
    imgMatNdGAnnuler = imgMatTrNdG.clone();
    ui->SWTR->setCurrentIndex(2);
}


void Traitement::on_AnnulerFL_clicked()
{
    QImage img_retour = imgNdGAnnuler.copy();
    imgNdGTr = imgNdGAnnuler.copy();
    imgMatTrNdG = imgMatNdGAnnuler.clone();
    img_retour = img_retour.scaledToWidth(ui->LBLtr->width(), Qt::SmoothTransformation);
    img_retour = img_retour.scaledToHeight(ui->LBLtr->height(), Qt::SmoothTransformation);
    ui->LBLtr->setPixmap(QPixmap::fromImage(img_retour));
    im_fen = img_retour;
    ui->SWTR->setCurrentIndex(1);

}


void Traitement::on_FG_clicked()
{
    Mat img_mat;
    img_mat = imgMatTrNdG.clone();

    //Traitement
    img_mat = filtrage(img_mat, "gaussien1");

    //

    imgMatTrNdG =  img_mat.clone(); //Set de la matrice image traitée
    //imgNdGMatTrF = img_mat.clone(); //Set de la matrice image traitée

    QImage img_out(img_mat.data, img_mat.cols, img_mat.rows, static_cast<int>(img_mat.step), QImage::Format_Grayscale8); //Conversion mat->QImage (img_out en sortie)
    // imgNdGTr = img_out; //Set de la QIMAGE traitée
    imgNdGTr = img_out.copy();
    im_fen = img_out.copy();;

    //Affichage
    img_out = img_out.scaledToWidth(ui->LBLtr->width(), Qt::SmoothTransformation);
    img_out = img_out.scaledToHeight(ui->LBLtr->height(), Qt::SmoothTransformation);
    ui->LBLtr->setPixmap(QPixmap::fromImage(img_out));


}


void Traitement::on_valider_clicked()
{
    QImage img_retour = imgNdGTr.copy();
    img_retour = img_retour.scaledToWidth(ui->LBLtr->width(), Qt::SmoothTransformation);
    img_retour = img_retour.scaledToHeight(ui->LBLtr->height(), Qt::SmoothTransformation);
    ui->LBLtr->setPixmap(QPixmap::fromImage(img_retour));
    im_fen = img_retour;
    ui->SWTR->setCurrentIndex(1);

}
void Traitement::on_FM_clicked()
{

    Mat img_mat;
    img_mat = imgMatTrNdG.clone();

    //Traitement
    img_mat = filtrage(img_mat, "moyenneur");

    //

    imgMatTrNdG =  img_mat.clone(); //Set de la matrice image traitée
    //imgNdGMatTrF = img_mat.clone(); //Set de la matrice image traitée

    QImage img_out(img_mat.data, img_mat.cols, img_mat.rows, static_cast<int>(img_mat.step), QImage::Format_Grayscale8); //Conversion mat->QImage (img_out en sortie)
    // imgNdGTr = img_out; //Set de la QIMAGE traitée
    imgNdGTr = img_out.copy();
    im_fen = img_out.copy();

    //Affichage
    img_out = img_out.scaledToWidth(ui->LBLtr->width(), Qt::SmoothTransformation);
    img_out = img_out.scaledToHeight(ui->LBLtr->height(), Qt::SmoothTransformation);
    ui->LBLtr->setPixmap(QPixmap::fromImage(img_out));
}


void Traitement::on_FL4_clicked()
{
    Mat img_mat;
    img_mat = imgMatTrNdG.clone();

    //Traitement
    img_mat = filtrage(img_mat, "laplacien4");

    //

    imgMatTrNdG =  img_mat.clone(); //Set de la matrice image traitée
    //imgNdGMatTrF = img_mat.clone(); //Set de la matrice image traitée

    QImage img_out(img_mat.data, img_mat.cols, img_mat.rows, static_cast<int>(img_mat.step), QImage::Format_Grayscale8); //Conversion mat->QImage (img_out en sortie)
    // imgNdGTr = img_out; //Set de la QIMAGE traitée
    imgNdGTr = img_out.copy();
    im_fen = img_out;

    //Affichage
    img_out = img_out.scaledToWidth(ui->LBLtr->width(), Qt::SmoothTransformation);
    img_out = img_out.scaledToHeight(ui->LBLtr->height(), Qt::SmoothTransformation);
    ui->LBLtr->setPixmap(QPixmap::fromImage(img_out));
}



void Traitement::on_FL8_clicked()
{
    if (quatre_connexites == 1 && huit_connexites == 0)
    {
        Mat img_mat;
        img_mat = imgMatTrNdG.clone();

        //Traitement
        img_mat = filtrage(img_mat, "laplacien4");

        //

        imgMatTrNdG =  img_mat.clone(); //Set de la matrice image traitée
        //imgNdGMatTrF = img_mat.clone(); //Set de la matrice image traitée

        QImage img_out(img_mat.data, img_mat.cols, img_mat.rows, static_cast<int>(img_mat.step), QImage::Format_Grayscale8); //Conversion mat->QImage (img_out en sortie)
        // imgNdGTr = img_out; //Set de la QIMAGE traitée
        imgNdGTr = img_out.copy();
        im_fen = img_out.copy();;

        //Affichage
        img_out = img_out.scaledToWidth(ui->LBLtr->width(), Qt::SmoothTransformation);
        img_out = img_out.scaledToHeight(ui->LBLtr->height(), Qt::SmoothTransformation);
        ui->LBLtr->setPixmap(QPixmap::fromImage(img_out));
    }
    else if (huit_connexites == 1 && quatre_connexites == 0)
    {
        Mat img_mat;
        img_mat = imgMatTrNdG.clone();

        //Traitement
        img_mat = filtrage(img_mat, "laplacien8");

        //

        imgMatTrNdG =  img_mat.clone(); //Set de la matrice image traitée
        //imgNdGMatTrF = img_mat.clone(); //Set de la matrice image traitée

        QImage img_out(img_mat.data, img_mat.cols, img_mat.rows, static_cast<int>(img_mat.step), QImage::Format_Grayscale8); //Conversion mat->QImage (img_out en sortie)
        // imgNdGTr = img_out; //Set de la QIMAGE traitée
        imgNdGTr = img_out.copy();
        im_fen = img_out.copy();;

        //Affichage
        img_out = img_out.scaledToWidth(ui->LBLtr->width(), Qt::SmoothTransformation);
        img_out = img_out.scaledToHeight(ui->LBLtr->height(), Qt::SmoothTransformation);
        ui->LBLtr->setPixmap(QPixmap::fromImage(img_out));
    }

}



void Traitement::on_FPX_clicked()
{
    Mat img_mat;
    img_mat = imgMatTrNdG.clone();

    //Traitement
    img_mat = filtrage(img_mat, "prewittX");

    //

    imgMatTrNdG =  img_mat.clone(); //Set de la matrice image traitée
    //imgNdGMatTrF = img_mat.clone(); //Set de la matrice image traitée

    QImage img_out(img_mat.data, img_mat.cols, img_mat.rows, static_cast<int>(img_mat.step), QImage::Format_Grayscale8); //Conversion mat->QImage (img_out en sortie)
    // imgNdGTr = img_out; //Set de la QIMAGE traitée
    imgNdGTr = img_out.copy();
    im_fen = img_out.copy();;

    //Affichage
    img_out = img_out.scaledToWidth(ui->LBLtr->width(), Qt::SmoothTransformation);
    img_out = img_out.scaledToHeight(ui->LBLtr->height(), Qt::SmoothTransformation);
    ui->LBLtr->setPixmap(QPixmap::fromImage(img_out));
}


void Traitement::on_FPY_clicked()
{
    if (horiz_prew == 1 && vertic_prew == 0)
    {
        Mat img_mat;
        img_mat = imgMatTrNdG.clone();

        //Traitement
        img_mat = filtrage(img_mat, "prewittX");

        //

        imgMatTrNdG =  img_mat.clone(); //Set de la matrice image traitée
        //imgNdGMatTrF = img_mat.clone(); //Set de la matrice image traitée

        QImage img_out(img_mat.data, img_mat.cols, img_mat.rows, static_cast<int>(img_mat.step), QImage::Format_Grayscale8); //Conversion mat->QImage (img_out en sortie)
        // imgNdGTr = img_out; //Set de la QIMAGE traitée
        imgNdGTr = img_out.copy();
        im_fen = img_out.copy();;

        //Affichage
        img_out = img_out.scaledToWidth(ui->LBLtr->width(), Qt::SmoothTransformation);
        img_out = img_out.scaledToHeight(ui->LBLtr->height(), Qt::SmoothTransformation);
        ui->LBLtr->setPixmap(QPixmap::fromImage(img_out));
    }
    else if (vertic_prew == 1 && horiz_prew == 0)
    {
        Mat img_mat;
        img_mat = imgMatTrNdG.clone();

        //Traitement
        img_mat = filtrage(img_mat, "prewittY");

        //

        imgMatTrNdG =  img_mat.clone(); //Set de la matrice image traitée
        //imgNdGMatTrF = img_mat.clone(); //Set de la matrice image traitée

        QImage img_out(img_mat.data, img_mat.cols, img_mat.rows, static_cast<int>(img_mat.step), QImage::Format_Grayscale8); //Conversion mat->QImage (img_out en sortie)
        // imgNdGTr = img_out; //Set de la QIMAGE traitée
        imgNdGTr = img_out.copy();
        im_fen = img_out.copy();;

        //Affichage
        img_out = img_out.scaledToWidth(ui->LBLtr->width(), Qt::SmoothTransformation);
        img_out = img_out.scaledToHeight(ui->LBLtr->height(), Qt::SmoothTransformation);
        ui->LBLtr->setPixmap(QPixmap::fromImage(img_out));
    }
}



void Traitement::on_FSX_clicked()
{
    Mat img_mat;
    img_mat = imgMatTrNdG.clone();

    //Traitement
    img_mat = filtrage(img_mat, "sobelX");

    //

    imgMatTrNdG =  img_mat.clone(); //Set de la matrice image traitée
    //imgNdGMatTrF = img_mat.clone(); //Set de la matrice image traitée

    QImage img_out(img_mat.data, img_mat.cols, img_mat.rows, static_cast<int>(img_mat.step), QImage::Format_Grayscale8); //Conversion mat->QImage (img_out en sortie)
    // imgNdGTr = img_out; //Set de la QIMAGE traitée
    imgNdGTr = img_out.copy();
    im_fen = img_out.copy();;

    //Affichage
    img_out = img_out.scaledToWidth(ui->LBLtr->width(), Qt::SmoothTransformation);
    img_out = img_out.scaledToHeight(ui->LBLtr->height(), Qt::SmoothTransformation);
    ui->LBLtr->setPixmap(QPixmap::fromImage(img_out));

}




void Traitement::on_FSY_clicked()
{
    if (vertic_sob == 1 && horiz_sob == 0)
    {
        Mat img_mat;
        img_mat = imgMatTrNdG.clone();

        //Traitement
        img_mat = filtrage(img_mat, "sobelY");

        //

        imgMatTrNdG =  img_mat.clone(); //Set de la matrice image traitée
        //imgNdGMatTrF = img_mat.clone(); //Set de la matrice image traitée

        QImage img_out(img_mat.data, img_mat.cols, img_mat.rows, static_cast<int>(img_mat.step), QImage::Format_Grayscale8); //Conversion mat->QImage (img_out en sortie)
        // imgNdGTr = img_out; //Set de la QIMAGE traitée
        imgNdGTr = img_out.copy();
        im_fen = img_out.copy();;

        //Affichage
        img_out = img_out.scaledToWidth(ui->LBLtr->width(), Qt::SmoothTransformation);
        img_out = img_out.scaledToHeight(ui->LBLtr->height(), Qt::SmoothTransformation);
        ui->LBLtr->setPixmap(QPixmap::fromImage(img_out));
    }
    else if (vertic_sob == 0 && horiz_sob == 1)
    {
        Mat img_mat;
        img_mat = imgMatTrNdG.clone();

        //Traitement
        img_mat = filtrage(img_mat, "sobelX");

        //

        imgMatTrNdG =  img_mat.clone(); //Set de la matrice image traitée
        //imgNdGMatTrF = img_mat.clone(); //Set de la matrice image traitée

        QImage img_out(img_mat.data, img_mat.cols, img_mat.rows, static_cast<int>(img_mat.step), QImage::Format_Grayscale8); //Conversion mat->QImage (img_out en sortie)
        // imgNdGTr = img_out; //Set de la QIMAGE traitée
        imgNdGTr = img_out.copy();
        im_fen = img_out.copy();;

        //Affichage
        img_out = img_out.scaledToWidth(ui->LBLtr->width(), Qt::SmoothTransformation);
        img_out = img_out.scaledToHeight(ui->LBLtr->height(), Qt::SmoothTransformation);
        ui->LBLtr->setPixmap(QPixmap::fromImage(img_out));
    }
}


// Manipulation Histogrammes

void Traitement::on_H_clicked()
{
    imgNdGAnnuler = imgNdGTr.copy();
    imgMatNdGAnnuler = imgMatTrNdG.clone();
    ui->SWTR->setCurrentIndex(5);
}


void Traitement::on_normal_clicked()
{
    Mat img_mat;
    img_mat = imgMatTrNdG.clone();

    //Traitement
    img_mat = im_norm(img_mat, 255, 0);

    //

    imgMatTrNdG =  img_mat.clone(); //Set de la matrice image traitée
    //imgNdGMatTrF = img_mat.clone(); //Set de la matrice image traitée

    QImage img_out(img_mat.data, img_mat.cols, img_mat.rows, static_cast<int>(img_mat.step), QImage::Format_Grayscale8); //Conversion mat->QImage (img_out en sortie)
    // imgNdGTr = img_out; //Set de la QIMAGE traitée
    imgNdGTr = img_out.copy();
    im_fen = img_out.copy();;

    //Affichage
    img_out = img_out.scaledToWidth(ui->LBLtr->width(), Qt::SmoothTransformation);
    img_out = img_out.scaledToHeight(ui->LBLtr->height(), Qt::SmoothTransformation);
    ui->LBLtr->setPixmap(QPixmap::fromImage(img_out));


}


void Traitement::on_egal_clicked()
{
    Mat img_mat;
    img_mat = imgMatTrNdG.clone();

    //Traitement
    img_mat = im_egal(img_mat, 0, 255);

    //

    imgMatTrNdG =  img_mat.clone(); //Set de la matrice image traitée
    //imgNdGMatTrF = img_mat.clone(); //Set de la matrice image traitée

    QImage img_out(img_mat.data, img_mat.cols, img_mat.rows, static_cast<int>(img_mat.step), QImage::Format_Grayscale8); //Conversion mat->QImage (img_out en sortie)
    // imgNdGTr = img_out; //Set de la QIMAGE traitée
    imgNdGTr = img_out.copy();
    im_fen = img_out.copy();;

    //Affichage
    img_out = img_out.scaledToWidth(ui->LBLtr->width(), Qt::SmoothTransformation);
    img_out = img_out.scaledToHeight(ui->LBLtr->height(), Qt::SmoothTransformation);
    ui->LBLtr->setPixmap(QPixmap::fromImage(img_out));


}



void Traitement::on_Annuler_H_clicked()
{
    QImage img_retour = imgNdGAnnuler.copy();
    imgNdGTr = imgNdGAnnuler.copy();
    imgMatTrNdG = imgMatNdGAnnuler.clone();
    img_retour = img_retour.scaledToWidth(ui->LBLtr->width(), Qt::SmoothTransformation);
    img_retour = img_retour.scaledToHeight(ui->LBLtr->height(), Qt::SmoothTransformation);
    ui->LBLtr->setPixmap(QPixmap::fromImage(img_retour));
    im_fen = img_retour;
    ui->SWTR->setCurrentIndex(1);
}



void Traitement::on_ValiderH_clicked()
{
    QImage img_retour = imgNdGTr.copy();
    img_retour = img_retour.scaledToWidth(ui->LBLtr->width(), Qt::SmoothTransformation);
    img_retour = img_retour.scaledToHeight(ui->LBLtr->height(), Qt::SmoothTransformation);
    ui->LBLtr->setPixmap(QPixmap::fromImage(img_retour));
    im_fen = img_retour;
    ui->SWTR->setCurrentIndex(1);

}




void Traitement::on_His_clicked()
{
    QPointer<histogramme> hist = new histogramme();
    hist->setAttribute(Qt::WA_DeleteOnClose);
    Mat IM_MAT = imgMatNdG.clone();
    Mat IM_MAT_TR = imgMatTrNdG.clone();
    hist->setWindowFlags(Qt::Window);
    hist->activateWindow();
    hist->hist_pre(IM_MAT,imgNdG);
    hist->hist_post(IM_MAT_TR,imgNdGTr);
    hist->setModal(1);
    hist->show();
}

// Algo traitements d'images

void Traitement::on_AT_clicked()
{
    imgNdGAnnuler = imgNdGTr.copy();
    imgMatNdGAnnuler = imgMatTrNdG.clone();
    ui->SWTR->setCurrentIndex(6);

    ui->SLIDKM->setRange(2,20); //intervalle du nombre de classes
    ui->SLIDVAR->setRange(0,100);
    ui->SLIDSEUIL->setRange(0,255); //seuil possible pour la binarisation
    ui->BI_CURS->setRange(0,100);

    ui->SLIDKM->setValue(2); //intervalle du nombre de classes
    ui->SLIDVAR->setValue(0);
    ui->SLIDSEUIL->setValue(0); //seuil possible pour la binarisation
    ui->BI_CURS->setValue(0);

    QString text;
    text = QString("Binarisation : Valeur du seuil : 1");
    ui->SEUILB->setText(text);
    text = QString("Nombre de classes : 2");
    ui->CLAS->setText(text);
    text = QString("Bruit Blanc Additif : Variance : 0");
    ui->VAR->setText(text);
    text = QString("Bruit impulsionnel : 0 %");
    ui->lblPS->setText(text);

}


void Traitement::on_ANLAT_clicked()
{
    QImage img_retour = imgNdGAnnuler.copy();
    imgNdGTr = imgNdGAnnuler.copy();
    imgMatTrNdG = imgMatNdGAnnuler.clone();
    img_retour = img_retour.scaledToWidth(ui->LBLtr->width(), Qt::SmoothTransformation);
    img_retour = img_retour.scaledToHeight(ui->LBLtr->height(), Qt::SmoothTransformation);
    ui->LBLtr->setPixmap(QPixmap::fromImage(img_retour));
    im_fen = img_retour;
    ui->SWTR->setCurrentIndex(1);

}


void Traitement::on_VALIDAT_clicked()
{
    QImage img_retour = imgNdGTr.copy();
    img_retour = img_retour.scaledToWidth(ui->LBLtr->width(), Qt::SmoothTransformation);
    img_retour = img_retour.scaledToHeight(ui->LBLtr->height(), Qt::SmoothTransformation);
    ui->LBLtr->setPixmap(QPixmap::fromImage(img_retour));
    im_fen = img_retour;
    ui->SWTR->setCurrentIndex(1);

}



void Traitement::on_NEG_clicked()
{

    Mat img_mat;
    img_mat = imgMatTrNdG.clone();

    //Traitement
    img_mat = neg(img_mat);

    //

    imgMatTrNdG =  img_mat.clone(); //Set de la matrice image traitée
    //imgNdGMatTrF = img_mat.clone(); //Set de la matrice image traitée

    QImage img_out(img_mat.data, img_mat.cols, img_mat.rows, static_cast<int>(img_mat.step), QImage::Format_Grayscale8); //Conversion mat->QImage (img_out en sortie)
    // imgNdGTr = img_out; //Set de la QIMAGE traitée
    imgNdGTr = img_out.copy();
    im_fen = img_out.copy();;

    //Affichage
    img_out = img_out.scaledToWidth(ui->LBLtr->width(), Qt::SmoothTransformation);
    img_out = img_out.scaledToHeight(ui->LBLtr->height(), Qt::SmoothTransformation);
    ui->LBLtr->setPixmap(QPixmap::fromImage(img_out));


}


void Traitement::on_DOG_clicked()
{
    Mat img_mat;
    img_mat = imgMatTrNdG.clone();

    //Traitement
    img_mat = DiffGaus(img_mat);

    //

    imgMatTrNdG =  img_mat.clone(); //Set de la matrice image traitée
    //imgNdGMatTrF = img_mat.clone(); //Set de la matrice image traitée

    QImage img_out(img_mat.data, img_mat.cols, img_mat.rows, static_cast<int>(img_mat.step), QImage::Format_Grayscale8); //Conversion mat->QImage (img_out en sortie)
    // imgNdGTr = img_out; //Set de la QIMAGE traitée
    imgNdGTr = img_out.copy();
    im_fen = img_out.copy();;

    //Affichage
    img_out = img_out.scaledToWidth(ui->LBLtr->width(), Qt::SmoothTransformation);
    img_out = img_out.scaledToHeight(ui->LBLtr->height(), Qt::SmoothTransformation);
    ui->LBLtr->setPixmap(QPixmap::fromImage(img_out));

}



void Traitement::on_RC_clicked()
{
    Mat img_mat;
    img_mat = imgMatTrNdG.clone();

    //Traitement
    img_mat = rehau(img_mat);

    //

    imgMatTrNdG =  img_mat.clone(); //Set de la matrice image traitée
    //imgNdGMatTrF = img_mat.clone(); //Set de la matrice image traitée

    QImage img_out(img_mat.data, img_mat.cols, img_mat.rows, static_cast<int>(img_mat.step), QImage::Format_Grayscale8); //Conversion mat->QImage (img_out en sortie)
    // imgNdGTr = img_out; //Set de la QIMAGE traitée
    imgNdGTr = img_out.copy();
    im_fen = img_out.copy();;

    //Affichage
    img_out = img_out.scaledToWidth(ui->LBLtr->width(), Qt::SmoothTransformation);
    img_out = img_out.scaledToHeight(ui->LBLtr->height(), Qt::SmoothTransformation);
    ui->LBLtr->setPixmap(QPixmap::fromImage(img_out));

}



void Traitement::on_BIN_clicked()
{
    Mat img_mat;
    img_mat = imgMatTrNdG.clone();

    //Traitement
    img_mat = binarisation(img_mat, curseur_seuil);
    imgMatTrNdG = img_mat.clone();

    //

    //imgMatTrNdG = img_mat; //Set de la matrice image traitée

    QImage img_out(img_mat.data, img_mat.cols, img_mat.rows, static_cast<int>(img_mat.step), QImage::Format_Grayscale8); //Conversion mat->QImage (img_out en sortie)
    imgNdGTr = img_out.copy(); //Set de la QIMAGE traitée
    //imgNdGTrF = img_out;
    im_fen = img_out.copy();;

    //Affichage
    img_out = img_out.scaledToWidth(ui->LBLtr->width(), Qt::SmoothTransformation);
    img_out = img_out.scaledToHeight(ui->LBLtr->height(), Qt::SmoothTransformation);
    ui->LBLtr->setPixmap(QPixmap::fromImage(img_out));



}


void Traitement::on_KM_clicked()
{
    Mat img_mat;
    img_mat = imgMatTrNdG.clone();

    //Traitement
    img_mat = km(img_mat, curseur_classes);
    imgMatTrNdG = img_mat.clone();

    //

    //imgMatTrNdG = img_mat; //Set de la matrice image traitée

    QImage img_out(img_mat.data, img_mat.cols, img_mat.rows, static_cast<int>(img_mat.step), QImage::Format_Grayscale8); //Conversion mat->QImage (img_out en sortie)
    imgNdGTr = img_out.copy(); //Set de la QIMAGE traitée
    //imgNdGTrF = img_out;
    im_fen = img_out.copy();;

    //Affichage
    img_out = img_out.scaledToWidth(ui->LBLtr->width(), Qt::SmoothTransformation);
    img_out = img_out.scaledToHeight(ui->LBLtr->height(), Qt::SmoothTransformation);
    ui->LBLtr->setPixmap(QPixmap::fromImage(img_out));

}



void Traitement::on_BB_clicked()
{
    Mat img_mat;
    img_mat = imgMatTrNdG.clone();

    //Traitement
    img_mat = bruit_blanc(img_mat, curseur_variance);
    imgMatTrNdG = img_mat.clone();

    //

    //imgMatTrNdG = img_mat; //Set de la matrice image traitée

    QImage img_out(img_mat.data, img_mat.cols, img_mat.rows, static_cast<int>(img_mat.step), QImage::Format_Grayscale8); //Conversion mat->QImage (img_out en sortie)
    imgNdGTr = img_out.copy(); //Set de la QIMAGE traitée
    //imgNdGTrF = img_out;
    im_fen = img_out.copy();;

    //Affichage
    img_out = img_out.scaledToWidth(ui->LBLtr->width(), Qt::SmoothTransformation);
    img_out = img_out.scaledToHeight(ui->LBLtr->height(), Qt::SmoothTransformation);
    ui->LBLtr->setPixmap(QPixmap::fromImage(img_out));

}




/*void Traitement::on_BI_clicked()
{
    Mat img_mat;
    img_mat = imgMatTrNdG.clone();

    //Traitement
    img_mat = bruit_ps(img_mat,curseur_poivre/10);

    //

    imgMatTrNdG =  img_mat.clone(); //Set de la matrice image traitée
    //imgNdGMatTrF = img_mat.clone(); //Set de la matrice image traitée

    QImage img_out(img_mat.data, img_mat.cols, img_mat.rows, static_cast<int>(img_mat.step), QImage::Format_Grayscale8); //Conversion mat->QImage (img_out en sortie)
    // imgNdGTr = img_out; //Set de la QIMAGE traitée
    imgNdGTr = img_out.copy();
    im_fen = img_out.copy();;

    //Affichage
    img_out = img_out.scaledToWidth(ui->LBLtr->width(), Qt::SmoothTransformation);
    img_out = img_out.scaledToHeight(ui->LBLtr->height(), Qt::SmoothTransformation);
    ui->LBLtr->setPixmap(QPixmap::fromImage(img_out));
}
*/

void Traitement::on_SLIDKM_sliderMoved(int position)
{

    QString text = QString("");

    text = QString("Nombre de classes : %1").arg(position);
    ui->CLAS->setText(text);
    ui->SLIDKM->setValue(position);

    curseur_classes = position;

}

void Traitement::on_SLIDSEUIL_sliderMoved(int position)
{
    curseur_seuil = position;
    QString text = QString("");
    text = QString("Binarisation : Valeur du seuil : %1").arg(position);
    ui->SEUILB->setText(text);

    Mat img_mat;
    img_mat = imgMatTrNdG.clone();

    //Traitement
    img_mat = binarisation(img_mat, curseur_seuil);
    //imgMatTrNdG = img_mat.clone();
    imgMatNdGPS =  img_mat.clone(); //Set de la matrice image traitée
    //

    //imgMatTrNdG = img_mat; //Set de la matrice image traitée

    QImage img_out(img_mat.data, img_mat.cols, img_mat.rows, static_cast<int>(img_mat.step), QImage::Format_Grayscale8); //Conversion mat->QImage (img_out en sortie)
    imgNdGPS = img_out.copy();
    //imgNdGTrF = img_out;
    im_fen = img_out.copy();;

    //Affichage
    img_out = img_out.scaledToWidth(ui->LBLtr->width(), Qt::SmoothTransformation);
    img_out = img_out.scaledToHeight(ui->LBLtr->height(), Qt::SmoothTransformation);
    ui->LBLtr->setPixmap(QPixmap::fromImage(img_out));


}

void Traitement::on_SLIDVAR_sliderMoved(int position)
{
    curseur_variance = position;

    QString text = QString("Bruit Blanc Additif : Variance: %1").arg(position);
    ui->VAR->setText(text);

    Mat img_mat;
    img_mat = imgMatTrNdG.clone();

    //Traitement
    img_mat = bruit_blanc(img_mat, curseur_variance);
    //imgMatTrNdG = img_mat.clone();
    imgMatNdGPS =  img_mat.clone(); //Set de la matrice image traitée

    //imgMatTrNdG = img_mat; //Set de la matrice image traitée

    QImage img_out(img_mat.data, img_mat.cols, img_mat.rows, static_cast<int>(img_mat.step), QImage::Format_Grayscale8); //Conversion mat->QImage (img_out en sortie)
    //imgNdGTr = img_out.copy(); //Set de la QIMAGE traitée
    //imgNdGTrF = img_out;
    imgNdGPS = img_out.copy();
    im_fen = img_out.copy();;

    //Affichage
    img_out = img_out.scaledToWidth(ui->LBLtr->width(), Qt::SmoothTransformation);
    img_out = img_out.scaledToHeight(ui->LBLtr->height(), Qt::SmoothTransformation);
    ui->LBLtr->setPixmap(QPixmap::fromImage(img_out));
}


void Traitement::on_BI_CURS_sliderMoved(int position)
{
   curseur_poivre = position;
   QString text = QString("Bruit impulsionnel : %1 %").arg((curseur_poivre/1000)*100);
   ui->lblPS->setText(text);

   Mat img_mat;
   img_mat = imgMatTrNdG.clone();

   //Traitement
   img_mat = bruit_ps(img_mat,curseur_poivre/1000);

   //

   imgMatNdGPS =  img_mat.clone(); //Set de la matrice image traitée
   //imgNdGMatTrF = img_mat.clone(); //Set de la matrice image traitée

   QImage img_out(img_mat.data, img_mat.cols, img_mat.rows, static_cast<int>(img_mat.step), QImage::Format_Grayscale8); //Conversion mat->QImage (img_out en sortie)
   // imgNdGTr = img_out; //Set de la QIMAGE traitée
   imgNdGPS = img_out.copy();
   im_fen = img_out.copy();;

   //Affichage
   img_out = img_out.scaledToWidth(ui->LBLtr->width(), Qt::SmoothTransformation);
   img_out = img_out.scaledToHeight(ui->LBLtr->height(), Qt::SmoothTransformation);
   ui->LBLtr->setPixmap(QPixmap::fromImage(img_out));
}


void Traitement::on_BI_CURS_sliderReleased()
{
    imgMatTrNdG = imgMatNdGPS.clone();
    imgNdGTr = imgNdGPS.copy();
}


void Traitement::on_SLIDVAR_sliderReleased()
{
    imgMatTrNdG = imgMatNdGPS.clone();
    imgNdGTr = imgNdGPS.copy();
}


void Traitement::on_SLIDSEUIL_sliderReleased()
{
    imgMatTrNdG = imgMatNdGPS.clone();
    imgNdGTr = imgNdGPS.copy();
}


void Traitement::on_QCON_clicked()
{
    ui->HCON->setChecked(0);
    quatre_connexites = 1;
    huit_connexites = 0;
}


void Traitement::on_HCON_clicked()
{
    ui->QCON->setChecked(0);
    huit_connexites = 1;
    quatre_connexites = 0;
}


void Traitement::on_HPREW_clicked()
{
    ui->VPREW->setChecked(0);
    horiz_prew = 1;
    vertic_prew = 0;
}



void Traitement::on_VPREW_clicked()
{
    ui->HPREW->setChecked(0);
    vertic_prew = 1;
    horiz_prew = 0;
}




void Traitement::on_HSOB_clicked()
{
    ui->VSOB->setChecked(0);
    vertic_sob = 0;
    horiz_sob = 1;
}


void Traitement::on_VSOB_clicked()
{
    ui->HSOB->setChecked(0);
    vertic_sob = 1;
    horiz_sob = 0;
}


void Traitement::on_FF_clicked()
{
    imgNdGAnnulerFreq = imgNdGTr.copy();
    imgMatNdGAnnulerFreq = imgMatTrNdG.clone();
    imgNdGFreq = imgNdGTr.copy();
    imgMatNdGFreq = imgMatTrNdG.clone();

    ui->SWTR->setCurrentIndex(7);
}


void Traitement::on_VAL_FREQ_clicked()
{
    imgNdGTr = imgNdGFreq.copy();
    imgMatTrNdG = imgMatNdGFreq.clone();

    QImage img_retour = imgNdGTr.copy();
    img_retour = img_retour.scaledToWidth(ui->LBLtr->width(), Qt::SmoothTransformation);
    img_retour = img_retour.scaledToHeight(ui->LBLtr->height(), Qt::SmoothTransformation);
    ui->LBLtr->setPixmap(QPixmap::fromImage(img_retour));
    im_fen = img_retour;

    ui->SWTR->setCurrentIndex(1);
}


void Traitement::on_ANN_FREQ_clicked()
{
    imgNdGTr = imgNdGAnnulerFreq.copy();
    imgMatTrNdG = imgMatNdGAnnulerFreq.clone();
    QImage img_retour = imgNdGTr.copy();
    img_retour = img_retour.scaledToWidth(ui->LBLtr->width(), Qt::SmoothTransformation);
    img_retour = img_retour.scaledToHeight(ui->LBLtr->height(), Qt::SmoothTransformation);
    ui->LBLtr->setPixmap(QPixmap::fromImage(img_retour));
    im_fen = img_retour;

    ui->SWTR->setCurrentIndex(1);
}


void Traitement::on_PH_clicked()
{
    QPointer<frequentiel> f = new frequentiel();
    f->deleteLater();
    //f->setAttribute(Qt::WA_DeleteOnClose);
    //frequentiel *f = new frequentiel();
    f->setWindowFlags(Qt::Window);
    f->activateWindow();
    f->imgpre(imgMatTrNdG,imgNdGTr,0);
    f->setModal(1);
    //f->exec();
    f->setWindowTitle("Filtre fréquentiel : Passe-Bas");
    QImage img_out;
    Mat img_mat;
    if (f->exec() == 0)
    {   if (f->VALIDER == 1)
        {
                    img_mat = (f->imgMat_post).clone();
                    QImage imgVAL_out(img_mat.data, img_mat.cols, img_mat.rows, static_cast<int>(img_mat.step), QImage::Format_Grayscale8); //Conversion mat->QImage (img_out en sortie)
                    imgMatNdGFreq = img_mat.clone();
                    imgNdGFreq = imgVAL_out.copy();
                    img_out = imgVAL_out.copy();
        }
        else
        {
            img_mat = imgMatTrNdG.clone();
            QImage imgNOTVAL_out(img_mat.data, img_mat.cols, img_mat.rows, static_cast<int>(img_mat.step), QImage::Format_Grayscale8); //Conversion mat->QImage (img_out en sortie)
            img_out = imgNOTVAL_out.copy();
        }
    }

    //imgMatNdGFreq = img_mat.clone();
    //imgNdGFreq = img_out.copy();
    im_fen = img_out.copy();

    //Affichage
    img_out = img_out.scaledToWidth(ui->LBLtr->width(), Qt::SmoothTransformation);
    img_out = img_out.scaledToHeight(ui->LBLtr->height(), Qt::SmoothTransformation);
    ui->LBLtr->setPixmap(QPixmap::fromImage(img_out));
}


void Traitement::on_PB_clicked()
{
    QPointer<frequentiel> f = new frequentiel();
    f->deleteLater();
    f->setWindowFlags(Qt::Window);
    f->activateWindow();
    f->imgpre(imgMatTrNdG,imgNdGTr,1);
    f->setModal(1);
    //f->exec();
    f->setWindowTitle("Filtre fréquentiel : Passe-Haut");
    QImage img_out;
    Mat img_mat;
    if (f->exec() == 0)
    {   if (f->VALIDER == 1)
        {
                    img_mat = (f->imgMat_post).clone();
                    QImage imgVAL_out(img_mat.data, img_mat.cols, img_mat.rows, static_cast<int>(img_mat.step), QImage::Format_Grayscale8); //Conversion mat->QImage (img_out en sortie)
                    imgMatNdGFreq = img_mat.clone();
                    imgNdGFreq = imgVAL_out.copy();
                    img_out = imgVAL_out.copy();
        }
        else
        {
            img_mat = imgMatTrNdG.clone();
            QImage imgNOTVAL_out(img_mat.data, img_mat.cols, img_mat.rows, static_cast<int>(img_mat.step), QImage::Format_Grayscale8); //Conversion mat->QImage (img_out en sortie)
            img_out = imgNOTVAL_out.copy();
        }
    }

    //imgMatNdGFreq = img_mat.clone();
    //imgNdGFreq = img_out.copy();
    im_fen = img_out.copy();

    //Affichage
    img_out = img_out.scaledToWidth(ui->LBLtr->width(), Qt::SmoothTransformation);
    img_out = img_out.scaledToHeight(ui->LBLtr->height(), Qt::SmoothTransformation);
    ui->LBLtr->setPixmap(QPixmap::fromImage(img_out));
}


void Traitement::on_PBA_clicked()
{
    QPointer<frequentiel> f = new frequentiel();
    f->deleteLater();
    f->setWindowFlags(Qt::Window);
    f->activateWindow();
    f->imgpre(imgMatTrNdG,imgNdGTr,2);
    f->setModal(1);
    //f->exec();
    f->setWindowTitle("Filtre fréquentiel : Passe-Bande");
    QImage img_out;
    Mat img_mat;
    if (f->exec() == 0)
    {   if (f->VALIDER == 1)
        {
                    img_mat = (f->imgMat_post).clone();
                    QImage imgVAL_out(img_mat.data, img_mat.cols, img_mat.rows, static_cast<int>(img_mat.step), QImage::Format_Grayscale8); //Conversion mat->QImage (img_out en sortie)
                    imgMatNdGFreq = img_mat.clone();
                    imgNdGFreq = imgVAL_out.copy();
                    img_out = imgVAL_out.copy();
        }
        else
        {
            img_mat = imgMatTrNdG.clone();
            QImage imgNOTVAL_out(img_mat.data, img_mat.cols, img_mat.rows, static_cast<int>(img_mat.step), QImage::Format_Grayscale8); //Conversion mat->QImage (img_out en sortie)
            img_out = imgNOTVAL_out.copy();
        }
    }

    im_fen = img_out.copy();

    //Affichage
    img_out = img_out.scaledToWidth(ui->LBLtr->width(), Qt::SmoothTransformation);
    img_out = img_out.scaledToHeight(ui->LBLtr->height(), Qt::SmoothTransformation);
    ui->LBLtr->setPixmap(QPixmap::fromImage(img_out));
}


void Traitement::on_CB_clicked()
{
    QPointer<frequentiel> f = new frequentiel();
    f->deleteLater();
    f->setWindowFlags(Qt::Window);
    f->activateWindow();
    f->imgpre(imgMatTrNdG,imgNdGTr,3);
    f->setModal(1);
    //f->exec();
    f->setWindowTitle("Filtre fréquentiel : Coupe-Bande");
    QImage img_out;
    Mat img_mat;
    if (f->exec() == 0)
    {   if (f->VALIDER == 1)
        {
                    img_mat = (f->imgMat_post).clone();
                    QImage imgVAL_out(img_mat.data, img_mat.cols, img_mat.rows, static_cast<int>(img_mat.step), QImage::Format_Grayscale8); //Conversion mat->QImage (img_out en sortie)
                    imgMatNdGFreq = img_mat.clone();
                    imgNdGFreq = imgVAL_out.copy();
                    img_out = imgVAL_out.copy();
        }
        else
        {
            img_mat = imgMatTrNdG.clone();
            QImage imgNOTVAL_out(img_mat.data, img_mat.cols, img_mat.rows, static_cast<int>(img_mat.step), QImage::Format_Grayscale8); //Conversion mat->QImage (img_out en sortie)
            img_out = imgNOTVAL_out.copy();
        }
    }

    im_fen = img_out.copy();

    //Affichage
    img_out = img_out.scaledToWidth(ui->LBLtr->width(), Qt::SmoothTransformation);
    img_out = img_out.scaledToHeight(ui->LBLtr->height(), Qt::SmoothTransformation);
    ui->LBLtr->setPixmap(QPixmap::fromImage(img_out));
}


void Traitement::on_AFFICH_FREQ_clicked()
{
    if (passage_freq == 1)
    {
        ui->SWTRCLR->setCurrentIndex(2);
        QString text = QString("Affichage image");
        ui->AFFICH_FREQ->setText(text);

        Mat mat_freq = imgMatTrNdG.clone();
        Mat mat_out = amplitude_fft(mat_freq);

        QImage img_freq(mat_out.data, mat_out.cols, mat_out.rows, static_cast<int>(mat_out.step), QImage::Format_Grayscale8); //Conversion mat->QImage (img_out en sortie)

        im_fen_freq = img_freq.copy();

        img_freq = img_freq.scaledToWidth(ui->LBLFREQ->width(), Qt::SmoothTransformation);
        img_freq = img_freq.scaledToHeight(ui->LBLFREQ->height(), Qt::SmoothTransformation);
        ui->LBLFREQ->setPixmap(QPixmap::fromImage(img_freq));

        ui->H->setEnabled(false);
        ui->FL->setEnabled(false);
        ui->AT->setEnabled(false);
        ui->FMED->setEnabled(false);
        ui->FF->setEnabled(false);
        ui->REN->setEnabled(false);

        passage_freq = 0;
    }
    else
    {
        ui->SWTRCLR->setCurrentIndex(0);
        QString text = QString("Affichage fréquentiel");
        ui->AFFICH_FREQ->setText(text);
        ui->H->setEnabled(true);
        ui->FL->setEnabled(true);
        ui->AT->setEnabled(true);
        ui->FMED->setEnabled(true);
        ui->FF->setEnabled(true);
        ui->REN->setEnabled(true);
        passage_freq = 1;
    }
}

void Traitement::on_actionSAVE_triggered()
{
    QString OS = QSysInfo::productType();
    if(PAGE == 1)
    {
        QImage image = imgNdGTr.copy();

        QFileDialog::Options option;
        QString filter;

        QString fileName = QFileDialog::getSaveFileName(this, tr("Save Image File"), QString(), tr("Images *.jpg;;Images *.png;;Image *.bmp"), &filter, option);

        if (!fileName.isEmpty())
        {
            QString Name;
            if(OS == "ubuntu")
                Name = fileName + "." + QFileInfo(filter).suffix();
            else
                Name = fileName;
            image.save(Name);
            QMessageBox::information(this, "Sauvegarde", "Image sauvegardée !");
        }

    }
    if(PAGE ==  2)
    {
        QImage image = imgTr.copy();

        QFileDialog::Options option;
        QString filter;

        QString fileName = QFileDialog::getSaveFileName(this, tr("Save Image File"), QString(), tr("Images *.jpg;;Images *.png;;Image *.bmp"), &filter, option);

        if (!fileName.isEmpty())
        {
            QString Name;
            if(OS == "ubuntu")
                Name = fileName + "." + QFileInfo(filter).suffix();
            else
                Name = fileName;
            image.save(Name);
            QMessageBox::information(this, "Sauvegarde", "Image sauvegardée !");
        }
   }
    if(PAGE != 1 && PAGE != 2)
    {
        QMessageBox::information(this, "Ah Bon ?", "Je vous conseille d'appliquer quelque traitement sur une image que vous avez ouverte au préalable, sinon ça ne marche pas bien...");
    }

}


void Traitement::on_actionImporter_triggered()
{
    if(PAGE == 1)
    {
        QPointer<Accreditation> accreditation = new Accreditation();
        accreditation->deleteLater();
        accreditation->setModal(1);

        //accreditation = new Accreditation();
        if (accreditation -> exec() == 0)
        {
            int var = accreditation->numero_acces;

            //QString adrImg = &imgNdGTr;

            if (var == 1)
            {
                string current = filesystem::current_path().string();
                string imgPATH = "temp.jpg";
                QString IMGPATH = QString::fromStdString(imgPATH);
                QDir::setCurrent(QString::fromStdString(current) + "/Temp");
                imgNdGTr.save(IMGPATH);
                QString BIBOPEN = QString::fromStdString(current) + "/Temp/" + IMGPATH;
                QDir::setCurrent(BIBOPEN);
                SetAdr(BIBOPEN);
                QDir::setCurrent(QString::fromStdString(current));

                // Acceder à la bibliothèque.
                QPointer<Bibliotheque> bibliotheque = new Bibliotheque();
                bibliotheque->setAttribute(Qt::WA_DeleteOnClose);
                bibliotheque->RecupAccred(var);
                bibliotheque->setImp(1);
                bibliotheque->init();
                bibliotheque->SetImg(imgNdGTr);
                bibliotheque->SetAdr(BIBOPEN);
                bibliotheque->show();
                bibliotheque->AffImage();
                fenetre_traitement->close();
            }
            else
            {
                //QMessageBox::information(this, "ERREUR", "Vous n'avez pas les droits administrateurs pour enregistrer cette image dans la bibliothèque.");
            }
        }
    }
    if(PAGE == 2)
    {
        Accreditation *accreditation = new Accreditation();
        accreditation->setModal(1);

        //accreditation = new Accreditation();
        if (accreditation -> exec() == 0)
        {
            int var = accreditation->numero_acces;

            if (var == 1)
            {
                string current = filesystem::current_path().string();
                string imgPATH = "temp.jpg";
                QString IMGPATH = QString::fromStdString(imgPATH);
                QDir::setCurrent(QString::fromStdString(current) + "/Temp");
                imgTr.save(IMGPATH);
                QString BIBOPEN = QString::fromStdString(current) + "/Temp/" + IMGPATH;
                QDir::setCurrent(BIBOPEN);
                SetAdr(BIBOPEN);
                QDir::setCurrent(QString::fromStdString(current));

                // Acceder à la bibliothèque.
                QPointer<Bibliotheque> bibliotheque = new Bibliotheque();
                bibliotheque->setAttribute(Qt::WA_DeleteOnClose);
                bibliotheque->RecupAccred(var);
                bibliotheque->setImp(1);
                bibliotheque->init();
                bibliotheque->SetImg(imgTr);
                bibliotheque->SetAdr(BIBOPEN);
                bibliotheque->show();
                bibliotheque->AffImage();
                fenetre_traitement->close();
            }
            else
            {
                //QMessageBox::information(this, "ERREUR", "Vous n'avez pas les droits administrateurs pour enregistrer cette image dans la bibliothèque.");
            }
        }
    }
    if(PAGE != 2 && PAGE != 1 && adr ==(""))
    {
        QMessageBox::information(this, "Ah Bon ?", "Alors, pour importer, il faudrait déjà une image...");
    }
    if (PAGE == -1)
    {
        QPointer<Accreditation> accreditation = new Accreditation();
        accreditation->deleteLater();
        accreditation->setModal(1);

        //accreditation = new Accreditation();
        if (accreditation -> exec() == 0)
        {
            int var = accreditation->numero_acces;

            if (var == 1)
            {
                string current = filesystem::current_path().string();
                string imgPATH = "temp.jpg";
                QString IMGPATH = QString::fromStdString(imgPATH);
                QDir::setCurrent(QString::fromStdString(current) + "/Temp");
                img.save(IMGPATH);
                QString BIBOPEN = QString::fromStdString(current) + "/Temp/" + IMGPATH;
                QDir::setCurrent(BIBOPEN);
                SetAdr(BIBOPEN);
                QDir::setCurrent(QString::fromStdString(current));

                // Acceder à la bibliothèque.
                QPointer<Bibliotheque> bibliotheque = new Bibliotheque();
                accreditation->deleteLater();
                bibliotheque->RecupAccred(var);
                bibliotheque->setImp(1);
                bibliotheque->init();
                bibliotheque->SetImg(img);
                bibliotheque->SetAdr(BIBOPEN);
                bibliotheque->show();
                bibliotheque->AffImage();
                fenetre_traitement->close();
            }
            else
            {
                //QMessageBox::information(this, "ERREUR", "Vous n'avez pas les droits administrateurs pour enregistrer cette image dans la bibliothèque.");
            }
        }
    }
}

void Traitement::on_NEGCLR_clicked()
{
    Mat img_mat = imgMatTr.clone();
    Mat MedMatCLR;

    MedMatCLR = neg(img_mat);

    imgMatTr = MedMatCLR.clone();
    QImage img_out = QImage((uchar*) MedMatCLR.data, MedMatCLR.cols, MedMatCLR.rows, MedMatCLR.step, QImage::Format_RGB888);
    imgTr = img_out.copy();

    VisuCanal();
    VisuImage();
}


void Traitement::on_FGCLR_clicked()
{
    Mat img_mat = imgMatTr.clone();
    Mat MedMatCLR;

    MedMatCLR = filtrage(img_mat, "gaussien1");

    imgMatTr = MedMatCLR.clone();
    QImage img_out = QImage((uchar*) MedMatCLR.data, MedMatCLR.cols, MedMatCLR.rows, MedMatCLR.step, QImage::Format_RGB888);
    imgTr = img_out.copy();

    VisuCanal();
    VisuImage();
}


void Traitement::on_FMCLR_clicked()
{
    Mat img_mat = imgMatTr.clone();
    Mat MedMatCLR;

    MedMatCLR = filtrage(img_mat, "moyenneur");

    imgMatTr = MedMatCLR.clone();
    QImage img_out = QImage((uchar*) MedMatCLR.data, MedMatCLR.cols, MedMatCLR.rows, MedMatCLR.step, QImage::Format_RGB888);
    imgTr = img_out.copy();

    VisuCanal();
    VisuImage();
}


void Traitement::on_SLIDORD_actionTriggered(int action)
{
    on_SLIDORD_sliderMoved(action);
}

