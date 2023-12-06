#ifndef TP3_ED_SEGTREE_HPP
#define TP3_ED_SEGTREE_HPP

#include "../include/matriz.hpp"

class SegTree {
    private:
        Matriz* seg;

    public:
        SegTree(int tamanho);
        ~SegTree();

        Matriz atualiza(int no, int tl, int tr, int idx, Matriz &mat);
        Matriz consulta(int no, int tl, int tr, int a, int b);
};

#endif
