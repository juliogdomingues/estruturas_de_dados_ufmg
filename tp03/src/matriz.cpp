#include "../include/matriz.hpp"
#include <stdexcept>

Matriz::Matriz() {
    m[0][0] = 1; m[0][1] = 0;
    m[1][0] = 0; m[1][1] = 1;
}

Matriz::Matriz(long long a, long long b, long long c, long long d) {
    m[0][0] = a; m[0][1] = b;
    m[1][0] = c; m[1][1] = d;
}

void Matriz::defineIndice(int i, int j, long long val) {
    if (i < 0 || i >= 2 || j < 0 || j >= 2) {
        throw std::out_of_range("Índice de matriz fora do intervalo.");
    }
    m[i][j] = val;
}

void Matriz::somaIndice(int i, int j, long long val) {
    if (i < 0 || i >= 2 || j < 0 || j >= 2) {
        throw std::out_of_range("Índice de matriz fora do intervalo.");
    }
    m[i][j] = (m[i][j] + val) % MOD;
}

long long Matriz::pegaIndice(int i, int j) const {
    if (i < 0 || i >= 2 || j < 0 || j >= 2) {
        throw std::out_of_range("Índice de matriz fora do intervalo.");
    }
    return m[i][j];
}

Matriz multiplica(const Matriz &mat1, const Matriz &mat2) {
    Matriz resultado;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            resultado.defineIndice(i, j, 0);
            for (int k = 0; k < 2; k++) {
                resultado.somaIndice(i, j, mat1.pegaIndice(i, k) * mat2.pegaIndice(k, j));
            }
        }
    }
    return resultado;
}
