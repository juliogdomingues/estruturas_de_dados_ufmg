#include <iostream>
#include <math.h>

#include "../include/avexp.hpp"
#include "../include/pilha.hpp"

int precedencia(char op) {
    if (op == '~') return 2;
    if (op == '&') return 1;
    if (op == '|') return 0;
    return -1;
}

char aplicarOperador(char op, char operando1, char operando2) {
    if (op == '&') return (operando1 == '1' && operando2 == '1') ? '1' : '0';
    if (op == '|') return (operando1 == '1' || operando2 == '1') ? '1' : '0';
    if (op == '~') return (operando2 == '1') ? '0' : '1';
    return '0';  // Lidar com erros
}

int avaliadorExpressoes(const std::string& formula, const std::string& valoracao) {
    
    PilhaArranjo operadores;
    PilhaArranjo valores;
    bool valoresVariaveis[100] = {false};

    for (std::string::size_type i = 0; i < formula.length(); ++i) {
        valoresVariaveis[i + 1] = (valoracao[i] == '1');
    }

    for (std::string::size_type i = 0; i < formula.length(); ++i) {
        char caractere = formula[i];

        if (caractere == ' ') continue;

        std::cout << "Caractere atual: " << caractere << std::endl;
        std::cout << "Valores da pilha de valores: ";


        // Loop para imprimir os valores da pilha de valores
        PilhaArranjo tempValores = valores;
        while (!tempValores.Vazia()) {
            char valor = tempValores.Desempilha();
            std::cout << valor << " ";
        }
        std::cout << std::endl;
        


        if (caractere >= '0' && caractere <= '9') {
            int indiceVariavel = caractere - '0';
            valores.Empilha(valoresVariaveis[indiceVariavel]);
        } else if (caractere == '(') {
            operadores.Empilha(caractere);
        } else if (caractere == ')') {
            while (!operadores.Vazia() && operadores.GetTopo() != '(') {
                char op = operadores.Desempilha();
                char operando2 = valores.Desempilha();
                char operando1 = valores.Desempilha();
                valores.Empilha(aplicarOperador(op, operando1, operando2));
            }
            operadores.Desempilha();  // Remover o '('
        } else {
            while (!operadores.Vazia() && precedencia(operadores.GetTopo()) >= precedencia(caractere)) {
                char op = operadores.Desempilha();
                char operando2 = valores.Desempilha();
                char operando1 = valores.Desempilha();
                valores.Empilha(aplicarOperador(op, operando1, operando2));
            }
            operadores.Empilha(caractere);
        }
    }

    while (!operadores.Vazia()) {
        char op = operadores.Desempilha();
        char operando2 = valores.Desempilha();
        char operando1 = valores.Desempilha();
        valores.Empilha(aplicarOperador(op, operando1, operando2));
    }

    return valores.GetTopo() ? 1 : 0;
}
