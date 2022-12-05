#include "inc/listaseq.h"
#include "ui_listaseq.h"

ListaSeq::ListaSeq(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ListaSeq)
{
    ui->setupUi(this);
}

ListaSeq::~ListaSeq()
{
    delete ui;
}
