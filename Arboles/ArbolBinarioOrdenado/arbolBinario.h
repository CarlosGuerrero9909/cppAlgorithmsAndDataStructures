#include "cola.h"
#include "pila.h"
#ifndef ARBOLBINARIO_H
#define ARBOLBINARIO_H

using namespace std;

struct nodo
{
    int clave;
    int izq, der;
};

// Creacion de la clase ArbolBinario
class ArbinOrdenado
{
private:
    nodo *arbol;

public:
    ArbinOrdenado(int tam)
    {
        arbol = new nodo[tam + 1];
        for (int i = 0; i < tam + 1; i++)
        {
            arbol[i].izq = 0;
            i == tam ? arbol[i].der = 0 : arbol[i].der = i + 1; // operador ternario para inicializar el arbol
        }
    }
    ~ArbinOrdenado()
    {
        delete arbol;
    }
    bool insertar(int dato);
    bool eliminar(int dato);
    int getraiz() { return arbol[0].izq; }
    cola inorden(int inicio);
    cola preorden(int inicio);
    cola posorden(int inicio);
    cola niveles(int inicio);
};

bool ArbinOrdenado :: insertar(int dato)
{
    int pos = arbol[0].der;

    if (arbol[0].der == 0)
        return false; // arbol lleno

    if (getraiz() == 0)
    {
        arbol[0].izq = pos; // actualizar raiz
        arbol[pos].clave = dato;
        arbol[0].der = arbol[pos].der; // actualizar pos libre en cabecra
        arbol[pos].der = 0;
        arbol[pos].izq = 0;

        return true;
    }

    arbol[pos].clave = dato;
    arbol[0].der = arbol[pos].der; // actualizar pos libre en cabecra
    arbol[pos].der = 0;
    arbol[pos].izq = 0;

    int i = getraiz();

    while (true)
    {
        if (dato < arbol[i].clave)
        { // caso de tomar la izq
            if (arbol[i].izq == 0)
            {
                arbol[i].izq = pos;
                break;
            }
            i = arbol[i].izq;
        }
        else
        { // caso de tomar la der
            if (arbol[i].der == 0)
            {
                arbol[i].der = pos;
                break;
            }
            i = arbol[i].der;
        }
    }

    return true;
}

bool ArbinOrdenado :: eliminar(int dato)
{
    int actual = getraiz();
    int padre = 0;

    while (true)
    {
        if (arbol[actual].clave == dato)
            break;

        if (dato < arbol[actual].clave)
        { // caso de tomar la izq
            if (arbol[actual].izq == 0)
                return false; // no hay mas que buscar
            padre = actual;
            actual = arbol[actual].izq;
        }

        else
        { // caso de tomar la der
            if (arbol[actual].der == 0)
                return false;
            padre = actual;
            actual = arbol[actual].der;
        }
    }
	
	// caso nodo con dos hijos
    if (arbol[actual].izq != 0 && arbol[actual].der != 0)
    {
		int hijoR,padreR;
		padreR=actual;
		hijoR=arbol[padreR].der;
		while(arbol[hijoR].izq!=0){
			padreR=hijoR;
			hijoR=arbol[padreR].izq;
		}
		arbol[actual].clave = arbol[hijoR].clave;
		
		padre=padreR;
		actual=hijoR; //el hijo de reemplazo sera el actual a eliminar
    }
	
	// caso nodo con un hijo
    if (arbol[actual].izq != 0 || arbol[actual].der != 0)
    {
        if (arbol[actual].clave < arbol[padre].clave) //actual a la izq del padre
        {
            arbol[padre].izq = arbol[actual].izq == 0 ? arbol[actual].der : arbol[actual].izq; //conectando padre con nieto
        }
        else
        {
            arbol[padre].der = arbol[actual].izq == 0 ? arbol[actual].der : arbol[actual].izq; //conectando padre con nieto
        }
    }
	
	// caso nodo hoja
    if (arbol[actual].izq == 0 && arbol[actual].der == 0)
    {
        if (arbol[actual].clave < arbol[padre].clave)
        {
            arbol[padre].izq = 0;
        }
        else
        {
            arbol[padre].der = 0;
        }
    }
	
    
	
    // borrar - actulizar pos libre
    arbol[actual].clave = 0;
    arbol[actual].izq = 0;

    int i = 0;

    if (arbol[0].der == 0)
    { // arbol lleno
        arbol[0].der = actual;
        return true;
    }
    
	int sigLib;
    while (true)
    {
        sigLib = arbol[i].der;
        if (sigLib == 0)
        { // arbol lleno
            arbol[i].der = actual;
        }
        if (sigLib > actual)
        {
            arbol[actual].der = sigLib;
            arbol[i].der = actual;
            break;
        }
        i = sigLib;
    }
    
    return true;
}


cola ArbinOrdenado :: inorden(int inicio){
	/*if(arbol[inicio].izq!=0) posorden(arbol[inicio].izq);
	cout<<arbol[inicio].clave<<" ";
	if(arbol[inicio].der!=0) posorden(arbol[inicio].der);
	*/
	cola C;
	while(!C.ColaVacia()){
		C.AtenderCola();
	}
	pila P;
	while(!P.PilaVacia() || inicio!=0){
		if(inicio!=0){
			P.Push(inicio);
			inicio=arbol[inicio].izq;
		}
		else{
			inicio=P.Pop();
			C.InsCola(arbol[inicio].clave);
			inicio=arbol[inicio].der;
		}
	}
	return C;
}

cola ArbinOrdenado :: preorden(int inicio){
	cola C;
	if (inicio==0) return C;
	pila P;
	P.Push(inicio);
	while(!P.PilaVacia()){
		inicio=P.Pop();
		C.InsCola(arbol[inicio].clave);
		if(arbol[inicio].der!=0){
			P.Push(arbol[inicio].der);
		}
		if(arbol[inicio].izq!=0){
			P.Push(arbol[inicio].izq);
		}
	}
	return C;
}

cola ArbinOrdenado :: posorden(int inicio){
	int n = 0;
	cola C;
	pila P;
	while(!P.PilaVacia() || inicio!=0){
		if(inicio!=0){
			P.Push(inicio);
			inicio=arbol[inicio].izq;
		}
		else{
			int aux=P.Pop();
			P.Push(aux);
			if(arbol[aux].der!=0 && n!=arbol[aux].der){
				inicio=arbol[aux].der;
			}
			else{
				C.InsCola(arbol[aux].clave);
				n = P.Pop();
			}
		}
	}
	return C;
}

cola ArbinOrdenado :: niveles(int inicio){
	cola C;
	cola aux;
	aux.InsCola(inicio);
	while(!aux.ColaVacia()){
		inicio=aux.AtenderCola();
		C.InsCola(arbol[inicio].clave);
		if(arbol[inicio].izq!=0){
			aux.InsCola(arbol[inicio].izq);
		}
		if(arbol[inicio].der!=0){
			aux.InsCola(arbol[inicio].der);
		}
	}
	return C;
}
#endif
