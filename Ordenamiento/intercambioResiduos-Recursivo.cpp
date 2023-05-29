/*ALGORITMO DE ORDENAMIENTO POR INTERCAMBIO DE RESIDUOS*/
#include <iostream>
#include <windows.h>

using namespace std;

/* retorna "a - b" en segundos */
double performancecounter_diff(LARGE_INTEGER *a, LARGE_INTEGER *b)
{
  LARGE_INTEGER freq;
  QueryPerformanceFrequency(&freq);
  return (double)(a->QuadPart - b->QuadPart) / (double)freq.QuadPart;
}

class clavebits{
	private: 
		int x;
	public:
		clavebits& operator=(int i)
			{x=i; return *this; }
		inline unsigned bits (int k, int j)
			{return (x>>k)&~(~0<<j);}
};

typedef clavebits tipoElemento;//Asigna un nombre alternativo (tipoElemento) a tipos existentes (clavebits)

void cambioresiduos(tipoElemento a[], int izq, int der, int b){ 
	int i,j; /*int t;*/
	if (der>izq && b>0){
		i= izq; j=der;
		while(j!=i){
			while(!a[i].bits(b,1) && i<j)i++;
			while( a[j].bits(b,1) && j>i)j--;
			swap(a[i], a[j]);//intercambio(a, i, j);
		}
		if (!a[i].bits(b,1)) j++;
		cambioresiduos(a, izq, j-1, b-1);
		cambioresiduos(a, j, der, b-1);
	}
}

int main(){
	LARGE_INTEGER t_ini, t_fin;
  	double secs;
  	
  	int i, N;
  	cout<<"N: ";
	cin>>N;
	tipoElemento a[N];
	
	
	
	//Llenar el arreglo para el peor caso de desorden (mayor a menor)
	for(i=N-1;i>=0;i--){
		a[N-1-i]=i;
	}
	//Mostrar arreglo Antes de ordenar
  	for(i=0;i<N;i++){
		printf("%d ", a[i]);
	}
  	
  	QueryPerformanceCounter(&t_ini);
  	//
  	cambioresiduos(a,0,N-1,10);
  	//
  	QueryPerformanceCounter(&t_fin);
	secs = performancecounter_diff(&t_fin, &t_ini);
  	printf("\n\nTiempo: %.16g milliseconds\n", secs * 1000.0);
  	
  	//Mostrar arreglo Despues de ordenar
  	cout<<endl;
	for(i=0;i<N;i++){
		printf("%d ", a[i]);
	}
  	
  	return 0;
}
