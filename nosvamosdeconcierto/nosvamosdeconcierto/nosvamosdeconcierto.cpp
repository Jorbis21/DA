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
struct concierto {
    int numGrupos, presupuesto;
    concierto() : numGrupos(0), presupuesto(0) {};
    concierto(int n, int p) : numGrupos(n), presupuesto(p) {}
    bool operator < (concierto c) {
        return this->numGrupos > c.numGrupos;
    }
};

bool resuelveCaso() {

    // leer los datos de la entrada
    int P, N, sol = 0;
    cin >> P >> N;

    if (!std::cin)  // fin de la entrada
        return false;

    vector<concierto> festival(N);
    for(int i = 0; i < N; i++){
        int g, p; cin >> g >> p;
        festival[i] = concierto(g, p);
    }
    sort(festival.begin(), festival.end());

    for (int i = 0; i < N; i++) {
        if (P >= festival[i].presupuesto) {
            sol += festival[i].numGrupos;
            P -= festival[i].presupuesto;
        }
    }
    cout << sol << "\n";
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