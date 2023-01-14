//Eva Sanchez Muñoz
//VJ60 

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

#include "Set.h"

using namespace std;

bool esFeliz(Set<int>&numeros, int n)
{
    int aux = 0; 

    while (n >= 10)
    {
        int num = n % 10; 
        aux += num * num;

        n = n / 10; 
    }

    aux += n * n; 

    if (aux == 1)
        return true;

    else if (aux == 0)
    {
        cout << aux << " ";
        return false;
    }

    else
    {
        cout << aux << " ";

        if (!numeros.contains(aux))
        {
            numeros.add(aux);
            return esFeliz(numeros, aux);
        }
            
        else
            return false; 
    }
}

bool resuelveCaso()
{
    int n;
    cin >> n; 

    if (!cin)
        return false; 

    Set<int>numeros; 
    numeros.add(n); 

    cout << n << " ";

    if (esFeliz(numeros, n))
        cout << 1 << "\n";
    else
        cout << 0 << "\n";

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
