
/*@ <answer>
 *
 * Nombre y Apellidos:
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
using namespace std;

#include "GrafoValorado.h"  // propios o los de las estructuras de datos de clase
#include "ConjuntosDisjuntos.h"
#include "PriorityQueue.h"
/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

class ARM_Kruskal {
private:
    std::vector<Arista<int>> _ARM;
    int coste;
    
public:  
    int numConj;
    int costeARM() const {
        return coste;
    }
  
    std::vector<Arista<int>> const& ARM() const {
        return _ARM;
    }
    ARM_Kruskal(GrafoValorado<int> const& g) : coste(0) {
        PriorityQueue<Arista<int>> pq(g.aristas());
        ConjuntosDisjuntos cjtos(g.V());
        while (!pq.empty()) {
            auto a = pq.top(); pq.pop();
            int v = a.uno(), w = a.otro(v);
            if (!cjtos.unidos(v, w)) {
                cjtos.unir(v, w);
                _ARM.push_back(a); 
                coste = a.valor();
                if (_ARM.size() == g.V() - 1) break;
            }
        }
       numConj = cjtos.num_cjtos() - 1;
    }
};


void resuelveCaso() {
    int N, M, V1, V2, valor;
    cin >> N >> M;
    GrafoValorado<int> g = GrafoValorado<int>(N+1);
    for (int i = 0; i < M; i++) {
        cin >> V1 >> V2 >> valor;
        g.ponArista(Arista<int>(V1, V2, valor));
    }
    ARM_Kruskal x = ARM_Kruskal(g);
    if (x.numConj > 1)
        cout << "Imposible\n";
    else
        cout << x.costeARM() << "\n";
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}
