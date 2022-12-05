#ifndef PILHA_H
#define PILHA_H

#include <QDialog>

namespace Ui {
class Pilha;
}

class Pilha : public QDialog
{
    Q_OBJECT

public:
    explicit Pilha(QWidget *parent = nullptr);
    ~Pilha();

private:
    Ui::Pilha *ui;
};

#endif // PILHA_H
