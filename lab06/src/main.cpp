#include <iostream>
#include <getopt.h>
#include <stdlib.h>


#include "../include/graph.hpp"
#include "../include/listaadj.hpp"
#include "../include/msgassert.h"

// definicoes de operacoes a serem testadas

// variaveis globais para opcoes
static int opescolhida;
char outnome[100];
int optn, optnt, optnb;

void parse_args(int argc,char ** argv) {
// Descricao: le as opcoes da linha de comando e inicializa variaveis
// Entrada: argc e argv
// Saida: optescolhida, optn, optalg

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
     int completo = 1;

     int numVertices;
     std::cin >> numVertices;
     
    Grafo meuGrafo;

    for (int i = 0; i < numVertices; i++) {
        int numVizinhos;
        std::cin >> numVizinhos;

        for (int j = 0; j < numVizinhos; j++) {
            int vizinho;
            std::cin >> vizinho;
            meuGrafo.InsereAresta(i, vizinho); // Insira o vizinho na lista de adjacência do vértice i
        }
    }


     // getopt - letra indica a opcao, : junto a letra indica parametro
     // no caso de escolher mais de uma operacao, vale a ultima
     while ((c = getopt(argc, argv, "d:n:k")) != -1){
       switch(c) {
         case 'd':
         // Dados básicos: Deve imprimir na tela, um valor por linha: a quantidade de vértices e de arestas do grafo, o grau mínimo e o máximo.
            avisoAssert(opescolhida==-1,"Mais de uma operacao escolhida");
            std::cout << meuGrafo.QuantidadeVertices() << std::endl;
            std::cout << meuGrafo.QuantidadeArestas() << std::endl;
            std::cout << meuGrafo.GrauMinimo() << std::endl;
            std::cout << meuGrafo.GrauMaximo() << std::endl;
            break;
         case 'n':
        //  Vizinhanças: Deve imprimir os vizinhos de cada um dos vértices. Todos os vizinhos de um vértice devem estar na mesma linha separados por um espaço em branco e encerrando com uma quebra de linha.
            avisoAssert(opescolhida==-1,"Mais de uma operacao escolhida");
            for (int v = 0; v < numVertices; v++) {
              meuGrafo.ImprimeVizinhos(v);
              std::cout << std::endl;
              }
            break;
         case 'k':
        //  Deve imprimir 1 caso o grafo de entrada seja um grafo completo e 0 caso contrário.
            avisoAssert(opescolhida==-1,"Mais de uma operacao escolhida");
            for (int i = 0; i < numVertices; i++) {
              if (meuGrafo.QuantidadeVertices() != numVertices - 1) {
                completo = 0; // Define como 0 (falso) se não for completo
                break;
                }
            }
            std::cout << completo << std::endl;
            break;
          default:
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
}