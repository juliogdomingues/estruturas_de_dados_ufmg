#include <iostream>
#include "../include/listaadj.hpp"

TipoCelula::TipoCelula() {}

TipoItem::TipoItem() {}

TipoItem::TipoItem(TipoChave c) {
    chave = c;
}

void TipoItem::SetChave(TipoChave c) {
    chave = c;
}

TipoChave TipoItem::GetChave() {
    return chave;
}

void TipoItem::Imprime() {
    std::cout << "Chave: " << chave << std::endl;
}

ListaAdjacencia::ListaAdjacencia() {
    primeiro = new TipoCelula();
    ultimo = primeiro;
};

ListaAdjacencia::~ListaAdjacencia()
{
    Limpa();
    delete primeiro;
};

TipoCelula* ListaAdjacencia::Posiciona(int pos, bool antes=false){
    TipoCelula *p; int i;

    if ( (pos > tamanho) || (pos <= 0) )
        throw "ERRO: Posicao Invalida!";

    // Posiciona na célula anterior a desejada
    p = primeiro;
    for(i=1; i<pos; i++){
        p = p->prox;
    }
    // vai para a próxima 
    // se antes for false
    if(!antes)
        p = p->prox;

    return p;
};

TipoItem ListaAdjacencia::GetItem(int pos){
    TipoCelula *p;

    p = Posiciona(pos);
    return p->item;
};

void ListaAdjacencia::SetItem(TipoItem item, int pos){
    TipoCelula *p;

    p = Posiciona(pos);
    p->item = item;
};

void ListaAdjacencia::InsereInicio(TipoItem item) {
    TipoCelula *nova;

    nova = new TipoCelula();
    nova->item = item;
    nova->prox = primeiro->prox;
    primeiro->prox = nova;
    tamanho++;

 	if(nova->prox == NULL)
        ultimo = nova;
};

void ListaAdjacencia::InsereFinal(TipoItem item) {
    TipoCelula *nova;

    nova = new TipoCelula();
    nova->item = item;
    ultimo->prox = nova;
    ultimo = nova;
    tamanho++;

};

void ListaAdjacencia::InserePosicao(TipoItem item, int pos) {
    TipoCelula *p, *nova;

    p = Posiciona(pos,true); // posiciona na célula anterior

    nova = new TipoCelula();
    nova->item = item;
    nova->prox = p->prox;
    p->prox = nova;
    tamanho++;

    if(nova->prox == NULL)
        ultimo = nova;
};

TipoItem ListaAdjacencia::RemoveInicio() {;
    TipoItem aux;
    TipoCelula *p;

    if (tamanho == 0)
        throw "ERRO: Lista vazia!";

    p = primeiro->prox;
    primeiro->prox = p->prox;
    tamanho--;
    if(primeiro->prox == NULL)
        ultimo = primeiro;
    aux = p->item;
    delete p;

    return aux;
}

TipoItem ListaAdjacencia::RemoveFinal() {
    TipoItem aux;
    TipoCelula *p;

    if (tamanho == 0)
        throw "ERRO: Lista vazia!";

    // posiciona p na celula anterior à última
    p = Posiciona(tamanho, true);

    p->prox = NULL;
    tamanho--;
    aux = ultimo->item;
    delete ultimo;
    ultimo = p;

    return aux;
}


TipoItem ListaAdjacencia::RemovePosicao(int pos) {;
    TipoItem aux;
    TipoCelula *p, *q;

    if (tamanho == 0)
        throw "ERRO: Lista vazia!";

    // posiciona p na celula anterior à pos
    p = Posiciona(pos, true);
    q = p->prox;
    p->prox = q->prox;
    tamanho--;
    aux = q->item;
    delete q;
    if(p->prox == NULL)
        ultimo = p;
    return aux;
}


TipoItem  ListaAdjacencia::Pesquisa(TipoChave c) {
    TipoItem aux;
    TipoCelula *p;

    if (tamanho == 0)
        throw "ERRO: Lista vazia!";

    p = primeiro->prox;
    aux.SetChave(-1);
    while (p!=NULL) {
        if (p->item.GetChave() == c) {
            aux = p->item;
            break;
        }
        p = p->prox;
    }

    return aux;
 };


void ListaAdjacencia::Imprime() {
    TipoCelula *p;

    p = primeiro->prox;
    while (p!=NULL) {
        p->item.Imprime();
        p = p->prox;
    }

    printf("\n");
};

void ListaAdjacencia::Limpa() {
    TipoCelula *p;

    p = primeiro->prox;
    while (p!=NULL) {
        primeiro->prox = p->prox;
        delete p;
        p = primeiro->prox;
    }
    ultimo = primeiro;
    tamanho = 0;
};

