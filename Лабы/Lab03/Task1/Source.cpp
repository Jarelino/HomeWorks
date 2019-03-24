#include <iostream>
#include "MatrixLibrary.h"


using namespace std;
using namespace MatrixExtension;

void inputIndexes(int*, int);
void deleteItems(double**, int**, int, int*, int*, int, int, key, key);

int main()
{
	int rowsCount = inputRowsCount();
	int* columnsCount = inputColumnsCount(rowsCount);
	double** matrix = allocateDoubleMatrixMemory(rowsCount, columnsCount);
	inputNonRectangularMatrix(matrix, rowsCount, columnsCount);

	cout << "Your matrix: ";
	displayNonRectangularMatrix(matrix, rowsCount, columnsCount);

	cout << "Enter count of rows you want to sort: ";
	int changeCount = inputInt();

	int* changeIndexes = allocateIntMemory(changeCount);
	inputIndexes(changeIndexes, changeCount);

	int** keys = allocateIntMatrixMemory(rowsCount, columnsCount);
	keys = createKeysD(matrix, changeCount, changeIndexes, roundDown);;

	sort(matrix, columnsCount, changeCount, changeIndexes, mergeSort, countOfUnits);

	cout << "Your sorted matrix: ";
	displayNonRectangularMatrix(matrix, rowsCount, columnsCount);

	int zerosCount, unitsCount;

	cout << "Numbers with how many units you want to delete: ";
	unitsCount = inputInt();
	cout << "Numbers with how many zeros you want to delete: ";
	zerosCount = inputInt();

	matrix = deleteElementsInMatrix(matrix, rowsCount, columnsCount, changeIndexes, unitsCount, zerosCount, countOfUnits, countOfZeros);

	cout << "Your matrix: ";
	displayNonRectangularMatrix(matrix, rowsCount, columnsCount);

	

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


