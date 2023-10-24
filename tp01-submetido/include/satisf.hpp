#ifndef TP1_ED_SATISF_H
#define TP1_ED_SATISF_H

#include <iostream>
#include "./arvore.hpp"
#include "./avexp.hpp"

class Satisfaz {
    public:
        Satisfaz(std::string formula, std::string valoracao);
        ~Satisfaz() {};
        void insereItem(TipoNo *item);
        bool resolve(TipoNo *no);   // Resolve a satisfabilidade da fórmula.
        void avaliaSatisfaz();      // Avalia a satisfabilidade.

    private:
        std::string formula;
        ArvoreBinaria arvore;

};

#endif