#include <iostream>
#include <getopt.h>
#include <stdlib.h>


#include "../include/graph.hpp"
#include "../include/listaadj.hpp"

int main(int argc, char ** argv) {
  int numVertices;
  std::cin >> numVertices;
    
  Grafo meuGrafo;

  for (int i = 0; i < numVertices; i++) {
      meuGrafo.InsereVertice();
      
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
  // while ((c = getopt(argc, argv, "dnk")) != -1){
  switch(argv[1][1]) {
    case 'd':
      // Dados básicos: Deve imprimir na tela, um valor por linha: a quantidade de vértices e de arestas do grafo, o grau mínimo e o máximo.
      std::cout << meuGrafo.QuantidadeVertices() << std::endl;
      std::cout << meuGrafo.QuantidadeArestas() << std::endl;
      std::cout << meuGrafo.GrauMinimo() << std::endl;
      std::cout << meuGrafo.GrauMaximo() << std::endl;
      break;
    case 'n':
      //  Vizinhanças: Deve imprimir os vizinhos de cada um dos vértices. Todos os vizinhos de um vértice devem estar na mesma linha separados por um espaço em branco e encerrando com uma quebra de linha.
      for (int v = 0; v < numVertices; v++) {
        meuGrafo.ImprimeVizinhos(v);
        std::cout << std::endl;
        }
      break;
    case 'k':
      //  Deve imprimir 1 caso o grafo de entrada seja um grafo completo e 0 caso contrário.
      std::cout << meuGrafo.GrafoCompleto() << std::endl;            
      break;
    default:
          exit(1);
  }
}