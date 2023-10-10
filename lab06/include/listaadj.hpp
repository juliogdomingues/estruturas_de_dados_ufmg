#ifndef LISTAADJ_HPP
#define LISTAADJ_HPP

typedef int TipoChave; // TipoChave é um inteiro
typedef void *TipoValor;

class TipoItem
{
    public:
        TipoItem();
        TipoItem(TipoChave c);
        TipoItem(TipoValor v);
        void SetChave(TipoChave c);
        void SetValor(TipoValor v);
        TipoChave GetChave();
        TipoValor GetValor();
        void Imprime();

    private:
        TipoChave chave;
        TipoValor valor;
        // outros membros
};

class Lista
{
    public:
        Lista() {tamanho = 0;};
        int GetTamanho() {return tamanho;};
        bool Vazia() {return tamanho == 0;};

        virtual TipoItem GetItem(int pos) = 0;
        virtual void SetItem(TipoItem item, int pos) = 0;
        virtual void InsereInicio(TipoItem item) = 0;
        virtual void InsereFinal(TipoItem item) = 0;
        virtual void InserePosicao(TipoItem item, int pos) = 0;
        virtual TipoItem RemoveInicio() = 0;
        virtual TipoItem RemoveFinal() = 0;
        virtual TipoItem RemovePosicao(int pos) = 0;
        virtual TipoItem Pesquisa(TipoChave c) = 0;
        virtual void Imprime() = 0;
        virtual void Limpa() = 0;
    protected:
        int tamanho;
};

class TipoCelula
{
    public:
        TipoCelula();

    private:
        TipoItem item;
        TipoCelula *prox;

    friend class ListaEncadeada;
};

class ListaEncadeada : public Lista {
    public:
        ListaEncadeada();
        ~ListaEncadeada();

        TipoItem GetItem(int pos);
        void SetItem(TipoItem item, int pos);
        void InsereInicio(TipoItem item);
        void InsereFinal(TipoItem item);
        void InserePosicao(TipoItem item, int pos);
        TipoItem RemoveInicio();
        TipoItem RemoveFinal();
        TipoItem RemovePosicao(int pos);
        TipoItem Pesquisa(TipoChave c);
        void Imprime();
        void Limpa();
    private:
        TipoCelula* primeiro;
        TipoCelula* ultimo;
        TipoCelula* Posiciona(int pos, bool antes);
};

#endif