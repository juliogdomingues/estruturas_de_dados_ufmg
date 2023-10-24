#include "../include/arvore.hpp"
#include "../include/pilha.hpp"

TipoNo::TipoNo(std::string valoracao) : esq(nullptr), dir(nullptr), valoracao(valoracao) {}

// retorna true se houve variável indefinida e false se não houve (nó folha)
bool TipoNo::preencheProximoNivel() {
    for(unsigned int i = 0; i < valoracao.size(); i++) {
        // acha a primeira variável indefinida em valoracao
        if(valoracao[i] == 'a' || valoracao[i] == 'e') {
            quantificador = valoracao[i];
            posQuantificador = i;

            std::string valoracaoEsq = valoracao;
            valoracaoEsq[i] = '0'; 
            esq = new TipoNo(valoracaoEsq);
            
            std::string valoracaoDir = valoracao;
            valoracaoDir[i] = '1';
            dir = new TipoNo(valoracaoDir);

            return true;
        }
    }
    return false;
}

void ArvoreBinaria::Insere(std::string valoracao){
    InsereRecursivo(raiz,valoracao);
}

void ArvoreBinaria::InsereRecursivo(TipoNo* &p, std::string valoracao){
    if (p == NULL) {
        p = new TipoNo(valoracao);
    } else {
        if (valoracao < p->valoracao) {
            InsereRecursivo(p->esq, valoracao);
        } else {
            InsereRecursivo(p->dir, valoracao);
        }
    }
}

void ArvoreBinaria::Limpa(TipoNo* p) {
    if (p != nullptr) {
        Limpa(p->getEsq());
        Limpa(p->getDir());
        delete p;
    }
}