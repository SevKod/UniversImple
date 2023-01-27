#ifndef HISTOGRAMME_H
#define HISTOGRAMME_H

#include "qchartview.h"
#include <QDialog>

#include <opencv2/opencv.hpp>
//#include <opencv4/opencv2/opencv.hpp>

namespace Ui {
class histogramme;
}

class histogramme : public QDialog
{
    Q_OBJECT

public:
    explicit histogramme(QWidget *parent = nullptr);
    ~histogramme();
    void hist_pre(cv::Mat image, QImage IMGPRE);
    void hist_post(cv::Mat image_tr, QImage IMGPOST);
    void resizeEvent(QResizeEvent *event);
    void timerEvent(QTimerEvent *te);
    void on_actualiser_clicked();
private:
    Ui::histogramme *ui;
    QChart *histPr;
    QChart *histPo;
    QChartView *histV;
    QImage img_pre;
    QImage img_post;
    QImage im_fen_pre;
    QImage im_fen_post;
    int timerId;
};

#endif // HISTOGRAMME_H
