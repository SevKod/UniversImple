#include "fonctions.h"
#include "traitement.h"

//#include <opencv4/opencv2/opencv.hpp>
#include <opencv2/opencv.hpp>

#include <math.h>
#include <iostream>

using namespace std;
using namespace cv;

#include <QtWidgets>
#include <QMessageBox>
#include <QFileDialog>
#include <random>


// Constructeur
fonctions::fonctions(){}

fonctions::fonctions(int numero, string nom, double prix, int accreditation, double poids, string contenu)
{
    _numero = numero;
    _nom = nom;
    _prix = prix;
    _accreditation = accreditation;
    _poids = poids;
    _contenu = contenu;
}

// Getters
int fonctions::GetNumero()
{
    return _numero;
}
string fonctions::GetNom()
{
    return _nom;
}
double fonctions::GetPrix()
{
    return _prix;
}
int fonctions::GetAccreditaion()
{
    return _accreditation;
}
double fonctions::GetPoids()
{
    return _poids;
}
string fonctions::GetContenu()
{
    return _contenu;
}

// Setters
void fonctions::SetNumero(const int numero)
{
    _numero=numero;
}
void fonctions::SetNom(const string nom)
{
    _nom=nom;
}
void fonctions::SetPrix(const double prix)
{
    _prix=prix;
}
void fonctions::SetAccreditation(const int accreditation)
{
    _accreditation=accreditation;
}
void fonctions::SetPoids(const double poids)
{
    _poids=poids;
}
void fonctions::SetContenu(const string contenu)
{
    _contenu=contenu;
}

int i,j,k,l;

Mat filtre(String filter_name){
    ///////////////////////////////////////////////////////////////////
    // Fonction definissant et stockant les filtres par convolution  //
    ///////////////////////////////////////////////////////////////////
    // Mat filtre(String filter_name):       						 //
    ///////////////////////////////////////////////////////////////////
    // En entree : 												  	 //
    // String nfilter -> le nom du filtre avec lequel on va          //
    //                   travailler                                  //
    ///////////////////////////////////////////////////////////////////
    // En sortie :													 //
    // Mat filter -> ledit filtre									 //
    ///////////////////////////////////////////////////////////////////


    Mat filter;

    if (filter_name == "gaussien1"){
        // Le filtre gaussien 3x3
        filter = (Mat_<double>(3,3) << 1,2,1,2,4,2,1,2,1 )/16;

    }

    if (filter_name == "gaussien2"){
        // Le filtre gaussien 5x5
        filter = (Mat_<double>(5,5) << 1,2,3,2,1,2,7,11,7,2,3,11,17,11,3,2,7,11,7,2,1,2,3,2,1 )/121;

    }

    if (filter_name == "moyenneur"){
        // Le filtre moyenneur
        filter = (Mat_<double>(3,3) << 1,1,1,1,1,1,1,1,1 )/9;

    }

    if (filter_name == "laplacien8"){
        // Le filtre laplacien en 8 connexités
        filter = (Mat_<double>(3,3) << -1,-1,-1,-1,8,-1,-1,-1,-1 );

    }

    if (filter_name == "laplacien4"){
        // Le filtre laplacien en 4 connexités
        filter = (Mat_<double>(3,3) << 0,-1,0,-1,4,-1,0,-1,0 );

    }

    if (filter_name == "prewittX"){
        // Le filtre prewitt en X
        filter = (Mat_<double>(3,3) << -1,0,1,-1,0,1,-1,0,1 )/3;

    }

    if (filter_name == "prewittY"){
        // Le filtre prewitt en Y
        filter = (Mat_<double>(3,3) << -1,-1,-1,0,0,0,1,1,1 )/3;

    }

    if (filter_name == "sobelX"){
        // Le filtre sobel en X
        filter = (Mat_<double>(3,3) << -1,0,1,-2,0,2,-1,0,1 )/4;

    }

    if (filter_name == "sobelY"){
        // Le filtre sobel en Y
        filter = (Mat_<double>(3,3) << -1,-2,-1,0,0,0,1,2,1 )/4;

    }
    if (filter_name == "rehauss"){
        // Le filtre de rehaussement
        filter = (Mat_<double>(3,3) << 0,-1,0,-1,5,-1,0,-1,0 );

    }

    return filter;
}

Mat conv(Mat image, Mat filter){
    ///////////////////////////////////////////////////////////////////
    // Fonction de convolution 3x3   								 //
    // Ici, les conditions aux bords son en mirroir					 //
    ///////////////////////////////////////////////////////////////////
    // Mat conv(Mat image, Mat nfilter) :				     		 //
    ///////////////////////////////////////////////////////////////////
    // En entree : 													 //
    // Mat image -> une matrice image que l'on souhaite convoluer  	 //
    // String nfilter -> le filtre avec lequel on va travailler      //
    ///////////////////////////////////////////////////////////////////
    // En sortie :													 //
    // Mat image_conv -> l'image convoluee							 //
    ///////////////////////////////////////////////////////////////////

    Mat imageC, image_conv, mod;									 // On va copier l'image pour avoir une trace du type de l'image de base

    if(image.channels() == 1){

        image.convertTo(imageC, CV_64FC1);     						 // La on convertit l'image en 64FC1 sinon ca marche pas...

        // LES VARIABLES
        image_conv = Mat(imageC.rows, imageC.cols, CV_64FC1);		 // Definition de l'image convoluee
        mod = Mat(imageC.rows, imageC.cols, CV_64FC1);				 // Copie de l'image
        double Somme;												 // Somme la convolution

        // LE CORPS DU CODE
        copyMakeBorder(imageC, mod, 1,1,1,1, BORDER_REPLICATE);		 // Le "zero padding" en mirroir
        rotate(filter, filter, ROTATE_90_CLOCKWISE);				 // On tourne le filtre de 90deg sinon on va se faire gronder par Mme Herbulot

        for (i = (filter.rows -1)/2; i < imageC.rows-((filter.rows-1)/2); i++){
            for (j = (filter.cols -1)/2; j < imageC.cols-((filter.cols-1)/2); j++){
                                                                     // On parcourt l'image en fonction de la taille du filtre

                Somme = 0;											 // La somme est a zero pour chaque entree dans le filtre

                for (k = -(filter.rows - 1)/2; k < (filter.rows - 1)/2 + 1; k++){
                    for (l = -(filter.cols - 1)/2; l < (filter.cols - 1)/2 + 1; l++){
                                                                     // On parcourt le filtre en fonction de sa taille

                        Somme = Somme + mod.at<double>(i+k,j+l)*filter.at<double>(k+((filter.rows -1)/2),l+((filter.cols -1)/2));
                                                                     // Le calcul de la convolution
                    }
                }

                image_conv.at<double>(i-((filter.rows -1)/2),j-((filter.cols -1)/2)) = Somme;
                                                                     // On remplace le pixel par la valeur du produit
            }
        }

        image_conv.convertTo(image_conv, image.type());				 // On convertit pour faire genre il ne s'est rien passé
        return image_conv;

    }
    else{

        image.convertTo(imageC, CV_64FC3);     						 // La on convertit l'image en 64FC1 sinon ca marche pas...

        // LES VARIABLES
        image_conv = Mat(imageC.rows, imageC.cols, CV_64FC3);		 // Definition de l'image convoluee
        mod = Mat(imageC.rows, imageC.cols, CV_64FC3);				 // Copie de l'image
        double SommeR, SommeG, SommeB;								 // Somme la convolution

        // LE CORPS DU CODE
        copyMakeBorder(imageC, mod, 1,1,1,1, BORDER_REPLICATE);		 // Le "zero padding" en mirroir
        rotate(filter, filter, ROTATE_90_CLOCKWISE);				 // On tourne le filtre de 90deg sinon on va se faire gronder par Mme Herbulot

        for (i = (filter.rows -1)/2; i < imageC.rows-((filter.rows-1)/2); i++){
            for (j = (filter.cols -1)/2; j < imageC.cols-((filter.cols-1)/2); j++){
                                                                     // On parcourt l'image par rapport a la taille du filtre

                SommeR = 0;											 // La somme est a zero pour chaque entree dans le filtre
                SommeG = 0;
                SommeB = 0;

                for (k = -(filter.rows - 1)/2; k < (filter.rows - 1)/2 + 1; k++){
                    for (l = -(filter.cols - 1)/2; l < (filter.cols - 1)/2 + 1; l++){
                                                                     // On parcourt le filtre en accrod avec sa taille

                        SommeR = SommeR + mod.at<Vec3d>(i+k,j+l)[0]*filter.at<double>(k+((filter.rows -1)/2),l+((filter.cols -1)/2));
                        SommeG = SommeG + mod.at<Vec3d>(i+k,j+l)[1]*filter.at<double>(k+((filter.rows -1)/2),l+((filter.cols -1)/2));
                        SommeB = SommeB + mod.at<Vec3d>(i+k,j+l)[2]*filter.at<double>(k+((filter.rows -1)/2),l+((filter.cols -1)/2));
                                                                     // Le calcul de la convolution
                    }
                }

                image_conv.at<Vec3d>(i-((filter.rows -1)/2),j-((filter.cols -1)/2))[0] = SommeR;
                image_conv.at<Vec3d>(i-((filter.rows -1)/2),j-((filter.cols -1)/2))[1] = SommeG;
                image_conv.at<Vec3d>(i-((filter.rows -1)/2),j-((filter.cols -1)/2))[2] = SommeB;
                                                                     // On remplace le pixel par la valeur du produit
            }
        }

        image_conv.convertTo(image_conv, image.type());				 // On convertit pour faire genre il ne s'est rien passé
        return image_conv;

    }

    return image_conv;
}

Mat filtrage(Mat image, String nfilter){
    ///////////////////////////////////////////////////////////////////
    // Fonction de filtrage 2D/3D par convolution                    //
    ///////////////////////////////////////////////////////////////////
    // Mat filtrage(Mat image, String nfilter) :					 //
    ///////////////////////////////////////////////////////////////////
    // En entree :													 //
    // Mat image -> une matrice image que l'on souhaite filtrer		 //
    // String nfilter -> le nom du filtre avec lequel on va          //
    //                   travailler                                  //
    ///////////////////////////////////////////////////////////////////
    // Sortie :														 //
    // Mat image_Fil -> L'image filtree								 //
    ///////////////////////////////////////////////////////////////////

    // VARIABLE
    Mat imageF, image_Fil, filter;									 // On va copier l'image pour avoir une trace du type de l'image de base

    if (nfilter == "prewittX" || nfilter == "prewittY" || nfilter == "sobelX" || nfilter == "sobelY" || nfilter == "laplacien"){

        if (image.channels() == 3){

            cvtColor(image, imageF, COLOR_RGB2GRAY);
            imageF.convertTo(imageF, CV_64FC1);     				 // La on convertit l'image en 64FC1 sinon ca marche pas...

        }
        else {

            image.convertTo(imageF, CV_64FC1);     					 // La on convertit l'image en 64FC1 sinon ca marche pas...

        }

        filter = filtre(nfilter);									 // Le filtre
        image_Fil = Mat(imageF.rows, imageF.cols, CV_64FC1);		 // Definition de l'image convoluee

    }
    else if (image.channels() == 1){

        image.convertTo(imageF, CV_64FC1);     						 // La on convertit l'image en 64FC1 sinon ca marche pas...
        filter = filtre(nfilter);									 // Le filtre
        image_Fil = Mat(imageF.rows, imageF.cols, CV_64FC1);		 // Definition de l'image convoluee

    }
    else{

        image.convertTo(imageF, CV_64FC3);     						 // La on convertit l'image en 64FC1 sinon ca marche pas...
        filter = filtre(nfilter);									 // Le filtre
        image_Fil = Mat(imageF.rows, imageF.cols, CV_64FC3);		 // Definition de l'image convoluee

    }

    // FONCTION DE CONVOLUTION
    image_Fil = conv(imageF, filter);

    // SORTIE
    image_Fil.convertTo(image_Fil, image.type());				     // On convertit pour faire genre il ne s'est rien passé
    return image_Fil;

}



Mat neg(Mat image){
    ///////////////////////////////////////////////////////////////////
    // Une fonction pour faire le negatif d'une image, waow			 //
    ///////////////////////////////////////////////////////////////////
    // Mat neg(Mat image) :											 //
    ///////////////////////////////////////////////////////////////////
    // En entrée :													 //
    // Mat image -> L'image que l'on veut traiter					 //
    ///////////////////////////////////////////////////////////////////
    // En sortie :													 //
    // Mat Image_Neg -> L'image en negatif							 //
    ///////////////////////////////////////////////////////////////////

    Mat imageN, image_Neg;											 // On va copier l'image pour avoir une trace du type de l'image de base

    if (image.channels() == 1){

        image.convertTo(imageN, CV_64FC1);     						 // La on convertit l'image en 64fc1 sinon ca marche pas...

        // LES VARIABLES
        image_Neg = Mat(imageN.rows, imageN.cols, CV_64FC1);		 // L'image negative a vide

        // LE CORPS DU CODE
        image_Neg = 255 - imageN;									 // Bah on soustrait, le gros cerveau quoi

        image_Neg.convertTo(image_Neg, image.type());
        return image_Neg;
    }
    else{

        image.convertTo(imageN, CV_64FC3);     						 // La on convertit l'image en 64fc3 sinon ca marche pas...

        // LES VARIABLES
        image_Neg = Mat(imageN.rows, imageN.cols, CV_64FC3, CV_RGB(0,0,0));
                                                                     // L'image negative a vide
        Mat canalB,canalG,canalR;
        vector<Mat> canaux(3);

        extractChannel(imageN,canalB,0); 							 // On extrait les canaux R, G, B
        extractChannel(imageN,canalG,1);
        extractChannel(imageN,canalR,2);

        // LE CORPS DU CODE
        canaux[0] = 255 - canalB;									 // Bah on soustrait la valeur max aux canaux, le gros cerveau quoi
        canaux[1] = 255 - canalG;
        canaux[2] = 255 - canalR;

        merge(canaux,image_Neg);									 // On fusionne les canaux pour créer la nouvelle image couleur

        image_Neg.convertTo(image_Neg, image.type());				 // On reconvertit dans le type d'origine
        return image_Neg;

    }

    return image_Neg;
}
Mat rehau(Mat image){
    ///////////////////////////////////////////////////////////////////
    // Fonction de rehaussement de contour							 //
    ///////////////////////////////////////////////////////////////////
    // Mat rehau(Mat image):										 //
    ///////////////////////////////////////////////////////////////////
    // En entree :													 //
    // Mat image -> L'image que l'on souhaite traiter 				 //
    ///////////////////////////////////////////////////////////////////
    // En sortie :													 //
    // Mat image_rehau -> L'image rehaussee	 						 //
    ///////////////////////////////////////////////////////////////////

    Mat imageR, image_rehau, filter;								 // On va copier l'image pour avoir une trace du type de l'image de base

    if (image.channels() == 1){

        image.convertTo(imageR, CV_64FC1);     						 // La on convertit l'image en 64fc1 sinon ca marche pas...
        image_rehau = Mat(imageR.rows, imageR.cols, CV_64FC1);		 // L'image rehaussait a vide

        // LE FILTRE
        filter = filtre("rehauss");
                                                                         // On definit le filtre de rehaussement
        // FONCTION DE CONVOLUTION
        image_rehau = conv(imageR, filter);								 // L'image rehaussait
        image_rehau.convertTo(image_rehau, image.type());				 // On reconvertit dans le type d'origine

        return image_rehau;
    }
    else{

        image.convertTo(imageR, CV_64FC3);     						 // La on convertit l'image en 64fc3 sinon ca marche pas...
        image_rehau = Mat(imageR.rows, imageR.cols, CV_64FC3);		 // L'image rehaussait a vide

        // FILTRE
        filter = filtre("rehauss");
                                                                         // On definit le filtre de rehaussement
        // FONCTION DE CONVOLUTION
        image_rehau = conv(imageR, filter);								 // L'image rehaussait
        image_rehau.convertTo(image_rehau, image.type());				 // On reconvertit dans le type d'origine

        return image_rehau;
    }

    return image_rehau;
}

Mat DiffGaus(Mat image){
    ///////////////////////////////////////////////////////////////////
    // Fonction DOG            										 //
    ///////////////////////////////////////////////////////////////////
    // Mat DiffGaus(Mat image):										 //
    ///////////////////////////////////////////////////////////////////
    // En entree :													 //
    // Mat image -> L'image que l'on souhaite traiter 				 //
    ///////////////////////////////////////////////////////////////////
    // En sortie :													 //
    // Mat image_DiffG -> L'image ayant subit une difference de 	 //
    // 					  gaussienne   		 						 //
    ///////////////////////////////////////////////////////////////////

    // LES VARIABLES
    Mat imageDG, filter1, filter2, Gauss1, Gauss2;

    // LES CONVERSIONS
    if (image.channels() == 3){

            cvtColor(image, imageDG, COLOR_RGB2GRAY);				 // On convertit les images en rgb en ndg pour la detection de contour
            imageDG.convertTo(imageDG, CV_64FC1);     				 // La on convertit l'image en 64FC1 sinon ca marche pas...

    }
    else{

        image.convertTo(imageDG, CV_64FC1);							 // La on convertit l'image en 64FC1 sinon ca marche pas...

    }

    Mat image_DiffG(imageDG.rows, imageDG.cols, CV_64FC1);			 // On initialise la nouvelle image vide

    filter1 = filtre("gaussien1");									 // Les deux gaussiennes
    filter2 = filtre("gaussien2");

    Gauss1 = conv(imageDG,filter1);									 // La convolution de l'image avec les deux gaussiennes
    Gauss2 = conv(imageDG,filter2);

    image_DiffG = abs(Gauss2 - Gauss1);   							 // On soustrait

    image_DiffG.convertTo(image_DiffG, image.type());				 // On reconvertit dans le type d'origine
    return image_DiffG;
}


///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
/////////////////////////////  SERVERIN  //////////////////////////////
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

Mat visualiser_canal(Mat image, int rouge, int vert, int bleu)
{
    //Utilisation : Mettre l'image d'entr�e pour le param�tre Mat image. Puis mettre � 1 ou 0 chaque canal de couleur afin de d�finir
    //quel canal de couleur on souhaite extraire pour visualisation.

    //L'objectif est de pouvoir visualiser les canaux prit individuellements, de chaque format d'image (RGB,HSV,YCbCr, etc...).
    //Pour cela, on r�cup�re l'image, on isole le canal souhait�, et on compl�te les deux "canaux restants" par des matrices compos�s de 0
    //que l'on va concat�ner afin de faire appara�tre la notion de couleur sur la fonction imshow.
    //On aura alors une image r�sultante avec 3 canaux, dont 2 canaux seront � 0.

    int ligne = image.rows; //R�cup�ration du nombre de lignes de l'image
    int colonne = image.cols; //R�cuparations du nombre de colonnes de l'image
    Mat canal; //Matrice de chaque canal extrait
    Mat zero = Mat::zeros(ligne, colonne, CV_8UC1); //La matrice de 0 qui servira � remplir les canaux restants non isol�s. 8UC1 signifie que le codage des valeurs
    //est fait sur 8 bits non sign�s
    Mat im_out(ligne, colonne, CV_8UC3, CV_RGB(0,0,0)); //Image r�sultante
    vector<Mat> channels; //Vecteur de 3 �l�ments, contenant pour chaque �l�ment, une matrice Mat.

    //On commence le remplissage des couleurs par la fin car la concat�nation par "push_back" rajoute la valeur � l'indice 0, et non pas � la fin du vecteur.
    //On r�alise les conditions
    if (bleu == 1 && vert == 0 && rouge == 0){
        extractChannel(image, canal, 2); //Extraction du canal
        channels.push_back(canal); //Concat�nation dans chaque matrice de "channels", la matrice "canal"
    }
    else{
        channels.push_back(zero);
    }
    if (bleu == 0 && vert == 1 && rouge == 0){
        extractChannel(image, canal, 1);
        channels.push_back(canal);
    }
    else{
        channels.push_back(zero);
    }
    if (bleu == 0 && vert == 0 && rouge == 1){
        extractChannel(image, canal, 0);
        channels.push_back(canal);
    }
    else{
        channels.push_back(zero);
    }


    merge(channels, im_out); //La fonction "merge" prend les valeurs de chacune des 3 matrices de channels, et les regroupe dans une seule et m�me cellule.
    //On aura alors une seule matrice contenant des cellules pour chaque �l�ment. Ces cellules auront les triplets RGB...
    im_out.convertTo(im_out, image.type());
    return im_out;
}

void afficher(Mat image, String nom)
{
    //Utilisation : Fonction d'affichage d'une image (format UINT8). Mettre l'image en param�tre 1, et le nom de la fen�tre en param�tre 2 (String).

    namedWindow(nom); // Cr�ation de la fen�tre

    imshow(nom, image); // Affichage

    waitKey(0); // Appuyer pour stopper l'affichage

    destroyWindow(nom); // Fermeture de la fen�tre

}

Mat seuillage_canal(Mat image, int seuil_bas_rouge, int seuil_haut_rouge, int seuil_bas_vert,int seuil_haut_vert, int seuil_bas_bleu, int seuil_haut_bleu)
{
    //Utilisation : Mettre l'image d'entr�e pour le param�tre Mat image. Puis mettre les trois seuils (valeur entre 0 et 255) pour chaque canal de couleur

    int ligne = image.rows; //R�cup�ration du nombre de lignes de l'image
    int colonne = image.cols; //R�cuparations du nombre de colonnes de l'image
    int i, j;
    Mat canalR, canalV, canalB; //Matrice de chaque canal extrait
    Mat zero = Mat::zeros(ligne, colonne, CV_8UC1); //La matrice de 0 qui servira � remplir les canaux restants non isol�s. 8UC1 signifie que le codage des valeurs
    //est fait sur 8 bits non sign�s
    Mat im_out; //Image r�sultante
    vector<Mat> channels; //Vecteur de 3 �l�ments, contenant pour chaque �l�ment, une matrice Mat.
    extractChannel(image, canalB, 0); //Extraction du canal
    extractChannel(image, canalV, 1); //Extraction du canal
    extractChannel(image, canalR, 2); //Extraction du canal
    //channels.push_back(canal); //Concat�nation dans chaque matrice de "channels", la matrice "canal"
    //Canal bleu
    for (i=0;i<ligne;i++)
    {   for(j=0;j<colonne;j++)
            {
            if ( ((canalB.at<uchar>(i, j)) < seuil_bas_bleu) || ((canalB.at<uchar>(i, j)) > seuil_haut_bleu))
                    {
                    canalB.at<uchar>(i, j) = 0;
                    }
            if (((canalV.at<uchar>(i, j)) < seuil_bas_vert) || ((canalV.at<uchar>(i, j)) > seuil_haut_vert))
                    {
                    canalV.at<uchar>(i, j) = 0;
                    }
            if (((canalR.at<uchar>(i, j)) < seuil_bas_rouge) || ((canalR.at<uchar>(i, j)) > seuil_haut_rouge))
                    {
                    canalR.at<uchar>(i, j) = 0;
                    }
            }
    }
    channels.push_back(canalB);
    channels.push_back(canalV);
    channels.push_back(canalR);
    merge(channels, im_out);
    return im_out;
}

void bloc(Mat image, int i, int j, int N, Mat& block)
{
    //Utilisation : Permet de r�cup�rer un bloc de pixels de taille NxN sur l'image, aux coordonn�es i,j. Mettre le bloc vide en entr�e

    int k, l;
    int bords = int(N / 2);
    int klimB = i - bords;
    int klimH = i + bords + 1;
    int llimB = j - bords;
    int llimH = j + bords + 1;
    for (k = klimB; k < klimH; k++)
    {
        for (l = llimB; l < llimH; l++)
        {
            block.at<double>(k - (klimB), l - (llimB)) = image.at<double>(k, l);
        }
    }
}


double median(vector<double> & vect)
{
    //Calcule la m�diane d'un vecteur
    sort(vect.begin(), vect.end());
    return(vect[round((vect.size() -1) / 2)]);
}

void mat_vecteur(Mat& block, vector<double>& vect)
{
    //Matrice block en entr�e, vecteur ligne en sortie.
    //Convertit la matrice block en vecteur ligne. Allouer le vecteur VECT avec la taille nécessaire en 0 au préalable.

    int N = block.cols;
    int i, j;
    int cpt = 0;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            vect[cpt] = block.at<double>(i, j);
            cpt = cpt + 1;
        }
    }
}

void mat_vecteur2(Mat& block, vector<double>& vect)
{
    //Matrice block en entr�e, vecteur ligne en sortie.
    //Convertit la matrice block en vecteur ligne
    int N = block.cols;
    block = block.reshape(0, 1);
    block.copyTo(vect);
    block = block.reshape(1, N);
}

Mat med_filter(Mat image, int N)
{
    //Param�tre 1 : Image d'entr�e � filtrer
    //Param�tre 2 : Taille du filtre NxN

    Mat block = Mat::zeros(N, N, CV_64FC1); //Matrice de bloc � traiter
    int i, j; //Indices pour parcourir l'image
    double val; // Valeur m�diane de chaque bloc
    vector<double> vect; //Valeurs de pixels d'un bloc mis en ligne

    for (i = 0; i < N * N; i++)
    {

        vect.push_back(0);

    }

    copyMakeBorder(image, image, 1, 1, 1, 1, BORDER_CONSTANT, Scalar(0)); //Z�ro-Padding r�alis� (n�c�ssaire ???)
    int L = image.rows; //r�cup�ration lignes
    int C = image.cols; //r�cup�ration colonnes

    Mat im_sortie = Mat::zeros(L, C, CV_8UC1); //Initialisation de la matrice de sortie

    image.convertTo(image, CV_64FC1); //Conversion de l'image au format float pour les calculs

    int bords = int(N / 2);

    ////////CHARGEMENT

    ////////


    for (i = bords; i < L - bords; i++) //On parcours l'image en partant du pixel central au bloc N/2
    {
        for (j = bords; j < C - bords; j++)
        {
            //PROGRESSION DU CHARGEMENT
            //fenetre->progression((C-bords)*i + j);
            //
            bloc(image, i, j, N, block); //On r�cup�re le bloc de taille N
            mat_vecteur(block, vect); //On met ce bloc en ligne
            val = median(vect); //On r�cup�re la m�diane de ce vecteur
            im_sortie.at<uchar>(i, j) = val; //On stocke la valeur m�diane � l'emplacement �tudi�
        }
    }
    im_sortie.convertTo(im_sortie, CV_8UC1);

    //Fin du chargement
    //fenetre->close();

    return(im_sortie);
}

vector<double> histo(Mat image)
{
    vector<double> vect;
    int i;
    Mat imageh;

    for (i = 0; i < imageh.rows * imageh.cols; i++)
    {

        vect.push_back(0);

    }
    int k;

    
    image.convertTo(imageh,CV_64FC1);
    mat_vecteur2(imageh,vect);
    int nb = vect.size();
    sort(vect.begin(), vect.end());

    vector<double> vect2;
    int l = 0;

    for (l = 0; l < 256; l++)
    {
        vect2.push_back(0);
    }

    int j = 0;

    for (k = 0; k < nb; k++)
    {
        if (vect[k] == j)
        {
            vect2[j] = vect2[j]+1;
        }
        else
        {
            j = j+1;
            k = k-1;
        }
    }

    /*for (k = 0; k<256; k++ )
    {
        cout << vect2[k] << endl;
    }*/


    return vect2;
}

// Manipulation d'histogrammes




// Normalisation histogramme
Mat im_norm(Mat image, int ValMax, int ValMin)
{
    Mat image2; //on passe l'image en niveaux de gris
    image.convertTo(image2,CV_64FC1);

    int i, j;
    int L = image.rows;
    int C = image.cols;

    Mat im_sortie = Mat::zeros(image.size(),CV_64FC1);

   // image.convertTo(im_sortie, CV_8UC1);

    double minVal, maxVal;

    minMaxLoc(image2, &minVal, &maxVal);

    for (i = 0; i < L ; i++)
    {
        for (j = 0; j < C ; j++)
        {
            im_sortie.at<double>(i, j) = ((ValMax - ValMin)/(maxVal - minVal))*((image2.at<double>(i,j))-minVal);
        }
    }

    im_sortie.convertTo(im_sortie, image.type());
    return im_sortie;
}

// Egalisation histogtramme

vector<double> histocumul(Mat image)
{
    vector<double> vect;
    int k;

    Mat imageh;
    image.convertTo(imageh,CV_64FC1);
    mat_vecteur2(imageh,vect);
    int nb = vect.size();
    sort(vect.begin(), vect.end());

    vector<double> vect2;
    vector<double> vect3;
    int l = 0;

    for (l = 0; l < 256; l++)
    {
        vect2.push_back(0);
        vect3.push_back(0);
    }

    int j = 0;

    for (k = 0; k < nb; k++)
    {
        if (vect[k] == j)
        {
            vect2[j] = vect2[j]+1;
        }
        else
        {
            j = j+1;
            k = k-1;
        }
    }

    vect3[0] = vect2[0];

    for (k = 1; k < 256 ; k++)
    {
        vect3[k] = vect3[k-1] + vect2[k];
    }


//    for (k = 0; k<256; k++ )
//    {
//        cout << vect3[k] << endl;
//    }
//
    return vect3;
}



Mat im_egal(Mat image, int ValMin, int ValMax)
{

    int i, j;
    int L = image.rows;
    int C = image.cols;

    Mat image2; //on passe l'image en niveaux de gris
    image.convertTo(image2,CV_64FC1);

    Mat im_sortie = Mat::zeros(image.size(),CV_64FC1);

    //Mat image2 = image.clone();

    //image2.convertTo(image2, CV_64FC1);

    vector<double> histo_c = histocumul(image2);

//    printf("%f\n",image2.at<double>(0, 0));

    equalizeHist(image,im_sortie);
    for (i = 0; i < 0 ; i++)
    {
        for (j = 0; j < 0 ; j++)
        {
            im_sortie.at<double>(i, j) = ((ValMax - ValMin)/(L*C))*histo_c[image2.at<double>(i,j)]+ValMin;
//            printf("%f\n",im_sortie.at<uchar>(i, j));


        }
    }
    normalize(im_sortie, im_sortie, 0, 255, NORM_MINMAX);

   im_sortie.convertTo(im_sortie, image.type());
    return(im_sortie);
}

// Algorithmes de traitement

// Bruitage
Mat bruit_blanc(Mat image, double variance)
{
/*
Fonction permettant de bruiter une image avec deux type de bruit : bruit impulsionnel ou bruit additif gaussien.
La fonction prend en entrée uniquement l'image originale à bruiter, le choix du type de bruit se fait par la suite.
*/
    Mat image2; //on passe l'image en niveaux de gris
    image.convertTo(image2,CV_64FC1);

    Mat image_bruitee = Mat::zeros(image.size(),CV_64FC1); //initialisation de l'image bruitée
    Mat b = Mat::zeros(image.size(),CV_64FC1); //matrice de bruit (elle est remplie en fonction du type de bruit)

    int ligne = image.rows; //récupération des dimensions de l'image initiale
    int colonne = image.cols;
    int x,y; //variables pour parcourir l'image


        RNG rng(clock());
        //cout << "quelle variance souhaitez-vous pour le bruit?" << endl;
        //cin >> variance; //on paramètre le bruit (plus la variance est élevée, plus le bruit est visible)
        //variance = 5;
        for (x=0; x<ligne; x++) //on parcourt l'image
        {
            for (y=0; y<colonne; y++)
            {
                b.at<double>(x,y) = rng.gaussian(variance); //on génère une VA suivant une loi normale
                image_bruitee.at<double>(x,y) = image2.at<double>(x,y) + b.at<double>(x,y); //on ajoute ce bruit à chaque pixel initiaux
            }
        }

    image_bruitee.convertTo(image_bruitee,image.type()); //on repasse au type d'image initiale
    return image_bruitee; //on offre l'image bruitée

}


Mat bruit_ps(Mat image, double poivre)
{
    Mat image2; //on passe l'image en niveaux de gris
    image.convertTo(image2, CV_64FC1);

    Mat image_bruitee = Mat::zeros(image.size(), CV_64FC1); //initialisation de l'image bruitée
    Mat b = Mat::zeros(image.size(), CV_64FC1); //matrice de bruit (elle est remplie en fonction du type de bruit)

    //double poivre = 0.01; //Variable de pourcentage de poivre et sel
    double sel = 1 - poivre;

    int ligne = image.rows; //récupération des dimensions de l'image initiale
    int colonne = image.cols;
    int x, y; //variables pour parcourir l'image

    double aleatoire;

    std::random_device rd;  // Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); // Standard mersenne_twister_engine seeded with rd()

    uniform_real_distribution<double> alea(0, 1.0); //Génération d'un nombre entre 0 et 1 suivant une distribution uniforme
    for (x = 0; x < ligne; x++) //on parcourt les pixels de l'image
    {
        for (y = 0; y < colonne; y++)
        {

            aleatoire = alea(gen);

            if (aleatoire < poivre) // si le bruit généré vaut 0, le pixel de l'image résultante par la valeur min (0)
            {
                image_bruitee.at<double>(x, y) = 0;
            }
            else if (aleatoire > sel) //si le bruit généré vaut 255, le pixel de l'image résultante prend la valeur max (255)
            {
                image_bruitee.at<double>(x, y) = 255;
            }
            else
            {
                image_bruitee.at<double>(x, y) = image2.at<double>(x, y); //pour tous les autres cas, on conserve les pixels originaux
            }
        }
    }
    image_bruitee.convertTo(image_bruitee, image.type()); //on repasse au type d'image initiale
    return(image_bruitee);
}



Mat binarisation(Mat image, double seuil){

    Mat image2;
    image.convertTo(image2,CV_64FC1);
    int ligne = image.rows;
    int colonne = image.cols;
    int x, y;
    Mat image_resultante(image.size(),CV_64FC1);

    for (x=0; x<ligne; x++)
    {
        for (y=0; y<colonne; y++)
        {
            if (image2.at<double>(x,y) >seuil)
            {
                image_resultante.at<double>(x,y)= 255;
            }
            else
            {
                image_resultante.at<double>(x,y) = 0;
            }

        }
    }
    image_resultante.convertTo(image_resultante,image.type());
    return(image_resultante);

}


Mat km(Mat image, int nombre_classes)
{
    Mat image2;
    image.convertTo(image2, CV_64FC1);
    Mat image_classifiee = Mat::zeros(image.size(), CV_64FC1); //initialisation de l'image classifiée (=image résultante)

    int ligne = image.rows; //récupération du nombre de lignes et de colonnes de l'image initiale
    int colonne = image.cols;

    vector<int> k(nombre_classes, 0); //Vecteur de stockage des centroïdes

    int dist; //Variable de stockage des distances

    int t = 0; //initialisation du compteur de la boucle
    int x, y, c, i; //déclaration des variables utilisées pour la suite
    double dist_m, val;
    int /*classe_pixel,*/ compteur;
    int iterations_max = 1000; //on définit un nombre d'itérations max pour limiter le coût temporel

    srand(time(0)); //Mise à jour de la seed

    for (i = 0; i < nombre_classes; i++) //initialisation aléatoire des centroides
    {
        RNG rng(clock()); //mise à jour du caractère aléatoire
        k[i] = (rand() % 255); //On prend une valeur entre 0 et 255
    }

    int taille_avant; //Variable pour le stockage des tailles du vecteur de centroïde k

    while (t < iterations_max + 1)
    {
        // attribution des centroïdes
        for (x = 0; x < ligne; x++)
        {
            for (y = 0; y < colonne; y++)
            {
                dist_m = 255;
                for (c = 0; c < nombre_classes; c++)
                {
                    dist = abs(image2.at<double>(x, y) - k[c]);
                    if (dist < dist_m)
                    {
                        dist_m = dist;
                        image_classifiee.at<double>(x, y) = c;
                    }
                }
            }
        }
        taille_avant = k.size(); //Récupération de la taille du vecteur avant suppression potentielle de centroïdes
        //mise à jour des centroïdes
        for (c = 0; c < nombre_classes; c++)
        {
            compteur = 0;
            val = 0;
            for (x = 0; x < ligne; x++)
            {
                for (y = 0; y < colonne; y++)
                {
                    if (image_classifiee.at<double>(x, y) == c)
                    {
                        compteur++;
                        val = val + image2.at<double>(x, y);
                    }
                }
            }
            if (compteur != 0)
            {
                k[c] = round(val / compteur);
            }
            else
            {
                k[c] = -1;
            }
        }
        //On efface les centroïdes de classe -1 et on reconcatène notre vecteur
        k.erase(std::remove(k.begin(), k.end(), -1), k.end());
        k.shrink_to_fit(); //Concaténation du vecteur
        nombre_classes = k.size(); //Récupération de la nouvelle taille de vecteur
        if (nombre_classes == taille_avant) //COmparaison avec l'ancienne taille
        {
            t = 1000; //Si la taille est la même, on sort du while
        }
        t++;

    }
    normalize(image_classifiee, image_classifiee, 0, 255, NORM_MINMAX);
    image_classifiee.convertTo(image_classifiee, image.type());

    return(image_classifiee);
}

//////////////////FILTRAGE////////////////////////

Mat fft_image (Mat image_entree)
{
    //PARAMETRE 1 : L'image dont on doit calculer la DFT
    //Cette fonction permet le calcul et le renvoi de la Transformée de Fourier 2D de n'importe quelle image COULEUR !! Il y a une conversion en NdG de réalisé
    image_entree.size();
    Mat image = image_entree.clone(); //Copie de l'image mise en entrée dans une nouvelle variable afin de ne pas convertir l'image de base en NdG,
    //cvtColor(image, image, COLOR_BGR2GRAY); //Si l'image est en couleur
    image.convertTo(image, CV_64FC1);

    Mat TF2D; //Cette variable stockera le résultat de la DFT
    Mat PretPourTF; //Cette fonction servir à stocker les données d'image d'entrée sous une forme convenable afin d'appliquer la DFT par la suite.
    vector<Mat> Complex = { image, Mat::zeros(image.rows, image.cols, CV_64F) }; //Ce vecteur de deux matrices permet le stockage de partie réelle et imaginaire de l'image d'entrée.
    //La matrice d'entrée étant une image, celle-ci ne contient pas de partie imaginaire. La seconde matrice est alors composée de 0.

    //P.S : L'entrée étant réel, la DFt donnera un résultat purement complêxe, mais aussi symétrique (complêxe conjugué).


    merge(Complex, PretPourTF); //Stockage de partie réelle et partie imaginaire (nulle) dans une matrice. La matrice aura alors deux composantes [Réelle, Imaginaire] par case
    dft(PretPourTF, TF2D, DFT_COMPLEX_OUTPUT); //Calcul de la DFT. On donne la directive que la sortie sera purement complêxe, et du fait que la sortie soit symétrique complêxe conjugué, on simplifie le temps de traitement.

    return(TF2D);
}

Mat normalisation_fft(Mat amplitude)
{
    //PARAMETRE 1 : Matrice image de l'amplitude de la FFT que l'on souhaite normaliser pour affichage

    amplitude = amplitude + 1; //Eviter les valeurs négatives en vu de l'application du log
    log(amplitude, amplitude);//Calcul du logarithme afin de distinguer les variations en intensité
    normalize(amplitude, amplitude, 0, 255, NORM_MINMAX); //Normalisation des valeurs d'amplitudes pour l'affichage

    return(amplitude);
}

Mat amplitude_fft (Mat image)
{
    //PARAMETRE 1 : L'image d'entrée dont on veut afficher la DFT. Il s'agit d'une image en NdG
    //Cette fonction calcule la DFT et affiche son amplitude (la partie exploitable).

    Mat amplitude;
    vector<Mat> ReelImaginaire; //Vecteur qui stockera les matrices des parties réelles et imaginaires
    Mat TF2D = fft_image(image); //Calcul de la dft

    split(TF2D, ReelImaginaire); //Stockage des parties réelles et imaginaires dans le vecteur
    magnitude(ReelImaginaire[0], ReelImaginaire[1], amplitude); //Calcul de l'amplitude
    amplitude = centrer_fft(amplitude); //Centrage de la DFT
    amplitude = normalisation_fft(amplitude); //Normalisation de la DFT
    amplitude.convertTo(amplitude, CV_8UC1);

    return(amplitude);
}

void FiltreOrdreUn(Mat image_entree ,int rayon,string filtre)
{
    //PARAMETRE 1 : L'image à filtrer
    //PARAMETRE 2 : Le rayon du cercle correspond à la partie de la FFT qui sera conservé (si passe-bas) ou mise à 0 (si passe-haut. Tout ce qui est extérieur au cercle sera mis à 0 (PB) ou 1 (PH).
    //              Le rayon est en unité de pixel par rapport au centre de l'image.
    //PARAMETRE 3 : Choix du filtre en entrant une chaine de caractère :
    //              - "PB" correspond au filtre PASSE-BAS
    //              - "PH" correspond au filtre PASSE-HAUT

    Mat image = image_entree.clone();
    Mat im_filtree;
    //Calcul de la FFT -> Réel/Complex et Amplitude

    Mat amplitude;
    Mat image_fft = fft_image(image);
    vector<Mat> ReelImaginaire; //Stockage de la partie réelle et imaginaire dans ce vecteur

    split(image_fft, ReelImaginaire); //Remplissage du vecteur à 2 dimension de matrices
    magnitude(ReelImaginaire[0], ReelImaginaire[1], amplitude); //Calcul de l'amplitude
    amplitude = centrer_fft(amplitude); //Centrage de l'amplitude en 0

    //Affichage de la DFT avant filtrage
    amplitude = normalisation_fft(amplitude); //Normalisation de l'amplitude pour l'affichage
    amplitude.convertTo(amplitude, CV_8UC1);
    afficher(amplitude, "Affichage de la DFT");
    amplitude.convertTo(amplitude, CV_64FC1);


    Point centre(image.rows / 2, image.cols / 2); //Position du filtre (centre de l'image ici)

    //Centrage de la DFT pour la partie réelle et complexe afin de procéder au filtrage.
    ReelImaginaire[0] = centrer_fft(ReelImaginaire[0]);
    ReelImaginaire[1] = centrer_fft(ReelImaginaire[1]);

    if (filtre == "PB")
    {
        int R = sqrt((image.rows / 2) * (image.rows / 2) + (image.cols / 2) * (image.cols / 2)); //Rayon externe fixe pour le passe-bas. (Commence aux bords de l'image)

        //La fonction circle permet de tracer un cercle dans l'image "amplitude", aux coordonnées "centre", de rayon "R", d'intensité "0" et d'épaisseur "2*R - rayon
        //Ici on exploite la fonction circle pour créer un cercle noir qui dépasse largement l'image et dont on contrôle le rayon par l'épaisseur interne.
        //L'épaisseur correspond au double du rayon interne du filtre

        //Application du filtre sur l'amplitude pour la visualisation

        circle(amplitude, centre, R, 0, 2 * R - rayon); //Passe-Bas sur l'amplitude
        //Application du filtre sur la DFT

        circle(ReelImaginaire[0], centre, R, 0, 2 * R - rayon); //Passe-Bas sur la partie réelle
        circle(ReelImaginaire[1], centre, R, 0, 2 * R - rayon); //Passe-Bas sur la partie imaginaire
    }

    if (filtre == "PH")
    {
        //La fonction circle permet de tracer un cercle dans l'image "amplitude", aux coordonnées "centre", de rayon "rayon", d'intensité "0" et d'épaisseur "-1" ce qui signifie que le cercle sera remplis.

        //Application du filtre sur l'amplitude pour la visualisation

        circle(amplitude, centre, rayon, 0, -1); //Passe-Haut sur l'amplitude
        //Application du filtre sur la DFT

        circle(ReelImaginaire[0], centre, rayon, 0, -1); //Passe-haut sur la partie réelle
        circle(ReelImaginaire[1], centre, rayon, 0, -1); //Passe-haut sur la partie imaginaire
    }

    //Visualisation de l'amplitude après filtrage
    amplitude.convertTo(amplitude, CV_8UC1);

    afficher(amplitude, "Impact du filtre sur la DFT");

    //Décentrage de la DFT
    ReelImaginaire[0] = centrer_fft(ReelImaginaire[0]);
    ReelImaginaire[1] = centrer_fft(ReelImaginaire[1]);

    //Concaténation de la partie réelle et imaginaire dans une matrice à deux composantes (réel et complexe)
    merge(ReelImaginaire, im_filtree);

    //Calcul de la DFT inverse, normalisation et affichage
    im_filtree = inverse_fft_image(im_filtree); //TF Inverse
    im_filtree.convertTo(im_filtree, CV_8UC1);
    normalize(im_filtree, im_filtree, 0, 255, NORM_MINMAX);
    afficher(im_filtree, "Image filtrée");
}


Mat centrer_fft(Mat fft_image)
{
    //PARAMETRE : La matrice image A UNE SEULE COMPOSANTE dont les cadrants sont à inverser.
    // Q1,Q2,Q3 et Q4 correspondent respectivement aux quatres régions de l'image (l'image est divisé en 4 régions égales).
    // L'objectif est d'inverser ces quatres cadrants afin que l'origine de l'image ne soit plus situé au bord, mais au centre.

    Mat Q1 = fft_image(Rect(0, 0, (int)fft_image.cols / 2, (int)fft_image.rows / 2)); //Attribution de chaque cadrant à la région de l'image
    Mat Q2 = fft_image(Rect(0, (int)fft_image.rows / 2, (int)fft_image.cols / 2, (int)fft_image.rows / 2));
    Mat Q3 = fft_image(Rect((int)fft_image.cols / 2, (int)fft_image.rows / 2, (int)fft_image.cols / 2, (int)fft_image.rows / 2));
    Mat Q4 = fft_image(Rect((int)fft_image.cols / 2, 0, (int)fft_image.cols / 2, (int)fft_image.rows / 2));

    rotate(Q1, Q1, ROTATE_180); //Rotation de 180° pour chaque cadrant
    rotate(Q2, Q2, ROTATE_180);
    rotate(Q3, Q3, ROTATE_180);
    rotate(Q4, Q4, ROTATE_180);

    return(fft_image);
}

void FiltreOrdreDeux(Mat image_entree, int R1, int R2, string filtre)
{
    //PARAMETRE 1 : L'image à filtrer
    //PARAMETRE 2 : Le rayon du premier cercle R1 qui correspond à la première fréquence de coupure du filtre, avec R2>R1.
    //PARAMETRE 3 : Le second rayon R2 qui vient définir la seconde fréquence de coupure.
    //PARAMETRE 4 : Choix du filtre en entrant une chaine de caractère :
    //              - "PB" correspond au filtre PASSE-BANDE
    //              - "CB" correspond au filtre COUPE-BANDE

    Mat image = image_entree.clone();
    Mat im_filtree;
    //Calcul de la FFT -> Réel/Complex et Amplitude

    Mat amplitude;
    Mat image_fft = fft_image(image);
    vector<Mat> ReelImaginaire; //Stockage de la partie réelle et imaginaire dans ce vecteur

    split(image_fft, ReelImaginaire); //Remplissage du vecteur à 2 dimension de matrices
    magnitude(ReelImaginaire[0], ReelImaginaire[1], amplitude); //Calcul de l'amplitude
    amplitude = centrer_fft(amplitude); //Centrage de l'amplitude en 0

    //Affichage de la DFT avant filtrage
    amplitude = normalisation_fft(amplitude); //Normalisation de l'amplitude pour l'affichage
    amplitude.convertTo(amplitude, CV_8UC1);
    afficher(amplitude, "Affichage de la DFT");
    amplitude.convertTo(amplitude, CV_64FC1);

    Point centre(image.rows / 2, image.cols / 2); //Position du filtre (centre de l'image ici)

    //Centrage de la DFT pour la partie réelle et complexe afin de procéder au filtrage.
    ReelImaginaire[0] = centrer_fft(ReelImaginaire[0]);
    ReelImaginaire[1] = centrer_fft(ReelImaginaire[1]);

    if (filtre == "PB")
    {
        int R = sqrt((image.rows / 2) * (image.rows / 2) + (image.cols / 2) * (image.cols / 2)); //Rayon externe fixe pour le passe-bas. (Commence aux bords de l'image)

        //La fonction circle permet de tracer un cercle dans l'image "amplitude", aux coordonnées "centre", de rayon "R", d'intensité "0" et d'épaisseur "2*R - rayon
        //Ici on exploite la fonction circle pour créer un cercle noir qui dépasse largement l'image et dont on contrôle le rayon par l'épaisseur interne.
        //L'épaisseur correspond au double du rayon interne du filtre

        //Application du filtre sur l'amplitude pour la visualisation

        circle(amplitude, centre, R, 0, 2 * R -1 - 2*R2-1); //Coupe-Bande : Passe-bas sur l'amplitude
        circle(amplitude, centre, R1, 0, -1); //Coupe-Bande : Passe-haut sur l'amplitude
        //Application du filtre sur la DFT
        //Il s'agit d'une somme entre un passe haut et un passe-bas

        circle(ReelImaginaire[0], centre, R, 0, 2*R-1-2*R2-1); //Passe-Bas sur la partie réelle
        circle(ReelImaginaire[1], centre, R, 0, 2*R-1-2*R2-1); //Passe-Bas sur la partie imaginaire
        circle(ReelImaginaire[0], centre, R1, 0, -1); //Passe-Haut sur la partie réelle
        circle(ReelImaginaire[1], centre, R1, 0, -1); //Passe-Haut sur la partie imaginaire
    }

    if (filtre == "CB")
    {
        //int R = sqrt((image.rows / 2) * (image.rows / 2) + (image.cols / 2) * (image.cols / 2)); //Rayon externe fixe pour le passe-bas. Il s'agit du rayon d'un cercle passant par les 4 côtés de l'image.


        //Application du filtre sur l'amplitude pour la visualisation
        int largeur = R2 - R1; //On calcule la relation entre les rayons R1 et R2, et la largeur
        int rayon = R1 + (int)((largeur) / 2); //Le rayon du cercle coupe bande sera le plus petit rayon auquel s'ajoute la moitié de la largeur du cercle.

        circle(amplitude, centre, rayon, 0, largeur); //Passe-Bande sur l'amplitude
        //Application du filtre sur la DFT

        circle(ReelImaginaire[0], centre, rayon, 0, largeur); //Passe-bande sur la partie réelle
        circle(ReelImaginaire[1], centre, rayon, 0, largeur); //Passe-bande sur la partie imaginaire
    }

    //Visualisation de l'amplitude après filtrage
    amplitude.convertTo(amplitude, CV_8UC1);
    afficher(amplitude, "Impact du filtre sur la DFT");

    //Décentrage de la DFT
    ReelImaginaire[0] = centrer_fft(ReelImaginaire[0]);
    ReelImaginaire[1] = centrer_fft(ReelImaginaire[1]);

    //Concaténation de la partie réelle et imaginaire dans une matrice à deux composantes (réel et complexe)
    merge(ReelImaginaire, im_filtree);

    //Calcul de la DFT inverse, normalisation et affichage
    im_filtree = inverse_fft_image(im_filtree); //TF Inverse
    im_filtree.convertTo(im_filtree, CV_8UC1);
    normalize(im_filtree, im_filtree, 0, 255, NORM_MINMAX);
    afficher(im_filtree, "Image filtrée");
}




Mat inverse_fft_image (Mat image_fft)
{
    //PARAMETRE 1 : Matrice au format MAT constitué de 2 COMPOSANTES par case : [Réel,Imaginaire]. La DFT inverse requiert le nombre complêxe issu de la DFT.
    //Cette fonction réalise la DFT inverse d'une matrice MAT.

    dft(image_fft, image_fft, DFT_INVERSE | DFT_REAL_OUTPUT); //Calcul de la TF2D inverse. On ne veut qu'une partie réelle puisqu'il s'agit de l'image résultante
    normalize(image_fft, image_fft, 0, 255, NORM_MINMAX); //On normalise le résultat pour l'affichage
    image_fft.convertTo(image_fft, CV_8UC1); //Conversion du type pour l'affichage

    return(image_fft);

}


Mat AffFiltreOrdreUn(Mat image_entree ,int rayon,string filtre)
{
    //PARAMETRE 1 : L'image à filtrer
    //PARAMETRE 2 : Le rayon du cercle correspond à la partie de la FFT qui sera conservé (si passe-bas) ou mise à 0 (si passe-haut. Tout ce qui est extérieur au cercle sera mis à 0 (PB) ou 1 (PH).
    //              Le rayon est en unité de pixel par rapport au centre de l'image.
    //PARAMETRE 3 : Choix du filtre en entrant une chaine de caractère :
    //              - "PB" correspond au filtre PASSE-BAS
    //              - "PH" correspond au filtre PASSE-HAUT

    Mat image = image_entree.clone();
    Mat im_filtree;
    //Calcul de la FFT -> Réel/Complex et Amplitude

    Mat amplitude;
    Mat image_fft = fft_image(image);
    vector<Mat> ReelImaginaire; //Stockage de la partie réelle et imaginaire dans ce vecteur

    split(image_fft, ReelImaginaire); //Remplissage du vecteur à 2 dimension de matrices
    magnitude(ReelImaginaire[0], ReelImaginaire[1], amplitude); //Calcul de l'amplitude
    amplitude = centrer_fft(amplitude); //Centrage de l'amplitude en 0

    //Affichage de la DFT avant filtrage
    amplitude = normalisation_fft(amplitude); //Normalisation de l'amplitude pour l'affichage
    amplitude.convertTo(amplitude, CV_8UC1);
    afficher(amplitude, "Affichage de la DFT");
    amplitude.convertTo(amplitude, CV_64FC1);


    Point centre(image.rows / 2, image.cols / 2); //Position du filtre (centre de l'image ici)

    //Centrage de la DFT pour la partie réelle et complexe afin de procéder au filtrage.
    ReelImaginaire[0] = centrer_fft(ReelImaginaire[0]);
    ReelImaginaire[1] = centrer_fft(ReelImaginaire[1]);

    if (filtre == "PB")
    {
        int R = sqrt((image.rows / 2) * (image.rows / 2) + (image.cols / 2) * (image.cols / 2)); //Rayon externe fixe pour le passe-bas. (Commence aux bords de l'image)

        //La fonction circle permet de tracer un cercle dans l'image "amplitude", aux coordonnées "centre", de rayon "R", d'intensité "0" et d'épaisseur "2*R - rayon
        //Ici on exploite la fonction circle pour créer un cercle noir qui dépasse largement l'image et dont on contrôle le rayon par l'épaisseur interne.
        //L'épaisseur correspond au double du rayon interne du filtre

        //Application du filtre sur l'amplitude pour la visualisation

        circle(amplitude, centre, R, 0, 2 * R - rayon); //Passe-Bas sur l'amplitude
        //Application du filtre sur la DFT

        circle(ReelImaginaire[0], centre, R, 0, 2 * R - rayon); //Passe-Bas sur la partie réelle
        circle(ReelImaginaire[1], centre, R, 0, 2 * R - rayon); //Passe-Bas sur la partie imaginaire
    }

    if (filtre == "PH")
    {
        //La fonction circle permet de tracer un cercle dans l'image "amplitude", aux coordonnées "centre", de rayon "rayon", d'intensité "0" et d'épaisseur "-1" ce qui signifie que le cercle sera remplis.

        //Application du filtre sur l'amplitude pour la visualisation

        circle(amplitude, centre, rayon, 0, -1); //Passe-Haut sur l'amplitude
        //Application du filtre sur la DFT

        circle(ReelImaginaire[0], centre, rayon, 0, -1); //Passe-haut sur la partie réelle
        circle(ReelImaginaire[1], centre, rayon, 0, -1); //Passe-haut sur la partie imaginaire
    }

    //Visualisation de l'amplitude après filtrage
    amplitude.convertTo(amplitude, CV_8UC1);

    return(amplitude);
}
