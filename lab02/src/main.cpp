#include <iostream>
#include "../include/fatorial.hpp"
#include "../include/fibonacci.hpp"


int main(int argc, char ** argv) {
    std::cout << "Fatorial" << std::endl;
    for (int i = 0; i < 5; i++) {
        std::cout << "n = " << i << std::endl;
        std::cout << "Iterativo = " << fatorial_iterativo(i) << std::endl;
        std::cout << "Recursivo = " << fatorial_recursivo(i) << std::endl;
    }

    std::cout << "Fibonacci" << std::endl;
    for (int i = 0; i < 5; i++) {
        std::cout << "n = " << i << std::endl;
        std::cout << "Iterativo = "<< fibonacci_iterativo(i) << std::endl;
        std::cout << "Recursivo = "<< fibonacci_recursivo(i) << std::endl;
    }
}

