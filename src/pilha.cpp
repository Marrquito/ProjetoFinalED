#include "inc/pilha.h"
#include "ui_pilha.h"
#include <QString>
#include <QMessageBox>
#include <iostream>

Pilha::Pilha(QWidget *parent) : QDialog(parent), ui(new Ui::Pilha)
{
    ui->setupUi(this);
    this->setWindowTitle("Pilha!");

    this->p1 = {
        .tamanho = 0,
        .topo    = NULL
    };

    this->pilha = &p1;

    this->inicia(this->pilha);
}

Pilha::~Pilha()
{
    delete ui;
}

void Pilha::on_btnAddPilha_clicked()
{
    QString value = ui->txt_value->text();
    QString txt   = ui->labelStack->text();
    int val = value.toInt();

    this->push(this->pilha, val);
    value.append("\n");
    value.append(txt);

    ui->txt_value->clear();
    ui->labelStack->setText(value);
    ui->txt_value->setFocus();
}

void Pilha::on_btnRemoverTopo_clicked()
{
    int num = 0;
    QString str;
    QString stack = ui->labelStack->text();

    if(!pop(this->pilha, &num))
    {
        str.append("Pilha vazia!");
        QMessageBox::information(this, "Removed element", str);
        return;
    }

    str.append("Elemento removido: ");
    str.append(QString::number(num));

    stack.replace(QString::number(num), "");
    stack = stack.trimmed();
    ui->labelStack->setText(stack);
    QMessageBox::information(this, "Removed element", str);
    ui->txt_value->setFocus();
}

void Pilha::on_btnConsultarTopo_clicked()
{
    int num = 0;
    QString str;

    if(!getTopo(*this->pilha, &num))
    {
        str.append("Pilha vazia!");
        QMessageBox::information(this, "Removed element", str);
        return;
    }

    str.append("Topo da pilha: ");
    str.append(QString::number(num));

    QMessageBox::information(this, "STACK TOP", str);
    ui->txt_value->setFocus();
}

void Pilha::inicia(Pilha_t* pilha)
{
    pilha->topo = NULL;
    pilha->tamanho = 0;
}

int Pilha::vazia(Pilha_t* pilha)
{
    return (pilha->tamanho == 0);
}

int Pilha::tamanho(Pilha_t* pilha)
{
    return pilha->tamanho;
}

int Pilha::getTopo(Pilha_t pilha, int* data)
{
    if(vazia(&pilha)) return 0;

    *data = pilha.topo->conteudo;

    return 1;
}

int Pilha::push(Pilha_t* pilha, int value)
{
    No_t* node = (No_t *) malloc(sizeof(No_t));

    if(!node) return 0;

    node->conteudo = value;

    node->prox = pilha->topo;
    pilha->topo = node;
    pilha->tamanho++;

    return 1;
}

int Pilha::pop(Pilha_t* pilha, int* data)
{
    No_t* node = NULL;

    if(vazia(pilha)) return 0;

    node = pilha->topo;
    *data = node->conteudo;

    pilha->topo = node->prox;
    pilha->tamanho--;

    free(node);

    return 1;
}
