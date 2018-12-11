#include <iostream>;
#include "MatrixLibrary.h";

using namespace std;

void matrixSquareReplace(int (*)[MAXSIZE], int);

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

	matrixSquareReplace(matrix, n);

	displayMatrix(matrix, n, n);

	system("pause");
	return  0;
}

void matrixSquareReplace(int(*matrix)[MAXSIZE], int n)
{
	int half = n / 2;
	for (int i = 0; i < half; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (j < half)
			{
				matrixSwap(matrix, i, j, i + half, j + half);
			}
			else
			{
				matrixSwap(matrix, i, j, i + half, j - half);
			}
		}
	}
}
