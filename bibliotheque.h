#ifndef BIBLIOTHEQUE_H
#define BIBLIOTHEQUE_H

#include <QMainWindow>
#include <QDialog>
#include <opencv2/opencv.hpp>
//#include <opencv4/opencv2/opencv.hpp>
#include "biblio.h"
//#include "traitement.h"

#include <vector>
#include <string>
#include <cstring>
#include <fstream>
#include <iostream>


namespace Ui {
class Bibliotheque;
}

class Bibliotheque : public QMainWindow
{
    Q_OBJECT

public:
    explicit Bibliotheque(QWidget *parent = nullptr);
    ~Bibliotheque();

    void SetAdr(QString adresse);
    void setImp(int imp);

    ///////

    int tailleTotal = 0, taille, max = 0, Accred, tailleAccred = 0;
    std::vector<Biblio> imgBDD;
    int NumAccred, importer = 0;

    void AffIm();
    void AffImage();
    void AffImageBibNDG();

    //Initialisation Images COULEURS
    void SetImg(QImage image);
    void SetImgMat(cv::Mat MatIm);
    void RecupAccred(int accred);
    void init();
    QImage GetImage();

    private slots:
    void on_Retour_2_clicked();
    void on_ADD_clicked();
    void on_BDD_clicked();
    void on_ANL_clicked();
    void on_ANL_2_clicked();
    void resizeEvent(QResizeEvent *event);
    void on_VALID_clicked();
    void on_MODIFSUPPB_clicked();
    void on_SUPPIMG_clicked();
    void on_MODIFBUTTON_clicked();

    // A fusionner
    void on_BDD_3_clicked();
    void on_RETOURMODIF_clicked();
    void on_ANLBIB_clicked();
    void on_VLDBIB_clicked();
    void on_PrixImg_clicked();

    void on_SLIP_clicked();

    void on_TPC_clicked();

    void on_Reset_clicked();

    void on_pushButton_clicked();

    void on_FREE_clicked();

    void on_M10_clicked();

    void on_P100_clicked();

    void on_M100_clicked();

    void on_STAT_clicked();

    void on_RetourK_clicked();

    void on_TTT_clicked();

private:
    Ui::Bibliotheque *ui;

    //Images de base
    QImage img;

    //Version matrice de ces images
    cv::Mat imgMat;

    QString adr;
    QImage im_fen;

    int timerId;



};

#endif // BIBLIOTHEQUE_H
