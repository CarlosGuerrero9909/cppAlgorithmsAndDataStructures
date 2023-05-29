#include <iostream>
#include "Lista.h"
using namespace std;

struct estudiante {
	int cod;
	string nombre;
	double telefono;
};

int main(int argc, char** argv) {
	
	int op,x,y,op2; 
	double x1; 
	char x2;
	estudiante e;
		
	Lista<int> enteros;
	Lista<float> flotantes;
	Lista<char> caracteres;
	Lista<estudiante> estudiantes;
		
	while(op!=5){
		cout<<"MENU LISTA PROPIA"<<endl;
		cout<<"1 - int \n2 - float\n3 - char\n4 - estudiante\n5 - Salir\nDigite la opcion deseada: ";
		cin>>op;
		op2=0;
		while(op2!=7){
			if(op!=5){
				cout<<"\n1 - lista vacia \n2 - tamaño lista\n3 - insertar final\n4 - eliminar pos\n5 - insertar pos\n6 - imprimir lista\n7 - volver\nDigite la opcion deseada: ";
				cin>>op2;
			}
			switch(op){
				case 1:	
					switch(op2){
						case 1:
							enteros.listaVacia()?cout<<"true"<<endl:cout<<"false"<<endl; //operador condicional ternario
							break;
						case 2:
							cout<<enteros.tamLista()<<endl;
							break;
						case 3:
							cout<<"x: "; 
							cin>>x;
							enteros.insertarFinal(x);
							break;
						case 4:
							cout<<"pos: "; 
							cin>>y;
							enteros.eliminar(y);
							break;
						case 5:
							cout<<"x: "; 
							cin>>x;
							cout<<"pos: "; 
							cin>>y;
							enteros.insertarPos(x,y); 
							break;
						case 6:
							enteros.mostrarLista();
							break;
					}
					break;
				case 2:
					switch(op2){
						case 1:
							flotantes.listaVacia()?cout<<"true"<<endl:cout<<"false"<<endl; //operador condicional ternario
							break;
						case 2:
							cout<<flotantes.tamLista()<<endl;
							break;
						case 3:
							cout<<"x: "; 
							cin>>x1;
							flotantes.insertarFinal(x1);
							break;
						case 4:
							cout<<"pos: "; 
							cin>>y;
							flotantes.eliminar(y);
							break;
						case 5:
							cout<<"x: "; 
							cin>>x1;
							cout<<"pos: "; 
							cin>>y;
							flotantes.insertarPos(x1,y); 
							break;
						case 6:
							flotantes.mostrarLista();
							break;
					}
					break;
				case 3:
					switch(op2){
						case 1:
							caracteres.listaVacia()?cout<<"true"<<endl:cout<<"false"<<endl; //operador condicional ternario
							break;
						case 2:
							cout<<caracteres.tamLista()<<endl;
							break;
						case 3:
							cout<<"x: "; 
							cin>>x2;
							caracteres.insertarFinal(x2);
							break;
						case 4:
							cout<<"pos: "; 
							cin>>y;
							caracteres.eliminar(y);
							break;
						case 5:
							cout<<"x: "; 
							cin>>x2;
							cout<<"pos: "; 
							cin>>y;
							caracteres.insertarPos(x2,y); 
							break;
						case 6:
							caracteres.mostrarLista();
							break;
					}
					break;
				case 4:
					switch(op2){
						case 1:
							estudiantes.listaVacia()?cout<<"true"<<endl:cout<<"false"<<endl; //operador condicional ternario
							break;
						case 2:
							cout<<estudiantes.tamLista()<<endl;
							break;
						case 3:
							cout<<"codigo: "; 
							cin>>e.cod; 
							cout<<"nombre: "; 
							cin>>e.nombre; 
							cout<<"telefono: "; 
							cin>>e.telefono; 
							
							estudiantes.insertarFinal(e);
							break;
						case 4:
							cout<<"pos: "<<endl;
							cin>>y;
							estudiantes.eliminar(y);
							break;
						case 5:
							cout<<"codigo: "; 
							cin>>e.cod; 
							cout<<"nombre: "; 
							cin>>e.nombre; 
							cout<<"telefono: "; 
							cin>>e.telefono;
							
							cout<<"pos: "; 
							cin>>y;
							estudiantes.insertarPos(e,y); 
							break;
						case 6:
							estudiantes.mostrarListaEstudiantes();
							break;
					}
					break;
				case 5:
					cout<<"Gracias"<<endl;
					op2=7;
					break;
				default:
					cout<<"Ingrese una opcion que este en el menu"<<endl;
					break;
			
			}
		}
	}
	return 0;
}
