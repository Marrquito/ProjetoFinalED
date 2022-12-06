from PyQt5.QtWidgets import QApplication, QLabel, QPushButton, QMessageBox, QGridLayout, QWidget, QLineEdit
# Inicialmente ia ser feito em python, mas no final ficou apenas a implementação da árvore, por isso o Estruturas
from Estruturas import Arvore

import random

print("entrei...")
app = QApplication([])
app.setStyle('Fusion')
window = QWidget()
window.setFixedWidth(1080)
window.setFixedHeight(720)

layout = QGridLayout()

labelAdd = QLabel()
labelAdd.setText('Valor para adicionar (int): ')

lineAdd = QLineEdit()

buttonAdd = QPushButton('Adicionar')

labelCaminhamento = QLabel()
textCaminhamento = '\nCaminhamento in order:\n'
labelCaminhamento.setText(textCaminhamento)

labelDisplay = QLabel()
textDisplay = '\nÁrvore Binária de Pesquisa:\n'
labelDisplay.setText(textDisplay)

layout.addWidget(labelAdd, 0, 0)
layout.addWidget(lineAdd, 0, 1)
layout.addWidget(buttonAdd, 0, 2)
layout.addWidget(labelCaminhamento, 1, 0)
layout.addWidget(labelDisplay, 2, 0)

window.setLayout(layout)

def on_buttonAdd_clicked():
    alert = QMessageBox()
    numero = int(lineAdd.text())
    flag = arvore.insere(numero)
    if flag == None:
        alert.setText(str(numero) + ' já existe na árvore!')
    else:
        alert.setText(str(numero) + ' adicionado!')
    #alert.show()
    alert.exec()

    if flag != None:
        textCaminhamento = '\nCaminhamento in order:\n'
        textCaminhamento += arvore.in_ordem()
        labelCaminhamento.setText(textCaminhamento)

        textDisplay = '\nÁrvore Binária de Pesquisa:\n'
        textDisplay += '\n'.join(arvore.display())
        print(textDisplay)
        labelDisplay.setText(textDisplay)

buttonAdd.clicked.connect(on_buttonAdd_clicked)

arvore = Arvore.Arvore()
window.show()
app.exec()