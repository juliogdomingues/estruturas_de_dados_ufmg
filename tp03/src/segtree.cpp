#include <iostream>
#include "../include/segtree.hpp"

Matriz multiplicaMatriz(const Matriz &a, const Matriz &b) {
    Matriz result;

    #ifdef DEBUG
    std::cout << "Multiplicando matrizes:\n";
    std::cout << "Matriz A:\n" << a.m[0][0] << " " << a.m[0][1] << "\n" << a.m[1][0] << " " << a.m[1][1] << "\n";
    std::cout << "Matriz B:\n" << b.m[0][0] << " " << b.m[0][1] << "\n" << b.m[1][0] << " " << b.m[1][1] << "\n";
    #endif

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            long long sum = 0; // Usando long long para evitar overflow na soma
            for (int k = 0; k < 2; k++) {
                sum += (long long)a.m[i][k] * b.m[k][j]; // Multiplicação
                sum %= MOD; // Aplicando MOD após cada multiplicação
            }
            result.m[i][j] = sum % MOD; // Garantindo que apenas os últimos 8 dígitos sejam mantidos
        }
    }
    
    #ifdef DEBUG
    std::cout << "Matriz Resultante:\n" << result.m[0][0] << " " << result.m[0][1] << "\n" << result.m[1][0] << " " << result.m[1][1] << "\n";
    #endif

    return result;
}

void segTree::build(int p, int l, int r) {
    if (l == r) {
        seg[p] = Matriz(); // Matriz identidade
        return;
    }
    int m = (l + r) / 2;
    build(2 * p, l, m);
    build(2 * p + 1, m + 1, r);
    seg[p] = multiplicaMatriz(seg[2 * p], seg[2 * p + 1]);
}

void segTree::update(int i, const Matriz &newValue, int p, int l, int r) {

    #ifdef DEBUG
    std::cout << "Atualizando índice: " << i << " na posição: " << p << ", intervalo: [" << l << ", " << r << "]\n";
    std::cout << "Nova Matriz:\n" << newValue.m[0][0] << " " << newValue.m[0][1] << "\n" << newValue.m[1][0] << " " << newValue.m[1][1] << "\n";
    #endif

    if (i < l || r < i) return;
    if (l == r) {
        seg[p] = newValue;
        return;
    }
    int m = (l + r) / 2;
    update(i, newValue, 2 * p, l, m);
    update(i, newValue, 2 * p + 1, m + 1, r);
    seg[p] = multiplicaMatriz(seg[2 * p], seg[2 * p + 1]);

    #ifdef DEBUG
    // Log da matriz resultante no nó atual após a atualização
    std::cout << "Matriz resultante após atualização na posição: " << p << "\n";
    std::cout << seg[p].m[0][0] << " " << seg[p].m[0][1] << "\n" << seg[p].m[1][0] << " " << seg[p].m[1][1] << "\n";
    #endif
}

Matriz segTree::query(int a, int b, int p, int l, int r) {

    #ifdef DEBUG
    std::cout << "Consultando intervalo: [" << a << ", " << b << "] na posição: " << p << ", intervalo: [" << l << ", " << r << "]\n";
    #endif

    if (a > r || b < l) return Matriz(); // Retorna a matriz identidade
    if (a <= l && r <= b) {

        #ifdef DEBUG
        std::cout << "Matriz retornada na posição: " << p << "\n";
        std::cout << seg[p].m[0][0] << " " << seg[p].m[0][1] << "\n" << seg[p].m[1][0] << " " << seg[p].m[1][1] << "\n";
        #endif

        return seg[p];
    }
    int m = (l + r) / 2;
    Matriz left = query(a, b, 2 * p, l, m);
    Matriz right = query(a, b, 2 * p + 1, m + 1, r);
    Matriz result = multiplicaMatriz(left, right);

    #ifdef DEBUG
    // Log da matriz resultante da consulta
    std::cout << "Matriz resultante da consulta na posição: " << p << "\n";
    std::cout << result.m[0][0] << " " << result.m[0][1] << "\n" << result.m[1][0] << " " << result.m[1][1] << "\n";
    #endif
    
    return result;
}
