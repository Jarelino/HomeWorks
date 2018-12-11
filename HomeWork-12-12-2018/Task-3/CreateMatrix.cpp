#include <iostream>;
#include "MatrixLibrary.h";

using namespace std;

void sampleA(int (*)[MAXSIZE],int);
void sampleB(int(*)[MAXSIZE],int);
void sampleC(int(*)[MAXSIZE],int);
void sampleD(int(*)[MAXSIZE],int);

int main()
{
	int n = -1;
	int matrix[MAXSIZE][MAXSIZE];
	int sampleNumber = 0;

	while (sampleNumber <= 0 || sampleNumber > 4)
	{
		cout << "Select sample number (1-4) ";
		cin >> sampleNumber;
	}

	system("cls");

	while (n < 0 || n > 100)
	{
		cout << "Choose the matrix size (1-100) ";
		cin >> n;
	}

	system("cls");

	switch (sampleNumber)
	{
	case 1:
		sampleA(matrix, n);
		break;
	case 2:
		sampleB(matrix, n);
		break;
	case 3:
		sampleC(matrix, n);
		break;
	case 4:
		sampleD(matrix, n);
		break;
	}

	displayMatrix(matrix, n, n);

	system("pause");
	return 0;

}

void sampleA(int (* matrix)[MAXSIZE], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == j)
			{
				matrix[i][j] = n;
			}
			else if (i > j)
			{
				matrix[i][j] = n - i + j;
			}
			else
			{
				matrix[i][j] = 0;
			}

		}
	}
}

void sampleB(int(*matrix)[MAXSIZE], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i < n / 2)
			{
				if (i > j || (n - (i + 1)) < j)
				{
					matrix[i][j] = 0;
				}
				else
				{
					matrix[i][j] = 1;
				}
			}
			else
			{
				if (i < j || (n - (i + 1)) > j)
				{
					matrix[i][j] = 0;
				}
				else
				{
					matrix[i][j] = 1;
				}
			}
		}
	}
}

void sampleC(int(*matrix)[MAXSIZE], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i < n / 2)
			{
				if (i >= j || (n - (i + 1)) <= j)
				{
					matrix[i][j] = 1;
				}
				else
				{
					matrix[i][j] = 0;
				}
			}
			else
			{
				if (i <= j || (n - (i + 1)) >= j)
				{
					matrix[i][j] = 1;
				}
				else
				{
					matrix[i][j] = 0;
				}
			}
		}
	}
}

void sampleD(int(*matrix)[MAXSIZE], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == j || (n - 1 - j) == i)
			{
				matrix[i][j] = j + 1;
			}
			else
			{
				matrix[i][j] = 0;
			}
		}
	}
}