#include "cola.h"
#include "pila.h"
#ifndef ARBOLROJINEGRO_H
#define ARBOLROJINEGRO_H

using namespace std;

struct nodo
{
    int clave;
    nodo *izq, *der;
    bool color; // true para rojo
};

class ArbolRojiNegro
{
private:
    nodo *raiz;

public:
    ArbolRojiNegro()
    {
        raiz = NULL;
    }
    ~ArbolRojiNegro() { delete raiz; }
    bool insertar(int dato);
    void ajustarInsercion(nodo *hijo);
    nodo *buscarPadre(int dato);
    void rotSencillaDer(nodo *padre, nodo *abuelo);
    void rotSencillaIzq(nodo *padre, nodo *abuelo);
    bool eliminar(int dato);
    nodo *buscarNodo(int dato);
    nodo *getraiz() { return raiz; }
    cola inorden(nodo *inicio);
    cola preorden(nodo *inicio);
    cola posorden(nodo *inicio);
    cola niveles(nodo *inicio);

    void inordenRecusivoPrueba(nodo *inicio);
};

void ArbolRojiNegro::inordenRecusivoPrueba(nodo *inicio)
{
    if (inicio == NULL)
    {
    }
    else
    {
        inordenRecusivoPrueba(inicio->izq);
        cout << inicio->clave;
        if (inicio->color == true)
        {
            cout << "R - ";
        }
        else
        {
            cout << "N - ";
        }
        // listInorden->InsCola(inicio->clave);
        inordenRecusivoPrueba(inicio->der);
    }
}

nodo *ArbolRojiNegro ::buscarPadre(int dato)
{
    nodo *aux = new nodo;
    nodo *p = NULL;
    aux = raiz;
    if (aux->clave == dato)
        return NULL;

    while (true)
    {
        if (dato == aux->clave)
            break;
        if (dato < aux->clave)
        {
            if (aux->izq == NULL)
            {
                return NULL;
            }
            p = aux;
            aux = aux->izq;
        }

        else
        {
            if (aux->der == NULL)
            {

                return NULL;
            }
            p = aux;
            aux = aux->der;
        }
    }
    return p;
}

// rotacion sobre el padre
void ArbolRojiNegro ::rotSencillaDer(nodo *padre, nodo *abuelo)
{
    nodo *hijo = padre->izq;
    padre->izq = hijo->der; // el hijo der del Hijo sera ahora el hijo izq del Padre
    hijo->der = padre;      // se conecta el padre con el hijo

    if (abuelo != NULL)
    {
        if (padre->clave < abuelo->clave)
        { // el Padre era hijo izq del Abuelo
            abuelo->izq = hijo;
        }
        else
        { // el Padre era hijo der del Abuelo
            abuelo->der = hijo;
        }
    }
    else
    {
        raiz = hijo;
    }
}

// rotacion sobre el padre
void ArbolRojiNegro ::rotSencillaIzq(nodo *padre, nodo *abuelo)
{
    nodo *hijo = padre->der;
    padre->der = hijo->izq; // el hijo izq del Hijo sera ahora el hijo der del Padre
    hijo->izq = padre;      // se conecta el padre con el hijo

    if (abuelo != NULL)
    {
        if (padre->clave < abuelo->clave)
        { // el Padre era hijo izq del Abuelo
            abuelo->izq = hijo;
        }
        else
        { // el Padre era hijo der del Abuelo
            abuelo->der = hijo;
        }
    }
    else
    {
        raiz = hijo;
    }
}

void ArbolRojiNegro ::ajustarInsercion(nodo *hijo)
{
    nodo *padre, *tio, *abuelo;
    padre = buscarPadre(hijo->clave);
    abuelo = buscarPadre(padre->clave);

    // direcciones del hijo y el tio false=izq y true=der
    bool dirHijo = false;
    bool dirTio = false;

    if ((hijo->color == padre->color) && (padre->color == true))
    {
        // hallar direcciones del hijo
        if (hijo->clave < padre->clave)
        {
            dirHijo = false;
        }
        else
        {
            dirHijo = true;
        }

        // hallar al tio y direccion del tio, Siempre va a haber un tio, asi sea NULL
        if (abuelo->izq == padre)
        {
            tio = abuelo->der;
            dirTio = true;
        }
        else
        {
            tio = abuelo->izq;
            dirTio = false;
        }
        // revision del caso 1
        if ((padre->color == true) && (tio != NULL) && (tio->color == true))
        {
            // se cambia el color del abuelo
            if (abuelo == raiz)
            {
                abuelo->color = false;
            }
            else
            {
                abuelo->color = !(abuelo->color);
            }
            // se cambia el color del padre y el tio
            padre->color = false;
            tio->color = false;
        }
        // revision de caso 2 y 3
        else if ((tio == NULL) || (tio->color == false))
        {
            // revision caso 2 izq
            if ((dirHijo == dirTio) && (dirTio == false))
            {
                rotSencillaDer(padre, abuelo); // se deja en caso tres
                hijo = padre;
                padre = buscarPadre(hijo->clave);
            }
            // revision caso 2 der
            else if ((dirHijo == dirTio) && (dirTio == true))
            {
                rotSencillaIzq(padre, abuelo); // se deja en caso tres
                hijo = padre;
                padre = buscarPadre(hijo->clave);
            }
            // revision caso 3 (ya traen direcciones diferentes el tio y el hijo)
            if (dirTio == true)
            {
                padre->color = !(padre->color);
                abuelo->color = !(abuelo->color);
                rotSencillaDer(abuelo, buscarPadre(abuelo->clave));
            }
            // revision caso 3 izq
            else if (dirTio == false)
            {
                padre->color = !(padre->color);
                abuelo->color = !(abuelo->color);
                rotSencillaIzq(abuelo, buscarPadre(abuelo->clave));
            }
        }
        raiz->color = false;
    }
    if ((buscarPadre(hijo->clave) != raiz))
    {
        ajustarInsercion(buscarPadre(hijo->clave));
    }
}

bool ArbolRojiNegro ::insertar(int dato)
{
    nodo *nuevoNodo = new nodo, *aux;
    nuevoNodo->clave = dato;
    nuevoNodo->color = true;
    nuevoNodo->izq = NULL;
    nuevoNodo->der = NULL;

    if (raiz == NULL)
    {
        nuevoNodo->color = false;
        raiz = nuevoNodo;
        return true;
    }
    else
    { // ya habra un arbol binario corformado
        aux = raiz;
        // se recorren los nodos del arbol binario hasta llegar al lugar de insercion
        while (true)
        {
            if (dato < aux->clave)
            {
                if (aux->izq == NULL)
                {
                    aux->izq = nuevoNodo;
                    ajustarInsercion(nuevoNodo);
                    return true;
                }
                aux = aux->izq;
            }
            else
            {
                if (aux->der == NULL)
                {
                    aux->der = nuevoNodo;
                    ajustarInsercion(nuevoNodo);
                    return true;
                }
                aux = aux->der;
            }
        }
    }
}

cola ArbolRojiNegro ::inorden(nodo *inicio)
{
    cola C;
    while (!C.ColaVacia())
    {
        C.AtenderCola();
    }
    pila P;
    while (!P.PilaVacia() || inicio != NULL)
    {
        if (inicio != NULL)
        {
            P.Push(inicio->clave);
            inicio = inicio->izq;
        }
        else
        {
            inicio = buscarNodo(P.Pop());
            C.InsCola(inicio->clave);
            inicio = inicio->der;
        }
    }
    return C;
}

cola ArbolRojiNegro ::preorden(nodo *inicio)
{
    cola C;
    if (inicio == NULL)
        return C;
    pila P;
    P.Push(inicio->clave);
    while (!P.PilaVacia())
    {
        inicio = buscarNodo(P.Pop());
        C.InsCola(inicio->clave);
        if (inicio->der != NULL)
        {
            P.Push(inicio->der->clave);
        }
        if (inicio->izq != NULL)
        {
            P.Push(inicio->izq->clave);
        }
    }
    return C;
}

nodo *ArbolRojiNegro ::buscarNodo(int dato)
{
    nodo *aux = new nodo;
    aux = raiz;
    while (true)
    {
        if (dato == aux->clave)
            break;
        if (dato < aux->clave)
        {
            if (aux->izq == NULL)
            {
                return NULL;
            }
            aux = aux->izq;
        }
        else
        {
            if (aux->der == NULL)
            {

                return NULL;
            }
            aux = aux->der;
        }
    }
    return aux;
}

cola ArbolRojiNegro ::posorden(nodo *inicio)
{
    int n = 0;
    cola C;
    pila P;
    while (!P.PilaVacia() || inicio != NULL)
    {
        if (inicio != NULL)
        {
            P.Push(inicio->clave);
            inicio = inicio->izq;
        }
        else
        {
            nodo *aux = buscarNodo(P.Pop());
            P.Push(aux->clave);
            if (aux->der != NULL && buscarNodo(n) != aux->der)
            {
                inicio = aux->der;
            }
            else
            {
                C.InsCola(aux->clave);
                n = P.Pop();
            }
        }
    }
    return C;
}

cola ArbolRojiNegro ::niveles(nodo *inicio)
{
    cola C;
    cola aux;
    aux.InsCola(inicio->clave);
    while (!aux.ColaVacia())
    {
        inicio = buscarNodo(aux.AtenderCola());
        C.InsCola(inicio->clave);
        if (inicio->izq != NULL)
        {
            aux.InsCola(inicio->izq->clave);
        }
        if (inicio->der != NULL)
        {
            aux.InsCola(inicio->der->clave);
        }
    }
    return C;
}

bool ArbolRojiNegro ::eliminar(int dato)
{
    nodo *actual = new nodo;
    nodo *padre = new nodo;
    actual = raiz;

    while (true)
    {
        if (actual->clave == dato)
            break;

        if (dato < actual->clave)
        { // caso toma por la izq
            if (actual->izq == NULL)
                return false; // no hay mas que buscar
            padre = actual;
            actual = actual->izq;
        }

        else
        { // caso de tomar la der
            if (actual->der == NULL)
                return false;
            padre = actual;
            actual = actual->der;
        }
    }

    if (actual->clave == raiz->clave)
    { // se quiere eliminar la raiz
        if (raiz->izq != NULL || raiz->der != NULL)
        { // raiz solo con 1 hijo
            raiz->clave = actual->izq == NULL ? actual->der->clave : actual->izq->clave;
            actual->clave = actual->izq == NULL ? actual->der->clave : actual->izq->clave;
            padre = actual;
            actual = actual->izq == NULL ? actual->der : actual->izq;
            actual->clave = -1;
        }
        else if (raiz->izq == NULL && raiz->der == NULL)
            raiz = NULL; // raiz sin hijos
    }

    // caso nodo con dos hijos
    if (actual->izq != NULL && actual->der != NULL)
    {
        nodo *hijoR, *padreR;
        padreR = actual;
        hijoR = padreR->der;
        while (hijoR->izq != NULL)
        {
            padreR = hijoR;
            hijoR = padreR->izq;
        }
        if (actual->clave == raiz->clave)
        { // caso en que se deba actualizar la raiz
            raiz->clave = hijoR->clave;
        }
        actual->clave = hijoR->clave;
        padre = padreR;
        actual = hijoR; // el hijo de reemplazo sera el actual a eliminar
    }

    // caso nodo con un hijo
    if (actual->izq != NULL || actual->der != NULL)
    {
        if (actual->clave < padre->clave)                                 // actual a la izq del padre
            padre->izq = actual->izq == NULL ? actual->der : actual->izq; // conectando padre con nieto

        else
            padre->der = actual->izq == NULL ? actual->der : actual->izq; // conectando padre con nieto
    }

    // caso nodo hoja
    if (actual->izq == NULL && actual->der == NULL)
    {
        if (actual->clave < padre->clave)
            padre->izq = NULL;
        else
            padre->der = NULL;
    }

    actual->clave = -1;
    nodo *w = new nodo;
    nodo *p = new nodo;
    nodo *x = actual;
    // implementacion de algoritmo visto en clase
    while (x->clave != raiz->clave && !x->color)
    {
        cout<<"??"<<endl;
        p = buscarPadre(x->clave);
        cout<<"!!!"<<endl;
        if (p->izq->clave == x->clave)
        {
            w = p->der;
            if (w != NULL && w->color)
            {
                cout<<"---"<<endl;
                w->color = false;
                p->color = true;
                rotSencillaIzq(p, buscarPadre(p->clave));
                w = p->der;
                
            }
            if (w->izq == NULL || !w->izq && w->der == NULL || !w->der)
            {
                w->color = true;
                x = p;
            }
            else
            {
                if (w->der == NULL || !w->der->color)
                {
                    w->izq->color = false;
                    w->color = true;
                    rotSencillaDer(w, buscarPadre(w->clave));
                    w = p->der;
                }
                w->color = p->color;
                p->color = false;
                w->der->color = false;
                rotSencillaIzq(p, buscarPadre(p->clave));
                x = raiz;
            }
        }
        else
        {
            w = p->izq;
            if (w != NULL && w->color)
            {
                w->color = false;
                p->color = true;
                rotSencillaDer(p, buscarPadre(p->clave));
                w = p->izq;
            }
            if (w->der == NULL || !w->der && w->izq == NULL || !w->izq)
            {
                w->color = true;
                x = p;
            }
            else
            {
                if (w->izq == NULL || !w->izq->color)
                {
                    w->der->color = false;
                    w->color = true;
                    rotSencillaIzq(w, buscarPadre(w->clave));
                    w = p->izq;
                }
                w->color = p->color;
                p->color = false;
                w->izq->color = false;
                rotSencillaDer(p, buscarPadre(p->clave));
                x = raiz;
            }
        }
    }
    x->color = false;

    return true;
}

#endif
