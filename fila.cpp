#include "fila.h"
#include "ui_fila.h"

Fila::Fila(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Fila)
{
    ui->setupUi(this);
}

Fila::~Fila()
{
    delete ui;
}
