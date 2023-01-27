#include "universimple.h"
#include <opencv2/opencv.hpp>

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    UniversImple w;
    w.show();
    return a.exec();
}
