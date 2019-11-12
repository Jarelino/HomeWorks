#include <iostream>;
#include "MatrixLibrary.h";

using namespace std;

void roundSquareReplace(int(*)[MAXSIZE], int);

int main()
{
	int n = -1;
	int matrix[MAXSIZE][MAXSIZE];

	while (n < 0 || n > 50)
	{
		cout << "Choose size of one square in matrix (1-50) : ";
		cin >> n;
	}

	system("cls");
	n *= 2;

	inputMatrix(matrix, n);

	system("cls");

	roundSquareReplace(matrix, n);

	displayMatrix(matrix, n, n);

	system("pause");
	return  0;
}

void roundSquareReplace(int(*matrix)[MAXSIZE], int n)
{
	n /= 2;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			matrixSwap(matrix, i, j, i, j + n);
			matrixSwap(matrix, i, j, i + n, j + n);
			matrixSwap(matrix, i, j, i + n, j);
		}
	}
}
