#ifndef PILHA_H
#define PILHA_H

#include <QDialog>

namespace Ui
{
    class Pilha;
}

typedef struct no
{
    int conteudo;
    struct no* prox;
}No_t;

typedef struct
{
    int tamanho;
    No_t* topo;
}Pilha_t;

class Pilha : public QDialog
{
    Q_OBJECT

    public:
        explicit Pilha(QWidget *parent = nullptr);
        ~Pilha();
        void inicia(Pilha_t* pilha);
        int vazia(Pilha_t* pilha);
        int tamanho(Pilha_t* pilha);
        int getTopo(Pilha_t pilha, int* data);
        int push(Pilha_t* pilha, int value);
        int pop(Pilha_t* pilha, int* data);


    private slots:
        void on_btnAddPilha_clicked();
        void on_btnRemoverTopo_clicked();

        void on_btnConsultarTopo_clicked();

private:
        Ui::Pilha *ui;
        Pilha_t p1;
        Pilha_t* pilha;
};

#endif // PILHA_H
