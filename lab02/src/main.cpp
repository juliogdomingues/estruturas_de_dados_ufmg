#include <iostream>

#include "../include/fatorial.hpp"
#include "../include/fibonacci.hpp"
#include "../include/time_count.hpp"


int main(int argc, char** argv) {

    start_count();
    std::cout << "Fatorial Iterativo" << std::endl;
    for (int i = 0; i < 20; i++) {
        std::cout << "n = " << i << std::endl;
        std::cout << "Iterativo = " << fatorial_iterativo(i) << std::endl;
    }
    end_count();

    start_count();
    std::cout << "Fatorial recursivo" << std::endl;
    for (int i = 0; i < 20; i++) {
        std::cout << "n = " << i << std::endl;
        std::cout << "Recursivo = " << fatorial_recursivo(i) << std::endl;
    }
    end_count();

    start_count();
    std::cout << "Fatorial recursivo modificado" << std::endl;
    for (int i = 0; i < 20; i++) {
        std::cout << "n = " << i << std::endl;
        std::cout << "Recursivo modificado = " << fatorial_recursivo_mod(i) << std::endl;
    }
    end_count();

    start_count();
    std::cout << "Fibonacci Iterativo" << std::endl;
    for (int i = 0; i < 20; i++) {
        std::cout << "n = " << i << std::endl;
        std::cout << "Iterativo = " << fibonacci_iterativo(i) << std::endl;
    }
    end_count();

    start_count();
    std::cout << "Fibonacci recursivo" << std::endl;
    for (int i = 0; i < 20; i++) {
        std::cout << "n = " << i << std::endl;
        std::cout << "Recursivo = " << fibonacci_recursivo(i) << std::endl;
    }
    end_count();

    start_count();
    std::cout << "Fibonacci recursivo modificado" << std::endl;
    for (int i = 0; i < 20; i++) {
        std::cout << "n = " << i << std::endl;
        std::cout << "Recursivo modificado = " << fibonacci_recursivo_mod(i) << std::endl;
    }
    end_count();

    return 0;
}

// A FAZER
// - COLOCAR TESTES A PARTIR DA CHAMADA DO MAKE E NAO NO MAIN
// ESTUDAR PROBLEMAS COM FATORIAL A PARTIR DO 13