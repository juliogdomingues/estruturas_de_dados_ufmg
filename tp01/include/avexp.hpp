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
        PilhaEncadeada<char> operadoresStack; 
        PilhaEncadeada<int> variaveisStack; 
        bool operador(char character);
        int precedencia(char op);
        void avaliarProximaOperacao();
        int valorDaVariavel(int variavel);
        
    public:
        ExpressaoLogica(std::string formula, std::string valoracao);
        ExpressaoLogica() {};
        ~ExpressaoLogica() { Limpa(); };
        char aplicarOperador(char op, int operando1, int operando2);
        bool avaliar();
        void Limpa();
};

#endif
