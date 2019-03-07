#include<iostream>
#include"ArrayLibrary.h"

using namespace std;
using namespace ArrayExtension;

double* createNewArray(double*, int*, int, int, int, int&, key, key);

int main()
{
	cout << "Enter dimension array: ";
	int mainSize = enterIntNumber();
	double* array = allocateMemoryDouble(mainSize);

	cout << " Enter array: ";
	inputArray(array, mainSize);

	cout << "You array: ";
	displayArray(array, mainSize);

	int* keys = allocateMemory(mainSize);
	keys = createKeysD(array, mainSize, roundDown);


	quickSort(array, keys, 0, mainSize, countOfUnits);


	int zerousCount, unitsCount;

	cout << " Enter count units: ";
	unitsCount = enterIntNumber();
	cout << " Enter count zeros: ";
	zerousCount = enterIntNumber();

	int newSize = 0;
	double *newArray = allocateMemoryDouble(mainSize);

	newArray = createNewArray(array, keys , mainSize, zerousCount, unitsCount, newSize, countOfUnits, countOfZeros);
	displayArray(newArray, newSize);

	system("pause");

	return 0;
}

double* createNewArray(double* array, int* sourse, int size, int zeros, int units, int& newSize, key unit, key zero)
{
	for (int i = 0, j = 0; i < size; i++)
	{
		if (unit(sourse[i]) != units || zero(sourse[i]) != zeros)
		{
			newSize++;
		}
	}

	double* result = allocateMemoryDouble(newSize);

	for (int i = 0, j = 0; i < size; i++)
	{
		if (unit(sourse[i]) != units || zero(sourse[i]) != zeros)
		{
			result[j] = sourse[i];
			j++;
		}
	}

	delete[] sourse;

	return result;
}

