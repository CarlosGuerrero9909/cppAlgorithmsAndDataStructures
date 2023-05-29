/*Algoritmo de las N reinas*/
/*https://www.youtube.com/watch?v=NVfKm-e8Quo*/
#include <iostream>
#include<stdio.h>
#include<math.h>
#include <fstream>
#include <windows.h>
#include <conio.h>

using namespace std;
int nSol=0;

/* retorna "a - b" en segundos */
double performancecounter_diff(LARGE_INTEGER *a, LARGE_INTEGER *b){
  LARGE_INTEGER freq;
  QueryPerformanceFrequency(&freq);
  return (double)(a->QuadPart - b->QuadPart) / (double)freq.QuadPart;
}

//Aca comprobamos si la reina esta colocado en una posicion valida
//para que la posicion sea valida las reinas no deben en la misma columna
//y tampoco pueden estar en la misma fila, ni diagonal
bool comprobar(int reinas[],int n, int k){
	int i;
	for(i=0;i<k;i++){
		if( (reinas[i]==reinas[k]) or (abs(k-i) == abs(reinas[k]-reinas[i]))){
			return false;
		}
	}
	return true;
}
	
void Nreinas(int reinas[],int n, int k){
	//este es el caso base que me indica que se ha encontrado una solucion
	//por lo cual ya no hay mas reinas por colocar.Hemos logrado poner
	//todas las reinas en el tablero deajerdrez
	if(k==n){
		//print(reinas,n);
		nSol++;
		/*cout<<"primera solucion encontrada: ";
		for(int i=0;i<n;i++){
			cout<<reinas[i]<<" , ";
		}
		cout<<endl;*/
		
	}
	//aun quedan reinas por colocar y el algoritmo debe seguir buscando
	else{
		for(reinas[k]=0;reinas[k]<n;reinas[k]++){
			if(comprobar(reinas,n,k)){
				Nreinas(reinas,n,k+1);
			}
		}
	}
}
		
int main(int argc, char *argv[]) {
	LARGE_INTEGER t_ini, t_fin;
	double secs;
	
	ofstream archivo;
    archivo.open("nReinas.txt", ios::out | ios::app);
	archivo<<"N"<<","<<"Tiempo(s)"<<"\n";
	
	int k=0;
  	int N=0;
  	
  	
  	
  	cout<<"N"<<","<<"nSol"<<","<<"Tiempo (s)"<<endl;
	while(true){
		nSol=0;
		N++;
		int *reinas = new int[N];
	
		for(int i=0;i<N;i++){
			reinas[i]=-1;
		}
		
		QueryPerformanceCounter(&t_ini);
		Nreinas(reinas,N,k);
		QueryPerformanceCounter(&t_fin);
		secs = performancecounter_diff(&t_fin, &t_ini);
		printf("%d,%d,%.16g \n", N, nSol, secs);
		archivo<<N<<","<<nSol<<","<<secs<<"\n";
		delete []reinas;
	}
	
	system("pause");
}
