#include <iostream>;
#include "MatrixLibrary.h"

using namespace std;

double* MatrixExtension::allocateMemory(int count)
{
	double* array = new double[count];
	
	return array;
} 

double** MatrixExtension::allocateMemory(double** array,int arraySize, int* count)
{
	for (int i = 0; i < arraySize; i++)
	{
		array[i] = new double[count[i]];
	}

	return array;
}

int MatrixExtension::inputRowsCount()
{
	int count;
	cout << "Input count of rows you want in your matrix: ";
	cin >> count;

	return count;
}

int* MatrixExtension::inputColumnsCount(double* array,int rowsCount)
{
	for (int i = 0; i < rowsCount; i++)
	{
		cout << "Enter count of columns in " << i << " row: ";
		cin >> array[i];
	}
}