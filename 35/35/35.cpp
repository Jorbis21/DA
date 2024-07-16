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

class Edificio{
public:
    Edificio() : ini(0), fin(0), camino(false){}
    

    bool operator<(Edificio x) {
        return fin < x.fin;
    }
    int ini, fin;
    bool camino;
};


bool resuelveCaso() {

    // leer los datos de la entrada
    int n, caminos = 0;
    cin >> n;

    if (n == 0)
        return false;

    vector<Edificio> edificios(n);
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        edificios[i].ini = a;
        edificios[i].fin = b;
    }

    sort(edificios.begin(), edificios.end());

    for (int i = 0; i < n-1; i++) {
        if (!edificios[i].camino) {
            if (edificios[i].ini < edificios[i + 1].ini && edificios[i].fin > edificios[i + 1].ini) {
                caminos++; edificios[i + 1].camino = true;
                edificios[i].camino = true;
            }
        }
     
    }
    if (caminos == 0)
        caminos = n;
    else if (!edificios[n - 1].camino)
        caminos++;
    cout << caminos << "\n";

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
