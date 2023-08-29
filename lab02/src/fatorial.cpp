#include <iostream>

#include "../include/fatorial.hpp"

int fatorial_iterativo (int n) {
    int total = 1;
    for (; n > 1; n--) {
        total *= n;
    }
    return total;
}

int fatorial_recursivo (int n) {
    if (n == 0 || n == 1) return 1;
    else return fatorial_recursivo(n) * fatorial_recursivo(n-1);
}