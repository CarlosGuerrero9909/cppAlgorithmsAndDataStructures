#include <iostream>
#include "LibPila.h"
/* main para convertir a notacion polaca*/

int main(int argc, char** argv) {
	cout<<"Ingrese operacion a convertir: ";
	char c;
	Pila<char> P1(50);
	while (cin.get(c)) { // si el caracter es un salto de linea sale del bucle
	    while (c >= '0' && c <= '9') {
	      cout.put(c);
	      cin.get(c);
	    }
	    if (c == ')') {
	      cout << " ";
	      cout.put(P1.sacar());
	    }
	    if (c == '+')
	      P1.meter(c);
	    if (c == '*')
	      P1.meter(c);
	    if (c != '(')
	      cout << " ";
	    if (c == '\n') // si el caracter es un salto de linea sale del bucle
	      break;
	}
	if (!P1.vacia())
	    cout.put(P1.sacar());
	
	cout << endl;

	return 0;
}
