#include <iostream>
#include "Matrix.h"

using namespace MatrixLibrary;
using namespace std;

double formula(int, int);
double formulaTeylor(int, int, int);

int main()
{
	int matrixSize = inputSquareMatrixSize();
	int accuracy = inputAccuracy();

	double** firstMatrix = allocateMemoryDouble(matrixSize, matrixSize);
	double** secondMatrix = allocateMemoryDouble(matrixSize, matrixSize);
	system("cls");


	cout << endl << "Matrix without Taylor series" << endl;
	fillMatrix(firstMatrix, matrixSize, matrixSize, formula);
	displayDoubleMatrix(firstMatrix, matrixSize, matrixSize);

	cout << endl << "Matrix with Taylor series" << endl;
	fillMatrix(firstMatrix, matrixSize, matrixSize, accuracy, formulaTeylor);
	displayDoubleMatrix(firstMatrix, matrixSize, matrixSize);

	cout << endl << "Max matrix difference: " << maxMatrixDifference(firstMatrix, secondMatrix, matrixSize, matrixSize) << endl;

	int i = 0;
	int j = 0;
	cout << ((sin(2 * i * j) + sin(i)) / (pow(i - j - 4, 3) + pow(i + j, 2))) << endl;


	system("pause");
	return 0;
}

double formula(int i, int j)
{
	if (i == 2 * j)
	{
		return ((sin(2 * i * j) + sin(i)) / (pow(i - j - 4, 3) + pow(i + j, 2)));
	}
	else
	{
		return i;
	}
}

double formulaTeylor(int i, int j, int accuracy)
{
	if (i == 2 * j)
	{
		return ((taylorSin(2 * i * j, accuracy) + taylorSin(i, accuracy)) / (pow(i - j - 4, 3) + pow(i + j, 2)));
	}
	else
	{
		return i;
	}
}

