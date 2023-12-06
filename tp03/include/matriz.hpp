#ifndef TP3_ED_MATRIZ_HPP
#define TP3_ED_MATRIZ_HPP

const int MOD = 1e8; // Para manter os últimos 8 dígitos

class Matriz {
    private:
        long long m[2][2];

    public:
        Matriz();
        Matriz(long long a, long long b, long long c, long long d);

        void defineIndice(int i, int j, long long val);
        void somaIndice(int i, int j, long long val);
        long long pegaIndice(int i, int j) const;
};

Matriz multiplica(const Matriz &mat1, const Matriz &mat2);

#endif
