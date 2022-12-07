#ifndef FILA_H
#define FILA_H

#define TAM_MAX 100

#include <QDialog>

namespace Ui {
class Fila;
}

typedef struct
{
    int inicio;
    int fim;
    int nElementos;
    int dados[TAM_MAX];

}Fila_t;

class Fila : public QDialog
{
    Q_OBJECT

    public:
        explicit Fila(QWidget *parent = nullptr);
        ~Fila();
        void inicia(Fila_t* fila);
        bool vazia(Fila_t* fila);
        bool cheia(Fila_t* fila);
        int tamanho(Fila_t* fila);
        int primeiro(Fila_t* fila, int* data);
        bool insere(Fila_t* fila, int valor);
        int remove(Fila_t* fila, int* data);

    private slots:
        void on_btnAddFila_clicked();
        void on_btnRemoverprimeiro_clicked();

        void on_btnConsultarprimeiro_clicked();

    private:
        Ui::Fila *ui;
        Fila_t f1;
        Fila_t* fila;

};

#endif // FILA_H