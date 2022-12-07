class No:
    def __init__(self, valor=0, esquerda=None, direita=None):
        self.valor = valor
        self.esquerda = esquerda
        self.direita = direita
    
    def __repr__(self) -> str:
        if self == None:
            return 'None'
        else:
            return str(self.valor)

class Arvore:
    def __init__(self):
        self.raiz = None

    def vazia(self):
        if self.raiz == None:
            return True

    # Busca por um nó na árvore, retorna None se não achar
    def busca(self, valor):
        return self.buscaRecursiva(valor, self.raiz)

    def buscaRecursiva(self, valor, no):
        # Fora da árvore
        if no == None:
            return None
        
        # Nó encontrado
        if no.valor == valor:
            return no
        
        # Recursividade na árvore de pesquisa
        if no.valor > valor:
            return self.buscaRecursiva(valor, no.esquerda)
        else:
            return self.buscaRecursiva(valor, no.direita)

    # Caminhamento in ordem
    def in_ordem(self):
        if self.raiz == None:
            return 'Árvore Vazia'
        
        else:
            # Fiz com lista para poder modificar fácil dentro do método, mas em c pode usar ponteiros
            caminhamento = []
            self.in_ordemRecursivo(self.raiz, caminhamento)
            caminhamento = ' '.join(caminhamento) # Converte a lista em uma string
            return caminhamento

    def in_ordemRecursivo(self, no, caminhamento):
        if no == None:
            return None
        
        self.in_ordemRecursivo(no.esquerda, caminhamento)
        # O nó é adicionado na lista de caminhamento após acessar seu filho a esquerda e antes de acessar o da direita
        caminhamento.append(no.__repr__())
        self.in_ordemRecursivo(no.direita, caminhamento)

    # Insere um elemento na árvore, retorna None se já tiver
    def insere(self, valor):
        # Caso a árvore esteja vazia
        if self.raiz == None:
            novoNo = No(valor)
            self.raiz = novoNo
            return novoNo

        # Caso já exista o nó
        if self.busca(valor) != None:
            return None

        # Se não, será feita a adição normal
        return self.insereRecursivo(valor, self.raiz)
    
    def insereRecursivo(self, valor, no):
        # Caso recursivo
        if no.valor > valor:
            # Achou o lugar para alocar o nó (aloquei aqui para não ter que se preocupar em passar o nó pai na função de recursividade)
            if no.esquerda == None:
                novoNo = No(valor)
                no.esquerda = novoNo
                return novoNo
            else:
                # Continua a recursividade
                return self.insereRecursivo(valor, no.esquerda)
        elif no.valor < valor:
            # Achou o lugar para alocar o nó
            if no.direita == None:
                novoNo = No(valor)
                no.direita = novoNo
                return novoNo
            else:
                # Continua a recursividade
                return self.insereRecursivo(valor, no.direita)

    def display(self):
        # Vai chamar a função recursiva e pegar dela todas as linhas de string que serão printadas
        linhas, *_ = self.displayRecursivo(self.raiz)
        return linhas

    def displayRecursivo(self, no):
        # Retorna a lista do que será printado em cada linha, a largura, altura e a posição horizontal da raiz da subárvore

        # Caso 1 -> nó folha
        if no.esquerda == None and no.direita == None:
            # Parada para a recursividade, a funcão displayRecursivo será chamada até encontrar o nó folha, em que começará a retornar
            # Aqui esses valores são referentes a um único nó, mas nos demais casos serão referentes à subárvore como um todo
            linha = '%s' % no.valor
            largura = len(linha)
            altura = 1
            meio = largura // 2
            return [linha], largura, altura, meio
        
        # Caso 2 -> nó com apenas o filho da esquerda
        if no.direita == None:
            # Valores acumulados da subárvore à esquerda obtidos pela função recursiva
            linhas, largura, altura, meio = self.displayRecursivo(no.esquerda)
            valor = '%s' % no.valor
            u = len(valor)
            # São calculados quantos espaços e quantos _ ficarão a ESQUERDA do nó com base na largura da subárvore e na posição do seu nó raiz
            primeiraLinha = (meio + 1) * ' ' + (largura - meio - 1) * '_' + valor
            # São calculados os espaços e os / da linha entre dois nós
            segundaLinha = meio * ' ' + '/' + (largura - meio - 1 + u) * ' '
            # As linhas da subárvore recebem espaços à direita com base no tamanho do valor do nó, serve para ajustar a largura da árvore e encaixar os nós nos /, _ e \
            linhasDeslocadas = [linha + u * ' ' for linha in linhas]
            # São retornadas as 2 linhas referentes ao nó, todas as linhas da subárvore, a largura acumulada (acrescida na largura do nó atual), a altura acumulada (acrescida em 2 linhas) e a posição central da sub árvore (largura acumulada acrescida do nó atual dividido por 2, pois é necessário deslocar a subárvore superior para direita)
            return [primeiraLinha, segundaLinha] + linhasDeslocadas, largura + u, altura + 2, largura + u // 2
        
        # Caso 3 -> nó com apenas o filho da direita
        if no.esquerda == None:
            # Valores acumulados da subárvore à direita obtidos pela função recursiva
            linhas, largura, altura, meio = self.displayRecursivo(no.direita)
            valor = '%s' % no.valor
            u = len(valor)
            # São calculados quantos espaços e quantos _ ficarão a DIREITA do nó com base na largura da subárvore e na posição do seu nó raiz
            primeiraLinha = valor + meio * '_' + (largura - meio) * ' '
            # São calculados os espaços e os \ da linha entre dois nós
            segundaLinha = (u + meio) * ' ' + '\\' + (largura - meio - 1) * ' '
            # As linhas da subárvore recebem espaços à direita com base no tamanho do valor do nó, serve para ajustar a largura da árvore e encaixar os nós nos /, _ e \
            linhasDeslocadas = [u * ' ' + linha for linha in linhas]
            # São retornadas as 2 linhas referentes ao nó, todas abaixo, a largura acumulada (acrescida na largura do nó atual), a altura acumulada (acrescida em 2 linhas) e a posição central da subárvore (não acrescenta a largura do nó atual pois o nó raiz estará sempre o 0 na distância horizontal da subárvore)
            return [primeiraLinha, segundaLinha] + linhasDeslocadas, largura + u, altura + 2, u // 2

        # Caso 4 -> nó com os dois filhos
        # Valores acumulados das duas subárvores obtidos pela função recursiva
        esquerda, largura, altura, meio = self.displayRecursivo(no.esquerda)
        direita, largura2, altura2, meio2 = self.displayRecursivo(no.direita)
        valor = '%s' % no.valor
        u = len(valor)
        # Calculados quantos espaços e _ com base nas duas sub-árvores abaixo
        # OBS: Lembrar que meio não é necessariamente largura da subárvore/2 (ela pode estar desbalanceada), mas a posição do nó raiz dela
        primeiraLinha = (meio + 1) * ' ' + (largura - meio - 1) * '_' + valor + meio2 * '_' + (largura2 - meio2) * ' '
        # São calculados os espaços, os \ e os / da linha entre dois nós
        segundaLinha = meio * ' ' + '/' + (largura - meio - 1 + u + meio2) * ' ' + '\\' + (largura2 - meio2 - 1) * ' '
        # Aqui ocorre o ajuste horizontal nas duas subárvores, a da esquerda recebe espaços para não colidir com a da direita, e a da direita para não colidir com outras subárvores que possam ter ficado a sua direita
        if altura < altura2:
            esquerda += [largura * ' '] * (altura2 - altura)
        elif altura2 < altura:
            direita += [largura2 * ' '] * (altura - altura2)
        # Aqui as linhas das subárvores são combinadas e espaçadas tendo a posição da raiz como referência
        zipped_lines = zip(esquerda, direita)
        linhas = [primeiraLinha, segundaLinha] + [a + u * ' ' + b for a, b in zipped_lines]
        # São retornadas todas as linhas (as 2 referentes ao nó e todas das duas subárvores), a largura é acrescida com base nas duas subárvores mais a largura do valor da raiz, a altura é a maior dentre as subárvores + as 2 linhas da raiz, a largura acrescida ao meio é apenas a da subárvore da esquerda
        return linhas, largura + largura2 + u, max(altura, altura2) + 2, largura + u // 2