#include "accreditation.h"
// Appel des autres fenêtres
#include "ui_accreditation.h"
//#include "accred.h"


#include <QDialog>
#include <QMainWindow>
#include <QMessageBox>
#include <QFileDialog>
#include <QSlider>
#include <QLCDNumber>

#include <QDir>
#include <QComboBox>

#include <iostream>
#include <fstream>

using namespace std;

Accreditation::Accreditation(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Accreditation)
{
    ui->setupUi(this);
}

Accreditation::~Accreditation()
{
    delete ui;
}

void Accreditation::SetAdr(QString adresse)
{
    adr = adresse;
}




void Accreditation::on_Annuler_Accred_clicked()
{
    // retour sur la page arrière

    close();

}


void Accreditation::on_Valider_Accred_clicked()
{
    if(ui->code->text().isEmpty())
    {
        QMessageBox::information(this, "Erreur", "Veuillez vous identifier");

    }

    else
    {
        QString code;

        //Accreditation();
        code = ui->code->text();

        //Accreditation mdp;

        if (code.toStdString() == "AB-01-CD")
        //if (code == "1")
        {
                numero_acces = 1; //ils ont tous les droits
                QMessageBox::information(this, "Information", "Votre numéro d'accréditation est : 1 ");
                //mdp.numero_acces;

                close();
        }
        else if (code.toStdString() == "EF-02-GH")
        //else if (code == "2")
        {
                numero_acces = 2;
                QMessageBox::information(this, "Information", "Votre numéro d'accréditation est : 2");
                //mdp.numero_acces;

                close();
        }
        else
        {
                numero_acces = 0; //Aucun droit
                QMessageBox::information(this, "Information", "Votre numéro d'accréditation est : 0, vous n'avez pas accès à la bibliothèque! Désolés! Essayez les traitements ou volez un numéro d'accréditation");


                close();

            }
    }


}

