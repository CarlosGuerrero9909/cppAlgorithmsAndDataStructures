//ALGORITMO DE ORDENAMIENTO POR SELECCION
// https://davidcapello.com/blog/cpp/medir-el-tiempo-de-una-rutina/ --->para windows
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

int main(){
	LARGE_INTEGER t_ini, t_fin;
  	double secs;
	
	int i, j, min, N;
	
	cout<<"N: ";
	cin>>N;
	int a[N];
	
	//Llenar el arreglo para el peor caso de desorden (mayor a menor)
	for(i=N-1;i>=0;i--){
		a[N-1-i]=i;
	}
	
	//Aplicacion del algoritmo de ordenamiento por seleccion al arreglo a[]
	QueryPerformanceCounter(&t_ini);
	for(i=0;i<N-1;i++){
		min=i;
		for(j=i+1;j<N;j++)
			if(a[j]<a[min])
				min=j;
		swap(a[min],a[i]);
	}
	QueryPerformanceCounter(&t_fin);
	secs = performancecounter_diff(&t_fin, &t_ini);
  	printf("%.16g milliseconds\n", secs * 1000.0);
	
	//Mostrar arreglo
	for(i=0;i<N;i++){
		cout<<a[i]<<" ";
	}
	
	return 0;
}
