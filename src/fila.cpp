#include "inc/fila.h"
#include "ui_fila.h"
#include <QString>
#include <QMessageBox>
#include <iostream>

Fila::Fila(QWidget *parent) : QDialog(parent), ui(new Ui::Fila)
{
    ui->setupUi(this);
    this->setWindowTitle("Fila!");

    this->f1 = {
        .inicio = 0,
        .fim = 0,
        .nElementos = 0
    };

    this->fila = &f1;

    this->inicia(this->fila);
}

Fila::~Fila()
{
    delete ui;
}

void Fila::on_btnAddFila_clicked()
{
    QString value = ui->txt_valor_fila->text();
    QString txt   = ui->mostrar_fila->text();
    int val = value.toInt();

    this->insere(this->fila, val);
    txt.append("\n");
    txt.append(value);

    ui->txt_valor_fila->clear();
    ui->mostrar_fila->setText(txt);
    ui->txt_valor_fila->setFocus();
}

void Fila::on_btnRemoverprimeiro_clicked()
{
    int num = 0;
    QString str;
    QString stack = ui->mostrar_fila->text();

    if(!remove(this->fila, &num))
    {
        str.append("Fila vazia!");
        QMessageBox::information(this, "Removed element", str);
        return;
    }

    str.append("Elemento removido: ");
    str.append(QString::number(num));

    stack.replace(QString::number(num), "");
    stack = stack.trimmed();
    ui->mostrar_fila->setText(stack);
    QMessageBox::information(this, "Removed element", str);
    ui->txt_valor_fila->setFocus();
}

void Fila::on_btnConsultarprimeiro_clicked()
{
    int num = 0;
    QString str;

    if(!primeiro(this->fila, &num))
    {
        str.append("Fila vazia!");
        QMessageBox::information(this, "Removed element", str);
        return;
    }

    str.append("Primeiro da fila: ");
    str.append(QString::number(num));

    QMessageBox::information(this, "STACK TOP", str);
    ui->txt_valor_fila->setFocus();
}

void Fila::inicia(Fila_t* fila)
{
    fila->inicio = 0;
    fila->nElementos = 0;
    fila->fim=-1;
    fila->inicio=0;
}

/** Verifica se a Fila está vazia */
bool Fila::vazia(Fila_t* fila) {
    return (fila->nElementos == 0);
}

/**Verifica se a Fila está cheia */
bool Fila::cheia(Fila_t* fila) {
    return (fila->nElementos == TAM_MAX);
}

/** Obtém o tamanho da Fila */
int Fila::tamanho(Fila_t* fila) {
    return fila->nElementos;
}

/** Consulta o elemento do início da fila.*/
int Fila::primeiro(Fila_t* fila, int* dado) {
    if (this->vazia(this->fila))
        return 0; // Erro: Fila vazia

    *dado = fila->dados[fila->inicio];

    return 1;
}

/**Insere um elemento no fim de uma fila*/
bool Fila::insere(Fila_t* fila, int valor) {
    if (this->cheia(this->fila))
        return false;

    fila->fim = (fila->fim + 1) % TAM_MAX; // Circularidade
    fila->dados[fila->fim] = valor;
    fila->nElementos++;
    return true;
}

int Fila::remove(Fila_t* fila,int* data) {
    if (this->vazia(this->fila))
        return 0;

    // Guarda o valor a ser removido
    //int valor = primeiro();
    int valor = fila->dados[fila->inicio];
    *data = valor;

    // Atualiza o atributo inicio;
    fila->inicio = (fila->inicio + 1) % TAM_MAX; //Circularidade
    fila->nElementos--;
    return 1;
}
