#ifndef FENTR_H
#define FENTR_H

#include <QMainWindow>

namespace Ui {
class FenTr;
}

class FenTr : public QMainWindow
{
    Q_OBJECT

public:
    explicit FenTr(QWidget *parent = nullptr);
    ~FenTr();

private:
    Ui::FenTr *ui;
    void FermerFenetre();
};

#endif // FENTR_H
