#include <iostream>
#include <chrono>
#include <fstream>
#include "../include/segtree.hpp"

int main() {
    auto start = std::chrono::high_resolution_clock::now();

    int instantesTempo, nOperacoes;
    if (!(std::cin >> instantesTempo >> nOperacoes)) {
        std::cerr << "Erro ao ler entrada.\n";
        return 1;
    }

    segTree st; // Cria instância da segTree
    st.build(1, 0, MAX - 1);

    for (int i = 0; i < nOperacoes; i++) {
        char operacao;
        std::cin >> operacao;
        if (operacao == 'u') {
            long long int tempo, a, b, c, d;
            std::cin >> tempo >> a >> b >> c >> d;
            Matriz newMatrix(a, b, c, d);
            st.update(tempo, newMatrix, 1, 0, MAX - 1);
        } else if (operacao == 'q') {
            int t0, td, x, y;
            std::cin >> t0 >> td >> x >> y;

            Matriz resultado = st.query(t0, td, 1, 0, MAX - 1);
            int finalX = (resultado.m[0][0] * x + resultado.m[0][1] * y) % MOD;
            int finalY = (resultado.m[1][0] * x + resultado.m[1][1] * y) % MOD;

            std::cout << finalX << " " << finalY << std::endl;

            #ifdef DEBUG
            std::cout << "Matriz de transformação final:\n";
            std::cout << resultado.m[0][0] << " " << resultado.m[0][1] << "\n" << resultado.m[1][0] << " " << resultado.m[1][1] << "\n";
            std::cout << "Aplicando transformação ao ponto (" << x << ", " << y << ")\n";
            std::cout << "Ponto transformado: (" << finalX << ", " << finalY << ")\n";
            #endif
        }
    }

    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    
    #ifdef DEBUG
    std::cout << "Tempo de execução: " << duration.count() << " microssegundos" << std::endl;
    #endif
    std::ofstream file("resultadoados.txt");
    file << "Tempo de execução para o método " << nOperacoes << ": " << duration.count() << " microssegundos" << std::endl;
    file.close();

    return 0;
}
