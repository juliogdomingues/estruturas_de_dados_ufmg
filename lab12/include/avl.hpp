#ifndef AVL_HPP
#define AVL_HPP

class AVLTree {
private:
    struct No {
        int chave;
        No *esquerdo;
        No *direito;
        int altura;
    };

    No *raiz;

    No* novoNo(int chave);
    No* rotacaoDireita(No *y);
    No* rotacaoEsquerda(No *x);
    int obterAltura(No *N) const;
    int obterBalanco(No *N) const;
    No* inserir(No* node, int chave);
    No* remover(No* node, int chave);
    No* obterMenorNo(No* node) const;
    void liberarMemoria(No *node);
    void preOrdem(No *node) const;
    void emOrdem(No *node) const;
    void posOrdem(No *node) const;

public:
    AVLTree();
    ~AVLTree();
    void inserir(int chave);
    void remover(int chave);
    void imprimirPreOrdem() const;
    void imprimirEmOrdem() const;
    void imprimirPosOrdem() const;
};

#endif
