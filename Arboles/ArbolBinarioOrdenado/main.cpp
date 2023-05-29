#include <iostream>
#include "arbolBinario.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int tam;
	cout<<"Digite el numero de elementos del arbol: ";
	cin>>tam;
	ArbinOrdenado A(tam);
	/*
	A.insertar(50);
	A.insertar(75);
	A.insertar(60);
	A.insertar(30);
	A.insertar(90);
	A.insertar(10);
	A.insertar(40);
	A.insertar(65);
	A.preorden(A.getraiz()).ImprimirCola();
	cout<<endl;
	A.posorden(A.getraiz()).ImprimirCola();
	cout<<endl;
	A.inorden(A.getraiz()).ImprimirCola();
	cout<<endl;
	A.niveles(A.getraiz()).ImprimirCola();
	cout<<endl;
	A.eliminar(50);
	A.eliminar(30);
	A.eliminar(10);
	A.preorden(A.getraiz()).ImprimirCola();
	cout<<endl;
	A.posorden(A.getraiz()).ImprimirCola();
	cout<<endl;
	A.inorden(A.getraiz()).ImprimirCola();
	cout<<endl;
	A.niveles(A.getraiz()).ImprimirCola();
	cout<<endl;
	*/
	int val,op;
	
	while(op!=6){
		cout<<"\n-----------------------------"<<endl;
		cout<<"MENU ARBOL BINARIO ORDENADO"<<endl;
		cout<<"-------------------------------"<<endl;
		cout<<"\n0 - insertar\n1 - eliminar\n2 - Inorden\n3 - Preorden\n4 - Posorden\n5 - Niveles\n6 - salir \nSeleccione una opcion: ";
		cin>>op;
		switch(op) {
			case 0:
		        cout<<"valor: "; 
				cin>>val;
		        A.insertar(val); 
			break;
			case 1:
				cout<<"valor a eliminar: "; 
				cin>>val;
		        A.eliminar(val);
			break;
			case 2:
        		A.inorden(A.getraiz()).ImprimirCola();
				cout<<endl;
			break;
			case 3:
				A.preorden(A.getraiz()).ImprimirCola();
				cout<<endl;
			break;
			case 4:
				A.posorden(A.getraiz()).ImprimirCola();
				cout<<endl;
			break;
			case 5:
				A.niveles(A.getraiz()).ImprimirCola();
				cout<<endl;
			break;
			case 6:
        		cout<<"Gracias"<<endl;
			break;	
		}
	}
	return 0;
}
