#include <iostream>
#include <cmath>

#include "../include/avexp.hpp"

ExpressaoLogica::ExpressaoLogica(std::string formula, std::string valoracao) : tamanho(0), valores(), operadores() {
    if (formula.size() > 1000000 || valoracao.size() > 100) {
        throw std::invalid_argument("A fórmula pode ter até 10^6 caracteres e a valoracao até 100 caracteres.");
    }

    toPostfix(formula, valoracao);
}

void ExpressaoLogica::toPostfix(std::string formula, std::string valoracao) {
    TipoItem *item;

    for (int i = 0; i < formula.size(); i++) {
        char caractere = formula[i];

        if (caractere == ' ') continue;
        if (caractere == '&' || caractere == '|' || caractere == '~' || caractere == '(' || caractere == ')') {
            while (!operadores.Vazia() && precedencia(operadores.GetTopo()) >= precedencia(caractere) && operadores.GetTopo() != '(') {
                char op = operadores.Desempilha();
                char operando2 = valores.Desempilha();
                char operando1 = valores.Desempilha();
                valores.Empilha(aplicarOperador(op, operando1 == '1', operando2 == '1') ? '1' : '0');
            }

            if (caractere != ')') {
                operadores.Empilha(caractere);
            } else {
                operadores.Desempilha();  // Remover o '('
            }
        } else if (caractere >= '0' && caractere <= '9') {
            int indiceVariavel = caractere - '0';
            valores.Empilha(valoracao[indiceVariavel] == '1' ? '1' : '0');
        }
    }

    while (!operadores.Vazia()) {
        char op = operadores.Desempilha();
        char operando2 = valores.Desempilha();
        char operando1 = valores.Desempilha();
        valores.Empilha(aplicarOperador(op, operando1 == '1', operando2 == '1') ? '1' : '0');
    }
}


int ExpressaoLogica::precedencia(char op) {
    if (op == '~') return 2;
    if (op == '&') return 1;
    if (op == '|') return 0;
    return -1;
}

char ExpressaoLogica::aplicarOperador(char op, char operando1, char operando2) {
    if (op == '&') return (operando1 == '1' && operando2 == '1') ? '1' : '0';
    if (op == '|') return (operando1 == '1' || operando2 == '1') ? '1' : '0';
    if (op == '~') return (operando1 == '1') ? '0' : '1';
    return '0';  // Lidar com erros
}

bool ExpressaoLogica::avaliar() {
    if (valores.Vazia()) {
        throw std::runtime_error("A expressão está vazia.");
    }
    return valores.GetTopo() == '1';
}
