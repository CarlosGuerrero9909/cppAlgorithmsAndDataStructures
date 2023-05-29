#include <iostream>
#include "ColaDoble.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */


int main(int argc, char** argv) {
	
	int op, x;
	ColaDoble<int> enteros;
	
	while(op!=9){
		cout<<"\n-----------------------------"<<endl;
		cout<<"MENU COLA DOBLE"<<endl;
		cout<<"-------------------------------"<<endl;
		cout<<"\n1 - cola vacia \n2 - tamaño cola\n3 - insertar derecha\n4 - insertar izquierda\n"<<
		"5 - atender derecha\n6 - atender izquierda\n7 - imprimir derecha\n8 - imprimir izquierda\n9 - Salir\nDigite la opcion deseada: ";
		cin>>op;
		
		switch(op) {
			case 1:
				enteros.colaVacia()?cout<<"true"<<endl:cout<<"false"<<endl; //operador condicional ternario
				break;
			case 2:
				cout<<enteros.tamCola()<<endl;
				break;
			case 3:
				cout<<"x: "; 
				cin>>x;
				enteros.inqueue(x, 'D');
				break;
			case 4:
				cout<<"x: "; 
				cin>>x;
				enteros.inqueue(x, 'I');
				break;
			case 5:
				enteros.dequeue('D')?cout<<"Atendido"<<endl:cout<<"No se pudo atender (Cola vacia)"<<endl; //operador condicional ternario
				break;
			case 6:
				enteros.dequeue('I')?cout<<"Atendido"<<endl:cout<<"No se pudo atender (Cola vacia)"<<endl; //operador condicional ternario
				break;
			case 7:
				enteros.imprimirCola('D')?cout<<"":cout<<"Cola vacia"<<endl; //operador condicional ternario
				break;
			case 8:
				enteros.imprimirCola('I')?cout<<"":cout<<"Cola vacia"<<endl; //operador condicional ternario
				break;
			case 9:
				cout<<"Gracias"<<endl;
				break;
		}
	}
		
	return 0;
}
