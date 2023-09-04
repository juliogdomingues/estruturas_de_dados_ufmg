#include <iostream>
#include <getopt.h>
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
int optn, optnt, optnb;
int optn, optnt, optnb;

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
     optnt = -1;
     optnb = -1;
     optnt = -1;
     optnb = -1;
     outnome[0] = 0;

     // getopt - letra indica a opcao, : junto a letra indica parametro
     // no caso de escolher mais de uma operacao, vale a ultima
     while ((c = getopt(argc, argv, "b:t:")) != -1){
       switch(c) {
         case 't':
            avisoAssert(opescolhida==-1,"Mais de uma operacao escolhida");
	          opescolhida = OPFATORIAL;
              optnt = atoi(optarg)+1;
              optnt = atoi(optarg)+1;
            break;
         case 'b':
            avisoAssert(opescolhida==-1,"Mais de uma operacao escolhida");
	          opescolhida = OPFIBONACCI;
              optnb = atoi(optarg);
            break;
              optnb = atoi(optarg);
            break;
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
            for (int i = 0; i < optnt; i++) {
                std::cout << "n = " << i << " --> " << fatorial_iterativo(i) << std::endl;
            for (int i = 0; i < optnt; i++) {
                std::cout << "n = " << i << " --> " << fatorial_iterativo(i) << std::endl;
            }
            end_count();

            start_count();
            std::cout << "Fatorial Recursivo" << std::endl;
            for (int i = 0; i < optnt; i++) {
                std::cout << "n = " << i << " --> " << fatorial_recursivo(i) << std::endl;
            std::cout << "Fatorial Recursivo" << std::endl;
            for (int i = 0; i < optnt; i++) {
                std::cout << "n = " << i << " --> " << fatorial_recursivo(i) << std::endl;
            }
            end_count();

            start_count();
            std::cout << "Fatorial Recursivo Modificado" << std::endl;
            for (int i = 0; i < optnt; i++) {
                std::cout << "n = " << i << " --> " << fatorial_recursivo_mod(i) << std::endl;
            std::cout << "Fatorial Recursivo Modificado" << std::endl;
            for (int i = 0; i < optnt; i++) {
                std::cout << "n = " << i << " --> " << fatorial_recursivo_mod(i) << std::endl;
            }
            end_count();
            break;

        case OPFIBONACCI:
            start_count();
            std::cout << "Fibonacci Iterativo" << std::endl;
            for (int i = 1; i <= optnb; i++) {
                std::cout << "n = " << i << " --> " << fibonacci_iterativo(i) << std::endl;
            for (int i = 1; i <= optnb; i++) {
                std::cout << "n = " << i << " --> " << fibonacci_iterativo(i) << std::endl;
            }
            end_count();

            start_count();
            std::cout << "Fibonacci Recursivo" << std::endl;
            for (int i = 1; i <= optnb; i++) {
                std::cout << "n = " << i << " --> " << fibonacci_recursivo(i) << std::endl;
            std::cout << "Fibonacci Recursivo" << std::endl;
            for (int i = 1; i <= optnb; i++) {
                std::cout << "n = " << i << " --> " << fibonacci_recursivo(i) << std::endl;
            }
            end_count();

            start_count();
            std::cout << "Fibonacci Recursivo Modificado" << std::endl;
            for (int i = 1; i <= optnb; i++) {
                std::cout << "n = " << i << " --> " << fibonacci_recursivo_mod(i) << std::endl;
            }
            end_count();
            break;
        default:
         // nao deve ser executado, pois ha um erroAssert em parse_args
            // uso();
            exit(1);
    }
}

