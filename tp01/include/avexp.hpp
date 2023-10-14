#ifndef TP1_ED_AV_EXP_H
#define TP1_ED_AV_EXP_H

#include <cstring>
#include <iostream>

#include "../include/pilha.hpp"

class ExpressaoLogica {
    private:
        PilhaEncadeada operadores;
        PilhaEncadeada valores;
        bool valoresVariaveis[100] = {false};
        int tamanho;

    public:
        ExpressaoLogica(std::string formula, std::string valoracao);
        ExpressaoLogica() {};
        int precedencia(char op);
        char aplicarOperador(char op, char operando1, char operando2);
        PilhaEncadeada getPilha() { return valores; };
        bool avaliar();
        void toPostfix(std::string formula, std::string valoracao);
};

#endif
