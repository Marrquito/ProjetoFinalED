#include "inc/listaenc.h"
#include "ui_listaenc.h"
#include <stdlib.h>
#include <QString>
#include <QMessageBox>
#include <iostream>

ListaEnc::ListaEnc(QWidget *parent) : QDialog(parent), ui(new Ui::ListaEnc)
{
    ui->setupUi(this);

    cria(&this->minhaLista);
}

ListaEnc::~ListaEnc()
{
    delete ui;
}

void ListaEnc::cria(tLista *lista) {
    lista->cabeca = NULL;
    lista->tamanho = 0;
}

int ListaEnc::vazia(tLista lista) {
    if (lista.tamanho == 0)
        return 1;
    else
        return 0;
}

int ListaEnc::tamanho(tLista lista) {
    return lista.tamanho;
}

int ListaEnc::elemento(tLista lista, int pos, int *dado ) {
    tNo *p;
    int n = 1;

    if (lista.cabeca == NULL) {
            return 0;
    }

    p = lista.cabeca;
    while ((p != NULL) && (n < pos)){
        p = p-> prox;
        n++;
    }

     if (p == NULL) {
            return 0;
     }

    *dado = p->dado;
    return 1;
}

int ListaEnc::posicao(tLista lista, int dado) {
    int n = 1;
    tNo *p;


    if ( lista.cabeca == NULL) {
            return 0;
    }


    p = lista.cabeca;
    while (p != NULL) {

        if (p->dado == dado){
            return n;
        }

        p = p->prox;
        n++;
    }

    return 0;
}

int ListaEnc::insereInicioLista(tLista *lista, int valor) {
    tNo *novoNo;

    novoNo =(tNo *) malloc(sizeof(tNo));
    if (novoNo == NULL) {
         return 0;
    }
    novoNo->dado = valor;

    if(tamanho(*lista) > 1) novoNo->prox = lista->cabeca;
    else novoNo->prox = NULL;
    lista->cabeca = novoNo;
    lista->tamanho++;
    return 1;
}

int ListaEnc::insereMeioLista(tLista *lista, int pos, int dado){
    tNo *p, *novoNo;

    int n = 1;
    p = lista->cabeca;
    while ((n < pos-1) && (p != NULL)){
          p = p->prox;
          n++;
    }

    if (p == NULL) {
            return 0;
    }


    novoNo = (tNo *)  malloc(sizeof(tNo));
    if (novoNo == NULL) {
         return 0;
    }

    novoNo->dado = dado;
    novoNo->prox = p->prox;
    p->prox = novoNo;
    lista->tamanho++;

    return 1;
}

int ListaEnc::inserirFimLista(tLista *lista, int dado){
    tNo *novoNo;

    novoNo =(tNo *)  malloc(sizeof(tNo));
    if (novoNo == NULL) {
         return 0;
    }

    novoNo->dado = dado;
    tNo *ult = lista->cabeca;
    while(ult->prox != NULL){
        ult = ult->prox;
    }

    ult->prox = novoNo;
    novoNo->prox = NULL;
    lista->tamanho++;

    return 1;
}

int ListaEnc::insere(tLista *lista, int pos, int dado ) {

    int  ret, tamanho = lista->tamanho;

    if ((vazia(*lista)) || (pos == 1)){
        ret = insereInicioLista(lista, dado);
        return ret;
    }

    else if (pos == tamanho+1){
        ret = inserirFimLista(lista, dado);
        return ret;
   }

   else{
        ret = insereMeioLista(lista, pos, dado);
        return ret;
   }
}

int ListaEnc::removeInicioLista(tLista *lista, int *dado){
    tNo *p = lista->cabeca;


    *dado = p->dado;


    lista->cabeca = p->prox;
    lista->tamanho--;

    free(p);

    return 1;
}

int ListaEnc::removeNaLista(tLista *lista, int pos, int *dado){
     tNo *aux, *p;
     int n = 1;

     p = lista->cabeca;
     while((n < pos) && (p != NULL)){
           aux = p;
           p = p->prox;
           n++;
     }

     if (p == NULL) {
        return (0);
     }

    *dado = p->dado;
     aux->prox = p->prox;
     lista->tamanho--;

     free(p);
     return 1;
}

int ListaEnc::remov(tLista *lista, int pos, int *dado ) {
    int  ret;

    if (vazia(*lista)) {
            return 0;
    }

    if (pos == 1){
        ret = removeInicioLista(lista, dado);
        return ret;
    }

    else{
        ret = removeNaLista(lista, pos, dado);
        return ret;
    }
}

void ListaEnc::on_btnAddList_clicked()
{
    QString value = ui->txt_value->text();
    QString pos = ui->txt_pos->text();
    QString cont = ui->labelStack->text();
    QString txt;

    if(pos == ""){
        pos = "1";
    }

    insere(&this->minhaLista, value.toInt(), pos.toInt());
    int valor_lista;

    //QMessageBox::information(this, "Removeu", QString::number(minhaLista.tamanho));

    nos* aux = minhaLista.cabeca;

    while(aux != NULL){
        txt.append(QString::number(aux->dado));
        txt.append(" ");
        aux = aux->prox;
    }

    cont.append(value);
    cont.append(" ");
    ui->labelStack->setText(txt);

}

void ListaEnc::on_btnRemList_clicked()
{
    QString value = ui->txt_remove->text();
    QString txt;
    int dado = 0;

    remov(&this->minhaLista, value.toInt(), &dado);
    QMessageBox::information(this, "Removeu", value);

    nos* aux = minhaLista.cabeca;
    while(aux != NULL){
        txt.append(QString::number(aux->dado));
        txt.append(" ");
        aux = aux->prox;
    }

    ui->labelStack->setText(txt);
}


void ListaEnc::on_pushButton_3_clicked() // consultar
{
    QString pos = ui->txt_consult->text();
    QString str;
    int dado = 0;

    elemento(this->minhaLista, pos.toInt(), &dado);
    str.append("elemento consultado: ");
    str.append(QString::number(dado));
    QMessageBox::information(this, "Valor consultado ", str);
}
