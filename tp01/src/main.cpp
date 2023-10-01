#include <iostream>
#include <cstring>
#include <getopt.h>
#include <cstdlib>
#include <stdexcept>

// Variáveis globais para opções
static char opcao;
char argumento1[100];
int argumento2;
int contador_arg = 0;

void parse_args(int argc, char **argv) {
    int c;
    extern char *optarg;

    opcao = '\0';
    argumento1[0] = '\0';
    argumento2 = 0;

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
    
    // // Verifique se há exatamente dois argumentos após a opção
    // if (argc - optind != 2) {
    //     std::cerr << "Você deve fornecer exatamente dois argumentos após a opção." << std::endl;
    //     exit(1);
    // }

    // Copie o segundo argumento após a opção
    try {
        argumento2 = std::stoi(argv[optind]);
        std::cout << "2o argumento: " << argumento2 << std::endl;
    } catch (const std::invalid_argument &e) {
        std::cerr << "O segundo argumento deve ser um número inteiro." << std::endl;
        exit(1);
    }
}

int main(int argc, char **argv) {
    parse_args(argc, argv);

    if (opcao == 'a') {
        std::cout << "Opção -a escolhida com argumentos: " << argumento1 << " " << argumento2 << std::endl;
    } else if (opcao == 's') {
        std::cout << "Opção -s escolhida com argumentos: " << argumento1 << " " << argumento2 << std::endl;
    } else {
        std::cerr << "Opção inválida." << std::endl;
        exit(1);
    }

    return 0;
}
