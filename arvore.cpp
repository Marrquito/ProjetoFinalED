#include "arvore.h"
#include "ui_arvore.h"

Arvore::Arvore(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Arvore)
{
    ui->setupUi(this);
}

Arvore::~Arvore()
{
    delete ui;
}
