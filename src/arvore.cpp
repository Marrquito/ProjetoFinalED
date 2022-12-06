#include "inc/arvore.h"
#include "ui_arvore.h"
#include <QProcess>

Arvore::Arvore(QWidget *parent) : QDialog(parent), ui(new Ui::Arvore)
{
    ui->setupUi(this);
}

Arvore::~Arvore()
{
    delete ui;
}
