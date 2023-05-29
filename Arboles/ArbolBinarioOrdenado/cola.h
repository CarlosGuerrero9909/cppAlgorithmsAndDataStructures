#include <cstdlib>
#include <iostream>

#ifndef COLA1_H     
#define COLA1_H 

using namespace std;

struct nodoCola{
	int dato;
    nodoCola *sig;
};

class cola{
	nodoCola *cab,*fin;
	public: cola(){cab=fin=NULL;}
	void InsCola(int i);
	int AtenderCola();
	void ImprimirCola();
	bool ColaVacia();
	~cola();
};

void cola::InsCola(int i){
	nodoCola *nuevo;
	nuevo= new nodoCola;
	nuevo->dato=i;
	nuevo->sig= NULL;
	if (cab==NULL){
		cab=nuevo;	
	} 
	else {fin->sig = nuevo;}
	fin=nuevo;
}

int cola::AtenderCola()
{   int x;
    nodoCola *aux = cab; 
    cab=aux->sig;
    x=aux->dato;
    delete aux;
    return x;
}

void cola::ImprimirCola(){
	nodoCola *aux;
	aux=cab;
	while(aux!=NULL){
	cout<<aux->dato<<" ";
	aux=aux->sig;}    
}

bool cola::ColaVacia(){
	return (cab==NULL);
}

cola::~cola(){
	nodoCola *aux;
	while(cab!=NULL)
	{aux= cab;
	cab=aux->sig;
	delete aux;}
	delete cab;
}

#endif

