#include "../include/Set.hpp"

StringSet::StringSet(int tamanho) : tamanhoOriginal(tamanho), tamanhoTabela(tamanho), tamanhoConjunto(0) {
    tabela = new ElementoTabela[tamanho];
}

StringSet::~StringSet() {
    delete [] tabela;
}

void StringSet::Inserir(string s) {
    if (Pertence(s)) return;

    if(tamanhoConjunto > tamanhoTabela / 2) Resize(tamanhoTabela * 2);

    int pos = Hash(s);

    for (int i = 0; i < tamanhoTabela; ++i) {
        if (tabela[pos].vazio) {
            tabela[pos].dado = s;
            tabela[pos].vazio = false;
            tabela[pos].retirada = false;
            tamanhoConjunto++;
            return;
        }
        pos = (pos + 1) % tamanhoTabela;
    }
}

void StringSet::Remover(string s) {
    int pos = Hash(s);
    int contador = 0;

    while (!tabela[pos].vazio && contador < tamanhoTabela) {
        if (tabela[pos].dado == s && !tabela[pos].retirada) {
            tabela[pos].vazio = true;
            tabela[pos].retirada = true;
            tamanhoConjunto--;
            return;
        }

        pos = (pos + 1) % tamanhoTabela;
        contador++;
    }
}

bool StringSet::Pertence(string s) {
    int pos = Hash(s);
    int contador = 0;

    while (!tabela[pos].vazio && contador < tamanhoTabela) {
        if (tabela[pos].dado == s && !tabela[pos].retirada) return true;

        pos = (pos + 1) % tamanhoTabela;
        contador++;
    }
    return false;
}

StringSet* StringSet::Intersecao(StringSet* S) {
    if (!S) return nullptr;
    StringSet* ans = new StringSet(tamanhoTabela);

    for (int i = 0; i < tamanhoTabela; i++) {
        if (!tabela[i].vazio && S->Pertence(tabela[i].dado)) {
            ans->Inserir(tabela[i].dado);
        }
    }

    return ans;
}

StringSet* StringSet::Uniao(StringSet* S) {
    if (!S) return nullptr;
    StringSet* ans = new StringSet(tamanhoTabela);

    for (int i = 0; i < tamanhoTabela; i++) {
        if (!tabela[i].vazio) ans->Inserir(tabela[i].dado);
    }
    for (int i = 0; i < S->tamanhoTabela; i++) {
        if (!S->tabela[i].vazio) ans->Inserir(S->tabela[i].dado);
    }

    return ans;
}

StringSet* StringSet::DiferencaSimetrica(StringSet* S) {
    if (!S) return nullptr;
    StringSet* ans = new StringSet(tamanhoTabela);

    for (int i = 0; i < tamanhoTabela; i++) {
        if (!tabela[i].vazio && !S->Pertence(tabela[i].dado)) {
            ans->Inserir(tabela[i].dado);
        }
    }
    for (int i = 0; i < S->tamanhoTabela; i++) {
        if (!S->tabela[i].vazio && !Pertence(S->tabela[i].dado)) {
            ans->Inserir(S->tabela[i].dado);
        }
    }

    return ans;
}

void StringSet::Imprimir() {
    std::cout << "{ ";
    bool isFirst = true;
    for (int i = 0; i < tamanhoTabela; i++) {
        if (!tabela[i].vazio) {
            if (!isFirst) std::cout << ", ";
            std::cout << tabela[i].dado;
            isFirst = false;
        }
    }
    std::cout << " }" << std::endl;
}

int StringSet::Hash(string s) {
    std::size_t sum = 0;

    for (auto& x : s) {
        sum = (sum * HASH_FACTOR + x) % tamanhoTabela;
    }

    return static_cast<int>(sum);
}

void StringSet::Rehash(int pos) {}

void StringSet::Resize(size_t tamanho) {
    ElementoTabela* novaTabela = new ElementoTabela[tamanho];
    tamanhoTabela = tamanho;

    for (int i = 0; i < tamanhoOriginal; i++) {
        if (!tabela[i].vazio && !tabela[i].retirada) {
            int pos = Hash(tabela[i].dado);
            while (!novaTabela[pos].vazio) {
                pos = (pos + 1) % tamanho;
            }
            novaTabela[pos] = tabela[i];
        }
    }

    delete[] tabela;
    tabela = novaTabela;
    tamanhoTabela = tamanho;
    tamanhoOriginal = tamanho; 
} 