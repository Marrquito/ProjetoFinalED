#include "inc/listaseq.h"
#include "ui_listaseq.h"
#include <QMessageBox>

#include <iostream>

ListaSeq::ListaSeq(QWidget *parent) : QDialog(parent), ui(new Ui::ListaSeq){
    ui->setupUi(this);
    this->setWindowTitle("Lista Sequencial!");

    nElementos = 0;
}

ListaSeq::~ListaSeq(){
    delete ui;
}

bool ListaSeq::vazia(){
    if (nElementos == 0){
        return true;

    }else{
        return false;
    }
}

bool ListaSeq::cheia(){
    if (nElementos == TAM_MAX){
        return true;

    }else{
        return false;
    }
}

int ListaSeq::tamanho(){
    return nElementos;
}

int ListaSeq::elemento(int pos){
    if ((pos > nElementos) || (pos <= 0)){
        return -1;
    }

    return dados[pos-1];
}

int ListaSeq::posicao (int valor){
    for (int i = 0; i < nElementos; i++){
        if (dados[i] == valor){
            return (i + 1);
        }
    }

    return -1;
}

int ListaSeq::posicao (int valor, int desloc){
    for (int i = desloc; i < nElementos; i++){
        if (dados[i] == valor){
            return (i + 1);
        }
    }

    return -1;
}

bool ListaSeq::insere (int pos, int valor){
    if (cheia() || (pos > nElementos + 1) || (pos <= 0)){
        return false;
    }

    for (int i = nElementos; i >= pos; i--){
        dados[i] = dados[i-1];
    }

    dados[pos - 1] = valor;
    nElementos++;

    return true;
}

int ListaSeq::remove(int pos){
    if ((pos > nElementos) || (pos < 1 )){
        return -1;
    }

    int aux = dados[pos-1];

    for (int i = pos - 1; i < nElementos - 1; i++){
        dados[i] = dados[i + 1];
    }

    nElementos--;

    return aux;
}

void ListaSeq::on_btn_add_lista_clicked(){
    QString valor = ui->txt_add_valor->text();
    QString pos   = ui->txt_add_pos->text();
    QString txt;

    if(valor == ""){
        return;
    }

    if(pos == ""){
        pos = "1";
    }

    int v = valor.toInt();
    int p = pos.toInt();

    this->insere(p, v);
    for(int i = 0; i < tamanho(); i++){
        txt.append(QString::number(this->elemento(i + 1)));
        txt.append(" ");
    }

    ui->txt_add_valor->clear();
    ui->txt_add_pos->clear();

    ui->label_lista->setText(txt);
    ui->txt_add_valor->setFocus();
}

void ListaSeq::on_btn_rem_lista_clicked(){
    QString pos = ui->txt_rem_pos->text();
    QString txt;

    if(pos == ""){
        return;
    }

    int p = pos.toInt();

    if(this->remove(p) == -1){
        QMessageBox::information(this, "Erro", "Algum problema aconteceu");
        return;
    }

    for(int i = 0; i < tamanho(); i++){
        txt.append(QString::number(this->elemento(i + 1)));
        txt.append(" ");
    }

    ui->txt_rem_pos->clear();

    ui->label_lista->setText(txt);
    ui->txt_rem_pos->setFocus();
}


void ListaSeq::on_btn_consulta_clicked(){
    QString str;
    QString pos = ui->txt_consulta->text();

    if(pos == ""){
        return;
    }

    int p = pos.toInt();
    int e = this->elemento(p);

    if(e != -1){
        str.append("O valor na posição ");
        str.append(pos);
        str.append(" é ");
        str.append(QString::number(e));

    }else{
        str.append("Nenhum valor foi encontrado");
    }


    QMessageBox::information(this, "Consulta", str);
    ui->txt_consulta->clear();
}