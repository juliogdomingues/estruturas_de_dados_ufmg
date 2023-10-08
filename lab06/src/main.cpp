#include <iostream>
#include <getopt.h>
#include <stdlib.h>


#include "../include/graph.hpp"
#include "../include/listaadj.hpp"
#include "../include/msgassert.h"

// definicoes de operacoes a serem testadas
// #define OPFATORIAL 1
// #define OPFIBONACCI 2

// variaveis globais para opcoes
static int opescolhida;
char outnome[100];
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
     outnome[0] = 0;

     // getopt - letra indica a opcao, : junto a letra indica parametro
     // no caso de escolher mais de uma operacao, vale a ultima
     while ((c = getopt(argc, argv, "d:n:k")) != -1){
       switch(c) {
         case 'd':
         // Dados básicos: Deve imprimir na tela, um valor por linha: a quantidade de vértices e de arestas do grafo, o grau mínimo e o máximo.
            avisoAssert(opescolhida==-1,"Mais de uma operacao escolhida");
            std::cout << QuantidadeVertices() << std::endl;
            std::cout << QuantidadeArestas() << std::endl;
            std::cout << GrauMinimo() << std::endl;
            std::cout << GrauMaximo() << std::endl;
            break;
         case 'n':
        //  Vizinhanças: Deve imprimir os vizinhos de cada um dos vértices. Todos os vizinhos de um vértice devem estar na mesma linha separados por um espaço em branco e encerrando com uma quebra de linha.
            avisoAssert(opescolhida==-1,"Mais de uma operacao escolhida");
            for (v : vertices) {
                ImprimeVizinhos(int v);
                std::endl;
            }
            break;
         case 'k':
        //  Deve imprimir 1 caso o grafo de entrada seja um grafo completo e 0 caso contrário.
            avisoAssert(opescolhida==-1,"Mais de uma operacao escolhida");
            std::cout << QuantidadeVertices() << std::endl;
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
    // switch (opescolhida){
    //     case OPFATORIAL:
    //         start_count();
    //         std::cout << "Fatorial Iterativo" << std::endl;
    //         for (int i = 0; i < optnt; i++) {
    //             std::cout << "n = " << i << " --> " << fatorial_iterativo(i) << std::endl;
    //         }
    //         end_count();

    //         start_count();
    //         std::cout << "Fatorial Recursivo" << std::endl;
    //         for (int i = 0; i < optnt; i++) {
    //             std::cout << "n = " << i << " --> " << fatorial_recursivo(i) << std::endl;
    //         }
    //         end_count();

    //         start_count();
    //         std::cout << "Fatorial Recursivo Modificado" << std::endl;
    //         for (int i = 0; i < optnt; i++) {
    //             std::cout << "n = " << i << " --> " << fatorial_recursivo_mod(i) << std::endl;
    //         }
    //         end_count();
    //         break;

    //     case OPFIBONACCI:
    //         start_count();
    //         std::cout << "Fibonacci Iterativo" << std::endl;
    //         for (int i = 1; i <= optnb; i++) {
    //             std::cout << "n = " << i << " --> " << fibonacci_iterativo(i) << std::endl;
    //         }
    //         end_count();

    //         start_count();
    //         std::cout << "Fibonacci Recursivo" << std::endl;
    //         for (int i = 1; i <= optnb; i++) {
    //             std::cout << "n = " << i << " --> " << fibonacci_recursivo(i) << std::endl;
    //         }
    //         end_count();

    //         start_count();
    //         std::cout << "Fibonacci Recursivo Modificado" << std::endl;
    //         for (int i = 1; i <= optnb; i++) {
    //             std::cout << "n = " << i << " --> " << fibonacci_recursivo_mod(i) << std::endl;
    //         }
    //         end_count();
    //         break;
    //     default:
    //      // nao deve ser executado, pois ha um erroAssert em parse_args
    //         // uso();
    //         exit(1);
    }
}