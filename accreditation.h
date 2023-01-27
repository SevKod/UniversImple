#ifndef ACCREDITATION_H
#define ACCREDITATION_H

#include <QDialog>
#include <opencv2/opencv.hpp>
//#include <opencv4/opencv2/opencv.hpp>
//#include "accred.h"

#include <vector>
#include <string>
#include <cstring>
#include <fstream>
#include <iostream>

namespace Ui {
class Accreditation;
}

class Accreditation : public QDialog
{
    Q_OBJECT

public:
    explicit Accreditation(QWidget *parent = nullptr);
    ~Accreditation();

    void SetAdr(QString adresse);
    void AffImage();

    //Initialisation Images COULEURS
    void SetImg(QImage image);
    void SetImgMat(cv::Mat MatIm);

    // Getter
    int GetCode();

    // Setter
    void SetCode(int numero_acces);


    int num;
    int numero_acces;

private slots:
    void on_Annuler_Accred_clicked();

    void on_Valider_Accred_clicked();

private:
    Ui::Accreditation *ui;

    QString adr;
    QImage img;
};

#endif // ACCREDITATION_H
