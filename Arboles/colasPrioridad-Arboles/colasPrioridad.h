#ifndef COLASPRIORIDAD_H
#define COLASPRIORIDAD_H

using namespace std;

class Monticulo
{
private:
	int *arr, tam, posAct;

public:
	Monticulo(int tam)
	{
		this->tam = tam;
		arr = new int[tam + 1];
		posAct = 0;

		for (int i = 1; i < tam + 1; i++)
			arr[i] = 0;
	}

	~Monticulo()
	{
		delete arr;
	}

	bool insertar(int val);
	int atender();
	void imprimirArreglo();
	bool monticuloLleno();
};

bool Monticulo ::insertar(int val)
{
	if (monticuloLleno())
		return false;

	posAct++;

	int padre = posAct / 2;

	if (padre == 0)
	{
		arr[posAct] = val;
		return true;
	}

	int posLib = posAct;

	while (val > arr[padre])
	{
		arr[posLib] = arr[padre];
		posLib = padre;
		padre = padre / 2;

		if (padre == 0)
		{
			arr[1] = val;
			return true;
		}
	}
	arr[posLib] = val;
	return true;
}

int Monticulo ::atender()
{
	int aten = arr[1];
	int ult = arr[posAct];
	arr[posAct] = 0;
  if(posAct==1)posAct--;
  if(posAct<=1) return aten;
	posAct--;
	arr[1] = 0;
    
	int i = 1;
	int posLib = 1;
	while (i < tam)
	{
		i = i * 2;
		if (ult > arr[i] && ult > arr[i + 1])
		{
			arr[posLib] = ult;
			break;
		}
		else
		{
			if (arr[i] > arr[i + 1])
			{
				arr[posLib] = arr[i];
				posLib = i;
			}
			else
			{
				arr[posLib] = arr[i + 1];
				posLib = i + 1;
			}
		}
	}

	return aten;
}

void Monticulo ::imprimirArreglo()
{
	for (int i = 1; i < posAct + 1; i++)
		cout << arr[i] << " ";
}

bool Monticulo ::monticuloLleno()
{
	for (int i = 1; i < tam + 1; i++)
		if (arr[i] == 0)
			return false;
	return true;
}

#endif

