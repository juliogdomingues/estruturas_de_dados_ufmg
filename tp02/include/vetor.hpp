#ifndef TP2_ED_VETOR_HPP
#define TP2_ED_VETOR_HPP

#include "../include/item.hpp"

#include <iostream>
#include <stdexcept>

class Vetor {
private:
    size_t capacidade;
    size_t tamanho;
    Item* array;

    void redimensionar() {
        capacidade = capacidade * 2;
        Item* novoArray = new Item[capacidade];
        for (size_t i = 0; i < tamanho; ++i) {
            novoArray[i] = array[i];
        }
        delete[] array;
        array = novoArray;
    }

public:
    Vetor() : capacidade(10), tamanho(0), array(new Item[capacidade]) {}
    Vetor(size_t capacidadeInicial) : capacidade(capacidadeInicial), tamanho(0), array(new Item[capacidadeInicial]) {}
    ~Vetor() { delete[] array; }

    void adicionar(Item valor) {
        if (tamanho == capacidade) {
            redimensionar();
        }
        array[tamanho++].chave = valor.chave;
    }

    Item& operator[](size_t indice) {
        if (indice >= tamanho) {
            throw std::out_of_range("Índice fora do intervalo");
        }
        return array[indice];
    }

    size_t getTamanho() const { return tamanho; }
    Item* getArray() { return array; }
};

#endif
