#ifndef LISTAENC_H
#define LISTAENC_H

#include <QDialog>

namespace Ui {
class ListaEnc;
}

typedef struct nos{
    int dado;
    struct nos *prox;
}tNo;

typedef struct lista{
   struct nos *cabeca;
   int tamanho;
}tLista;

class ListaEnc : public QDialog
{
    Q_OBJECT

public:
    explicit ListaEnc(QWidget *parent = nullptr);
    ~ListaEnc();
    void cria(tLista *lista);
    int vazia(tLista lista);
    int tamanho(tLista lista);
    int elemento(tLista lista, int pos, int *dado );
    int posicao(tLista lista, int dado);
    int insere(tLista *lista, int pos, int dado );
    int remov(tLista *lista, int pos, int *dado );
    int insereInicioLista(tLista *lista, int valor);
    int insereMeioLista(tLista *lista, int pos, int dado);
    int inserirFimLista(tLista *lista, int dado);
    tLista minhaLista;


private:
    Ui::ListaEnc *ui;
    int removeInicioLista(tLista *lista, int *dado);
    int removeNaLista(tLista *lista, int pos, int *dado);

private slots:


    void on_btnAddList_clicked();
    void on_btnRemList_clicked();
    void on_pushButton_3_clicked();
};

#endif // LISTAENC_H
