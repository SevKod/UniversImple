#include "fentr.h"
#include "ui_fentr.h"
#include "traitement.h"

FenTr::FenTr(QWidget *) :
    QMainWindow(),
    ui(new Ui::FenTr)
{
    ui->setupUi(this);
}

FenTr::~FenTr()
{
    delete ui;
}

void FenTr::FermerFenetre()
{
    close();
}
