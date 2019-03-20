#include <iostream>

using namespace std;
const int MAXSIZE = 100;

//matrix
void displayMatrix(int(*)[MAXSIZE], int, int);
void inputMatrix(int(*)[MAXSIZE], int);
void matrixSwap(int(*)[MAXSIZE], int, int, int, int);
void transpose(int(*)[MAXSIZE], int);
void matrixLineSwap(int(*)[MAXSIZE], int, int, int);
void matrixBubbleSort(int(*)[MAXSIZE], int*, int, int);


//array
void inputArray(int *, int);
void swap(int &, int &);
void displayArray(int *, int);
void arrayBubbleSort(int *, int*, int, int);


//numbers
bool isPrimeNumber(int);
bool isPalindrome(long long);
long long makingReverse(long long);




void displayMatrix(int(*a)[MAXSIZE], int n, int m)
{
	cout << "Your matrix : " << endl;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout.width(3);
			cout << a[i][j];
		}
		cout << endl;
	}

	cout << endl;
}

void inputArray(int * arr, int n)
{
	cout << "Input your array : ";

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
}

void inputMatrix(int(*matrix)[MAXSIZE], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "Input " << i + 1 << " line of your matrix (" << n << " elements) : ";
		for (int j = 0; j < n; j++)
		{
			cin >> matrix[i][j];
		}
	}
}

void matrixSwap(int(*matrix)[MAXSIZE], int i, int j, int m, int n)
{
	int t = matrix[i][j];
	matrix[i][j] = matrix[m][n];
	matrix[m][n] = t;
}

void swap(int & first, int & second)
{
	int t = first;
	first = second;
	second = t;
}

void displayArray(int * arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout.width(3);
		cout << arr[i];
	}

	cout << endl;
}

void transpose(int(*a)[MAXSIZE], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			swap(a[i][j], a[j][i]);
		}
	}
}

void matrixBubbleSort(int(*matrix)[MAXSIZE], int* keys, int n, int m)
{
	bool swapped = true;
	int i = 1;
	while (swapped)
	{
		swapped = false;
		for (int j = n - 1; j >= i; j--)
		{
			if (keys[j] < keys[j - 1])
			{
				matrixLineSwap(matrix, j, j - 1, m);
				swap(keys[j], keys[j - 1]);
				swapped = true;
			}
		}
		i++;
	}
}

void matrixLineSwap(int(*matrix)[MAXSIZE], int first, int second, int length)
{
	int t;

	for (int i = 0; i < length; i++)
	{
		t = matrix[first][i];
		matrix[first][i] = matrix[second][i];
		matrix[second][i] = t;
	}
}

void arrayBubbleSort(int * arr, int* keys, int n, int m)
{
	bool swapped = true;
	int i = 1;
	while (swapped)
	{
		swapped = false;
		for (int j = n - 1; j >= i; j--)
		{
			if (keys[j] < keys[j - 1])
			{
				swap(arr[j], arr[j - 1]);
				swap(keys[j], keys[j - 1]);
				swapped = true;
			}
		}
		i++;
	}
}

bool isPrimeNumber(int number)
{
	if (number <= 1)
	{
		return false;
	}

	bool result = true;

	for (int i = 2; i <= sqrt(number); i++)
	{
		if (!(number % i))
		{
			result = false;
			break;
		}
	}

	return result;
}

long long makingReverse(long long number)
{
	int sign = number >= 0 ? 1 : -1;
	number = abs(number);
	long long reverse = 0;

	while (number)
	{
		int digit = number % 10;
		reverse = reverse * 10 + digit;
		number /= 10;
	}
	return sign * reverse;
}

bool isPalindrome(long long number)
{
	return number == makingReverse(number);
}