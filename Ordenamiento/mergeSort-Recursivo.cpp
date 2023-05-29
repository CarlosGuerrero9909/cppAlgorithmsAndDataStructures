#include<iostream>
#include <windows.h>

using namespace std;

/* retorna "a - b" en segundos */
double performancecounter_diff(LARGE_INTEGER *a, LARGE_INTEGER *b)
{
  LARGE_INTEGER freq;
  QueryPerformanceFrequency(&freq);
  return (double)(a->QuadPart - b->QuadPart) / (double)freq.QuadPart;
}

void mergeList(int a[], int start1, int end1, int start2, int end2, int N){
	//supone que los elementos de A y B son contiguos en la lista
	int finalStart=start1;
	int finalEnd=end2;
	int indexC=1;
	int result[N];
	
	while((start1<=end1) && (start2<=end2)){
		if(a[start1]<a[start2]){
			result[indexC]=a[start1];
			start1=start1+1;
		}else{
			result[indexC]=a[start2];
			start2=start2+1;
		}
		indexC=indexC+1;
	}
	
	//mover la parte de la lista que sobra
	if(start1<=end1){
		for(int i=start1; i<=end1; i++){
			result[indexC]=a[i];
			indexC=indexC+1;
		}
	}else{
		for(int i=start2; i<=end2; i++){
			result[indexC]=a[i];
			indexC=indexC+1;
		}
	}
	
	//ahora vuelve a poner el resultado en la lista
	indexC=1;
	for(int i=finalStart; i<=finalEnd; i++){
		a[i]=result[indexC];
		indexC=indexC+1;
	}
}

void mergeSort(int a[], int first, int last, int N){
	int middle;
	
	if(first<last){
		middle=(first+last)/2;
		mergeSort(a, first, middle, N);
		mergeSort(a, middle+1, last, N);
		mergeList(a, first, middle, middle+1, last, N);
	}
	
}

int main(){
	LARGE_INTEGER t_ini, t_fin;
  	double secs;
  	
  	int i, N;
  	cout<<"N: ";
	cin>>N;
	int a[N];
	
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
  	mergeSort(a, 0, N-1, N);
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

