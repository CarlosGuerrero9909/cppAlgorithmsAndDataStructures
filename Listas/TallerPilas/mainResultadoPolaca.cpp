#include <iostream>
#include "LibPila.h"
/* main para resolver operaciones en notacion polaca */

int main(int argc, char** argv) {
	cout << "ingrese en notacion polaca Separada por espacios: ";
  char c1;
  Pila<int> P2(50);
  int x;
  
  while (cin.get(c1)) {
    x = 0;
    while (c1 == ' ')
      cin.get(c1);
    while (c1 >= '0' && c1 <= '9') {
      x = 10 * x + (c1 - '0');
      cin.get(c1);
    }
    if (c1 == '+')
      x = P2.sacar() + P2.sacar();
    if (c1 == '*')
      x = P2.sacar() * P2.sacar();
    if (c1 == '\n') // si el caracter es un salto de linea sale del bucle
      break;
    P2.meter(x);
  }
  cout << P2.sacar() << endl;
	return 0;
}
