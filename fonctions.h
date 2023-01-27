#ifndef FONCTIONS_H
#define FONCTIONS_H


#include <opencv2/opencv.hpp>
//#include <opencv4/opencv2/opencv.hpp>

#include <QtWidgets>
#include <QMessageBox>

#include <math.h>

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <vector>

using namespace std;
using namespace cv;

class fonctions
{
private :

    // Attributs
    int _numero;
    string _nom;
    double _prix;
    int _accreditation;
    double _poids;
    string _contenu;

public:

    // Constructeurs
    fonctions();
    fonctions(int numero, string nom, double prix, int accreditation, double poids, string contenu);

    // Getters
    int GetNumero();
    string GetNom();
    double GetPrix();
    int GetAccreditaion();
    double GetPoids();
    string GetContenu();

    // Setters
    void SetNumero(const int numero);
    void SetNom(const string nom);
    void SetPrix(const double prix);
    void SetAccreditation(const int accreditation);
    void SetPoids(const double poids);
    void SetContenu(const string contenu);

    // Méthodes
    Mat test(Mat image);

};

void afficher(Mat image, String nom);
void bloc(Mat image, int i, int j, int N, Mat& block);
void mat_vecteur(Mat& block, vector<double>& vect);
double median(vector<double>& vect);
Mat med_filter(Mat image, int N);
vector<double> histo(Mat image);
Mat filtre(String filter_name);
Mat filtrage(Mat image, String nfilter);
Mat conv(Mat image, Mat filter);
Mat neg(Mat image);
Mat rehau(Mat image);
Mat DiffGaus(Mat image);
Mat binarisation(Mat image, double seuil);
Mat km(Mat image, int nombre_classes);
Mat bruit_ps(Mat image, double poivre);
Mat bruit_blanc(Mat image, double variance);
Mat bruit(Mat image, int type_bruit);
Mat im_norm(Mat image, int ValMax, int ValMin);
vector<double> histocumul(Mat image);
Mat im_egal(Mat image, int ValMin, int ValMax);
Mat visualiser_canal(Mat image, int rouge, int vert, int bleu);
Mat seuillage_canal(Mat image, int seuil_bas_rouge, int seuil_haut_rouge, int seuil_bas_vert, int seuil_haut_vert, int seuil_bas_bleu, int seuil_haut_bleu);
Mat amplitude_fft(Mat image);
Mat fft_image(Mat image);
Mat inverse_fft_image(Mat image_fft);
Mat centrer_fft(Mat fft_image);
Mat normalisation_fft(Mat amplitude);
void FiltreOrdreUn(Mat image_entree, int rayon, string filtre);
void FiltreOrdreDeux(Mat image_entree, int R1, int R2, string filtre);
Mat AffFiltreOrdreUn(Mat image_entree ,int rayon,string filtre);

#endif // FONCTIONS_H
