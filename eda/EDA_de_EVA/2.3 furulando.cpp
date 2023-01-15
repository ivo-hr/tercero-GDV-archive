// Nombre del alumno Javier Murillo González
// Usuario del Juez VJ38


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <climits>

using namespace std;

struct Valores {
    int max;
    int min;
    Valores() : max(INT_MIN), min(INT_MIN) {};
};

// Complejidad log(n) -> n es el numero de numeros del vector
bool resolver(vector<int>& datos, int start, int end, Valores& mit) {

    if (end - start == 0) {
        mit.max = datos[start];
        mit.min = datos[start];
        return true;
    }

    else {
        int mitad = (end + start) / 2;
        Valores mitad1 = Valores();
        Valores mitad2 = Valores();
        bool m1 = resolver(datos, start, mitad, mitad1);
        bool m2 = resolver(datos, mitad + 1, end, mitad2);
        if (m2 == false || m1 == false) return false;
        else {
            if (mitad1.min <= mitad2.min && mitad1.max <= mitad2.max) {
                mit.min = mitad1.min;
                mit.max = mitad2.max;
                return true;
            }
            else return false;
        }
    }
}



// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n;
    cin >> n;
    if (n == 0) return false;
    vector<int> v;
    while (n != 0) {
        v.push_back(n);
        cin >> n;
    }
    Valores mitad = Valores();
    cout << (resolver(v, 0, v.size() - 1, mitad) ? "SI" : "NO") << endl;
    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.in");
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