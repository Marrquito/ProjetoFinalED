#include "pilha.h"
#include "ui_pilha.h"

Pilha::Pilha(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Pilha)
{
    ui->setupUi(this);
}

Pilha::~Pilha()
{
    delete ui;
}
