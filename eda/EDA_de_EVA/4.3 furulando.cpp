// Nombre del alumno Javier Murillo González
// Usuario del Juez VJ38


#include <iostream>
#include <iomanip>
#include <fstream>
#include "Set2.h"

using namespace std;


// función que resuelve el problema



void resolver(int dato) {
    Set2<int> datos;

    //Mientras no contenga el dato
    while (!datos.contains(dato)) {
        cout << dato << " "; // para ver los numeros por los que pasa
        //añadimos el dato
        datos.add(dato);

        //pasamos al siguiente dato
        int suma = 0;

        //Mientras haya  potencias de 10
        while (dato > 0) {
            int digito = dato % 10; //Sacamos el modulo 10
            suma += digito * digito; //sacamos el cuadrado del digito
            dato /= 10; // avanzo de digito
        }

        dato = suma;
    }

    //Si el dato ha llegado a 1 es feliz :D
    if (dato == 1) {
        cout << dato << endl;
    }

    //Si el dato no ha llegado a 1 no es feliz :d
    else {
        cout <<dato<<" "<< 0 << endl;
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n = -1;
    cin >> n;
    if (n == -1) {
        return false;
    }
    resolver(n);

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