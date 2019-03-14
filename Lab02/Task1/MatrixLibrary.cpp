#include <iostream>
#include "Matrix.h"

using namespace std;

int MatrixLibrary::inputSquareMatrixSize()
{
	int matrixSize;

	cout << "Enter size of your (N x N) matrix: ";
	cin >> matrixSize;

	return matrixSize;
}


int MatrixLibrary::inputAccuracy()
{
	int accuracy;

	cout << "Enter a number of simbols after comma: ";
	cin >> accuracy;

	return accuracy;
}

int** MatrixLibrary::allocateMemoryInt(int rows, int colums)
{
	int** matrix = new int*[rows];

	for (int i = 0; i < rows; i++)
	{
		matrix[i] = new int[colums];
	}

	return matrix;
}

double** MatrixLibrary::allocateMemoryDouble(int rows, int colums)
{
	double** matrix = new double*[rows];

	for (int i = 0; i < rows; i++)
	{
		matrix[i] = new double[colums];
	}

	return matrix;
}

void MatrixLibrary::fillMatrix(double** matrix, int rows, int colums, value formula)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < colums; j++)
		{
			matrix[i][j] = formula(i, j);
		}
	}
}

void MatrixLibrary::fillMatrix(double** matrix, int rows, int colums, int accuracy, exactValue formula)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < colums; j++)
		{
			matrix[i][j] = formula(i, j, accuracy);
		}
	}
}

void MatrixLibrary::displayDoubleMatrix(double** matrix, int rows, int colums)
{
	cout << "Matrix: " << endl;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < colums; j++)
		{
			cout << " " << matrix[i][j];
		}
		cout << endl;
	}
}

double MatrixLibrary::taylorSin(double number, int accuracy)
{
	const double PI = 3.14159265358979323846;
	number = fmod(number, PI * 2);
	double sin = 0, term = number;
	int i = 1;
	while (abs(term) > pow(0.1, accuracy))
	{
		sin += term;
		term *= -1.0*(number * number) / (2 * i) / (2 * i + 1);
		i++;
	}
	return sin;
}


double MatrixLibrary::maxMatrixDifference(double** firstMatrix, double** secondMatrix, int rows, int colums)
{
	double maxDifference = 0;
	double currentDifference = 0;

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < colums; j++)
		{
			currentDifference = fabs(secondMatrix[i][j] - firstMatrix[i][j]);
			if (currentDifference > maxDifference)
			{
				maxDifference = currentDifference;
			}
		}
	}

	return maxDifference;
}