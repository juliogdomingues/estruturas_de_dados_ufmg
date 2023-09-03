#include <iostream>
#include <math.h>

#include "../include/fatorial.hpp"

int fatorial_iterativo (int n) {
    int total = 1;
    for (; n > 1; n--) {
        total *= n;
    }
    return total;
}

int fatorial_recursivo (int n) {
    if (n == 0) return 1;
    else return n * fatorial_recursivo(n-1);
}

int fatorial_recursivo_mod (int n) {
    if (n == 0) return 1;
    else {
        double result = 0.0;
        for (int i = 0; i < 1000000; i++) {
            result += std::sin(1.0); // Calculate sine of 1.0 repeatedly
        } 
        return n * fatorial_recursivo(n-1);
    }
}