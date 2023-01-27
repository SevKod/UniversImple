#include "frequentiel.h"
#include "ui_frequentiel.h"
#include "fonctions.h"
#include <opencv2/opencv.hpp>
//#include <opencv4/opencv2/opencv.hpp>

using namespace cv;

frequentiel::frequentiel(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::frequentiel)
{
    ui->setupUi(this);
}

frequentiel::~frequentiel()
{
    delete ui;
}


void frequentiel::imgpre(Mat imgMatNdG, QImage imgNdG,int filtre)
{
    //filtre : 0 : Passe BAS
    //filtre : 1 : Passe HAUT
    //filtre : 2 : Passe BANDE
    //filtre : 3 : Coupe BANDE
    imgMat_pre = imgMatNdG.clone();
    img_pre = imgNdG.copy();

    ui->IMGPRE->setMinimumSize((int)img_pre.width()/8, (int)img_pre.height()/8);
    ui->IMGPOST->setMinimumSize((int)img_pre.width()/8, (int)img_pre.height()/8);
    ui->FREQPRE->setMinimumSize((int)img_pre.width()/8, (int)img_pre.height()/8);
    ui->FREQPOST->setMinimumSize((int)img_pre.width()/8, (int)img_pre.height()/8);

    QImage img_out = img_pre.copy();
    img_fen_pre = img_out;
    img_out = img_out.scaledToWidth(ui->IMGPRE->width(), Qt::SmoothTransformation);
    img_out = img_out.scaledToHeight(ui->IMGPRE->height(), Qt::SmoothTransformation);
    ui->IMGPRE->setPixmap(QPixmap::fromImage(img_out));

    Mat mat_out = amplitude_fft(imgMat_pre);
    imgMat_freq_pre = mat_out.clone();

    QImage img_freq_pres_out(mat_out.data, mat_out.cols, mat_out.rows, static_cast<int>(mat_out.step), QImage::Format_Grayscale8); //Conversion mat->QImage (img_out en sortie)

    img_fen_freq_pre = img_freq_pres_out.copy();
    img_out = img_freq_pres_out.copy();
    img_out = img_out.scaledToWidth(ui->FREQPRE->width(), Qt::SmoothTransformation);
    img_out = img_out.scaledToHeight(ui->FREQPRE->height(), Qt::SmoothTransformation);
    ui->FREQPRE->setPixmap(QPixmap::fromImage(img_out));

    //PARTIE FILTRAGE : ORDRE 1
    //int rayon = 100;    

    Mat amplitude = imgMat_freq_pre.clone();

    Mat image_fft = fft_image(imgMat_pre);
    Mat im_filtree;
    vector<Mat> ReelImaginaire = {Mat::zeros(imgMatNdG.rows, imgMatNdG.cols, CV_64F), Mat::zeros(imgMatNdG.rows, imgMatNdG.cols, CV_64F) }; //Stockage de la partie réelle et imaginaire dans ce vecteur

    split(image_fft, ReelImaginaire); //Remplissage du vecteur à 2 dimension de matrices
    ReelImaginaire[0] = centrer_fft(ReelImaginaire[0]);
    ReelImaginaire[1] = centrer_fft(ReelImaginaire[1]);

    Reel = ReelImaginaire[0].clone();
    Imag = ReelImaginaire[1].clone();

    Point centre(amplitude.cols / 2, amplitude.rows / 2); //Position du filtre (centre de l'image ici)
    if (filtre == 0) //PASSE BAS
    {
        ui->PAGE_FILTRE->setCurrentIndex(0);
        int R = sqrt((imgMat_pre.rows / 2) * (imgMat_pre.rows / 2) + (imgMat_pre.cols / 2) * (imgMat_pre.cols / 2)); //Rayon externe fixe pour le passe-bas. (Commence aux bords de l'image)
        int rayon = R;
        ui->SLIDPB->setRange(0, 2*R);
        ui->SLIDPB->setValue(R);
        ui->SLIDXPB->setRange(0,(int)amplitude.rows);
        ui->SLIDYPB->setRange(0,(int)amplitude.cols);
        ui->SLIDXPB->setValue((int)amplitude.rows/2);
        ui->SLIDYPB->setValue((int)amplitude.cols/2);

        QString text = QString("Rayon : %1").arg(R);
        ui->TXTSLIDPB->setText(text);

        text = QString("Y : %1").arg((int)amplitude.rows / 2);
        ui->XPB->setText(text);

        text = QString("X : %1").arg((int)amplitude.cols / 2);
        ui->YPB->setText(text);

        //La fonction circle permet de tracer un cercle dans l'image "amplitude", aux coordonnées "centre", de rayon "R", d'intensité "0" et d'épaisseur "2*R - rayon
        //Ici on exploite la fonction circle pour créer un cercle noir qui dépasse largement l'image et dont on contrôle le rayon par l'épaisseur interne.
        //L'épaisseur correspond au double du rayon interne du filtre

        //Application du filtre sur l'amplitude pour la visualisation

        circle(amplitude, centre, R, 0, 2 * R - rayon); //Passe-Bas sur l'amplitude
        circle(ReelImaginaire[0], centre, R, 0, 2 * R - rayon); //Passe-Bas sur la partie réelle
        circle(ReelImaginaire[1], centre, R, 0, 2 * R - rayon); //Passe-Bas sur la partie imaginaire


        //Application du filtre sur la DFT
        PB = 1;
    }

    if (filtre == 1) //PASSE HAUT
    {
        ui->PAGE_FILTRE->setCurrentIndex(1);
        //La fonction circle permet de tracer un cercle dans l'image "amplitude", aux coordonnées "centre", de rayon "rayon", d'intensité "0" et d'épaisseur "-1" ce qui signifie que le cercle sera remplis.

        //Application du filtre sur l'amplitude pour la visualisation
        int R = sqrt((imgMat_pre.rows / 2) * (imgMat_pre.rows / 2) + (imgMat_pre.cols / 2) * (imgMat_pre.cols / 2)); //Rayon externe fixe pour le passe-bas. (Commence aux bords de l'image)
        int rayon = R/4;
        ui->SLIDPH->setRange(0, R+1);
        ui->SLIDPH->setValue(rayon);
        ui->SLIDXPH->setRange(0,(int)amplitude.rows);
        ui->SLIDYPH->setRange(0,(int)amplitude.cols);
        ui->SLIDXPH->setValue((int)amplitude.rows/2);
        ui->SLIDYPH->setValue((int)amplitude.cols/2);
        QString text = QString("Rayon : %1").arg(rayon);
        ui->TXTRAYPH->setText(text);

        text = QString("Y : %1").arg((int)amplitude.rows / 2);
        ui->XPH->setText(text);

        text = QString("X : %1").arg((int)amplitude.cols / 2);
        ui->YPH->setText(text);

        circle(amplitude, centre, rayon, 0, -1); //Passe-Haut sur l'amplitude
        circle(ReelImaginaire[0], centre, rayon, 0, -1); //Passe-haut sur la partie réelle
        circle(ReelImaginaire[1], centre, rayon, 0, -1); //Passe-haut sur la partie imaginaire


        //Application du filtre sur la DFT
        PH = 1;
    }

    if (filtre == 2) //PASSE BANDE
    {
        ui->PAGE_FILTRE->setCurrentIndex(2);
        //La fonction circle permet de tracer un cercle dans l'image "amplitude", aux coordonnées "centre", de rayon "rayon", d'intensité "0" et d'épaisseur "-1" ce qui signifie que le cercle sera remplis.

        //Application du filtre sur l'amplitude pour la visualisation
        int R = sqrt((imgMat_pre.rows / 2) * (imgMat_pre.rows / 2) + (imgMat_pre.cols / 2) * (imgMat_pre.cols / 2)); //Rayon externe fixe pour le passe-bas. (Commence aux bords de l'image)
        int R1 = R/4;
        int R2 = 3*R/4;

        ui->SLIDRINFPB->setRange(0, R-1);
        ui->SLIDRINFPB->setValue(R1);
        ui->SLIDRSUPPB->setRange(0, R-1);
        ui->SLIDRSUPPB->setValue(R2);
        ui->SLIDXPBA->setRange(0,(int)amplitude.rows);
        ui->SLIDYPBA->setRange(0,(int)amplitude.cols);
        ui->SLIDXPBA->setValue((int)amplitude.rows/2);
        ui->SLIDYPBA->setValue((int)amplitude.cols/2);

        QString text = QString("Rayon Inf. : %1").arg(R1);
        ui->TXTLBLINF->setText(text);

        text = QString("Rayon Sup. : %1").arg(R2);
        ui->TXTLBLSUP->setText(text);

        text = QString("Y : %1").arg((int)amplitude.rows / 2);
        ui->XPBA->setText(text);

        text = QString("X : %1").arg((int)amplitude.cols / 2);
        ui->YPBA->setText(text);

        circle(amplitude, centre, R, 0, 2 * R -1 - 2*R2-1); //Coupe-Bande : Passe-bas sur l'amplitude
        circle(amplitude, centre, R1, 0, -1); //Coupe-Bande : Passe-haut sur l'amplitude
        //Application du filtre sur la DFT
        //Il s'agit d'une somme entre un passe haut et un passe-bas

        circle(ReelImaginaire[0], centre, R, 0, 2*R-1-2*R2-1); //Passe-Bas sur la partie réelle
        circle(ReelImaginaire[1], centre, R, 0, 2*R-1-2*R2-1); //Passe-Bas sur la partie imaginaire
        circle(ReelImaginaire[0], centre, R1, 0, -1); //Passe-Haut sur la partie réelle
        circle(ReelImaginaire[1], centre, R1, 0, -1); //Passe-Haut sur la partie imaginaire

        //Application du filtre sur la DFT
        PBA = 1;
    }

    if (filtre == 3)
    {
        ui->PAGE_FILTRE->setCurrentIndex(3);
        int R = sqrt((imgMat_pre.rows / 2) * (imgMat_pre.rows / 2) + (imgMat_pre.cols / 2) * (imgMat_pre.cols / 2));
        int R1 = R/4;
        int R2 = 3*R/4;

        ui->SLIDRINFCB->setRange(0, R-1);
        ui->SLIDRINFCB->setValue(R1);
        ui->SLIDRSUPCB->setRange(0, R-1);
        ui->SLIDRSUPCB->setValue(R2);
        ui->SLIDXCB->setRange(0,(int)amplitude.rows);
        ui->SLIDYCB->setRange(0,(int)amplitude.cols);
        ui->SLIDXCB->setValue((int)amplitude.rows/2);
        ui->SLIDYCB->setValue((int)amplitude.cols/2);

        QString text = QString("Rayon Inf. : %1").arg(R1);
        ui->TXTLBLINFCB->setText(text);

        text = QString("Rayon Sup. : %1").arg(R2);
        ui->TXTLBLSUPCB->setText(text);

        text = QString("Y : %1").arg((int)amplitude.rows / 2);
        ui->XCB->setText(text);

        text = QString("X : %1").arg((int)amplitude.cols / 2);
        ui->YCB->setText(text);


        int largeur = R2 - R1; //On calcule la relation entre les rayons R1 et R2, et la largeur
        int rayon = R1 + (int)((largeur) / 2); //Le rayon du cercle coupe bande sera le plus petit rayon auquel s'ajoute la moitié de la largeur du cercle.

        circle(amplitude, centre, rayon, 0, largeur); //Passe-Bande sur l'amplitude
        //Application du filtre sur la DFT

        circle(ReelImaginaire[0], centre, rayon, 0, largeur); //Passe-bande sur la partie réelle
        circle(ReelImaginaire[1], centre, rayon, 0, largeur); //Passe-bande sur la partie imaginaire

        CB = 1;
    }

    //AFFICHAGE FILTRAGE AMPLITUDE
    imgMat_freq_post = amplitude.clone();

    QImage img_freq_post_out(imgMat_freq_post.data, imgMat_freq_post.cols, imgMat_freq_post.rows, static_cast<int>(imgMat_freq_post.step), QImage::Format_Grayscale8); //Conversion mat->QImage (img_out en sortie)
    img_fen_freq_post =img_freq_post_out.copy();
    img_out = img_freq_post_out.copy();
    img_out = img_out.scaledToWidth(ui->FREQPOST->width(), Qt::SmoothTransformation);
    img_out = img_out.scaledToHeight(ui->FREQPOST->height(), Qt::SmoothTransformation);
    ui->FREQPOST->setPixmap(QPixmap::fromImage(img_out));

    //CALCUL DE LA TF INVERSE

    //Décentrage de la DFT
    ReelImaginaire[0] = centrer_fft(ReelImaginaire[0]);
    ReelImaginaire[1] = centrer_fft(ReelImaginaire[1]);

    //Concaténation de la partie réelle et imaginaire dans une matrice à deux composantes (réel et complexe)
    merge(ReelImaginaire, im_filtree);

    //Calcul de la DFT inverse, normalisation et affichage
    im_filtree = inverse_fft_image(im_filtree); //TF Inverse
    //im_filtree.convertTo(im_filtree, CV_8UC1);
    normalize(im_filtree, im_filtree, 0, 255, NORM_MINMAX);

    //AFFICHAGE TF INVERSE

    imgMat_post = im_filtree.clone();

    QImage img_post_out(imgMat_post.data, imgMat_post.cols, imgMat_post.rows, static_cast<int>(imgMat_post.step), QImage::Format_Grayscale8); //Conversion mat->QImage (img_out en sortie)
    img_fen_post =img_post_out.copy();
    img_out = img_post_out.copy();
    img_out = img_out.scaledToWidth(ui->IMGPOST->width(), Qt::SmoothTransformation);
    img_out = img_out.scaledToHeight(ui->IMGPOST->height(), Qt::SmoothTransformation);
    ui->IMGPOST->setPixmap(QPixmap::fromImage(img_out));

}



void frequentiel::on_SLIDPH_sliderMoved(int position)
{
    QString text = QString("Rayon : %1").arg(position);
    ui->TXTRAYPH->setText(text);
    Mat amplitude = imgMat_freq_pre.clone();
    Mat im_filtree;
    vector<Mat> ReelImaginaire = { Mat::zeros(imgMat_pre.rows, imgMat_pre.cols, CV_64F), Mat::zeros(imgMat_pre.rows, imgMat_pre.cols, CV_64F) }; //Stockage de la partie réelle et imaginaire dans ce vecteur
    ReelImaginaire[0] = Reel.clone();
    ReelImaginaire[1] = Imag.clone();

    int ligne = ui->SLIDYPH->value();
    int colonne = ui->SLIDXPH->value();

    Point centre(ligne, colonne); //Position du filtre (centre de l'image ici)
    //int R = sqrt((imgMat_pre.rows / 2) * (imgMat_pre.rows / 2) + (imgMat_pre.cols / 2) * (imgMat_pre.cols / 2)); //Rayon externe fixe pour le passe-bas. (Commence aux bords de l'image)
    int rayon = position;
    circle(amplitude, centre, rayon, 0, -1); //Passe-Haut sur l'amplitude
    circle(ReelImaginaire[0], centre, rayon, 0, -1); //Passe-haut sur la partie réelle
    circle(ReelImaginaire[1], centre, rayon, 0, -1); //Passe-haut sur la partie imaginaire

    //Décentrage de la DFT
    ReelImaginaire[0] = centrer_fft(ReelImaginaire[0]);
    ReelImaginaire[1] = centrer_fft(ReelImaginaire[1]);

    //Concaténation de la partie réelle et imaginaire dans une matrice à deux composantes (réel et complexe)
    merge(ReelImaginaire, im_filtree);

    //Calcul de la DFT inverse, normalisation et affichage
    im_filtree = inverse_fft_image(im_filtree); //TF Inverse
    //im_filtree.convertTo(im_filtree, CV_8UC1);
    normalize(im_filtree, im_filtree, 0, 255, NORM_MINMAX);

    imgMat_post = im_filtree.clone();

    QImage img_post_out(imgMat_post.data, imgMat_post.cols, imgMat_post.rows, static_cast<int>(imgMat_post.step), QImage::Format_Grayscale8); //Conversion mat->QImage (img_out en sortie)
    img_fen_post =img_post_out.copy();
    QImage img_out = img_post_out.copy();
    img_out = img_out.scaledToWidth(ui->IMGPOST->width(), Qt::SmoothTransformation);
    img_out = img_out.scaledToHeight(ui->IMGPOST->height(), Qt::SmoothTransformation);
    ui->IMGPOST->setPixmap(QPixmap::fromImage(img_out));


    imgMat_freq_post = amplitude.clone();
    QImage img_freq_post_out(imgMat_freq_post.data, imgMat_freq_post.cols, imgMat_freq_post.rows, static_cast<int>(imgMat_freq_post.step), QImage::Format_Grayscale8); //Conversion mat->QImage (img_out en sortie)
    img_fen_freq_post =img_freq_post_out.copy();
    img_out = img_freq_post_out.copy();
    img_out = img_out.scaledToWidth(ui->FREQPOST->width(), Qt::SmoothTransformation);
    img_out = img_out.scaledToHeight(ui->FREQPOST->height(), Qt::SmoothTransformation);
    ui->FREQPOST->setPixmap(QPixmap::fromImage(img_out));
}


void frequentiel::on_SLIDRINFPB_sliderMoved(int position)
{
    QString text = QString("Rayon Inf. : %1").arg(position);
    ui->TXTLBLINF->setText(text);

    if (position >= ui->SLIDRSUPPB->value())
    {
        ui->SLIDRSUPPB->setValue(position);
        ui->SLIDRINFPB->setValue(position);
    }
    else
    {
        ui->SLIDRINFPB->setValue(position);
    }
    text = QString("Rayon Sup. : %1").arg(ui->SLIDRSUPPB->value());
    ui->TXTLBLSUP->setText(text);

    Mat amplitude = imgMat_freq_pre.clone();
    Mat im_filtree;
    vector<Mat> ReelImaginaire = { Mat::zeros(imgMat_pre.rows, imgMat_pre.cols, CV_64F), Mat::zeros(imgMat_pre.rows, imgMat_pre.cols, CV_64F) }; //Stockage de la partie réelle et imaginaire dans ce vecteur
    ReelImaginaire[0] = Reel.clone();
    ReelImaginaire[1] = Imag.clone();
    //Point centre(amplitude.cols / 2, amplitude.rows / 2); //Position du filtre (centre de l'image ici)


    //PASSE BANDE


    //Application du filtre sur l'amplitude pour la visualisation
    int R = sqrt((imgMat_pre.rows / 2) * (imgMat_pre.rows / 2) + (imgMat_pre.cols / 2) * (imgMat_pre.cols / 2)); //Rayon externe fixe pour le passe-bas. (Commence aux bords de l'image)
    R = 2*R;
    //int R1 = R/4;
    //int R2 = 3*R/4;

    int R1 = position;
    int R2 = ui->SLIDRSUPPB->value();
    int colonne = ui->SLIDXPBA->value();
    int ligne = ui->SLIDYPBA->value();

    Point centre(ligne,colonne); //Position du filtre (centre de l'image ici)

    circle(amplitude, centre, R, 0, 2 * R -1 - 2*R2); //Coupe-Bande : Passe-bas sur l'amplitude
    circle(amplitude, centre, R1, 0, -1); //Coupe-Bande : Passe-haut sur l'amplitude
    //Application du filtre sur la DFT
    //Il s'agit d'une somme entre un passe haut et un passe-bas

    circle(ReelImaginaire[0], centre, R, 0, 2*R-1-2*R2); //Passe-Bas sur la partie réelle
    circle(ReelImaginaire[1], centre, R, 0, 2*R-1-2*R2); //Passe-Bas sur la partie imaginaire
    circle(ReelImaginaire[0], centre, R1, 0, -1); //Passe-Haut sur la partie réelle
    circle(ReelImaginaire[1], centre, R1, 0, -1); //Passe-Haut sur la partie imaginaire

    //Décentrage de la DFT
    ReelImaginaire[0] = centrer_fft(ReelImaginaire[0]);
    ReelImaginaire[1] = centrer_fft(ReelImaginaire[1]);

    //Concaténation de la partie réelle et imaginaire dans une matrice à deux composantes (réel et complexe)
    merge(ReelImaginaire, im_filtree);

    //Calcul de la DFT inverse, normalisation et affichage
    im_filtree = inverse_fft_image(im_filtree); //TF Inverse
    //im_filtree.convertTo(im_filtree, CV_8UC1);
    normalize(im_filtree, im_filtree, 0, 255, NORM_MINMAX);

    imgMat_post = im_filtree.clone();

    QImage img_post_out(imgMat_post.data, imgMat_post.cols, imgMat_post.rows, static_cast<int>(imgMat_post.step), QImage::Format_Grayscale8); //Conversion mat->QImage (img_out en sortie)
    img_fen_post =img_post_out.copy();
    QImage img_out = img_post_out.copy();
    img_out = img_out.scaledToWidth(ui->IMGPOST->width(), Qt::SmoothTransformation);
    img_out = img_out.scaledToHeight(ui->IMGPOST->height(), Qt::SmoothTransformation);
    ui->IMGPOST->setPixmap(QPixmap::fromImage(img_out));


    imgMat_freq_post = amplitude.clone();
    QImage img_freq_post_out(imgMat_freq_post.data, imgMat_freq_post.cols, imgMat_freq_post.rows, static_cast<int>(imgMat_freq_post.step), QImage::Format_Grayscale8); //Conversion mat->QImage (img_out en sortie)
    img_fen_freq_post =img_freq_post_out.copy();
    img_out = img_freq_post_out.copy();
    img_out = img_out.scaledToWidth(ui->FREQPOST->width(), Qt::SmoothTransformation);
    img_out = img_out.scaledToHeight(ui->FREQPOST->height(), Qt::SmoothTransformation);
    ui->FREQPOST->setPixmap(QPixmap::fromImage(img_out));
}


void frequentiel::on_SLIDRSUPPB_sliderMoved(int position)
{
    QString text = QString("Rayon Sup. : %1").arg(position);
    ui->TXTLBLSUP->setText(text);

    if (position <= ui->SLIDRINFPB->value())
    {
        ui->SLIDRSUPPB->setValue(position);
        ui->SLIDRINFPB->setValue(position);
    }
    else
    {
        ui->SLIDRSUPPB->setValue(position);
    }

    text = QString("Rayon Inf. : %1").arg(ui->SLIDRINFPB->value());
    ui->TXTLBLINF->setText(text);

    Mat amplitude = imgMat_freq_pre.clone();
    Mat im_filtree;
    vector<Mat> ReelImaginaire = { Mat::zeros(imgMat_pre.rows, imgMat_pre.cols, CV_64F), Mat::zeros(imgMat_pre.rows, imgMat_pre.cols, CV_64F) }; //Stockage de la partie réelle et imaginaire dans ce vecteur
    ReelImaginaire[0] = Reel.clone();
    ReelImaginaire[1] = Imag.clone();
    //Point centre(amplitude.cols / 2, amplitude.rows / 2); //Position du filtre (centre de l'image ici)


    //PASSE BANDE


    //Application du filtre sur l'amplitude pour la visualisation
    int R = sqrt((imgMat_pre.rows / 2) * (imgMat_pre.rows / 2) + (imgMat_pre.cols / 2) * (imgMat_pre.cols / 2)); //Rayon externe fixe pour le passe-bas. (Commence aux bords de l'image)
    R = 2*R;
    //int R1 = R/4;
    //int R2 = 3*R/4;

    int R1 = ui->SLIDRINFPB->value();
    int R2 = position;
    int colonne = ui->SLIDXPBA->value();
    int ligne = ui->SLIDYPBA->value();

    Point centre(ligne,colonne); //Position du filtre (centre de l'image ici)

    circle(amplitude, centre, R, 0, 2 * R -1 - 2*R2); //Coupe-Bande : Passe-bas sur l'amplitude
    circle(amplitude, centre, R1, 0, -1); //Coupe-Bande : Passe-haut sur l'amplitude
    //Application du filtre sur la DFT
    //Il s'agit d'une somme entre un passe haut et un passe-bas

    circle(ReelImaginaire[0], centre, R, 0, 2*R-1-2*R2); //Passe-Bas sur la partie réelle
    circle(ReelImaginaire[1], centre, R, 0, 2*R-1-2*R2); //Passe-Bas sur la partie imaginaire
    circle(ReelImaginaire[0], centre, R1, 0, -1); //Passe-Haut sur la partie réelle
    circle(ReelImaginaire[1], centre, R1, 0, -1); //Passe-Haut sur la partie imaginaire

    //Décentrage de la DFT
    ReelImaginaire[0] = centrer_fft(ReelImaginaire[0]);
    ReelImaginaire[1] = centrer_fft(ReelImaginaire[1]);

    //Concaténation de la partie réelle et imaginaire dans une matrice à deux composantes (réel et complexe)
    merge(ReelImaginaire, im_filtree);

    //Calcul de la DFT inverse, normalisation et affichage
    im_filtree = inverse_fft_image(im_filtree); //TF Inverse
    //im_filtree.convertTo(im_filtree, CV_8UC1);
    normalize(im_filtree, im_filtree, 0, 255, NORM_MINMAX);

    imgMat_post = im_filtree.clone();

    QImage img_post_out(imgMat_post.data, imgMat_post.cols, imgMat_post.rows, static_cast<int>(imgMat_post.step), QImage::Format_Grayscale8); //Conversion mat->QImage (img_out en sortie)
    img_fen_post =img_post_out.copy();
    QImage img_out = img_post_out.copy();
    img_out = img_out.scaledToWidth(ui->IMGPOST->width(), Qt::SmoothTransformation);
    img_out = img_out.scaledToHeight(ui->IMGPOST->height(), Qt::SmoothTransformation);
    ui->IMGPOST->setPixmap(QPixmap::fromImage(img_out));


    imgMat_freq_post = amplitude.clone();
    QImage img_freq_post_out(imgMat_freq_post.data, imgMat_freq_post.cols, imgMat_freq_post.rows, static_cast<int>(imgMat_freq_post.step), QImage::Format_Grayscale8); //Conversion mat->QImage (img_out en sortie)
    img_fen_freq_post =img_freq_post_out.copy();
    img_out = img_freq_post_out.copy();
    img_out = img_out.scaledToWidth(ui->FREQPOST->width(), Qt::SmoothTransformation);
    img_out = img_out.scaledToHeight(ui->FREQPOST->height(), Qt::SmoothTransformation);
    ui->FREQPOST->setPixmap(QPixmap::fromImage(img_out));
}


void frequentiel::on_SLIDRINFCB_sliderMoved(int position)
{
    QString text = QString("Rayon Inf. : %1").arg(position);
    ui->TXTLBLINFCB->setText(text);

    if (position >= ui->SLIDRSUPCB->value())
    {
        ui->SLIDRSUPCB->setValue(position);
        ui->SLIDRINFCB->setValue(position);
    }
    else
    {
        ui->SLIDRINFCB->setValue(position);
    }
    text = QString("Rayon Sup. : %1").arg(ui->SLIDRSUPCB->value());
    ui->TXTLBLSUPCB->setText(text);

    int R1 = position;
    int R2 = ui->SLIDRSUPCB->value();
    int colonne = ui->SLIDYCB->value();
    int ligne = ui->SLIDXCB->value();

    Mat amplitude = imgMat_freq_pre.clone();
    Mat im_filtree;
    vector<Mat> ReelImaginaire = { Mat::zeros(imgMat_pre.rows, imgMat_pre.cols, CV_64F), Mat::zeros(imgMat_pre.rows, imgMat_pre.cols, CV_64F) }; //Stockage de la partie réelle et imaginaire dans ce vecteur
    ReelImaginaire[0] = Reel.clone();
    ReelImaginaire[1] = Imag.clone();
    Point centre(colonne,ligne); //Position du filtre (centre de l'image ici)

    int largeur = R2 - R1; //On calcule la relation entre les rayons R1 et R2, et la largeur
    int rayon = R1 + (int)((largeur) / 2); //Le rayon du cercle coupe bande sera le plus petit rayon auquel s'ajoute la moitié de la largeur du cercle.

    circle(amplitude, centre, rayon, 0, largeur); //Passe-Bande sur l'amplitude
    //Application du filtre sur la DFT

    circle(ReelImaginaire[0], centre, rayon, 0, largeur); //Passe-bande sur la partie réelle
    circle(ReelImaginaire[1], centre, rayon, 0, largeur); //Passe-bande sur la partie imaginaire

    //Décentrage de la DFT
    ReelImaginaire[0] = centrer_fft(ReelImaginaire[0]);
    ReelImaginaire[1] = centrer_fft(ReelImaginaire[1]);

    //Concaténation de la partie réelle et imaginaire dans une matrice à deux composantes (réel et complexe)
    merge(ReelImaginaire, im_filtree);

    //Calcul de la DFT inverse, normalisation et affichage
    im_filtree = inverse_fft_image(im_filtree); //TF Inverse
    //im_filtree.convertTo(im_filtree, CV_8UC1);
    normalize(im_filtree, im_filtree, 0, 255, NORM_MINMAX);

    imgMat_post = im_filtree.clone();

    QImage img_post_out(imgMat_post.data, imgMat_post.cols, imgMat_post.rows, static_cast<int>(imgMat_post.step), QImage::Format_Grayscale8); //Conversion mat->QImage (img_out en sortie)
    img_fen_post =img_post_out.copy();
    QImage img_out = img_post_out.copy();
    img_out = img_out.scaledToWidth(ui->IMGPOST->width(), Qt::SmoothTransformation);
    img_out = img_out.scaledToHeight(ui->IMGPOST->height(), Qt::SmoothTransformation);
    ui->IMGPOST->setPixmap(QPixmap::fromImage(img_out));


    imgMat_freq_post = amplitude.clone();
    QImage img_freq_post_out(imgMat_freq_post.data, imgMat_freq_post.cols, imgMat_freq_post.rows, static_cast<int>(imgMat_freq_post.step), QImage::Format_Grayscale8); //Conversion mat->QImage (img_out en sortie)
    img_fen_freq_post =img_freq_post_out.copy();
    img_out = img_freq_post_out.copy();
    img_out = img_out.scaledToWidth(ui->FREQPOST->width(), Qt::SmoothTransformation);
    img_out = img_out.scaledToHeight(ui->FREQPOST->height(), Qt::SmoothTransformation);
    ui->FREQPOST->setPixmap(QPixmap::fromImage(img_out));
}



void frequentiel::on_SLIDRSUPCB_sliderMoved(int position)
{
    QString text = QString("Rayon Sup. : %1").arg(position);
    ui->TXTLBLSUPCB->setText(text);

    if (position <= ui->SLIDRINFCB->value())
    {
        ui->SLIDRSUPCB->setValue(position);
        ui->SLIDRINFCB->setValue(position);
    }
    else
    {
        ui->SLIDRSUPCB->setValue(position);
    }

    text = QString("Rayon Inf. : %1").arg(ui->SLIDRINFCB->value());
    ui->TXTLBLINFCB->setText(text);

    int R1 = ui->SLIDRINFCB->value();
    int R2 = position;
    int colonne = ui->SLIDYCB->value();
    int ligne = ui->SLIDXCB->value();

    Mat amplitude = imgMat_freq_pre.clone();
    Mat im_filtree;
    vector<Mat> ReelImaginaire = { Mat::zeros(imgMat_pre.rows, imgMat_pre.cols, CV_64F), Mat::zeros(imgMat_pre.rows, imgMat_pre.cols, CV_64F) }; //Stockage de la partie réelle et imaginaire dans ce vecteur
    ReelImaginaire[0] = Reel.clone();
    ReelImaginaire[1] = Imag.clone();

    Point centre(colonne,ligne); //Position du filtre (centre de l'image ici)

    int largeur = R2 - R1; //On calcule la relation entre les rayons R1 et R2, et la largeur
    int rayon = R1 + (int)((largeur) / 2); //Le rayon du cercle coupe bande sera le plus petit rayon auquel s'ajoute la moitié de la largeur du cercle.

    circle(amplitude, centre, rayon, 0, largeur); //Passe-Bande sur l'amplitude
    //Application du filtre sur la DFT

    circle(ReelImaginaire[0], centre, rayon, 0, largeur); //Passe-bande sur la partie réelle
    circle(ReelImaginaire[1], centre, rayon, 0, largeur); //Passe-bande sur la partie imaginaire

    //Décentrage de la DFT
    ReelImaginaire[0] = centrer_fft(ReelImaginaire[0]);
    ReelImaginaire[1] = centrer_fft(ReelImaginaire[1]);

    //Concaténation de la partie réelle et imaginaire dans une matrice à deux composantes (réel et complexe)
    merge(ReelImaginaire, im_filtree);

    //Calcul de la DFT inverse, normalisation et affichage
    im_filtree = inverse_fft_image(im_filtree); //TF Inverse
    //im_filtree.convertTo(im_filtree, CV_8UC1);
    normalize(im_filtree, im_filtree, 0, 255, NORM_MINMAX);

    imgMat_post = im_filtree.clone();

    QImage img_post_out(imgMat_post.data, imgMat_post.cols, imgMat_post.rows, static_cast<int>(imgMat_post.step), QImage::Format_Grayscale8); //Conversion mat->QImage (img_out en sortie)
    img_fen_post =img_post_out.copy();
    QImage img_out = img_post_out.copy();
    img_out = img_out.scaledToWidth(ui->IMGPOST->width(), Qt::SmoothTransformation);
    img_out = img_out.scaledToHeight(ui->IMGPOST->height(), Qt::SmoothTransformation);
    ui->IMGPOST->setPixmap(QPixmap::fromImage(img_out));


    imgMat_freq_post = amplitude.clone();
    QImage img_freq_post_out(imgMat_freq_post.data, imgMat_freq_post.cols, imgMat_freq_post.rows, static_cast<int>(imgMat_freq_post.step), QImage::Format_Grayscale8); //Conversion mat->QImage (img_out en sortie)
    img_fen_freq_post =img_freq_post_out.copy();
    img_out = img_freq_post_out.copy();
    img_out = img_out.scaledToWidth(ui->FREQPOST->width(), Qt::SmoothTransformation);
    img_out = img_out.scaledToHeight(ui->FREQPOST->height(), Qt::SmoothTransformation);
    ui->FREQPOST->setPixmap(QPixmap::fromImage(img_out));

}




void frequentiel::on_SLIDXCB_sliderMoved(int position)
{
    QString text = QString("Y : %1").arg(position);
    ui->XCB->setText(text);

    int R1 = ui->SLIDRINFCB->value();
    int R2 = ui->SLIDRSUPCB->value();
    int ligne = position;
    int colonne = ui->SLIDYCB->value() ;

    Mat amplitude = imgMat_freq_pre.clone();
    Mat im_filtree;
    vector<Mat> ReelImaginaire = { Mat::zeros(imgMat_pre.rows, imgMat_pre.cols, CV_64F), Mat::zeros(imgMat_pre.rows, imgMat_pre.cols, CV_64F) }; //Stockage de la partie réelle et imaginaire dans ce vecteur
    ReelImaginaire[0] = Reel.clone();
    ReelImaginaire[1] = Imag.clone();
    Point centre(colonne,ligne); //Position du filtre (centre de l'image ici)

    int largeur = R2 - R1; //On calcule la relation entre les rayons R1 et R2, et la largeur
    int rayon = R1 + (int)((largeur) / 2); //Le rayon du cercle coupe bande sera le plus petit rayon auquel s'ajoute la moitié de la largeur du cercle.

    circle(amplitude, centre, rayon, 0, largeur); //Passe-Bande sur l'amplitude
    //Application du filtre sur la DFT

    circle(ReelImaginaire[0], centre, rayon, 0, largeur); //Passe-bande sur la partie réelle
    circle(ReelImaginaire[1], centre, rayon, 0, largeur); //Passe-bande sur la partie imaginaire

    //Décentrage de la DFT
    ReelImaginaire[0] = centrer_fft(ReelImaginaire[0]);
    ReelImaginaire[1] = centrer_fft(ReelImaginaire[1]);

    //Concaténation de la partie réelle et imaginaire dans une matrice à deux composantes (réel et complexe)
    merge(ReelImaginaire, im_filtree);

    //Calcul de la DFT inverse, normalisation et affichage
    im_filtree = inverse_fft_image(im_filtree); //TF Inverse
    //im_filtree.convertTo(im_filtree, CV_8UC1);
    normalize(im_filtree, im_filtree, 0, 255, NORM_MINMAX);

    imgMat_post = im_filtree.clone();

    QImage img_post_out(imgMat_post.data, imgMat_post.cols, imgMat_post.rows, static_cast<int>(imgMat_post.step), QImage::Format_Grayscale8); //Conversion mat->QImage (img_out en sortie)
    img_fen_post =img_post_out.copy();
    QImage img_out = img_post_out.copy();
    img_out = img_out.scaledToWidth(ui->IMGPOST->width(), Qt::SmoothTransformation);
    img_out = img_out.scaledToHeight(ui->IMGPOST->height(), Qt::SmoothTransformation);
    ui->IMGPOST->setPixmap(QPixmap::fromImage(img_out));


    imgMat_freq_post = amplitude.clone();
    QImage img_freq_post_out(imgMat_freq_post.data, imgMat_freq_post.cols, imgMat_freq_post.rows, static_cast<int>(imgMat_freq_post.step), QImage::Format_Grayscale8); //Conversion mat->QImage (img_out en sortie)
    img_fen_freq_post =img_freq_post_out.copy();
    img_out = img_freq_post_out.copy();
    img_out = img_out.scaledToWidth(ui->FREQPOST->width(), Qt::SmoothTransformation);
    img_out = img_out.scaledToHeight(ui->FREQPOST->height(), Qt::SmoothTransformation);
    ui->FREQPOST->setPixmap(QPixmap::fromImage(img_out));
}


void frequentiel::on_SLIDYCB_sliderMoved(int position)
{
    QString text = QString("X : %1").arg(position);
    ui->YCB->setText(text);

    int R1 = ui->SLIDRINFCB->value();
    int R2 = ui->SLIDRSUPCB->value();
    int ligne = ui->SLIDXCB->value();
    int colonne = position ;

    Mat amplitude = imgMat_freq_pre.clone();
    Mat im_filtree;
    vector<Mat> ReelImaginaire = { Mat::zeros(imgMat_pre.rows, imgMat_pre.cols, CV_64F), Mat::zeros(imgMat_pre.rows, imgMat_pre.cols, CV_64F) }; //Stockage de la partie réelle et imaginaire dans ce vecteur
    ReelImaginaire[0] = Reel.clone();
    ReelImaginaire[1] = Imag.clone();
    Point centre(colonne,ligne); //Position du filtre (centre de l'image ici)

    int largeur = R2 - R1; //On calcule la relation entre les rayons R1 et R2, et la largeur
    int rayon = R1 + (int)((largeur) / 2); //Le rayon du cercle coupe bande sera le plus petit rayon auquel s'ajoute la moitié de la largeur du cercle.

    circle(amplitude, centre, rayon, 0, largeur); //Passe-Bande sur l'amplitude
    //Application du filtre sur la DFT

    circle(ReelImaginaire[0], centre, rayon, 0, largeur); //Passe-bande sur la partie réelle
    circle(ReelImaginaire[1], centre, rayon, 0, largeur); //Passe-bande sur la partie imaginaire

    //Décentrage de la DFT
    ReelImaginaire[0] = centrer_fft(ReelImaginaire[0]);
    ReelImaginaire[1] = centrer_fft(ReelImaginaire[1]);

    //Concaténation de la partie réelle et imaginaire dans une matrice à deux composantes (réel et complexe)
    merge(ReelImaginaire, im_filtree);

    //Calcul de la DFT inverse, normalisation et affichage
    im_filtree = inverse_fft_image(im_filtree); //TF Inverse
    //im_filtree.convertTo(im_filtree, CV_8UC1);
    normalize(im_filtree, im_filtree, 0, 255, NORM_MINMAX);

    imgMat_post = im_filtree.clone();

    QImage img_post_out(imgMat_post.data, imgMat_post.cols, imgMat_post.rows, static_cast<int>(imgMat_post.step), QImage::Format_Grayscale8); //Conversion mat->QImage (img_out en sortie)
    img_fen_post =img_post_out.copy();
    QImage img_out = img_post_out.copy();
    img_out = img_out.scaledToWidth(ui->IMGPOST->width(), Qt::SmoothTransformation);
    img_out = img_out.scaledToHeight(ui->IMGPOST->height(), Qt::SmoothTransformation);
    ui->IMGPOST->setPixmap(QPixmap::fromImage(img_out));


    imgMat_freq_post = amplitude.clone();
    QImage img_freq_post_out(imgMat_freq_post.data, imgMat_freq_post.cols, imgMat_freq_post.rows, static_cast<int>(imgMat_freq_post.step), QImage::Format_Grayscale8); //Conversion mat->QImage (img_out en sortie)
    img_fen_freq_post =img_freq_post_out.copy();
    img_out = img_freq_post_out.copy();
    img_out = img_out.scaledToWidth(ui->FREQPOST->width(), Qt::SmoothTransformation);
    img_out = img_out.scaledToHeight(ui->FREQPOST->height(), Qt::SmoothTransformation);
    ui->FREQPOST->setPixmap(QPixmap::fromImage(img_out));
}


void frequentiel::on_SLIDXPBA_sliderMoved(int position)
{
    QString text = QString("Y : %1").arg(position);
    ui->XPBA->setText(text);

    int R1 = ui->SLIDRINFPB->value();
    int R2 = ui->SLIDRSUPPB->value();
    int ligne = ui->SLIDYPBA->value();
    int colonne = position ;

    Mat amplitude = imgMat_freq_pre.clone();
    Mat im_filtree;
    vector<Mat> ReelImaginaire = { Mat::zeros(imgMat_pre.rows, imgMat_pre.cols, CV_64F), Mat::zeros(imgMat_pre.rows, imgMat_pre.cols, CV_64F) }; //Stockage de la partie réelle et imaginaire dans ce vecteur
    ReelImaginaire[0] = Reel.clone();
    ReelImaginaire[1] = Imag.clone();
    Point centre(ligne,colonne); //Position du filtre (centre de l'image ici)



    int R = sqrt((imgMat_pre.rows / 2) * (imgMat_pre.rows / 2) + (imgMat_pre.cols / 2) * (imgMat_pre.cols / 2)); //Rayon externe fixe pour le passe-bas. (Commence aux bords de l'image)
    R = 2*R;
    //int R1 = R/4;
    //int R2 = 3*R/4;

    circle(amplitude, centre, R, 0, 2 * R -1 - 2*R2); //Coupe-Bande : Passe-bas sur l'amplitude
    circle(amplitude, centre, R1, 0, -1); //Coupe-Bande : Passe-haut sur l'amplitude
    //Application du filtre sur la DFT
    //Il s'agit d'une somme entre un passe haut et un passe-bas

    circle(ReelImaginaire[0], centre, R, 0, 2*R-1-2*R2); //Passe-Bas sur la partie réelle
    circle(ReelImaginaire[1], centre, R, 0, 2*R-1-2*R2); //Passe-Bas sur la partie imaginaire
    circle(ReelImaginaire[0], centre, R1, 0, -1); //Passe-Haut sur la partie réelle
    circle(ReelImaginaire[1], centre, R1, 0, -1); //Passe-Haut sur la partie imaginaire

    //Décentrage de la DFT
    ReelImaginaire[0] = centrer_fft(ReelImaginaire[0]);
    ReelImaginaire[1] = centrer_fft(ReelImaginaire[1]);

    //Concaténation de la partie réelle et imaginaire dans une matrice à deux composantes (réel et complexe)
    merge(ReelImaginaire, im_filtree);

    //Calcul de la DFT inverse, normalisation et affichage
    im_filtree = inverse_fft_image(im_filtree); //TF Inverse
    //im_filtree.convertTo(im_filtree, CV_8UC1);
    normalize(im_filtree, im_filtree, 0, 255, NORM_MINMAX);

    imgMat_post = im_filtree.clone();

    QImage img_post_out(imgMat_post.data, imgMat_post.cols, imgMat_post.rows, static_cast<int>(imgMat_post.step), QImage::Format_Grayscale8); //Conversion mat->QImage (img_out en sortie)
    img_fen_post =img_post_out.copy();
    QImage img_out = img_post_out.copy();
    img_out = img_out.scaledToWidth(ui->IMGPOST->width(), Qt::SmoothTransformation);
    img_out = img_out.scaledToHeight(ui->IMGPOST->height(), Qt::SmoothTransformation);
    ui->IMGPOST->setPixmap(QPixmap::fromImage(img_out));


    imgMat_freq_post = amplitude.clone();
    QImage img_freq_post_out(imgMat_freq_post.data, imgMat_freq_post.cols, imgMat_freq_post.rows, static_cast<int>(imgMat_freq_post.step), QImage::Format_Grayscale8); //Conversion mat->QImage (img_out en sortie)
    img_fen_freq_post =img_freq_post_out.copy();
    img_out = img_freq_post_out.copy();
    img_out = img_out.scaledToWidth(ui->FREQPOST->width(), Qt::SmoothTransformation);
    img_out = img_out.scaledToHeight(ui->FREQPOST->height(), Qt::SmoothTransformation);
    ui->FREQPOST->setPixmap(QPixmap::fromImage(img_out));
}


void frequentiel::on_SLIDYPBA_sliderMoved(int position)
{
    QString text = QString("X : %1").arg(position);
    ui->YPBA->setText(text);

    int R1 = ui->SLIDRINFPB->value();
    int R2 = ui->SLIDRSUPPB->value();
    int ligne = position;
    int colonne = ui->SLIDXPBA->value();

    Mat amplitude = imgMat_freq_pre.clone();
    Mat im_filtree;
    vector<Mat> ReelImaginaire = { Mat::zeros(imgMat_pre.rows, imgMat_pre.cols, CV_64F), Mat::zeros(imgMat_pre.rows, imgMat_pre.cols, CV_64F) }; //Stockage de la partie réelle et imaginaire dans ce vecteur
    ReelImaginaire[0] = Reel.clone();
    ReelImaginaire[1] = Imag.clone();
    Point centre(ligne,colonne); //Position du filtre (centre de l'image ici)



    int R = sqrt((imgMat_pre.rows / 2) * (imgMat_pre.rows / 2) + (imgMat_pre.cols / 2) * (imgMat_pre.cols / 2)); //Rayon externe fixe pour le passe-bas. (Commence aux bords de l'image)
    R = 2*R;
    //int R1 = R/4;
    //int R2 = 3*R/4;

    circle(amplitude, centre, R, 0, 2 * R -1 - 2*R2); //Coupe-Bande : Passe-bas sur l'amplitude
    circle(amplitude, centre, R1, 0, -1); //Coupe-Bande : Passe-haut sur l'amplitude
    //Application du filtre sur la DFT
    //Il s'agit d'une somme entre un passe haut et un passe-bas

    circle(ReelImaginaire[0], centre, R, 0, 2*R-1-2*R2); //Passe-Bas sur la partie réelle
    circle(ReelImaginaire[1], centre, R, 0, 2*R-1-2*R2); //Passe-Bas sur la partie imaginaire
    circle(ReelImaginaire[0], centre, R1, 0, -1); //Passe-Haut sur la partie réelle
    circle(ReelImaginaire[1], centre, R1, 0, -1); //Passe-Haut sur la partie imaginaire

    //Décentrage de la DFT
    ReelImaginaire[0] = centrer_fft(ReelImaginaire[0]);
    ReelImaginaire[1] = centrer_fft(ReelImaginaire[1]);

    //Concaténation de la partie réelle et imaginaire dans une matrice à deux composantes (réel et complexe)
    merge(ReelImaginaire, im_filtree);

    //Calcul de la DFT inverse, normalisation et affichage
    im_filtree = inverse_fft_image(im_filtree); //TF Inverse
    //im_filtree.convertTo(im_filtree, CV_8UC1);
    normalize(im_filtree, im_filtree, 0, 255, NORM_MINMAX);

    imgMat_post = im_filtree.clone();

    QImage img_post_out(imgMat_post.data, imgMat_post.cols, imgMat_post.rows, static_cast<int>(imgMat_post.step), QImage::Format_Grayscale8); //Conversion mat->QImage (img_out en sortie)
    img_fen_post =img_post_out.copy();
    QImage img_out = img_post_out.copy();
    img_out = img_out.scaledToWidth(ui->IMGPOST->width(), Qt::SmoothTransformation);
    img_out = img_out.scaledToHeight(ui->IMGPOST->height(), Qt::SmoothTransformation);
    ui->IMGPOST->setPixmap(QPixmap::fromImage(img_out));


    imgMat_freq_post = amplitude.clone();
    QImage img_freq_post_out(imgMat_freq_post.data, imgMat_freq_post.cols, imgMat_freq_post.rows, static_cast<int>(imgMat_freq_post.step), QImage::Format_Grayscale8); //Conversion mat->QImage (img_out en sortie)
    img_fen_freq_post =img_freq_post_out.copy();
    img_out = img_freq_post_out.copy();
    img_out = img_out.scaledToWidth(ui->FREQPOST->width(), Qt::SmoothTransformation);
    img_out = img_out.scaledToHeight(ui->FREQPOST->height(), Qt::SmoothTransformation);
    ui->FREQPOST->setPixmap(QPixmap::fromImage(img_out));
}


void frequentiel::on_SLIDXPH_sliderMoved(int position)
{
    QString text = QString("Y : %1").arg(position);
    ui->XPH->setText(text);

    int ligne = ui->SLIDYPH->value();
    int colonne = position;

    Mat amplitude = imgMat_freq_pre.clone();
    Mat im_filtree;
    vector<Mat> ReelImaginaire = { Mat::zeros(imgMat_pre.rows, imgMat_pre.cols, CV_64F), Mat::zeros(imgMat_pre.rows, imgMat_pre.cols, CV_64F) }; //Stockage de la partie réelle et imaginaire dans ce vecteur
    ReelImaginaire[0] = Reel.clone();
    ReelImaginaire[1] = Imag.clone();

    Point centre(ligne, colonne); //Position du filtre (centre de l'image ici)
    //int R = sqrt((imgMat_pre.rows / 2) * (imgMat_pre.rows / 2) + (imgMat_pre.cols / 2) * (imgMat_pre.cols / 2)); //Rayon externe fixe pour le passe-bas. (Commence aux bords de l'image)
    int rayon = ui->SLIDPH->value();
    circle(amplitude, centre, rayon, 0, -1); //Passe-Haut sur l'amplitude
    circle(ReelImaginaire[0], centre, rayon, 0, -1); //Passe-haut sur la partie réelle
    circle(ReelImaginaire[1], centre, rayon, 0, -1); //Passe-haut sur la partie imaginaire

    //Décentrage de la DFT
    ReelImaginaire[0] = centrer_fft(ReelImaginaire[0]);
    ReelImaginaire[1] = centrer_fft(ReelImaginaire[1]);

    //Concaténation de la partie réelle et imaginaire dans une matrice à deux composantes (réel et complexe)
    merge(ReelImaginaire, im_filtree);

    //Calcul de la DFT inverse, normalisation et affichage
    im_filtree = inverse_fft_image(im_filtree); //TF Inverse
    //im_filtree.convertTo(im_filtree, CV_8UC1);
    normalize(im_filtree, im_filtree, 0, 255, NORM_MINMAX);

    imgMat_post = im_filtree.clone();

    QImage img_post_out(imgMat_post.data, imgMat_post.cols, imgMat_post.rows, static_cast<int>(imgMat_post.step), QImage::Format_Grayscale8); //Conversion mat->QImage (img_out en sortie)
    img_fen_post =img_post_out.copy();
    QImage img_out = img_post_out.copy();
    img_out = img_out.scaledToWidth(ui->IMGPOST->width(), Qt::SmoothTransformation);
    img_out = img_out.scaledToHeight(ui->IMGPOST->height(), Qt::SmoothTransformation);
    ui->IMGPOST->setPixmap(QPixmap::fromImage(img_out));


    imgMat_freq_post = amplitude.clone();
    QImage img_freq_post_out(imgMat_freq_post.data, imgMat_freq_post.cols, imgMat_freq_post.rows, static_cast<int>(imgMat_freq_post.step), QImage::Format_Grayscale8); //Conversion mat->QImage (img_out en sortie)
    img_fen_freq_post =img_freq_post_out.copy();
    img_out = img_freq_post_out.copy();
    img_out = img_out.scaledToWidth(ui->FREQPOST->width(), Qt::SmoothTransformation);
    img_out = img_out.scaledToHeight(ui->FREQPOST->height(), Qt::SmoothTransformation);
    ui->FREQPOST->setPixmap(QPixmap::fromImage(img_out));
}


void frequentiel::on_SLIDYPH_sliderMoved(int position)
{
    QString text = QString("X : %1").arg(position);
    ui->YPH->setText(text);

    int ligne = position;
    int colonne = ui->SLIDXPH->value();

    Mat amplitude = imgMat_freq_pre.clone();
    Mat im_filtree;
    vector<Mat> ReelImaginaire = { Mat::zeros(imgMat_pre.rows, imgMat_pre.cols, CV_64F), Mat::zeros(imgMat_pre.rows, imgMat_pre.cols, CV_64F) }; //Stockage de la partie réelle et imaginaire dans ce vecteur
    ReelImaginaire[0] = Reel.clone();
    ReelImaginaire[1] = Imag.clone();

    Point centre(ligne, colonne); //Position du filtre (centre de l'image ici)
    //int R = sqrt((imgMat_pre.rows / 2) * (imgMat_pre.rows / 2) + (imgMat_pre.cols / 2) * (imgMat_pre.cols / 2)); //Rayon externe fixe pour le passe-bas. (Commence aux bords de l'image)
    int rayon = ui->SLIDPH->value();
    circle(amplitude, centre, rayon, 0, -1); //Passe-Haut sur l'amplitude
    circle(ReelImaginaire[0], centre, rayon, 0, -1); //Passe-haut sur la partie réelle
    circle(ReelImaginaire[1], centre, rayon, 0, -1); //Passe-haut sur la partie imaginaire

    //Décentrage de la DFT
    ReelImaginaire[0] = centrer_fft(ReelImaginaire[0]);
    ReelImaginaire[1] = centrer_fft(ReelImaginaire[1]);

    //Concaténation de la partie réelle et imaginaire dans une matrice à deux composantes (réel et complexe)
    merge(ReelImaginaire, im_filtree);

    //Calcul de la DFT inverse, normalisation et affichage
    im_filtree = inverse_fft_image(im_filtree); //TF Inverse
    //im_filtree.convertTo(im_filtree, CV_8UC1);
    normalize(im_filtree, im_filtree, 0, 255, NORM_MINMAX);

    imgMat_post = im_filtree.clone();

    QImage img_post_out(imgMat_post.data, imgMat_post.cols, imgMat_post.rows, static_cast<int>(imgMat_post.step), QImage::Format_Grayscale8); //Conversion mat->QImage (img_out en sortie)
    img_fen_post =img_post_out.copy();
    QImage img_out = img_post_out.copy();
    img_out = img_out.scaledToWidth(ui->IMGPOST->width(), Qt::SmoothTransformation);
    img_out = img_out.scaledToHeight(ui->IMGPOST->height(), Qt::SmoothTransformation);
    ui->IMGPOST->setPixmap(QPixmap::fromImage(img_out));


    imgMat_freq_post = amplitude.clone();
    QImage img_freq_post_out(imgMat_freq_post.data, imgMat_freq_post.cols, imgMat_freq_post.rows, static_cast<int>(imgMat_freq_post.step), QImage::Format_Grayscale8); //Conversion mat->QImage (img_out en sortie)
    img_fen_freq_post =img_freq_post_out.copy();
    img_out = img_freq_post_out.copy();
    img_out = img_out.scaledToWidth(ui->FREQPOST->width(), Qt::SmoothTransformation);
    img_out = img_out.scaledToHeight(ui->FREQPOST->height(), Qt::SmoothTransformation);
    ui->FREQPOST->setPixmap(QPixmap::fromImage(img_out));
}

void frequentiel::on_SLIDPB_sliderMoved(int position)
{
    QString text = QString("Rayon : %1").arg(position);
    ui->TXTSLIDPB->setText(text);
    Mat amplitude = imgMat_freq_pre.clone();
    Mat im_filtree;
    vector<Mat> ReelImaginaire = { Mat::zeros(imgMat_pre.rows, imgMat_pre.cols, CV_64F), Mat::zeros(imgMat_pre.rows, imgMat_pre.cols, CV_64F) }; //Stockage de la partie réelle et imaginaire dans ce vecteur
    ReelImaginaire[0] = Reel.clone();
    ReelImaginaire[1] = Imag.clone();

    int ligne = ui->SLIDXPB->value();
    int colonne = ui->SLIDYPB->value();

    Point centre(colonne, ligne); //Position du filtre (centre de l'image ici)
    int R = sqrt((imgMat_pre.rows / 2) * (imgMat_pre.rows / 2) + (imgMat_pre.cols / 2) * (imgMat_pre.cols / 2)); //Rayon externe fixe pour le passe-bas. (Commence aux bords de l'image)
    R = 2*R;
    int rayon = position;
    circle(amplitude, centre, R, 0, 2 * R - rayon); //Passe-Bas sur l'amplitude
    circle(ReelImaginaire[0], centre, R, 0, 2 * R - rayon); //Passe-Bas sur la partie réelle
    circle(ReelImaginaire[1], centre, R, 0, 2 * R - rayon); //Passe-Bas sur la partie imaginaire

    //Décentrage de la DFT
    ReelImaginaire[0] = centrer_fft(ReelImaginaire[0]);
    ReelImaginaire[1] = centrer_fft(ReelImaginaire[1]);

    //Concaténation de la partie réelle et imaginaire dans une matrice à deux composantes (réel et complexe)
    merge(ReelImaginaire, im_filtree);

    //Calcul de la DFT inverse, normalisation et affichage
    im_filtree = inverse_fft_image(im_filtree); //TF Inverse
    //im_filtree.convertTo(im_filtree, CV_8UC1);
    normalize(im_filtree, im_filtree, 0, 255, NORM_MINMAX);

    imgMat_post = im_filtree.clone();

    QImage img_post_out(imgMat_post.data, imgMat_post.cols, imgMat_post.rows, static_cast<int>(imgMat_post.step), QImage::Format_Grayscale8); //Conversion mat->QImage (img_out en sortie)
    img_fen_post =img_post_out.copy();
    QImage img_out = img_post_out.copy();
    img_out = img_out.scaledToWidth(ui->IMGPOST->width(), Qt::SmoothTransformation);
    img_out = img_out.scaledToHeight(ui->IMGPOST->height(), Qt::SmoothTransformation);
    ui->IMGPOST->setPixmap(QPixmap::fromImage(img_out));


    imgMat_freq_post = amplitude.clone();
    QImage img_freq_post_out(imgMat_freq_post.data, imgMat_freq_post.cols, imgMat_freq_post.rows, static_cast<int>(imgMat_freq_post.step), QImage::Format_Grayscale8); //Conversion mat->QImage (img_out en sortie)
    img_fen_freq_post =img_freq_post_out.copy();
    img_out = img_freq_post_out.copy();
    img_out = img_out.scaledToWidth(ui->FREQPOST->width(), Qt::SmoothTransformation);
    img_out = img_out.scaledToHeight(ui->FREQPOST->height(), Qt::SmoothTransformation);
    ui->FREQPOST->setPixmap(QPixmap::fromImage(img_out));

}

void frequentiel::on_SLIDXPB_sliderMoved(int position)
{
    QString text = QString("Y : %1").arg(position);
    ui->XPB->setText(text);

    int ligne = ui->SLIDYPB->value();
    int colonne = position;

    Mat amplitude = imgMat_freq_pre.clone();
    Mat im_filtree;
    vector<Mat> ReelImaginaire = { Mat::zeros(imgMat_pre.rows, imgMat_pre.cols, CV_64F), Mat::zeros(imgMat_pre.rows, imgMat_pre.cols, CV_64F) }; //Stockage de la partie réelle et imaginaire dans ce vecteur
    ReelImaginaire[0] = Reel.clone();
    ReelImaginaire[1] = Imag.clone();

    Point centre(ligne, colonne); //Position du filtre (centre de l'image ici)
    int rayon = ui->SLIDPB->value();
    int R = sqrt((imgMat_pre.rows / 2) * (imgMat_pre.rows / 2) + (imgMat_pre.cols / 2) * (imgMat_pre.cols / 2)); //Rayon externe fixe pour le passe-bas. (Commence aux bords de l'image)
    R = 2*R;

    circle(amplitude, centre, R, 0, 2 * R - rayon); //Passe-Bas sur l'amplitude
    circle(ReelImaginaire[0], centre, R, 0, 2 * R - rayon); //Passe-Bas sur la partie réelle
    circle(ReelImaginaire[1], centre, R, 0, 2 * R - rayon); //Passe-Bas sur la partie imaginaire

    //Décentrage de la DFT
    ReelImaginaire[0] = centrer_fft(ReelImaginaire[0]);
    ReelImaginaire[1] = centrer_fft(ReelImaginaire[1]);

    //Concaténation de la partie réelle et imaginaire dans une matrice à deux composantes (réel et complexe)
    merge(ReelImaginaire, im_filtree);

    //Calcul de la DFT inverse, normalisation et affichage
    im_filtree = inverse_fft_image(im_filtree); //TF Inverse
    //im_filtree.convertTo(im_filtree, CV_8UC1);
    normalize(im_filtree, im_filtree, 0, 255, NORM_MINMAX);

    imgMat_post = im_filtree.clone();

    QImage img_post_out(imgMat_post.data, imgMat_post.cols, imgMat_post.rows, static_cast<int>(imgMat_post.step), QImage::Format_Grayscale8); //Conversion mat->QImage (img_out en sortie)
    img_fen_post =img_post_out.copy();
    QImage img_out = img_post_out.copy();
    img_out = img_out.scaledToWidth(ui->IMGPOST->width(), Qt::SmoothTransformation);
    img_out = img_out.scaledToHeight(ui->IMGPOST->height(), Qt::SmoothTransformation);
    ui->IMGPOST->setPixmap(QPixmap::fromImage(img_out));


    imgMat_freq_post = amplitude.clone();
    QImage img_freq_post_out(imgMat_freq_post.data, imgMat_freq_post.cols, imgMat_freq_post.rows, static_cast<int>(imgMat_freq_post.step), QImage::Format_Grayscale8); //Conversion mat->QImage (img_out en sortie)
    img_fen_freq_post =img_freq_post_out.copy();
    img_out = img_freq_post_out.copy();
    img_out = img_out.scaledToWidth(ui->FREQPOST->width(), Qt::SmoothTransformation);
    img_out = img_out.scaledToHeight(ui->FREQPOST->height(), Qt::SmoothTransformation);
    ui->FREQPOST->setPixmap(QPixmap::fromImage(img_out));
}


void frequentiel::on_SLIDYPB_sliderMoved(int position)
{
    QString text = QString("X : %1").arg(position);
    ui->YPB->setText(text);

    int ligne = position;
    int colonne = ui->SLIDXPB->value();

    Mat amplitude = imgMat_freq_pre.clone();
    Mat im_filtree;
    vector<Mat> ReelImaginaire = { Mat::zeros(imgMat_pre.rows, imgMat_pre.cols, CV_64F), Mat::zeros(imgMat_pre.rows, imgMat_pre.cols, CV_64F) }; //Stockage de la partie réelle et imaginaire dans ce vecteur
    ReelImaginaire[0] = Reel.clone();
    ReelImaginaire[1] = Imag.clone();

    Point centre(ligne, colonne); //Position du filtre (centre de l'image ici)
    int rayon = ui->SLIDPB->value();
    int R = sqrt((imgMat_pre.rows / 2) * (imgMat_pre.rows / 2) + (imgMat_pre.cols / 2) * (imgMat_pre.cols / 2)); //Rayon externe fixe pour le passe-bas. (Commence aux bords de l'image)
    R = 2*R;

    circle(amplitude, centre, R, 0, 2 * R - rayon); //Passe-Bas sur l'amplitude
    circle(ReelImaginaire[0], centre, R, 0, 2 * R - rayon); //Passe-Bas sur la partie réelle
    circle(ReelImaginaire[1], centre, R, 0, 2 * R - rayon); //Passe-Bas sur la partie imaginaire

    //Décentrage de la DFT
    ReelImaginaire[0] = centrer_fft(ReelImaginaire[0]);
    ReelImaginaire[1] = centrer_fft(ReelImaginaire[1]);

    //Concaténation de la partie réelle et imaginaire dans une matrice à deux composantes (réel et complexe)
    merge(ReelImaginaire, im_filtree);

    //Calcul de la DFT inverse, normalisation et affichage
    im_filtree = inverse_fft_image(im_filtree); //TF Inverse
    //im_filtree.convertTo(im_filtree, CV_8UC1);
    normalize(im_filtree, im_filtree, 0, 255, NORM_MINMAX);

    imgMat_post = im_filtree.clone();

    QImage img_post_out(imgMat_post.data, imgMat_post.cols, imgMat_post.rows, static_cast<int>(imgMat_post.step), QImage::Format_Grayscale8); //Conversion mat->QImage (img_out en sortie)
    img_fen_post =img_post_out.copy();
    QImage img_out = img_post_out.copy();
    img_out = img_out.scaledToWidth(ui->IMGPOST->width(), Qt::SmoothTransformation);
    img_out = img_out.scaledToHeight(ui->IMGPOST->height(), Qt::SmoothTransformation);
    ui->IMGPOST->setPixmap(QPixmap::fromImage(img_out));


    imgMat_freq_post = amplitude.clone();
    QImage img_freq_post_out(imgMat_freq_post.data, imgMat_freq_post.cols, imgMat_freq_post.rows, static_cast<int>(imgMat_freq_post.step), QImage::Format_Grayscale8); //Conversion mat->QImage (img_out en sortie)
    img_fen_freq_post =img_freq_post_out.copy();
    img_out = img_freq_post_out.copy();
    img_out = img_out.scaledToWidth(ui->FREQPOST->width(), Qt::SmoothTransformation);
    img_out = img_out.scaledToHeight(ui->FREQPOST->height(), Qt::SmoothTransformation);
    ui->FREQPOST->setPixmap(QPixmap::fromImage(img_out));
}

void frequentiel::resizeEvent(QResizeEvent *event)
{
    QDialog::resizeEvent(event);
    int w = ui->IMGPRE->width();
    int h = ui->IMGPRE->height();

    //Affichage de l'image avant tr
    QImage img_out_pre = img_fen_pre.copy();
    img_out_pre = img_out_pre.scaledToWidth(ui->IMGPRE->width(), Qt::SmoothTransformation);
    img_out_pre = img_out_pre.scaledToHeight(ui->IMGPRE->height(), Qt::SmoothTransformation);
    ui->IMGPRE->setPixmap(QPixmap::fromImage(img_out_pre).scaled(w,h,Qt::KeepAspectRatio));


    w = ui->IMGPOST->width();
    h= ui->IMGPOST->height();
    //Affichage de l'image après tr
    img_out_pre = img_fen_post.copy();
    img_out_pre = img_out_pre.scaledToWidth(ui->IMGPOST->width(), Qt::SmoothTransformation);
    img_out_pre = img_out_pre.scaledToHeight(ui->IMGPOST->height(), Qt::SmoothTransformation);
    ui->IMGPOST->setPixmap(QPixmap::fromImage(img_out_pre).scaled(w,h,Qt::KeepAspectRatio));

    w = ui->FREQPRE->width();
    h= ui->FREQPRE->height();
    //Affichage de l'image après tr
    img_out_pre = img_fen_freq_pre.copy();
    img_out_pre = img_out_pre.scaledToWidth(ui->FREQPRE->width(), Qt::SmoothTransformation);
    img_out_pre = img_out_pre.scaledToHeight(ui->FREQPRE->height(), Qt::SmoothTransformation);
    ui->FREQPRE->setPixmap(QPixmap::fromImage(img_out_pre).scaled(w,h,Qt::KeepAspectRatio));

    w = ui->FREQPOST->width();
    h = ui->FREQPOST->height();
    //Affichage de l'image après tr
    img_out_pre = img_fen_freq_post.copy();
    img_out_pre = img_out_pre.scaledToWidth(ui->FREQPOST->width(), Qt::SmoothTransformation);
    img_out_pre = img_out_pre.scaledToHeight(ui->FREQPOST->height(), Qt::SmoothTransformation);
    ui->FREQPOST->setPixmap(QPixmap::fromImage(img_out_pre).scaled(w, h, Qt::KeepAspectRatio));


}

void frequentiel::on_VALIDPB_clicked()
{
    VALIDER = 1;
    this->close();
}


void frequentiel::on_VALIDPH_clicked()
{
    VALIDER = 1;
    this->close();
}


void frequentiel::on_VALIDPBA_clicked()
{
    VALIDER = 1;
    this->close();
}



void frequentiel::on_VALIDCB_clicked()
{
    VALIDER = 1;
    this->close();
}
