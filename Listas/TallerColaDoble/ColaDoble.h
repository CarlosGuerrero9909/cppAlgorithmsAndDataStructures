#ifndef COLADOBLE_H
#define COLADOBLE_H

using namespace std;

//Estructura para el manejo de la lista por nodos
template <class T>//Plantilla
struct nodo {
	T info;
	nodo<T> *sigD;//apuntador desde derecha y hacia nodo de la izquierda
	nodo<T> *sigI;//apuntador desde izquierda y hacia nodo de la derecha
};

//Creación de la clase Lista
template <class T>
class ColaDoble{
	private:
		//Atributos de la ColaDoble 
		nodo<T> *finDer, *finIzq; //apuntadores a nodos de los extremos
		int tam;
	
	public:
		//Metodo Constructor (inicializacion de los atributos de la ColaDoble)
		ColaDoble(){
			tam=0;
			finDer=NULL;
			finIzq=NULL;
		}
		//Metodos (acciones) de la lista
		bool colaVacia();
		int tamCola();
		void inqueue(T inf, char lado);
		bool dequeue(char lado);
		bool imprimirCola(char lado);
		
};

template <class T>
bool ColaDoble<T> :: colaVacia(){
	return tam==0; //Retorna false o true 
}

template <class T>
int ColaDoble<T> :: tamCola(){
	return tam;
}

template <class T>
void ColaDoble<T> :: inqueue(T inf, char lado){
	
	nodo<T> *p = new nodo<T>;
	p->info=inf;
	p->sigD=NULL;
	p->sigI=NULL;	
	
	if(colaVacia()) { //cola vacia
		finDer=p;
		finIzq=p;
	} else{ //Ya hay una cola conformada
		if(lado=='I'){
			p->sigD=finIzq;
			finIzq->sigI=p;
			finIzq=p;
		}
		
		if(lado=='D'){
			p->sigI=finDer;
			finDer->sigD=p;
			finDer=p;
		}	
	}
	tam++;
	
}

template <class T>
bool ColaDoble<T> :: dequeue(char lado){
	
	if(colaVacia()) return false; //cola vacia, no hay nada que eliminar
	
	if(tam==1){
		finIzq=NULL;
		finDer=NULL;
		tam--;
		return true;
	}
	
	if(lado=='I'){
		finDer=finDer->sigI;
		delete finDer->sigD;
		finDer->sigD=NULL;
	}
		
	if(lado=='D'){
		finIzq=finIzq->sigD;
		delete finIzq->sigI;
		finIzq->sigI=NULL;
	}
	tam--;
	return true;	
}

template <class T>
bool ColaDoble<T> :: imprimirCola(char lado){
	
	if(colaVacia()) return false; //cola vacia, no hay nada que eliminar
	
	if(lado=='I'){
		nodo<T> *aux=finDer;
		while(aux != NULL){
			cout<<aux->info<<" ";
			aux=aux->sigI;
		}
		cout<<endl;
	}
		
	if(lado=='D'){
		nodo<T> *aux=finIzq;
		while(aux != NULL){
			cout<<aux->info<<" ";
			aux=aux->sigD;
		}
		cout<<endl;
	}
	
	return true;
}
#endif
