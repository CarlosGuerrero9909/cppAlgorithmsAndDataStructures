//ALGORITMO DE ORDENAMIENTO QUICKSORT
#include<iostream>
#include <stdio.h>
#include <windows.h>

using namespace std;

/* retorna "a - b" en segundos */
double performancecounter_diff(LARGE_INTEGER *a, LARGE_INTEGER *b)
{
  LARGE_INTEGER freq;
  QueryPerformanceFrequency(&freq);
  return (double)(a->QuadPart - b->QuadPart) / (double)freq.QuadPart;
}

void ordenrapido(int a[], int izq, int der)
	{
		int i, j, v;
		if (der> izq)
		{
			v= a[der]; i = izq -1; j= der;
			for(;;)
			{
				while (a[++i]<v);
				while (a[--j]>v);
				if(i>=j) break;
				swap(a[i],a[j]);
			}
			swap(a[i],a[der]);
			ordenrapido(a, izq, i-1);
			ordenrapido(a, i+1,der);
		}
	}

int main(){
	LARGE_INTEGER t_ini, t_fin;
  	double secs;
	
	int i, j, v, N;
	
	cout<<"N: ";
	cin>>N;
	int a[N];
	
	//Llenar el arreglo (mayor a menor)
	for(i=N-1;i>=0;i--){
		a[N-1-i]=i;
	}
	
	
	QueryPerformanceCounter(&t_ini);
	
	ordenrapido(a,0,N-1); // llamado de la funcion de ordenamiento
	
	QueryPerformanceCounter(&t_fin);
	secs = performancecounter_diff(&t_fin, &t_ini);
  	printf("%.16g milliseconds\n", secs * 1000.0);
	
	//Mostrar arreglo
	for(i=0;i<N;i++){
		cout<<a[i]<<" ";
	}
	
	return 0;
}
