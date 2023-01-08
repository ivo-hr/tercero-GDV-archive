#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <climits>

using namespace std;

bool resolver(vector<int> v, int& tam)
{
    int izq = 0, der = INT_MAX, size = tam / 2;

    vector <int> auxDer;
    vector <int> auxIzq;

    for (int i = 0; i < tam; i++)
    {
        if (i < size)
        {
            if (der > v[i])
               der = v[i];

            auxDer.push_back(v[i]);
        }

        else
        {
            if (izq < v[i])
                izq = v[i];

            auxIzq.push_back(v[i]);
        }
    }

    int aux = 0;
    bool ordenado = true;

    while (aux < size && ordenado)
    {
        if (der > auxIzq[aux] || izq < auxDer[aux])
            ordenado = false;

        aux++;
    } 

    if (ordenado)
    {
        if (size > 1)
            return resolver(auxIzq, size) && resolver(auxDer, size);
        else
            return true;
    }

    else
        return false; 
}

bool resuelveCaso()
{
    int aux = -1, tam = 0;

    vector <int> v;

    while (aux != 0)
    {
        cin >> aux;

        if (aux != 0)
        {
            v.push_back(aux);
            tam++;
        }
    }

    if (tam == 0)
        return false; 

    if (resolver(v, tam))
        cout << "SI\n";
    else
        cout << "NO\n";

    return true;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 

    while (resuelveCaso());


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}
