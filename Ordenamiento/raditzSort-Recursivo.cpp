//ALGORITMO DE ORDENAMIENTO RADIXSORT
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

int mayor(int a[],int n){
	int max=0;
	for(int i=0;i<n;i++){
		if(max<a[i]){
			max=a[i];
		}
	}
	return max;//retorna el mayor numero del arreglo
}

void radixSort(int a[], int n, int digito){//digito es un numero en base 10
	int max=mayor(a,n);
	if(digito<max){//se ejecuta si el nuemero mayor del arreglo tiene digitos sin ser ordenados
		int aux[10][n];
		int j,i;
		for(i=0;i<10;i++){
			for(j=0;j<n;j++){
				aux[i][j]=-1;//se llena la matriz con -1
			}
		}
		for(i=0;i<n;i++){
			int p=a[i]%(digito*10);
			p/=digito;
			j=0;
			while(aux[p][j]!=-1){
				j++;
			}
			aux[p][j]=a[i];//se guarda en la matriz el numero en la fila correspondiente al digito encontrado
		}
		
		int k=0;
		cout<<endl;
		
		for(i=0;i<10;i++){
			for(j=0;aux[i][j]!=-1;j++){
				cout<<aux[i][j]<<" ";
				a[k]=aux[i][j];
				k++;
			}
		}
		cout<<endl;
		radixSort(a,n,digito*10);
			
	}
}

int main(int argc, char** argv) {
	LARGE_INTEGER t_ini, t_fin;
	double secs;
	
	int i, j, v, N;
	cout<<"Digite n: "<<endl;
	cin>>N;
	int a[N];
	//Llenar el arreglo (mayor a menor)
	for(i=N-1;i>=0;i--){
		a[N-1-i]=i;
	}
	
	
	QueryPerformanceCounter(&t_ini);
	//llamado a la funcion de ordenamiento
	radixSort(a,N,1);
	QueryPerformanceCounter(&t_fin);
	cout<<endl;
	secs = performancecounter_diff(&t_fin, &t_ini);
  	printf("%.16g milliseconds\n", secs * 1000.0);
	
	//Mostrar arreglo
	for(i=0;i<N;i++){
		cout<<a[i]<<" ";
	}

	return 0;
}