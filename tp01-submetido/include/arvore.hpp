#ifndef TP1_ED_ARVORE_H
#define TP1_ED_ARVORE_H

#include <iostream>

class TipoNo
{
    public:

        TipoNo(std::string valoracao);

        // Métodos de acesso para membros privados.
        TipoNo* getEsq() { return esq; };
        TipoNo* getDir() { return dir; };
        bool getResultado() { return resultado; };
        void setResultado(bool novoResultado) { resultado = novoResultado; };
        char getQuantificador() { return quantificador; };
        int getPosQuantificador() { return posQuantificador; };
        std::string getValoracao() { return valoracao; };
        void setValoracao(std::string novaValoracao) { valoracao = novaValoracao; };
        bool preencheProximoNivel();

    private:
        TipoNo *esq;
        TipoNo *dir;
        std::string valoracao;
        bool resultado;
        char quantificador;
        int posQuantificador;

    friend class ArvoreBinaria;
};

class ArvoreBinaria
{
    public:
        ArvoreBinaria() : raiz(nullptr) {};
        ~ArvoreBinaria() { Limpa(raiz); };
        void Insere(std::string valoracao);
        TipoNo *ObtemRaiz() { return raiz; };
        void Caminha(int tipo);
        void Limpa(TipoNo* p);

    private:
        void InsereRecursivo(TipoNo* &p, std::string valoracao);

        TipoNo *raiz;
};


#endif
