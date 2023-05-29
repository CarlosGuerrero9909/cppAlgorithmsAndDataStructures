#ifndef LISTA_H
#define LISTA_H

using namespace std;

//Creaci?n de la clase Pila
template <class T>
class Pila{
	private:
		//Atributos de la Pila
		T *pila;
		int p;
	
	public:
		//Metodo Constructor (inicializacion de los atributos de la Pila)
		Pila(int max=100){
			pila = new T[max];
			p=0;
		}
		
		//Metodo Destructor (inicializacion de los atributos de la Pila)
		~Pila(){
			delete pila;
		}
		
		//Metodos (acciones) de la Pila
		inline void meter(T v){
			pila[p++]=v;
		}
		inline T sacar(){
			return pila[--p];
		}
		inline int vacia(){
			return !p;
		}
};
#endif

