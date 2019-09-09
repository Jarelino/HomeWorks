#include <iostream>
#include "MatrixLibrary.h"
#include <fstream>


using namespace std;
using namespace MatrixExtension;

void inputIndexes(int*, int);

void CreateFile(char* fileName, int n, int*);
int ContentsFile(char*);
double** InitMatrix(char*, int, int*);
void AddFile(char* , double** , int , int* );

int main()
{
	char input[] = "input.txt";
	char output[] = "output.txt";


	int rowsCount = inputRowsCount();
	int* columnsCount = inputColumnsCount(rowsCount);
	double** matrix = allocateDoubleMatrixMemory(rowsCount, columnsCount);
	matrix = InitMatrix(input, rowsCount, columnsCount);

	AddFile(output ,matrix, rowsCount, columnsCount);

	cout << "Enter count of rows you want to sort: ";
	int changeCount = inputInt();

	int* changeIndexes = allocateIntMemory(changeCount);
	inputIndexes(changeIndexes, changeCount);

	int** keys = allocateIntMatrixMemory(rowsCount, columnsCount);
	keys = createKeysD(matrix, changeCount, changeIndexes, roundDown);;

	sort(matrix, columnsCount, changeCount, changeIndexes, mergeSort, countOfUnits);

	AddFile(output,matrix, rowsCount, columnsCount);

	int zerosCount, unitsCount;

	cout << "Numbers with how many units you want to delete: ";
	unitsCount = inputInt();
	cout << "Numbers with how many zeros you want to delete: ";
	zerosCount = inputInt();


	cout << countOfUnits(4) << countOfZeros(4) << endl;
	matrix = deleteElementsInMatrix(matrix, rowsCount, columnsCount, changeIndexes, unitsCount, zerosCount, countOfUnits, countOfZeros);

	AddFile(output, matrix, rowsCount, columnsCount);

	
	delete[] matrix;
	delete[] changeIndexes;
	delete[] keys;
	system("pause");
	return 0;
}

void inputIndexes(int* array, int arraySize)
{
	for (int i = 0; i < arraySize; i++)
	{
		cout << "Input number of " << i + 1 << " row, you want to sort: ";
		cin >> array[i];
		array[i]--;
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

double** InitMatrix(char* fileName, int n, int* dimension)
{
	ifstream streamIn(fileName);
	if (!streamIn.is_open())
	{
		cout << "Cannot open file to read!" << endl;
		system("pause");
		exit(1);
	}
	double** matrix = allocateDoubleMatrixMemory(n, dimension);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < dimension[i]; j++)
		{
			streamIn >> matrix[i][j];
		}
	}

	streamIn.close();
	return matrix;
}

void AddFile(char* fileName, double** matrix, int n, int* dimension)
{
	ofstream streamOut(fileName, ios::app);

	if (!streamOut.is_open())
	{
		cout << "\nCannot open file to addition!\n";
		system("pause");
		exit(1);
	}
	streamOut << "Your matrix: \n";
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < dimension[i]; j++)
		{
			streamOut.width(5);
			streamOut << matrix[i][j];
		}
		streamOut << "\n";
	}
	streamOut.close();
}

