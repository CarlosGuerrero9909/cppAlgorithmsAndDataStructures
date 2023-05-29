#include <iostream>
#include <cstdlib>
#include <iostream>
#include <ctype.h>
#include <iomanip>
#include "pila1.h"
#include "Cola1.h"


using namespace std;

int main(int argc, char *argv[]) {
  cola Cola;
  pila Pila[3];
  int i, j, tam, grupo = 0, orden[3];
  char x;

  do {
    cout << "Escriba un mùltiplo de 3: "; //numero de elementos que queremos
    cin >> tam;
  } while (tam % 3 != 0);
  i = 1;
  x = 0;
  cout << x;
  while (i <= tam && i < 255) { //numero caracteres ascii
    if ((x == 0) || (x == 13) || (x == 32) || (x > 6 && x < 11)) //no son caracteres imprimibles
      x++;
    else { //va poniendo los elementos en la cola
      Cola.InsCola(x);
      i++;
      x++;
    }
  }
  cout << "mire cuidadosamente los sìmbolos y elija uno\n";

  for (j = 1; j < tam / 3; j++) {
    cout << "  Gr1  " << "Gr2  " << "Gr3  " << endl;
    while (!Cola.ColaVacia()) { //va sacando todo lo que este en la cola
      for (i = 0; i < 3; i++) {
        x = Cola.AtenderCola(); //va sacando los elementos de la cola
        cout << setw(4) << x; //deja 4 spacios e imprime
        Pila[i].Push(x); // va poniendo los elementos sacados de la cola en una pila distinta (recordar arreglo de pilas)
      }
      cout << "\n";
    }

    cout << "elija el grupo en que quedo el sìmbolo seleccionado (1, 2 o 3): ";
    cin >> grupo;
    switch (grupo) { //organiza las pilas de una manera
    case 1: {
      orden[0] = 1;
      orden[1] = 0;
      orden[2] = 2;
      break;
    }
    case 2: {
      orden[0] = 0;
      orden[1] = 1;
      orden[2] = 2;
      break;
    }
    case 3: {
      orden[0] = 0;
      orden[1] = 2;
      orden[2] = 1;
      break;
    }
    }
    for (i = 0; i < 3; i++) { //para cada pila
      while (!Pila[orden[i]].PilaVacia()) { //mientras que esa pila no este vacia
        Cola.InsCola(Pila[orden[i]].Pop()); //se inserta en la cola los elementos que vamos sacando de la cola
      }
    }
  }

  j = tam - tam / 2;

  for (i = 1; i <= j; i++) {
    x = Cola.AtenderCola();
  }
  cout << "La figura elegida es: " << x << endl;
  system("PAUSE");
  return EXIT_SUCCESS;
}
