#include <iostream>
#include <cmath>

#include "../include/avexp.hpp"

ExpressaoLogica::ExpressaoLogica(std::string formula, std::string valoracao)
    try : formula(formula), valoracao(valoracao), operadoresStack(), variaveisStack() {
        if (formula.size() > MAX_FORMULA_SIZE || valoracao.size() > MAX_VALORACAO_SIZE) {
            throw std::invalid_argument("Tamanho de entrada excede os limites.");
        }
    } catch (const std::exception &e) {
    std::cerr << "Erro na inicialização: " << e.what() << std::endl;
    throw;
    }

bool ExpressaoLogica::avaliar() {
    for (unsigned int i = 0; i < formula.size(); i++) {
        char caractere = formula[i];

        // Verifique se o caractere atual e o próximo são dígitos (para índices de dois dígitos)
        if (isdigit(caractere) && (i + 1 < formula.size()) && isdigit(formula[i + 1])) {
            // Combine o caractere atual e o próximo para formar um índice de dois dígitos
            std::string indice = "";
            indice += caractere;
            indice += formula[i + 1];
            i++; // Pula o próximo caractere, já que ele faz parte do índice de dois dígitos
        } else if (caractere != ' ') {
            if (operador(caractere)) {
                if (caractere == '(') {
                    operadoresStack.Empilha(caractere);
                }
                else if (caractere == ')') { 
                    while (operadoresStack.GetTopo() != '(') {
                        avaliarProximaOperacao();
                    }
                    operadoresStack.Desempilha(); // remove abre parenteses
                } else {
                    while (!operadoresStack.Vazia() && precedencia(operadoresStack.GetTopo()) > precedencia(caractere)) {
                        avaliarProximaOperacao();
                    }
                    operadoresStack.Empilha(caractere);
                }
            } else {
                variaveisStack.Empilha(valorDaVariavel(caractere));
            }
        }
    }
    while (!operadoresStack.Vazia()) {
        avaliarProximaOperacao();        
    }
    return variaveisStack.GetTopo() == '1';
}

bool ExpressaoLogica::operador(char character) {
    return character == '&' || character == '|' || character == '~' || character == '(' || character == ')';
}

int ExpressaoLogica::precedencia(char op) {
    if (op == '~') return 2;
    if (op == '&') return 1;
    if (op == '|') return 0;
    return -1;
}

void ExpressaoLogica::avaliarProximaOperacao() {
    char operador = operadoresStack.Desempilha();
    char operando1 = variaveisStack.Desempilha();
    char operando2 = '\0';
    if (operador != '~') {
        operando2 = variaveisStack.Desempilha();
    }
    variaveisStack.Empilha(aplicarOperador(operador, operando1, operando2));
}

char ExpressaoLogica::valorDaVariavel(char variavel) {
    int indice = variavel - '0';
    return valoracao[indice];
}

char ExpressaoLogica::aplicarOperador(char op, char operando1, char operando2) {
    // operadores unários
    if (op == '~') return (operando1 == '1') ? '0' : '1';

    // operadores binários
    if (op == '&') return (operando1 == '1' && operando2 == '1') ? '1' : '0';
    if (op == '|') return (operando1 == '1' || operando2 == '1') ? '1' : '0';

    return '0';
}

void ExpressaoLogica::Limpa() {
    variaveisStack.Limpa();
    operadoresStack.Limpa();
}

