#include <iostream>
#include "colasPrioridad.h"

using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char **argv)
{

	int tam, val, op = 0;
	cout << "Digite el numero de elementos del arbol: ";
	cin >> tam;
	Monticulo m(tam);

	while (op != 4)
	{
		cout << "\n-----------------------------" << endl;
		cout << "MENU COLA DE PRIORIDAD" << endl;
		cout << "-------------------------------" << endl;
		cout << "\n0 - insertar\n1 - atender \n2 - imprimir arreglo\n3 - monticulo lleno\n4 - Salir\nDigite la opcion deseada: ";
		cin >> op;

		switch (op)
		{
		case 0:
			cout << "dato a insertar: ";
			cin >> val;
			m.insertar(val) ? cout << "dato insertado" << endl : cout << "No se pudo insertar el dato" << endl; // operador condicional
			break;
		case 1:
			cout << "se tendio: " << m.atender() << endl;
			break;
		case 2:
			m.imprimirArreglo();
			break;
		case 3:
			m.monticuloLleno() ? cout << "true" << endl : cout << "false" << endl; // operador condicional ternario
			break;
		case 4:
			cout << "Gracias" << endl;
			break;
		}
	}

	return 0;
}
