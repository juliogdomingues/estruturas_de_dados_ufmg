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
        if (caractere != ' ') {
            if (std::isdigit(caractere)) {
                // Coleta dígitos consecutivos para formar um número
                std::string numeroStr;
                while (i < formula.size() && std::isdigit(formula[i])) {
                    numeroStr += formula[i];
                    i++;
                }
                i--; // Volta um passo para compensar a iteração extra no loop

                int numero = std::stoi(numeroStr); // Converte a string em um número inteiro

                std::cout << "Empilhando variável: " << valorDaVariavel(numero) << std::endl;
                variaveisStack.Empilha(valorDaVariavel(numero));
            } else if (operador(caractere)) {
                if (caractere == '(') {
                    operadoresStack.Empilha(caractere);
                } else if (caractere == ')') {
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
            }
        }
    }
    while (!operadoresStack.Vazia()) {
        avaliarProximaOperacao();
    }
    int resultado = variaveisStack.GetTopo();
    std::cout << "Resultado final: " << resultado << std::endl;
    return resultado == 1;
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
    int operando1 = variaveisStack.Desempilha();
    int operando2 = 0;

    if (operador != '~') {
        operando2 = variaveisStack.Desempilha();
    }

    int resultado = aplicarOperador(operador, operando1, operando2);
    std::cout << "Operando1: " << operando1 << ", Operando2: " << operando2 << ", Operador: " << operador << ", Resultado: " << resultado << std::endl;
    variaveisStack.Empilha(resultado);
}

int ExpressaoLogica::valorDaVariavel(int variavel) {
    int valor = 0;
    while (variavel < valoracao.size() && isdigit(valoracao[variavel])) {
        valor = valor * 10 + (valoracao[variavel] - '0');
        variavel++;
    }
    return valor;
}

char ExpressaoLogica::aplicarOperador(char op, int operando1, int operando2) {
    // operadores unários
    if (op == '~') return (operando1 == 1) ? 0 : 1;

    // operadores binários
    if (op == '&') return (operando1 == 1 && operando2 == 1) ? 1 : 0;
    if (op == '|') return (operando1 == 1 || operando2 == 1) ? 1 : 0;

    return 0;
}

void ExpressaoLogica::Limpa() {
    variaveisStack.Limpa();
    operadoresStack.Limpa();
}
