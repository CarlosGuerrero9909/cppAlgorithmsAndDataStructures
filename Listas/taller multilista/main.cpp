#include <iostream>
#include "Multilista.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	Multilista m;
	string nom, carr, act;
	int edad, pos, op=0;
	
	while(op!=9){
		cout<<"\n-----------------------------"<<endl;
		cout<<"MENU COLA DOBLE"<<endl;
		cout<<"-------------------------------"<<endl;
		cout<<"\n0 - buscar estudiante por nombre\n1 - anadir estudiante \n2 - eliminar estudiante\n3 - multilista llena\n4 - multilista vacia\n"<<
		"5 - lista ordenada nombres(alf)\n6 - lista por carreras\n7 - lista por actividad\n8 - lista ordenada edad (>a<)\n9 - Salir\nDigite la opcion deseada: ";
		cin>>op;
		
		switch(op) {
      case 0:
        cout<<"nombre: "; cin>>nom;
        m.buscarNombre(nom)?cout<<""<<endl:cout<<"No encontrado"<<endl; //operador condicional
        break;
			case 1:
				cout<<"nombre: "; cin>>nom;
				cout<<"carrera (sistemas, electrica, industrial, catastral): "; cin>>carr;
				cout<<"actividad (danza, basquet, natacion, beisbol): "; cin>>act;
				cout<<"edad: "; cin>>edad;
				m.insertar(nom,act,carr,edad)?cout<<""<<endl:cout<<"false"<<endl; //operador condicional ternario
				break;
			case 2:
        m.obtenerMultilista();
				cout<<"pos a eliminar: "; cin>>pos;
				m.eliminar(pos)?cout<<"true"<<endl:cout<<"false"<<endl; //operador condicional ternario
				break;
			case 3:
				m.multilistaLLena()?cout<<"true"<<endl:cout<<"false"<<endl; //operador condicional ternario
				break;
			case 4:
				m.multilistaVacia()?cout<<"true"<<endl:cout<<"false"<<endl; //operador condicional ternario
				break;
			case 5:
				m.obtenerNombres();
				break;
			case 6:
        		cout<<"carrera que desea obtener: "; cin>>carr;
				m.obtenerCarreras(carr);
				break;
			case 7:
				cout<<"actividad que desea obtener: "; cin>>act;
				m.obtenerActividades(act);
				break;
			case 8:
				m.obtenerEdades();
				break;
			case 9:
				cout<<"Gracias"<<endl;
				break;
		}
	}
	
	return 0;
}

