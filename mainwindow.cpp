#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "listaseq.h"
#include "listaenc.h"
#include "pilha.h"
#include "fila.h"
#include "arvore.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnListaSec_clicked()
{
    ListaSeq listaSeq;

    listaSeq.exec();
}



void MainWindow::on_btnListaEnc_clicked()
{
    ListaEnc listaEnc;

    listaEnc.exec();
}


void MainWindow::on_btnPilha_clicked()
{
    Pilha pilha;

    pilha.exec();
}


void MainWindow::on_btnFila_clicked()
{
    Fila fila;

    fila.exec();
}

void MainWindow::on_btnArvore_clicked()
{
    Arvore arvore;

    arvore.exec();
}

