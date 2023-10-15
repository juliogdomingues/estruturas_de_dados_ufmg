#include <iostream>
#include "../include/heap.hpp"

int main() {
    int n;
    std::cin >> n;

    Heap minHeap(n);

    for (int i = 0; i < n; ++i) {
        int num;
        std::cin >> num;
        minHeap.Inserir(num);
    }

    while (!minHeap.Vazio()) {
        std::cout << minHeap.Remover() << " ";
    }
    
    std::cout << std::endl;

    return 0;
}
