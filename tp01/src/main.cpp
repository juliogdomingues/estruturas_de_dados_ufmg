#include <iostream>
#include <cstring>
#include <getopt.h>
#include <stdexcept>

#include "../include/avexp.hpp"
#include "../include/pilha.hpp"
#include "../include/msgassert.h"
#include "../include/satisf.hpp"

// Defina constantes para opções
const char OPTION_A = 'a';
const char OPTION_S = 's';

void parse_args(int argc, char **argv, char &opcao, std::string &argumento1, std::string &argumento2) {
    int c;
    extern char *optarg;

    opcao = '\0';

    if (argc != 4) {
        avisoAssert(opcao != -4, "Forneça a quantidade correta de argumentos");
    }

    while ((c = getopt(argc, argv, "a:s:")) != -1) {
        switch (c) {
            case OPTION_A:
            case OPTION_S:
                if (opcao == '\0') {
                    opcao = c;
                    argumento1 = optarg;
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

    if (optind < argc) {
        argumento2 = argv[optind];
    } else {
        std::cerr << "Faltando o segundo argumento." << std::endl;
        exit(1);
    }
}

int main(int argc, char **argv) {
    char opcao;
    std::string argumento1, argumento2;

    parse_args(argc, argv, opcao, argumento1, argumento2);

    if (opcao == OPTION_A) {
        ExpressaoLogica av;
        av = ExpressaoLogica(argumento1.c_str(), argumento2.c_str());
        std::cout << "Opção -a escolhida com argumentos: " << argumento1 << " " << argumento2 << std::endl;
        bool resultado = av.avaliar(); // Avaliar a expressão
        std::cout << resultado << std::endl; // Imprimir o resultado

    } else if (opcao == OPTION_S) {
        Satisfaz resultado;
        resultado = Satisfaz(argumento1.c_str(), argumento2.c_str());
        std::cout << "Opção -s escolhida com argumentos: " << argumento1 << " " << argumento2 << std::endl;
        // if (resultado == 0) {
        //     std::cout << resultado << std::endl;
        //     return 0;
        // } else {
        //     std::cout << "1 " << resultado << std::endl;
        //     return 0;
        }
    // } else {
    //     std::cerr << "Opção inválida." << std::endl;
    //     exit(1);
    // }

    return 0;
}
