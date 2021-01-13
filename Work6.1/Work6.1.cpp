#include <iostream>
#include <iomanip>
#include <time.h>
#include "windows.h"
using namespace std;

void Print(int* a, const int& size)
{
	for (int i=0; i<size; i++)
		cout << setw(4) << a[i];

}

void Create(int* a, const int size, const int Low, const int High)
{
	for (int i=0; i<size; i++)
		a[i] = Low + rand() % (High-Low+1);
}

int Sum(int* a, const int size)
{
	int S=0;
	for (int i=0; i<size; i++)
		if (a[i] > 0 || a[i]%2 == 0)
			S += a[i];
	return S;
}

void New(int* a, const int size)
{
	int i = 0;
	for (int i = 0; i < size; i++)
	{
		if (a[i] > 0 || a[i]%2 == 0)
			a[i] = 0;
	}				
}

int Quantity(int* a, const int size)
{
	int Q = 0;
	for (int i=0; i<size; i++)
	{
		if (a[i] > 0 || a[i]%2 == 0)
		{
			Q++;
		}
	}	
	return Q;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	const int n=25;
	int a[n];
	int Low = -20;
	int High = 30;

	srand ((unsigned)time(NULL));
	Create(a, n, Low, High);
	Print(a, n);

	cout << endl << "Сума = " << Sum(a, n) << endl;
	cout << endl << "Кількість = " << Quantity(a, n) << endl;

	cout <<"                             Модифікований масив                                "<< endl;
	cout <<"================================================================================"<< endl;

	New(a, n);
	Print(a, n);

	return 0;
}