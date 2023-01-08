#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <climits>

using namespace std;

int findLostElement(vector<int>completo, vector<int>incompleto, int ini, int fin)
{
    int mitad = (ini + fin) / 2, tam = incompleto.size();

    if (mitad == tam || mitad == 0)
        return completo[mitad]; 
        
    if (completo[mitad] == incompleto[mitad])
        return findLostElement(completo, incompleto, mitad, fin); 
    else
    {
        if (completo[mitad] == incompleto[mitad - 1])
            return findLostElement(completo, incompleto, ini, mitad);
        else
            return completo[mitad]; 
    }
}

void resuelveCaso()
{
    int n, aux; 
    cin >> n; 

    vector<int>completo(n); 
    vector<int>incompleto(n - 1);

    for (int i = 0; i < n; i++)
    {
        cin >> aux; 
        completo[i] = aux; 
    }

    for (int i = 0; i < (n - 1); i++)
    {
        cin >> aux;
        incompleto[i] = aux;
    }

    cout << findLostElement(completo, incompleto, 0, n) << "\n"; 
}

int main() 
{
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 

    int n; 
    cin >> n; 

    for (int i = 0; i < n; i++)
        resuelveCaso(); 

    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}
