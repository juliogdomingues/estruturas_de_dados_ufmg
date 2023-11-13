
#ifndef TP2_ED_ITEM_HPP
#define TP2_ED_ITEM_HPP

typedef int TipoChave;
typedef int TipoValor;

struct Item {
    TipoChave chave;
    TipoValor valor;

    // Construtor padrão
    Item() : chave(0) {}

    // Construtor que aceita um TipoChave
    Item(TipoChave c) : chave(c) {}

    friend bool operator>= (const Item& item1, const Item& item2) {
        if (item1.valor == item2.valor) {
            return item1.chave >= item2.chave;
        }
        return item1.valor > item2.valor;
    }

    friend bool operator<= (const Item& item1, const Item& item2) {
        if (item1.valor == item2.valor) {
            return item1.chave <= item2.chave;
        }
        return item1.valor < item2.valor;
    }

    friend bool operator> (const Item& item1, const Item& item2) {
        if (item1.valor == item2.valor) {
            return item1.chave > item2.chave;
        }
        return item1.valor > item2.valor;
    }

    friend bool operator< (const Item& item1, const Item& item2) {
        if (item1.valor == item2.valor) {
            return item1.chave < item2.chave;
        }
        return item1.valor < item2.valor;
    }

    friend bool operator== (const Item& item1, const Item& item2) {
        return item1.valor == item2.valor && item1.chave == item2.chave;
    }

    friend bool operator!= (const Item& item1, const Item& item2) {
        return item1.valor != item2.valor || item1.chave != item2.chave;
    }
};



#endif
