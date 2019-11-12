#include <iostream>;
#include "MatrixLibrary.h"


using namespace std;

double* MatrixExtension::allocateDoubleMemory(int count)
{
	double* array = new double[count];

	return array;
}

int* MatrixExtension::allocateIntMemory(int count)
{
	int* array = new int[count];

	return array;
}

int** MatrixExtension::allocateIntMatrixMemory(int arraySize, int* count)
{
	int** matrix = new int*[arraySize];

	for (int i = 0; i < arraySize; i++)
	{
		matrix[i] = new int[count[i]];
	}

	return matrix;
}

double** MatrixExtension::allocateDoubleMatrixMemory(int arraySize, int* count)
{
	double** matrix = new double*[arraySize];

	for (int i = 0; i < arraySize; i++)
	{
		matrix[i] = new double[count[i]];
	}

	return matrix;
}

int MatrixExtension::inputInt()
{
	int number;

	cin >> number;

	return number;
}



int MatrixExtension::inputRowsCount()
{
	int count;
	cout << "Input count of rows you want in your matrix: ";
	cin >> count;


	return count;
}

int* MatrixExtension::inputColumnsCount(int rowsCount)
{
	int* array = new int(rowsCount);

	for (int i = 0; i < rowsCount; i++)
	{
		cout << "Enter count of columns in " << i + 1 << " row: ";
		cin >> array[i];
	}

	return array;
}

void MatrixExtension::inputNonRectangularMatrix(double** matrix, int rowsCount, int* columnsCount)
{
	for (int i = 0; i < rowsCount; i++)
	{
		cout << "Input elements in " << i + 1 << " row" << endl;

		for (int j = 0; j < columnsCount[i]; j++)
		{
			cout << j + 1 << " element: ";
			cin >> matrix[i][j];
		}
	}
}

void MatrixExtension::displayNonRectangularMatrix(double** matrix, int rowsCount, int* columnsCount)
{
	cout << endl;
	for (int i = 0; i < rowsCount; i++)
	{
		for (int j = 0; j < columnsCount[i]; j++)
		{
			cout << " " << matrix[i][j] << " ";
		}

		cout << endl;
	}
}

int** MatrixExtension::createKeysD(double** matrix, int rowsCount, int* columnsCount, keyD key)
{
	int** keys = MatrixExtension::allocateIntMatrixMemory(rowsCount, columnsCount);

	for (int i = 0; i < rowsCount; i++)
	{
		for (int j = 0; j < columnsCount[i]; j++)
		{
			keys[i][j] = key(matrix[i][j]);
		}

	}
	return keys;
}

int MatrixExtension::roundDown(double number)
{
	int roundDown = (int)number;

	return roundDown;
}

void MatrixExtension::mergeSort(double* array, int lb, int ub, key key)
{
	int split;

	if (lb < ub)
	{
		split = (lb + ub) / 2;
		mergeSort(array, lb, split, key);
		mergeSort(array, split + 1, ub, key);
		merge(array, lb, split, ub, key);
	}
}

void MatrixExtension::merge(double* array, int lb, int split, int ub, key key)
{
	int pos1 = lb, pos2 = split + 1, pos3 = 0;

	int* temp = allocateIntMemory(ub - lb + 1);

	while (pos1 <= split && pos2 <= ub) {
		if (key(array[pos1]) > key(array[pos2]))
		{
			temp[pos3++] = array[pos1++];
		}
		else
		{
			temp[pos3++] = array[pos2++];
		}
	}

	while (pos2 <= ub)
	{
		temp[pos3++] = array[pos2++];
	}
	while (pos1 <= split)
	{
		temp[pos3++] = array[pos1++];
	}

	for (pos3 = 0; pos3 < ub - lb + 1; pos3++)
	{
		array[lb + pos3] = temp[pos3];
	}

	delete[] temp;
}


void MatrixExtension::sort(double** matrix, int* columnsCount, int sortCount, int* sortIndexes, sortDouble sortDouble, key key)
{
	for (int i = 0; i < sortCount; i++)
	{
		sortDouble(matrix[sortIndexes[i]], 0, columnsCount[sortIndexes[i]] - 1, key);
	}
}

int MatrixExtension::countOfUnits(int number)
{
	int k = 0;

	number = abs(number);

	while (number)
	{
		int rest = number % 2;

		if (rest)
		{
			k++;
		}

		number /= 2;
	}

	return k;
}

int MatrixExtension::countOfZeros(int number)
{
	int k = 0;

	number = abs(number);

	while (number)
	{
		int rest = number % 2;

		if (!rest)
		{
			k++;
		}

		number /= 2;
	}

	return k;
}


double** MatrixExtension::deleteElementsInMatrix(double** matrix, int rows, int* size, int* changeIndexes, int units, int zeros, key unit, key zero)
{
	for (int i = 0, j = 0; i < rows; i++)
	{
		if (i == changeIndexes[j])
		{
			matrix[i] = deleteElementsInArray(matrix[i], size[i], units, zeros, unit, zero);
			j++;
		}
	}
	return matrix;
}

double* MatrixExtension::deleteElementsInArray(double* array, int& size, int units, int zeros, key unit, key zero)
{

	int copy = size;
	int length = 0;
	for (int i = 0; i < size; i++)
	{
		if (unit(array[i]) == units && zero(array[i]) == zeros)
		{
			length++;
		}
	}

	double* newArray = allocateDoubleMemory(length);


	for (int i = 0, j = 0; i < copy; i++)
	{
		if (!(unit(array[i]) == units && zero(array[i]) == zeros))
		{
			newArray[j] = array[i];
			j++;
		}
		else size--;
	}
	return newArray;
}