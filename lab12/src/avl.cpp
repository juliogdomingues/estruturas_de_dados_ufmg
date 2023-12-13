#include "../include/avl.hpp"
#include <iostream>

using namespace std;

AVLTree::AVLTree() : raiz(nullptr) {}

AVLTree::~AVLTree() {
    liberarMemoria(raiz);
}

AVLTree::No* AVLTree::novoNo(int chave) {
    No* node = new No();
    node->chave = chave;
    node->esquerdo = nullptr;
    node->direito = nullptr;
    node->altura = 1;
    return node;
}

AVLTree::No* AVLTree::rotacaoDireita(No *y) {
    No *x = y->esquerdo;
    No *T2 = x->direito;

    x->direito = y;
    y->esquerdo = T2;

    y->altura = max(obterAltura(y->esquerdo), obterAltura(y->direito)) + 1;
    x->altura = max(obterAltura(x->esquerdo), obterAltura(x->direito)) + 1;

    return x;
}

AVLTree::No* AVLTree::rotacaoEsquerda(No *x) {
    No *y = x->direito;
    No *T2 = y->esquerdo;

    y->esquerdo = x;
    x->direito = T2;

    x->altura = max(obterAltura(x->esquerdo), obterAltura(x->direito)) + 1;
    y->altura = max(obterAltura(y->esquerdo), obterAltura(y->direito)) + 1;

    return y;
}

int AVLTree::obterAltura(No *N) const {
    if (N == nullptr)
        return 0;
    return N->altura;
}

int AVLTree::obterBalanco(No *N) const {
    if (N == nullptr)
        return 0;
    return obterAltura(N->esquerdo) - obterAltura(N->direito);
}

AVLTree::No* AVLTree::inserir(No* node, int chave) {
    if (node == nullptr)
        return novoNo(chave);

    if (chave < node->chave)
        node->esquerdo = inserir(node->esquerdo, chave);
    else if (chave > node->chave)
        node->direito = inserir(node->direito, chave);
    else 
        return node;

    node->altura = 1 + max(obterAltura(node->esquerdo), obterAltura(node->direito));

    int balanco = obterBalanco(node);

    // Caso Esquerdo Esquerdo
    if (balanco > 1 && chave < node->esquerdo->chave)
        return rotacaoDireita(node);

    // Caso Direito Direito
    if (balanco < -1 && chave > node->direito->chave)
        return rotacaoEsquerda(node);

    // Caso Esquerdo Direito
    if (balanco > 1 && chave > node->esquerdo->chave) {
        node->esquerdo = rotacaoEsquerda(node->esquerdo);
        return rotacaoDireita(node);
    }

    // Caso Direito Esquerdo
    if (balanco < -1 && chave < node->direito->chave) {
        node->direito = rotacaoDireita(node->direito);
        return rotacaoEsquerda(node);
    }

    return node;
}

AVLTree::No* AVLTree::remover(No* node, int chave) {
    if (node == nullptr)
        return node;

    if (chave < node->chave)
        node->esquerdo = remover(node->esquerdo, chave);
    else if (chave > node->chave)
        node->direito = remover(node->direito, chave);
    else {
        if ((node->esquerdo == nullptr) || (node->direito == nullptr)) {
            No *temp = node->esquerdo ? node->esquerdo : node->direito;

            if (temp == nullptr) {
                temp = node;
                node = nullptr;
            } else 
                *node = *temp;

            delete temp;
        } else {
            No* temp = obterMenorNo(node->direito);
            node->chave = temp->chave;
            node->direito = remover(node->direito, temp->chave);
        }
    }

    if (node == nullptr)
        return node;

    node->altura = 1 + max(obterAltura(node->esquerdo), obterAltura(node->direito));
    int balanco = obterBalanco(node);

    // Caso Esquerdo Esquerdo
    if (balanco > 1 && obterBalanco(node->esquerdo) >= 0)
        return rotacaoDireita(node);

    // Caso Esquerdo Direito
    if (balanco > 1 && obterBalanco(node->esquerdo) < 0) {
        node->esquerdo = rotacaoEsquerda(node->esquerdo);
        return rotacaoDireita(node);
    }

    // Caso Direito Direito
    if (balanco < -1 && obterBalanco(node->direito) <= 0)
        return rotacaoEsquerda(node);

    // Caso Direito Esquerdo
    if (balanco < -1 && obterBalanco(node->direito) > 0) {
        node->direito = rotacaoDireita(node->direito);
        return rotacaoEsquerda(node);
    }

    return node;
}

AVLTree::No* AVLTree::obterMenorNo(No* node) const {
    No* atual = node;
    while (atual && atual->esquerdo != nullptr)
        atual = atual->esquerdo;
    return atual;
}

void AVLTree::liberarMemoria(No* node) {
    if (node != nullptr) {
        liberarMemoria(node->esquerdo);
        liberarMemoria(node->direito);
        delete node;
    }
}

void AVLTree::inserir(int chave) {
    raiz = inserir(raiz, chave);
}

void AVLTree::remover(int chave) {
    raiz = remover(raiz, chave);
}

void AVLTree::imprimirPreOrdem() const {
    preOrdem(raiz);
    cout << endl;
}

void AVLTree::imprimirEmOrdem() const {
    emOrdem(raiz);
    cout << endl;
}

void AVLTree::imprimirPosOrdem() const {
    posOrdem(raiz);
    cout << endl;
}

// Funções de caminhamento da árvore
void AVLTree::preOrdem(No *node) const {
    if(node != nullptr) {
        cout << node->chave << " ";
        preOrdem(node->esquerdo);
        preOrdem(node->direito);
    }
}

void AVLTree::emOrdem(No *node) const {
    if(node != nullptr) {
        emOrdem(node->esquerdo);
        cout << node->chave << " ";
        emOrdem(node->direito);
    }
}

void AVLTree::posOrdem(No *node) const {
    if(node != nullptr) {
        posOrdem(node->esquerdo);
        posOrdem(node->direito);
        cout << node->chave << " ";
    }
}
