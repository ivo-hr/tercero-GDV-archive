//Eva Sanchez Muñoz
//VJ60 

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <stack>

using namespace std;

bool resolver(stack<char>& simbolos, char fin)
{
    if (simbolos.empty())
        return false;

    else if ((simbolos.top() == '(' && fin == ')')
        || (simbolos.top() == '[' && fin == ']')
        || (simbolos.top() == '{' && fin == '}'))
        simbolos.pop();

    else
        return false;

    return true;
}

bool resuelveCaso() 
{
    string text;
    getline(cin, text);

    if (!cin)
        return false;

    stack<char>simbolos;

    bool correcto = true;
    int tam = text.size();

    for (int i = 0; i < tam && correcto; i++)
    {     
        if (text[i] == '(' || text[i] == '[' || text[i] == '{')
            simbolos.push(text[i]);

        else if (text[i] == ')' || text[i] == ']' || text[i] == '}')
            correcto = resolver(simbolos, text[i]);
    }

    if (correcto)
        cout << "SI\n";
    else
        cout << "NO\n";

    return true;
}


int main() 
{
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
