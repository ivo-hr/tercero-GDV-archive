// David Brey Plaza
// VJ08


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;


// función que resuelve el problema
int minimoCurva(vector<int> const &datos, int ini, int fin)
{
    // Si solo queda uno, entonces asumimos que es el minimo
    if (fin - ini <= 0)
        return datos[ini];
    else
    {
        // Si solo quedan 2, devolvemos el mas pequeño
        if (fin - ini == 1)
            return min(datos[ini], datos[fin]);

        int mit = (fin + ini) / 2;
        int ant = mit - 1;
        int sig = mit + 1;

        // Nos aseguramos de no salirnos del vector
        if (ant < 0)
            ant = mit;

        if (sig >= datos.size())
            sig = mit;


        if (datos[mit] > datos[sig])
            return minimoCurva(datos, mit, fin); // Si mi siguiente es menor, entonces el minimo esta hacia la derecha

        else if (datos[mit] > datos[ant])
            return minimoCurva(datos, ini, mit); // Si mi anterior es menor, entonces el minimo esta hacia la izquierda
        else
            return datos[mit];
    }

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int N;
    cin >> N;

    if (!std::cin)
        return false;

    vector<int> v(N);
    for (int i = 0; i < N; i++)
    {
        int aux;
        cin >> aux;
        v[i] = aux;
    }

    // escribir sol
    cout << minimoCurva(v, 0, v.size() - 1) << "\n";

    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


    while (resuelveCaso())
        ;


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}
