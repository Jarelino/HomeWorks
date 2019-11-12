#include <iostream>
#include "Matrix.h"
#include <fstream>

using namespace MatrixLibrary;
using namespace std;

double formula(int, int);
double formulaTeylor(int, int, int);

int ContentsFile(char*);
double** InitMatrix(char*, int, int);
void AddFile(char*, double**, int, int);

int main()
{
	
	int matrixSize = inputSquareMatrixSize();
	int accuracy = inputAccuracy();

	char input[] = "input.txt";
	char output[] = "output.txt";

	double** firstMatrix = allocateMemoryDouble(matrixSize, matrixSize);
	double** secondMatrix = allocateMemoryDouble(matrixSize, matrixSize);
	system("cls");


	cout << endl << "Matrix without Taylor series" << endl;
	fillMatrix(firstMatrix, matrixSize, matrixSize, formula);
	displayDoubleMatrix(firstMatrix, matrixSize, matrixSize);
	AddFile(output, firstMatrix, matrixSize, matrixSize);

	cout << endl << "Matrix with Taylor series" << endl;
	fillMatrix(secondMatrix, matrixSize, matrixSize, accuracy, formulaTeylor);
	displayDoubleMatrix(secondMatrix, matrixSize, matrixSize);
	AddFile(output, secondMatrix, matrixSize, matrixSize);


	cout << endl << "Max matrix difference: " << maxMatrixDifference(firstMatrix, secondMatrix, matrixSize, matrixSize) << endl;

	

	system("pause");
	return 0;
}

double formula(int i, int j)
{
	if (i == (2 * j))
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

int ContentsFile(char* fileName)
{
	ifstream streamIn(fileName);

	if (!streamIn.is_open())
	{
		cout << "Cannot open file to read!" << endl;
		system("pause");
		exit(1);
	}

	int count = 0, term;

	while (!streamIn.eof())
	{
		streamIn >> term;
		count++;
	}
	streamIn.close();
	return count;
}

double** InitMatrix(char* fileName, int rows, int columns)
{
	ifstream streamIn(fileName);
	if (!streamIn.is_open())
	{
		cout << "Cannot open file to read!" << endl;
		system("pause");
		exit(1);
	}
	double** matrix = allocateMemoryDouble(rows, columns);;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			streamIn >> matrix[i][j];
		}
	}

	streamIn.close();
	return matrix;
}

void AddFile(char* fileName, double** matrix, int rows, int columns)
{
	ofstream streamOut(fileName, ios::app);

	if (!streamOut.is_open())
	{
		cout << "\nCannot open file to addition!\n";
		system("pause");
		exit(1);
	}
	streamOut << "Your matrix: \n";
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			streamOut.width(5);
			streamOut << matrix[i][j];
		}
		streamOut << "\n";
	}
	streamOut.close();
}
