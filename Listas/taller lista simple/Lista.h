#ifndef LISTA_H
#define LISTA_H

using namespace std;

//Estructura para el manejo de la lista por nodos
template <class T>//Plantilla
struct nodo {
	T info;
	nodo<T> *sig;
};

//Creación de la clase Lista
template <class T>
class Lista{
	private:
		//Atributos de la lista 
		nodo<T> *cab;
		int tam;
	
	public:
		//Metodo Constructor (inicializacion de los atributos de la Lista)
		Lista(){
			cab=NULL;
			tam=0;
		}
		//Metodos (acciones) de la lista
		bool listaVacia();
		int tamLista();
		void insertarFinal(T inf);
		bool eliminar(int pos);
		void insertarPos(T inf, int pos);
		void mostrarLista();
		void mostrarListaEstudiantes();
};

//(::)Operador de resolución de alcance, utilizado en este caso para referirnos desde fuera de la clase Lista
//a los metodos pertenecientes a dicha clase (Definicion de metodos por fuera de la clase a la que pertenecen)
template <class T>
bool Lista<T> :: listaVacia(){
	return tam==0; //Retorna false o true 
}

template <class T>
int Lista<T> :: tamLista(){
	return tam;
}

template <class T>
void Lista<T> :: insertarFinal(T inf){
	nodo<T> *p = new nodo<T>,*aux;
	p->info=inf;
	p->sig=NULL;
	
	if(cab==NULL) { //No hay cabecera de la lista
		cab=p;
	} else{ //Ya hay una lista conformada
		aux=cab; 
		while (aux->sig!=NULL) //Se recorren los nodos de la lista hasta el nodo final
			aux=aux->sig;
		aux->sig=p; //Se enlaza el ultimo nodo de la lista con el nuevo nodo (nuevo ultimo nodo)
	}
	tam++;
}

template <class T>
bool Lista<T> :: eliminar(int pos){
	if(listaVacia()) //Lista vacia, no hay nada que eliminar
		return false;
	
	nodo<T> *aux=cab, *aux2;
	
	if(pos==1) { //Caso en el que se elimine la cabeza de la lista
		cab=cab->sig;
		delete aux;
	} else { //Cualquier otro nodo de la lista
		
		
		if(pos>tam) //Caso en el que la posicion a eliminar exceda el tam de la lista (Se elimina el ultimo)
			pos=tam;
			
		for(int i=1;i<pos-1;i++) //Se recorren los nodos de la lista hasta el nodo anterior a la pos a eliminar
			aux=aux->sig;
		
		aux2=aux->sig; //aux2 apunta al nodo en la pos que se quiere eliminar
		aux->sig=aux2->sig; //Se enlaza el nodo anterior a pos con el nodo siguiente a pos, para eliminar el nodo en pos
		
		delete aux2;
	}
	tam--;
	return true;
}

template <class T>
void Lista<T> :: insertarPos(T inf, int pos){
	if(pos>tam) //Caso en el que la posicion a insertar exceda el tam de la lista (Se inserta de ultimo)
		insertarFinal(inf);
		
	else{
		nodo<T> *p = new nodo<T>,*aux = cab;
		p->info=inf;
		
		if(pos==1){ //Caso en el que la posicion es 1 (Se debe cambiar la cabeza)
			p->sig=cab;
			cab=p;
		} else{ //Cualquier otra pos de la lista
			for(int i=1;i<pos-1;i++) //Se recorren los nodos de la lista hasta el nodo anterior a la pos a insertar
				aux=aux->sig;
				
			p->sig=aux->sig;
			aux->sig=p;
		}
		tam++;
	}
}

template <class T>
void Lista<T> :: mostrarLista(){
	nodo<T> *aux=cab;
	while(aux != NULL){
		cout<<aux->info<<" ";
		aux=aux->sig;
	}
	cout<<endl;
}

template <class T>
void Lista<T> :: mostrarListaEstudiantes(){
	nodo<T> *aux=cab;
	while(aux != NULL){
		cout<<"["<<aux->info.cod<<" "<<aux->info.nombre<<" "<<aux->info.telefono<<"] ";
		aux=aux->sig;
	}
	cout<<endl;
}
#endif
