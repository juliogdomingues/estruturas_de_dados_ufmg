#include <iostream>
#include <cmath>

#include "../include/satisf.hpp"

Satisfaz::Satisfaz(std::string formula, std::string valoracao) : formula(formula), arvore(ArvoreBinaria()) {
    arvore.Insere(valoracao);
    insereItem(arvore.ObtemRaiz());
}

void Satisfaz::insereItem(TipoNo* item) {
    bool possuiVariavelIndefinida = item->preencheProximoNivel();
    if (possuiVariavelIndefinida) {
        insereItem(item->getEsq());
        insereItem(item->getDir());
    }
}

bool Satisfaz::resolve(TipoNo *no) {
    if(no->getDir() != nullptr && no->getEsq() != nullptr) {
        // sempre haverá nó à esquerda e à direita, ou nenhum
        bool arg1 = resolve(no->getEsq());
        bool arg2 = resolve(no->getDir());

        char valorVariavel;
        std::string novaValoracao;
        if (arg1 && arg2) {
            valorVariavel = 'a';
            novaValoracao = no->getEsq()->getValoracao(); // esquerda ou direita como base
        } else if (arg1) {
            valorVariavel = '0';
            novaValoracao = no->getEsq()->getValoracao();
        } else if (arg2) {
            valorVariavel = '1';
            novaValoracao = no->getDir()->getValoracao();
        } else {
            // não existe solução para nenhuma das variações.
            no->setResultado(false);
            return false;
        }

        if(no->getQuantificador() == 'a' && valorVariavel != 'a') {
            // existe solução, mas o requisito "para todo" não é satisfeito.
            no->setResultado(false);
            return false;
        }

        char pos = no->getPosQuantificador();
        novaValoracao[pos] = valorVariavel;
        no->setValoracao(novaValoracao);

        no->setResultado(true);
        return true;
    }

    // nó folha: avaliar expressão
    ExpressaoLogica aval = ExpressaoLogica(formula, no->getValoracao());
    bool resultado = aval.avaliar();
    no->setResultado(resultado);
    return resultado;
}

void Satisfaz::avaliaSatisfaz() {
    TipoNo *raiz = arvore.ObtemRaiz();
    resolve(raiz);
    if (raiz->getResultado()) {
        std::cout << raiz->getResultado() << " " << raiz->getValoracao() << std::endl;
    } else {
        std::cout << raiz->getResultado() << std::endl;
    }
}