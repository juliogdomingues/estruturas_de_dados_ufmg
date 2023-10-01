#include <iostream>
#include <math.h>

#include "../include/avexp.hpp"

long long int fatorial_iterativo (int n) {
    if (n < 0) {
        std::cout << "Número inválido" << std::endl;
        return -1;
    }

    else {
    long long int total = 1;
    for (; n > 1; n--) {
        total *= n;
    }
    return total;
    }
}

long long int fatorial_recursivo (int n) {
    if (n < 0) {
        std::cout << "Número inválido" << std::endl;
        return -1;
    }

    else if (n == 0) return 1;
    else return n * fatorial_recursivo(n-1);
}

long long int fatorial_recursivo_mod (int n) {
    if (n < 0) {
        std::cout << "Número inválido" << std::endl;
        return -1;
    }
    
    else if (n == 0) return 1;
    else {
        double result = 0.0;
        for (int i = 0; i < 1000000; i++) {
            result += std::sin(1.0); // Calcula seno de 1 repetidamente
        } 
        return n * fatorial_recursivo(n-1);
    }
}