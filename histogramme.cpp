#include "histogramme.h"
#include "ui_histogramme.h"
#include "fonctions.h"

#include "QtCharts/qbarset.h"
//#include "qbarseries.h"
#include "qchart.h"
#include "qbarcategoryaxis.h"
#include "qvalueaxis.h"
#include "qchartview.h"
#include <QStackedBarSeries>

#include <opencv2/opencv.hpp>
//#include <opencv4/opencv2/opencv.hpp>


#include <QString>

//#include <QtCharts>
//using namespace QtCharts;

histogramme::histogramme(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::histogramme)
{
    ui->setupUi(this);
}

void histogramme::resizeEvent(QResizeEvent *event){

    QDialog::resizeEvent(event);
    //histPr->adjustSize();

    //PRE
    //Label pre

    QImage img_out_pre = im_fen_pre.copy();
    img_out_pre = img_out_pre.scaledToWidth(ui->LBLpre->width(), Qt::SmoothTransformation);
    img_out_pre = img_out_pre.scaledToHeight(ui->LBLpre->height(), Qt::SmoothTransformation);
    ui->LBLpre->setPixmap(QPixmap::fromImage(img_out_pre));

    //Chart pre

    QChartView *chartView = new QChartView(histPr);
    chartView->adjustSize();
    chartView->setRenderHint(QPainter::Antialiasing);
    ui->pre->setViewport(chartView);

    //POST
    //Label post

    QImage img_out_post = im_fen_post.copy();
    img_out_post = img_out_post.scaledToWidth(ui->LBLpost->width(), Qt::SmoothTransformation);
    img_out_post = img_out_post.scaledToHeight(ui->LBLpost->height(), Qt::SmoothTransformation);
    ui->LBLpost->setPixmap(QPixmap::fromImage(img_out_post));

    //Chart post

    QChartView *chartViewPost = new QChartView(histPo);
    chartViewPost->adjustSize();
    chartViewPost->setRenderHint(QPainter::Antialiasing);
    ui->post->setViewport(chartViewPost);



    //Délais pour laisser le temps que l'image soit resize. Puis, on appelle la fonction d'actualisation
    if (timerId){
        killTimer(timerId);
        timerId = 0;
    }
    timerId = startTimer(100);
}

void histogramme::timerEvent(QTimerEvent *te){
    on_actualiser_clicked();
    killTimer(te->timerId());
    timerId = 0;
}


histogramme::~histogramme()
{
    delete ui;
}

void histogramme::hist_pre(Mat image, QImage IMGPRE)
{
    int i;
    QStackedBarSeries *hist = new QStackedBarSeries();
    QBarSet *gris = new QBarSet("");
    QStringList categories;
    gris->setColor(Qt::black);
    vector<double> h = histo(image);
    //QImage img_out(image.data, image.cols, image.rows, static_cast<int>(image.step), QImage::Format_Grayscale8);
    img_pre = IMGPRE.copy();
    QStringList c;

    for (i=0;i<256;i++)
    {
        if (i%20 == 0)
        {
            c.append(QString::number(i));
        }
        *gris << h[i];
    }

    categories << c;
    hist->append(gris);
    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append("Intensités");

    QValueAxis *rangeX = new QValueAxis();
    rangeX->applyNiceNumbers();
    rangeX->setRange(0,256);
    rangeX->setTickCount(9);

    QValueAxis *axisY = new QValueAxis();
    hist->attachAxis(axisY);
    axisY->setRange(0,*max_element(h.begin(), h.end()));
    axisY->setTickCount(10);

    QChart *chart = new QChart();

    chart->removeAllSeries();
    chart->addSeries(hist);

    chart->setAnimationOptions(QChart::AllAnimations);
    chart->addAxis(rangeX, Qt::AlignBottom);
    chart->addAxis(axisX, Qt::AlignBottom);
    chart->addAxis(axisY, Qt::AlignLeft);

    chart->legend()->setVisible(false);
    chart->zoomReset();
    chart->adjustSize();

    im_fen_pre = img_pre;
    histPr = chart;

}


void histogramme::hist_post(Mat image_tr, QImage IMGPOST)
{
    if (image_tr.empty() == 1)
    {
        ui->LBLpost->setText("Pas de traitement réalisé");
    }
    else
    {
        int i;
        QStackedBarSeries *hist = new QStackedBarSeries();
        QBarSet *gris = new QBarSet("");
        QStringList categories;
        gris->setColor(Qt::black);
        vector<double> h = histo(image_tr);
        img_post = IMGPOST.copy();
        QStringList c;

        for (i=0;i<256;i++)
        {
            if (i%20 == 0)
            {
                c.append(QString::number(i));
            }
            *gris << h[i];
        }

        categories << c;
        hist->append(gris);
        QBarCategoryAxis *axisX = new QBarCategoryAxis();
        axisX->append("Intensités");

        QValueAxis *rangeX = new QValueAxis();
        rangeX->applyNiceNumbers();
        rangeX->setRange(0,256);
        rangeX->setTickCount(9);

        QValueAxis *axisY = new QValueAxis();
        hist->attachAxis(axisY);
        axisY->setRange(0,*max_element(h.begin(), h.end()));
        axisY->setTickCount(10);

        QChart *chart = new QChart();

        chart->removeAllSeries();
        chart->addSeries(hist);

        chart->setAnimationOptions(QChart::AllAnimations);
        chart->addAxis(rangeX, Qt::AlignBottom);
        chart->addAxis(axisX, Qt::AlignBottom);
        chart->addAxis(axisY, Qt::AlignLeft);

        chart->legend()->setVisible(false);
        chart->zoomReset();
        chart->adjustSize();

        im_fen_post = img_post;
        histPo = chart;

    }
}

void histogramme::on_actualiser_clicked()
{
    //Actualisation des images après scaling
    //Chart Pre

    QChartView *chartView = new QChartView(histPr);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->adjustSize();
    ui->pre->setViewport(chartView);

    //Label pre

    int w = ui->LBLpre->width();
    int h = ui->LBLpre->height();
    QImage img_out_pre = im_fen_pre.copy();
    img_out_pre = img_out_pre.scaledToWidth(ui->LBLpre->width(), Qt::SmoothTransformation);
    img_out_pre = img_out_pre.scaledToHeight(ui->LBLpre->height(), Qt::SmoothTransformation);
    ui->LBLpre->setPixmap(QPixmap::fromImage(img_out_pre).scaled(w,h,Qt::KeepAspectRatio));



    //Chart Post

    QChartView *chartViewPost = new QChartView(histPo);
    chartViewPost->setRenderHint(QPainter::Antialiasing);
    chartViewPost->adjustSize();
    ui->post->setViewport(chartViewPost);

    //Label Post

    w = ui->LBLpost->width();
    h = ui->LBLpost->height();
    QImage img_out_post = im_fen_post.copy();
    img_out_post = img_out_post.scaledToWidth(ui->LBLpost->width(), Qt::SmoothTransformation);
    img_out_post = img_out_post.scaledToHeight(ui->LBLpost->height(), Qt::SmoothTransformation);
    ui->LBLpost->setPixmap(QPixmap::fromImage(img_out_post).scaled(w,h,Qt::KeepAspectRatio));


}

