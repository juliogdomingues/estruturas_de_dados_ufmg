#ifndef SET_HPP
#define SET_HPP

#include <iostream>
using namespace std;

typedef struct s_table_elem{
    string dado;
    bool vazio;
    bool retirada;

} ElementoTabela;

class StringSet{

    public:
        StringSet(int tamanho);
        ~StringSet();

        void Inserir(string s);
        void Remover(string s);
        bool Pertence(string s);
        
        StringSet* Intersecao(StringSet* S);
        StringSet* Uniao(StringSet* S);
        StringSet* DiferencaSimetrica(StringSet* S);

        void Imprimir();

    private:
        int tamanhoOriginal;
        int tamanhoTabela;
        int tamanhoConjunto;
        ElementoTabela* tabela;

        int Hash(string s);
        void Rehash(int pos);
        void Resize(size_t tamanho);
        static const int HASH_FACTOR = 31; // Fator usado na função de hash
};


#endif