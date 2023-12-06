#include "../include/segtree.hpp"
#include <stdexcept>

SegTree::SegTree(int tamanho) {
    if (tamanho <= 0) {
        throw std::invalid_argument("Tamanho da SegTree inválido.");
    }
    seg = new Matriz[4 * tamanho];
}

SegTree::~SegTree() {
    delete[] seg;
}

Matriz SegTree::atualiza(int no, int tl, int tr, int idx, Matriz &mat) {
    if (idx < 0) {
        throw std::out_of_range("Índice fora dos limites na operação de atualização.");
    }

    if (idx < tl || idx > tr) return seg[no];
    if (tl == tr) return seg[no] = mat;

    int tm = (tl + tr) / 2;
    seg[no] = multiplica(atualiza(no * 2, tl, tm, idx, mat), atualiza(no * 2 + 1, tm + 1, tr, idx, mat));
    return seg[no];
}

Matriz SegTree::consulta(int no, int tl, int tr, int a, int b) {
    if (a < 0 || a > b) {
        throw std::out_of_range("Índices fora dos limites na operação de consulta.");
    }

    if (b < tl || a > tr) return Matriz();
    if (a <= tl && b >= tr) return seg[no];

    int tm = (tl + tr) / 2;
    return multiplica(consulta(no * 2, tl, tm, a, b), consulta(no * 2 + 1, tm + 1, tr, a, b));
}
