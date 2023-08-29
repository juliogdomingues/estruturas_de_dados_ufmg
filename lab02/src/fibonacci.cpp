#include <iostream>

#include "../include/fibonacci.hpp"

int fibonacci_iterativo(int n) {
    int x1 = 1, x2 = 1;
    int x;
    for (int i = 0; i < n; i++) {
        if (i < 3) {
            x = 1;
            continue;
        }
        x = x1 + x2;
        x2 = x1;
        x1 = x;
    }
    return x;
}

int fibonacci_recursivo (int n) {
    if (n == 0 || n == 1) return n;
    else {
        return fibonacci_recursivo(n) + fibonacci_recursivo(n-1);
    }
}