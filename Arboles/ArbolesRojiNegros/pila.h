#ifndef PILA1_H
#define PILA1_H

struct nodoPila
{
	int dato;
	nodoPila *sig;
};

class pila
{
	nodoPila *cab;

public:
	pila()
	{
		cab = new nodoPila;
		cab->dato = ' ';
		cab->sig = NULL;
	}
	void Push(int v);
	int Pop();
	bool PilaVacia();
	~pila();
};

void pila::Push(int v)
{
	nodoPila *t = new nodoPila;
	t->dato = v;
	t->sig = cab->sig;
	cab->sig = t;
}

int pila::Pop()
{
	int x;
	nodoPila *t = cab->sig;
	cab->sig = t->sig;
	x = t->dato;
	delete t;
	return x;
}

bool pila::PilaVacia()
{
	return cab->sig == NULL;
}

pila::~pila()
{
	nodoPila *t = cab;
	while (t != NULL)
	{
		cab = t;
		t = t->sig;
		delete cab;
	}
}

#endif
