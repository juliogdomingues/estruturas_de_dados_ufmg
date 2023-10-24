#ifndef TP1_ED_AV_EXP_H
#define TP1_ED_AV_EXP_H

#include <cstring>
#include <iostream>

#include "../include/pilha.hpp"

const int MAX_FORMULA_SIZE = 1000000;
const int MAX_VALORACAO_SIZE = 100;

class ExpressaoLogica {
    private:
        std::string formula;
        std::string valoracao;
        PilhaEncadeada operadoresStack;
        PilhaEncadeada variaveisStack;
        bool operador(char character);
        int precedencia(char op);
        void avaliarProximaOperacao();
        char valorDaVariavel(char variavel);

    public:
        ExpressaoLogica(std::string formula, std::string valoracao);
        ExpressaoLogica() {};
        ~ExpressaoLogica() { Limpa(); };
        char aplicarOperador(char op, char operando1, char operando2);
        bool avaliar();
        void Limpa();
};

#endif
