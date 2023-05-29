#include <iostream>
#include "ArbolRojiNegro.h"

using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char **argv)
{
	ArbolRojiNegro arn;
	
	arn.insertar(86);
	arn.insertar(65);
	arn.insertar(70);
	arn.insertar(73);
	arn.insertar(93);
	arn.insertar(69);
	arn.insertar(25);
	arn.insertar(66);
	arn.insertar(68);
	arn.insertar(47);
	arn.insertar(62);
	arn.insertar(10);
	arn.inorden(arn.getraiz()).ImprimirCola();
	cout<<endl;
	arn.preorden(arn.getraiz()).ImprimirCola();
	cout<<endl;
	arn.eliminar(10);
	arn.eliminar(25);
	arn.posorden(arn.getraiz()).ImprimirCola();
	cout<<endl;
	arn.niveles(arn.getraiz()).ImprimirCola();
	cout<<"Este metodo fue hecho con la finalidad de corroborar los colores ;)"<<endl;
	arn.inordenRecusivoPrueba(arn.getraiz());

	
	/*int val, op;
	while (op != 6)
	{
		cout << "\n-----------------------------" << endl;
		cout << "MENU ARBOL ROJI NEGRO" << endl;
		cout << "-------------------------------" << endl;
		cout << "\n0 - insertar\n1 - eliminar\n2 - Inorden\n3 - Preorden\n4 - Posorden\n5 - Niveles\n6 - salir \nSeleccione una opcion: ";
		cin >> op;
		switch (op)
		{
		case 0:
			cout << "valor: ";
			cin >> val;
			if (arn.insertar(val))
			{
				cout << "insertado" << endl;
			}

			break;
		case 1:
			cout << "valor a eliminar: ";
			cin >> val;
			// arn.eliminar(val);
			break;
		case 2:
			arn.inorden(arn.getraiz()).ImprimirCola();
			// arn.inordenRecusivoPrueba(arn.getraiz());
			cout << endl;
			break;
		case 3:
			arn.preorden(arn.getraiz()).ImprimirCola();
			cout << endl;
			break;
		case 4:
			arn.posorden(arn.getraiz()).ImprimirCola();
			cout << endl;
			break;
		case 5:
			arn.niveles(arn.getraiz()).ImprimirCola();
			cout << endl;
			break;
		case 6:
			cout << "Gracias" << endl;
			break;
		}
	}*/
	return 0;
}
