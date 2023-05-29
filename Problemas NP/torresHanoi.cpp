#include<iostream>
#include <stdio.h>
#include <windows.h>
#include <fstream>

using namespace std;

/* retorna "a - b" en segundos */
double performancecounter_diff(LARGE_INTEGER *a, LARGE_INTEGER *b)
{
  LARGE_INTEGER freq;
  QueryPerformanceFrequency(&freq);
  return (double)(a->QuadPart - b->QuadPart) / (double)freq.QuadPart;
}

void hanoi(int num,char A,char C,char B)
{
    if(num==1)
    {
        //cout<<"Mueva el bloque "<<num<<" desde "<<A<<" hasta  "<<C<<endl;
             
    }
    else
    {
        hanoi(num-1,A,B,C);
        //cout<<"Mueva el bloque "<<num<<" desde "<<A<<" hasta  "<<C<<endl;
        hanoi(num-1,B,C,A);
    }
}
 
int main()
{	
	LARGE_INTEGER t_ini, t_fin;
	double secs;
    int n=1;
    char A,B,C;
	
    //cout<<"Los clavijas son A B C\n";
    //cout<<"Numero de discos: ";
    //cin>>n;
    
    fstream fout;
    fout.open("Hanoi.csv", ios::out | ios::app);
	  fout<<"N"<<","<<"Tiempo (ms)"<<"\n";
	
	while(true){
    	QueryPerformanceCounter(&t_ini);
			hanoi(n,'A','C','B');
  		QueryPerformanceCounter(&t_fin);
  		secs = performancecounter_diff(&t_fin, &t_ini);
  		printf("%.16g milliseconds\n", secs * 1000.0);
      fout<<n<<","<<secs * 1000.0<<"\n";
      n++;
	}
    
    return 0; 
}
