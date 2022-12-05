#include "listaenc.h"
#include "ui_listaenc.h"

ListaEnc::ListaEnc(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ListaEnc)
{
    ui->setupUi(this);
}

ListaEnc::~ListaEnc()
{
    delete ui;
}
