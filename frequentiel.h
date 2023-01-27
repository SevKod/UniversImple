#ifndef FREQUENTIEL_H
#define FREQUENTIEL_H

#include <QDialog>
#include <stdio.h>
#include <iostream>

#include <opencv2/opencv.hpp>
//#include <opencv4/opencv2/opencv.hpp>


namespace Ui {
class frequentiel;
}

class frequentiel : public QDialog
{
    Q_OBJECT

public:
    explicit frequentiel(QWidget *parent = nullptr);
    ~frequentiel();
    void imgpre(cv::Mat imgMatNdG, QImage imgNdG, int filtre);
    void resizeEvent(QResizeEvent *);

    QImage img_pre;
    cv::Mat imgMat_pre;
    QImage img_post;
    cv::Mat imgMat_post;
    QImage img_fen_pre;
    QImage img_fen_post;

    cv::Mat imgMat_freq_pre;
    QImage img_fen_freq_pre;
    cv::Mat imgMat_freq_post;
    QImage img_fen_freq_post;
    cv::Mat Reel;
    cv::Mat Imag;

    int PB = 0;
    int PH = 0;
    int PBA = 0;
    int CB = 0;
    int VALIDER;

private slots:
    void on_SLIDPB_sliderMoved(int position);

    void on_SLIDPH_sliderMoved(int position);

    void on_SLIDRINFPB_sliderMoved(int position);

    void on_SLIDRSUPPB_sliderMoved(int position);

    void on_SLIDRINFCB_sliderMoved(int position);

    void on_SLIDRSUPCB_sliderMoved(int position);

    void on_VALIDPB_clicked();

    void on_VALIDPH_clicked();

    void on_VALIDPBA_clicked();

    void on_VALIDCB_clicked();

    void on_SLIDXCB_sliderMoved(int position);

    void on_SLIDYCB_sliderMoved(int position);

    void on_SLIDXPBA_sliderMoved(int position);

    void on_SLIDYPBA_sliderMoved(int position);

    void on_SLIDXPH_sliderMoved(int position);

    void on_SLIDYPH_sliderMoved(int position);

    void on_SLIDXPB_sliderMoved(int position);

    void on_SLIDYPB_sliderMoved(int position);

private:
    Ui::frequentiel *ui;
};

#endif // FREQUENTIEL_H
