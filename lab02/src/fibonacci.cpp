#include <iostream>
#include <math.h>

#include "../include/fibonacci.hpp"

int fibonacci_iterativo(int n) {
    if (n <= 0) {
        return 0;  // Tratar
    } else if (n == 1 || n == 2) {
        return 1;  // Tratar?
    }
    int x1 = 1, x2 = 1;
    int x;
    for (int i = 3; i <= n; i++) {
        x = x1 + x2;
        x2 = x1;
        x1 = x;
    }
    return x;
}

int fibonacci_recursivo (int n) {
    if (n == 0 || n == 1) return n;
    else {
        return fibonacci_recursivo(n-1) + fibonacci_recursivo(n-2);
    }
}

int fibonacci_recursivo_mod (int n) {
    if (n == 0 || n == 1) return n;
    else {
        double result = 0.0;
        for (int i = 0; i < 1000000; i++) {
            result += std::sin(1.0); // Calcula seno de 1 repetidamente
        } 
        return fibonacci_recursivo(n-1) + fibonacci_recursivo(n-2);
    }
}