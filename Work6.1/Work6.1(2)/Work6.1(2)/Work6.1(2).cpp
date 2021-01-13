#include <iostream>
#include <iomanip>
#include <time.h>
#include "windows.h"

using namespace std;

void Create(int* a, const int size, const int Low, const int High, int i)
{
	a[i] = Low + rand() % (High - Low + 1);
	if (i < size - 1)
		Create(a, size, Low, High, i + 1);
}
void Print(int* a, const int size, int i)
{
	cout << setw(4) << a[i];
	if (i < size - 1)
		Print(a, size, i + 1);
	else
		cout << endl;
}

int Sum(int* a, const int size, int i)
{
	if (i < size)
	{
		if (a[i] > 0 && a[i] % 2 == 0)
			return a[i] + Sum(a, size, i + 1);
		else
			return Sum(a, size, i + 1);
	}
	else
		return 0;
}
void New(int* a, const int size, int i)
{
	if (i < size)

	{
		if (a[i] > 0 && a[i] % 2 == 0)
			a[i] = 0;
		New(a, size, i + 1);
	}
}
int Quantity(int* a, const int size, int i)
{
	if (i < size)
	{

		if ((a[i] > 0 && a[i] % 2 == 0))

			return 1 + Quantity(a, size, i + 1);
		else
			return Quantity(a, size, i + 1);
	}
	else
		return 0;
}

int main()
{
	const int n = 25;
	int a[n];

	int Low = -20;
	int High = 30;

	srand((unsigned)time(NULL));
	Create(a, n, Low, High, 0);
	Print(a, n, 0);

	cout << endl << "Sum = " << Sum(a, n, 0) << endl;
	cout << endl << "Quantity = " << Quantity(a, n, 0) << endl;
	cout << "                              Modification masyv                                "<<endl;
	cout << "|~====================================================================================================================~|" << endl;

	New(a, n, 0);
	Print(a, n, 0);

	return 0;
}