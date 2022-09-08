
/*@ <answer>
 *
 * Nombre y Apellidos: Enrique Juan Gamboa
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
//#include <...>
using namespace std;

#include "../Código C++ TADs bintree y set-20220908/bintree_eda.h"  // propios o los de las estructuras de datos de clase

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

bool inEquil(bintree<int> const& tree, int& height) {

    int lHei = height, rHei = height;


    if (!tree.right().empty()) {
        rHei++;
        if (!inEquil(tree.right(), rHei)) return false;
    }
    if (!tree.left().empty()) {
        
        lHei++;
        if (!inEquil(tree.left(), lHei)) return false;
    }

    height = max(lHei, rHei);
    return abs(rHei - lHei) <= 1;

}

void resuelveCaso() {

    


    // leer los datos de la entrada
    int n;
    bintree<int> tree;

    tree = leerArbol(-1);
    // resolver el caso posiblemente llamando a otras funciones

    // escribir la solución
    int iteration = 0;
    bool isEquil = inEquil(tree, iteration);
    cout << (isEquil ? "SI" : "NO") << endl;

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
