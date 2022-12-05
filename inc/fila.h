#ifndef FILA_H
#define FILA_H

#include <QDialog>

namespace Ui {
class Fila;
}

class Fila : public QDialog
{
    Q_OBJECT

public:
    explicit Fila(QWidget *parent = nullptr);
    ~Fila();

private:
    Ui::Fila *ui;
};

#endif // FILA_H
