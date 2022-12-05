#ifndef ARVORE_H
#define ARVORE_H

#include <QDialog>

namespace Ui {
class Arvore;
}

class Arvore : public QDialog
{
    Q_OBJECT

public:
    explicit Arvore(QWidget *parent = nullptr);
    ~Arvore();

private:
    Ui::Arvore *ui;
};

#endif // ARVORE_H
