/*@ <answer>
 *
 * Nombre y Apellidos:
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
using namespace std;

#include "DigrafoValorado.h" // propios o los de las estructuras de datos de clase
#include "IndexPQ.h"
#define N 2147483648
/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>
template <typename Valor>
class Dijkstra {
public:
    Dijkstra(DigrafoValorado<Valor> const& g, int orig) : origen(orig),
        dist(g.V(), INF), ulti(g.V()), pq(g.V()), caminos(N) {
        dist[origen] = 0;
        caminos[origen] = 1;
        pq.push(origen, 0);
        while (!pq.empty()) {
            int v = pq.top().elem; pq.pop();
            for (auto a : g.ady(v))
                relajar(a);
        }
    }
    bool hayCamino(int v) const { return dist[v] != INF; }
    Valor distancia(int v) const { return dist[v]; }
    int numCaminos(int v) const { return caminos[v]; }
    
private:
    const Valor INF = std::numeric_limits<Valor>::max();
    int origen;
    std::vector<Valor> dist;
    std::vector<AristaDirigida<Valor>> ulti;
    std::vector<Valor> caminos;
    IndexPQ<Valor> pq;
    void relajar(AristaDirigida<Valor> a) {
        int v = a.desde(), w = a.hasta();
        if (dist[w] == dist[v] + a.valor()) {
            caminos[w] += caminos[v];
        }
        else if (dist[w] > dist[v] + a.valor()) {
            dist[w] = dist[v] + a.valor(); ulti[w] = a;
            caminos[w] = caminos[v];
            pq.update(w, dist[w]);
        }
    }
};
bool resuelveCaso() {

    // leer los datos de la entrada
    int V, A;
    cin >> V >> A;
    
    if (!std::cin)  // fin de la entrada
        return false;

    DigrafoValorado<int> sol(V+1);
    for (int i = 0; i < A; i++) {
        int v1, v2, val;
        cin >> v1 >> v2 >> val;
        sol.ponArista(AristaDirigida<int>(v1, v2, val));
        sol.ponArista(AristaDirigida<int>(v2, v1, val));
    }

    // resolver el caso posiblemente llamando a otras funciones
    Dijkstra<int> caminos = Dijkstra<int>(sol, 1);
    // escribir la solución
    cout << caminos.numCaminos(V) << "\n";

    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso());

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}
