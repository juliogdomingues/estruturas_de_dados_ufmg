#include <iostream>
#include <getopt.h>
#include <limits>
#include <stdlib.h>


#include "../include/fatorial.hpp"
#include "../include/fibonacci.hpp"
#include "../include/msgassert.h"
#include "../include/time_count.hpp"


// definicoes de operacoes a serem testadas
#define OPFATORIAL 1
#define OPFIBONACCI 2

// variaveis globais para opcoes
static int opescolhida;
char outnome[100];
int optn;

void parse_args(int argc,char ** argv)
// Descricao: le as opcoes da linha de comando e inicializa variaveis
// Entrada: argc e argv
// Saida: optescolhida, optn, optalg
{
     // variaveis externas do getopt
     extern char * optarg;
    //  extern int optind;

     // variavel auxiliar
     int c;

     // inicializacao variaveis globais para opcoes
     opescolhida = -1;
     optn = -1;
     outnome[0] = 0;

     // getopt - letra indica a opcao, : junto a letra indica parametro
     // no caso de escolher mais de uma operacao, vale a ultima
     while ((c = getopt(argc, argv, "tc:n:lh")) != EOF){
       switch(c) {
         case 't':
		  avisoAssert(opescolhida==-1,"Mais de uma operacao escolhida");
	          opescolhida = OPFATORIAL;
                  break;
         case 'c':
		  avisoAssert(opescolhida==-1,"Mais de uma operacao escolhida");
	          opescolhida = OPFIBONACCI;
                  break;
         case 'n': 
	          optn = atoi(optarg)+1;
		  break;
         case 'h':
         default:
                  // uso();
                  exit(1);

       }
     }
     
}

int main(int argc, char ** argv) {
// Descricao: programa principal
// Entrada: argc e argv
// Saida: depende da operacao escolhida

  // avaliar linha de comando
    parse_args(argc,argv);

  // execucao dependente da operacao escolhida
    switch (opescolhida){
        case OPFATORIAL:
            start_count();
            std::cout << "Fatorial Iterativo" << std::endl;
            for (int i = 0; i < optn; i++) {
                std::cout << "n = " << i << std::endl;
                std::cout << fatorial_iterativo(i) << std::endl;
            }
            end_count();

            start_count();
            std::cout << "Fatorial recursivo" << std::endl;
            for (int i = 0; i < optn; i++) {
                std::cout << "n = " << i << std::endl;
                std::cout << fatorial_recursivo(i) << std::endl;
            }
            end_count();

            start_count();
            std::cout << "Fatorial recursivo modificado" << std::endl;
            for (int i = 0; i < optn; i++) {
                std::cout << "n = " << i << std::endl;
                std::cout << fatorial_recursivo_mod(i) << std::endl;
            }
            end_count();
            // break;

        case OPFIBONACCI:
            start_count();
            std::cout << "Fibonacci Iterativo" << std::endl;
            for (int i = 0; i < optn; i++) {
                std::cout << "n = " << i << std::endl;
                std::cout << "Iterativo = " << fibonacci_iterativo(i) << std::endl;
            }
            end_count();

            start_count();
            std::cout << "Fibonacci recursivo" << std::endl;
            for (int i = 0; i < optn; i++) {
                std::cout << "n = " << i << std::endl;
                std::cout << "Recursivo = " << fibonacci_recursivo(i) << std::endl;
            }
            end_count();

            start_count();
            std::cout << "Fibonacci recursivo modificado" << std::endl;
            for (int i = 0; i < optn; i++) {
                std::cout << "n = " << i << std::endl;
                std::cout << "Recursivo modificado = " << fibonacci_recursivo_mod(i) << std::endl;
            }
            end_count();
            // break;
        default:
         // nao deve ser executado, pois ha um erroAssert em parse_args
            // uso();
            exit(1);
    }

  // conclui registro de acesso
    return 0;
    // Limpeza do buffer de entrada
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
