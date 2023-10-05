#include <iostream>
#include <cstring>
#include <getopt.h>
#include <cstdlib>
#include <stdexcept>

#include "../include/avexp.hpp"
#include "../include/pilha.hpp"


// Variáveis globais para opções
static char opcao;
char argumento1[100];
char argumento2[100];
int contador_arg = 0;

void parse_args(int argc, char **argv) {
    int c;
    extern char *optarg;

    opcao = '\0';
    argumento1[0] = '\0';
    argumento2[0] = '\0';

    while ((c = getopt(argc, argv, "a:s:")) != -1) {
      contador_arg = optind;
        switch (c) {
            case 'a':
            case 's':
                if (opcao == '\0') {
                    opcao = c;
                    strcpy(argumento1, optarg);
                    std::cout << "1o argumento: " << argumento1 << std::endl;
                } else {
                    std::cerr << "Escolha apenas uma opção: -a ou -s." << std::endl;
                    exit(1);
                }
                break;
            default:
                std::cerr << "Uso: " << argv[0] << " -a <argumento1> <argumento2> ou -s <argumento1> <argumento2>" << std::endl;
                exit(1);
        }
    }

    if (opcao == '\0') {
        std::cerr << "Você deve escolher -a ou -s." << std::endl;
        exit(1);
    }
    
    // Copie o segundo argumento após a opção
    try {
        strcpy(argumento2, argv[optind]);
        std::cout << "2o argumento: " << argumento2 << std::endl;
    } catch (const std::invalid_argument &e) {
        std::cerr << "O segundo argumento deve ser um número inteiro." << std::endl;
        exit(1);
    }
}

int main(int argc, char **argv) {
    parse_args(argc, argv);

    if (opcao == 'a') {
        int av = avaliadorExpressoes(argumento1, argumento2);
        std::cout << "Opção -a escolhida com argumentos: " << argumento1 << " " << argumento2 << std::endl;
        std::cout << "resultado: " << av << std::endl;

    } else if (opcao == 's') {
        int resultado = satifaz(argumento1, argumento2);
        std::cout << "Opção -s escolhida com argumentos: " << argumento1 << " " << argumento2 << std::endl;
        if (resultado == 0) {
            std::cout << resultado << std::endl;
            return 0;
        }
        else {
            std::cout << "1 " << resultado << std::endl;
            return 0;
        }
    } else {
        std::cerr << "Opção inválida." << std::endl;
        exit(1);
    }

    return 0;
}
