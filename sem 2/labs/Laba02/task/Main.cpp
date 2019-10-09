#include "Matrix.h"

int main()
{
	int n = 5, m = 5;
	int** result = new int*[n];

	for (int i = 0; i < n; i++)
	{
		result[i] = new int[m];
	}

	Matrix first(result, n, m);
	Matrix second(result, n, m);

	first.FillWith(1);
	second.FillWith(2);
	first = second;

	(first.GetMinor(1, 1) + second.GetMinor(1, 1)).Display();
	(first + second).Display();

	system("pause");
	return 0;
}