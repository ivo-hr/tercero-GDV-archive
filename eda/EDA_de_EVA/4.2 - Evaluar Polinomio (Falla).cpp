//Eva Sanchez Muñoz
//VJ60 

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

class Polinomio
{
protected: 
    vector<pair<int, int>> monomios; 

public:

    void introducirMonomio(const pair<int, int>& mon)
    {
        monomios.push_back(mon); 
    }

    int evaluar(const int& v) const
    {
        int result = 0;

        for (auto& m : monomios)
            result += m.first * pow(v, m.second);

        return result;
    }
};

bool resuelveCaso() 
{
    int mon, exp;
    cin >> mon >> exp;

    if (!cin)
        return false; 

    Polinomio p; 

    while (!(mon == 0 && exp == 0))
    {
        p.introducirMonomio({mon, exp});
        cin >> mon >> exp;
    }

    int valor, pruebas;
    cin >> pruebas;

    for (int i = 0; i < pruebas; i++) 
    {
        cin >> valor;
        cout << p.evaluar(valor) << " ";
    }

    cout << endl;

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
