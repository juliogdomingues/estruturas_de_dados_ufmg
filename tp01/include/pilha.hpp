#ifndef TP1_ED_PILHA_H
#define TP1_ED_PILHA_H

class Pilha
{
public:
    Pilha() { tamanho = 0; };
    int GetTamanho() { return tamanho; };
    bool Vazia() { return tamanho == 0; };

    virtual void Empilha(char item) = 0;
    virtual char Desempilha() = 0;
    virtual void Limpa() = 0;

protected:
    int tamanho;
};

class PilhaArranjo : public Pilha
{
public:
    PilhaArranjo();

    void Empilha(char item);
    char Desempilha();
    void Limpa();
    char GetTopo() const;

private:
    int topo;
    static const int MAXTAM = 100;
    char itens[MAXTAM];
};

#endif
