#ifndef LISTAENC_H
#define LISTAENC_H

#include <QDialog>

namespace Ui {
class ListaEnc;
}

class ListaEnc : public QDialog
{
    Q_OBJECT

public:
    explicit ListaEnc(QWidget *parent = nullptr);
    ~ListaEnc();

private:
    Ui::ListaEnc *ui;
};

#endif // LISTAENC_H
