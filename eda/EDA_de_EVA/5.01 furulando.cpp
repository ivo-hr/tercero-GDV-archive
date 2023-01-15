//Javier Murillo González
//VJ38

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "stack_eda.h"
using namespace std;

bool equilibrado(string& linea) {
    //STACK LAST IN FIRST OUT AKA LIFO
    stack<char> c;

    bool equilibrio = true;
    int i = 0;
    //Mientras no se acabe la frase
    while (i<linea.size() && equilibrio) {
        //Si es uno de los caracteres que buscamos
        if (linea[i] == '(' || linea[i] == '[' || linea[i] == '{') {
            //Lo metemos en el stack
            c.push(linea[i]);
        }
        else {
            //Si es el uno de los caracteres de cierre
            if(linea[i] == ')'){
                //Miramos a ver si el ultimo caracter que hemos metido es el equivalente
                if (!c.empty() && c.top() == '(') {
                    //Si lo es lo quitamos del stack
                    c.pop();
                }
                //Si no lo es no esta equilibrada la frase
                else equilibrio = false;
            }
            else if (linea[i] == ']') {
                if (!c.empty() && c.top() == '[') {
                    c.pop();
                }
                else equilibrio = false;
            }
            else if (linea[i] == '}') {
                if (!c.empty() && c.top() == '{') {
                    c.pop();
                }
                else equilibrio = false;
            }
        }
        i++;
    }

    return equilibrio && c.empty();
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n;
    string l;
    getline(cin, l);
    if (!cin) return false;

    if (equilibrado(l)) cout << "SI" << endl;
    else cout << "NO" << endl;
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
