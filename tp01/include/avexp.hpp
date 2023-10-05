#ifndef TP1_ED_AV_EXP_H
#define TP1_ED_AV_EXP_H

#include <cstring>
#include <iostream>
// #include "./pilha.hpp"

int precedencia(char op);
bool aplicarOperador(char op, bool operando1, bool operando2);
int avaliadorExpressoes(const std::string& formula, const std::string& valoracao);

#endif
