#include <iostream>
#include "../include/avl.hpp"

using namespace std;

int main() {
    AVLTree minhaArvore;
    int n;
    char operacao;
    int chave;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> operacao >> chave;
        switch (operacao) {
            case 'i':
                minhaArvore.inserir(chave);
                break;
            case 'r':
                minhaArvore.remover(chave);
                break;
            default:
                // Caso a entrada seja inválida, não faz nada
                break;
        }
    }

    // Caminhamentos
    // cout << "Caminhame/nto pré-ordem da árvore AVL construída:\n";
    minhaArvore.imprimirPreOrdem();

    // cout << "Caminhamento em ordem da árvore AVL construída:\n";
    minhaArvore.imprimirEmOrdem();

    // cout << "Caminhamento pós-ordem da árvore AVL construída:\n";
    minhaArvore.imprimirPosOrdem();

    // Não é necessário chamar liberarMemoria aqui, pois o destrutor da classe AVLTree cuidará disso
    return 0;
}
