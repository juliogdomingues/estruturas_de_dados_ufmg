#include <iostream>
#include <cstring>
#include <getopt.h>
#include <stdexcept>

#include "../include/avexp.hpp"
#include "../include/pilha.hpp"
#include "../include/satisf.hpp"

// Defina constantes para opções
const char OPTION_B = 'b';
const char OPTION_S = 's';
const char OPTION_I = 'i';
const char OPTION_Q = 'q';
const char OPTION_M = 'm';
const char OPTION_P = 'p';
const char OPTION_Y = 'y';

int vertices = 0;

void parse_args(int argc, char **argv, char &opcao, std::string &argumento1, std::string &argumento2) {
    int c = 0;
    extern char *optarg;

    opcao = '\0';

    if (argc != 4) {
        std::cerr << "Forneça a quantidade correta de argumentos." << std::endl;
        exit(1);
    }

    while ((c = getopt(argc, argv, "b:s:i:q:m:p:y")) != -1) {
        switch (c) {
            case OPTION_B:
            case OPTION_S:
            case OPTION_Q:
            case OPTION_M:
            case OPTION_P:
            case OPTION_Y:
                if (opcao == '\0') {
                    opcao = c;
                    if (optarg && optarg[0] != '\0') {
                        vertices = optarg;
                    } else {
                        std::cerr << "O argumento não pode ser vazio." << std::endl;
                        exit(1);
                    }
                } else {
                    std::cerr << "Escolha apenas uma opção de ordenação (b, s, i, q, m, p, y)" << std::endl;
                    exit(1);
                }
                break;
            default:
                std::cerr << "Uso: " << argv[0] << " -x [método de ordenação] <número de vértices>" << std::endl;
                exit(1);
        }
    }

    if (opcao == '\0') {
        std::cerr << "Escolha apenas uma opção de ordenação (b, s, i, q, m, p, y)" << std::endl;
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
    try {
        char opcao;
        std::string argumento1, argumento2;

        parse_args(argc, argv, opcao, argumento1, argumento2);

        if (opcao == OPTION_A) {
            ExpressaoLogica av = ExpressaoLogica(argumento1.c_str(), argumento2.c_str());
            bool resultado = av.avaliar();
            std::cout << resultado << std::endl;
        } else if (opcao == OPTION_S) {
            Satisfaz resultado = Satisfaz(argumento1.c_str(), argumento2.c_str());
            resultado.avaliaSatisfaz();
        } else {
            std::cerr << "Opção inválida." << std::endl;
            exit(1);
        }
        
        return 0;
    } catch (const std::exception &e) {
        std::cerr << "Erro: " << e.what() << std::endl;
        return 1;
    }
}
