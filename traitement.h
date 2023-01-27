#include <QDialog>
#include <opencv2/opencv.hpp>
//#include <opencv4/opencv2/opencv.hpp>
#include <QMainWindow>
#include "fentr.h"
#include "bibliotheque.h"

#ifndef TRAITEMENT_H
#define TRAITEMENT_H


namespace Ui {
class Traitement;
}

class Traitement : public QDialog
{
    Q_OBJECT

public:

    explicit Traitement(QWidget *parent = nullptr);
    ~Traitement();
    void SetFen(FenTr *fen);

    void SetAdr(QString adresse);
    void AffImageBibNDG();

    int PAGE = -1;

    ///////

    //Initialisation Images COULEURS
    void SetImg(QImage image);

    void SetImgMat(cv::Mat MatIm);
    void SetImgMatTr(cv::Mat MatImTr);

    //Initialisation Images NdG

    void SetImgNdG(QImage image);

    void SetImgMatNdG(cv::Mat MatIm);
    void SetImgMatTrNdG(cv::Mat MatImTr);

    void VisuCanal();
    void VisuImage();
    ///////

    void AffImage();
    void ReinitialiserTraitement();
    void timerEvent(QTimerEvent *te);

private slots:

    void on_NDG_clicked();
    void on_Retour_clicked();

    void on_FMED_clicked();

    void on_Annuler_clicked();

    void on_SLIDORD_sliderMoved(int position);

    void on_histogramme_clicked();

    void resizeEvent(QResizeEvent *event);

    //void actualiserNDG();

    void on_REN_clicked();

    void on_FL_clicked();

    void on_AnnulerFL_clicked();

    void on_FG_clicked();



    void on_valider_clicked();

    void on_CLR_clicked();

    void on_Annuler_2_clicked();

    void on_RVB_clicked();

    void on_SEGCLR_clicked();

    void on_AnnulerSEGCLR_clicked();

    void on_BS1_sliderMoved(int position);

    void on_BS2_sliderMoved(int position);

    void on_VS1_sliderMoved(int position);

    void on_VS2_sliderMoved(int position);

    void on_RS1_sliderMoved(int position);

    void on_RS2_sliderMoved(int position);

    void on_VALIDERSEG_clicked();

    void on_SLIDORDSEG_sliderMoved(int position);

    void on_MED_MARG_clicked();

    void on_FM_clicked();

    void on_FL4_clicked();

    void on_FL8_clicked();

    void on_FPX_clicked();

    void on_FPY_clicked();

    void on_FSX_clicked();

    void on_FSY_clicked();

    void on_normal_clicked();

    void on_H_clicked();

    void on_egal_clicked();

    void on_Annuler_H_clicked();

    void on_ValiderH_clicked();

    void on_His_clicked();

    void on_AT_clicked();

    void on_ANLAT_clicked();

    void on_VALIDAT_clicked();

    void on_NEG_clicked();

    void on_DOG_clicked();

    void on_RC_clicked();

    void on_BIN_clicked();

    void on_KM_clicked();

    void on_BB_clicked();

    void on_SLIDSEUIL_sliderMoved(int position);

    void on_SLIDKM_sliderMoved(int position);

    void on_SLIDVAR_sliderMoved(int position);

    void on_BI_CURS_sliderMoved(int position);

    void on_BI_CURS_sliderReleased();

    void on_SLIDVAR_sliderReleased();

    void on_SLIDSEUIL_sliderReleased();

    void on_QCON_clicked();

    void on_HCON_clicked();

    void on_HPREW_clicked();

    void on_VPREW_clicked();

    void on_HSOB_clicked();

    void on_VSOB_clicked();

    void on_FF_clicked();

    void on_VAL_FREQ_clicked();

    void on_ANN_FREQ_clicked();

    void on_PH_clicked();

    void on_PB_clicked();

    void on_PBA_clicked();

    void on_CB_clicked();

    void on_AFFICH_FREQ_clicked();

    void on_actionSAVE_triggered();

    void on_actionImporter_triggered();

    void on_NEGCLR_clicked();

    void on_FGCLR_clicked();

    void on_FMCLR_clicked();

    void on_SLIDORD_actionTriggered(int action);

private:
    Ui::Traitement *ui;
    FenTr *fenetre_traitement;
    Bibliotheque *bibliotheque;
    //Images de base + Image qui subit le traitement
    QImage img;
    QImage imgTr;
    QImage imgNdG;
    QImage imgNdGTr;
    //Version matrice de ces images
    cv::Mat imgMat;
    cv::Mat imgMatTr;
    //Version matrice de ces images NdG
    cv::Mat imgMatNdG;
    cv::Mat imgMatTrNdG;

    //Pour le bouton Annuler
    QImage imgNdGAnnuler;
    cv::Mat imgMatNdGAnnuler;
    //Annuler pour la couleur
    QImage imgCLRAnnuler;
    cv::Mat imgMatCLRAnnuler;
    //Bouton ANNULER pour le fréquentiel
    QImage imgNdGAnnulerFreq;
    cv::Mat imgMatNdGAnnulerFreq;
    //Revenir en arrière sur le poivre et sel
    QImage imgNdGPS;
    cv::Mat imgMatNdGPS;
    QImage imgNdGFreq;
    cv::Mat imgMatNdGFreq;

    QString adr;

    QImage im_fen;
    QImage im_fen_freq;

    int timerId;

    int curseur_ordre_med = 3;
    int curseur_classes = 2;
    int curseur_seuil = 1;
    double curseur_variance = 0.01;
    double curseur_poivre = 0;
    int quatre_connexites;
    int huit_connexites;
    int horiz_prew;
    int vertic_prew;
    int horiz_sob;
    int vertic_sob;

    int passage_freq = 1;

    //Couleur

    int canaux;
    //Matrice pour VISUALISATION
    cv::Mat MatR;
    cv::Mat MatV;
    cv::Mat MatB;

    //Mode Visualisation RGB
    QImage im_fen_tr;
    QImage im_fen_RVB;
    QImage im_fenR;
    QImage im_fenV;
    QImage im_fenB;

    //Segmentation
    int PRS1;
    int PRS2;
    int PVS1;
    int PVS2;
    int PBS1;
    int PBS2;

    //Segmentation
    QImage imgTrSEG;
    cv::Mat imgMatTrSEG;

};

#endif // TRAITEMENT_H
