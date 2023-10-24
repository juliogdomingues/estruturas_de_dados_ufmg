#include <iostream>
#include <cstring>
#include <getopt.h>
#include <stdexcept>

#include "../include/avexp.hpp"
#include "../include/pilha.hpp"
#include "../include/satisf.hpp"

// Defina constantes para opções
const char OPTION_A = 'a';
const char OPTION_S = 's';

void parse_args(int argc, char **argv, char &opcao, std::string &argumento1, std::string &argumento2) {
    int c;
    extern char *optarg;

    opcao = '\0';

    if (argc != 4) {
        std::cerr << "Forneça a quantidade correta de argumentos." << std::endl;
        exit(1);
    }

    while ((c = getopt(argc, argv, "a:s:")) != -1) {
        switch (c) {
            case OPTION_A:

            case OPTION_S:
                if (opcao == '\0') {
                    opcao = c;
                    if (optarg && optarg[0] != '\0') {
                        argumento1 = optarg;
                    } else {
                        std::cerr << "O argumento não pode ser vazio." << std::endl;
                        exit(1);
                    }
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
