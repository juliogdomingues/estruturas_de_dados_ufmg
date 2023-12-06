#include <iostream>

#include "../include/matriz.hpp"
#include "../include/segtree.hpp"


int main() {
    int instantesTempo, nOperacoes;
    if (!(std::cin >> instantesTempo >> nOperacoes) || instantesTempo <= 0 || nOperacoes < 0) {
        std::cerr << "Erro: Entrada inválida para instantes de tempo ou número de operações.\n";
        return 1;
    }

    SegTree* st = new SegTree(instantesTempo); // Cria instância da SegTree    

    for (int i = 0; i < nOperacoes; i++) {
        char operacao;
        int tempo, a, b, c, d;
        int t0, td, x, y;

        std::cin >> operacao;
        if (operacao == 'u') {
            if (!(std::cin >> tempo >> a >> b >> c >> d) || tempo < 0 || tempo >= instantesTempo) {
                std::cerr << "Erro: Entrada inválida para operação de atualização.\n";
                continue;
            }
            Matriz m(a, b, c, d);
            st->atualiza(1, 0, instantesTempo-1, tempo, m);
        } else if (operacao == 'q') {
            if (!(std::cin >> t0 >> td >> x >> y) || t0 < 0 || td >= instantesTempo || t0 > td) {
                std::cerr << "Erro: Entrada inválida para operação de consulta.\n";
                continue;
            }
            Matriz m = st->consulta(1, 0, instantesTempo-1, t0, td);
            Matriz resultado = multiplica(m, Matriz(x, 0, y, 0));
            std::cout << resultado.pegaIndice(0, 0) << " " << resultado.pegaIndice(1, 0) << std::endl;
        }
    }

    delete st;
    return 0;
}
