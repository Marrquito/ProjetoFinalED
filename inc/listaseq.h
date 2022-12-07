#ifndef LISTASEQ_H
#define LISTASEQ_H

#include <QDialog>
#include <QMessageBox>

#define TAM_MAX 100

namespace Ui
{
    class ListaSeq;
}

class ListaSeq : public QDialog
{
    Q_OBJECT

    public:
        explicit ListaSeq(QWidget parent = nullptr);
        ~ListaSeq();

        bool vazia();
        bool cheia();
        int  tamanho();
        int  elemento(int pos);
        int  posicao (int valor);
        int  posicao (int valor, int desloc);
        bool insere (int pos, int valor);
        int  remove(int pos);
        QString mostra();

    private slots:
        void on_btn_add_lista_clicked();
        void on_btn_rem_lista_clicked();
        void on_btn_consulta_clicked();

private:
        Ui::ListaSequi;
        int dados[TAM_MAX];
        int nElementos;
};

#endif // LISTASEQ_H