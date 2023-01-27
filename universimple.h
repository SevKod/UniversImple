#ifndef UNIVERSIMPLE_H
#define UNIVERSIMPLE_H

#include <QDialog>
#include <QMainWindow>
#include <QtWidgets>
#include <QMessageBox>
#include <QFileDialog>
#include <QSlider>
#include <QLCDNumber>


#include <opencv2/opencv.hpp>
//#include <opencv4/opencv2/opencv.hpp>
//#include "fonctions.h"
#include "traitement.h"
//#include "fentr.h"
#include "bibliotheque.h"

QT_BEGIN_NAMESPACE
namespace Ui { class UniversImple; }
QT_END_NAMESPACE

class UniversImple : public QMainWindow
{
    Q_OBJECT

public:
    UniversImple(QWidget *parent = nullptr);
    ~UniversImple();
    void Retour_Traitement();
    void SetAdr(QString adresse);
    void SetIm(QImage image);
    void AffIm();
    void AffImageBibNDG();
    void resizeEvent(QResizeEvent *event);
    void montrer();
    void OpenTr();

private slots:

    void on_APROPOS_triggered();

    void on_actionImporter_une_image_triggered();

    void on_traitements_clicked();

    void on_bibliotheque_clicked();

    void on_actionImporter_une_biblioth_que_triggered();

private:
    Ui::UniversImple *ui;
    Traitement *traitement;
    Bibliotheque *bibliotheque;
    QString adr;
    QImage img, im_fen;

};
#endif // UNIVERSIMPLE_H
