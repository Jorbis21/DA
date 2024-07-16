
/*@ <answer>
 *
 * Nombre y Apellidos:
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;


/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

int esfuerzo(vector<int> cortes, int longitud) {
    if (1 == cortes.size()) {
        return 2 * longitud;
    }
    else {
        int esfuer;
        for (int i = 0; i < cortes.size(); i++) {
            int corte = cortes[i];
            esfuer = min(esfuerzo(), esfuerzo());
        }
        return 2 * longitud + esfuer;
    }
}

bool resuelveCaso() {

    int longitud, Ncortes;
    cin >> longitud >> Ncortes;

    if (longitud == 0 && Ncortes == 0)
        return false;

    vector<int> dist_corte(Ncortes);
    for (int i = 0; i < Ncortes; i++) {
        int x; cin >> x;
        dist_corte[i] = x;
    }

    // escribir la solución

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
