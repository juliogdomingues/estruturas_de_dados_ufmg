#ifndef TP3_ED_SEGTREE_HPP
#define TP3_ED_SEGTREE_HPP

// #define DEBUG

#define MAX 8
const int MOD = 1e8; // Para manter os últimos 8 dígitos

struct Matriz {
    long long int m[2][2];

    Matriz() {
        m[0][0] = m[1][1] = 1; // Matriz identidade
        m[0][1] = m[1][0] = 0;
    }

    Matriz(int a, int b, int c, int d) {
        m[0][0] = a; m[0][1] = b;
        m[1][0] = c; m[1][1] = d;
    }
};

Matriz multiplicaMatriz(const Matriz &a, const Matriz &b);

class segTree {
private:
    Matriz seg[4 * MAX];

public:
    void build(int p, int l, int r); // Inicializa a segTree
    void update(int i, const Matriz &newValue, int p, int l, int r);
    Matriz query(int a, int b, int p, int l, int r);
};

#endif
