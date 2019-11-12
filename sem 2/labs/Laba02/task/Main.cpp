#include "Matrix.h"

void Task(Matrix*, int, int, int, int);

int main()
{
	setlocale(LC_ALL, "");
	int n = 5, m = 5;

	int** result = new int*[n];

	for (int i = 0; i < n; i++)
	{
		result[i] = new int[m];
	}

	Matrix* obj = new Matrix[2];
	obj[0].Enter(result, n, m);
	obj[1].Enter(result, n, m);

	obj[0].FillWith(1);
	obj[1].FillWith(2);

	cout << "Cумма матрицы с 1 и 2: ";
	(obj[0] + obj[1]).Display();

	cout << "Сумма миноров с 1 и 1: ";
	(obj[0].GetMinor(1, 1) + obj[0].GetMinor(1, 1)).Display();
	
	Matrix object(result, n, m);
	object = obj[0];

	cout << "Проверка копипрования: ";

	object.FillWith(10).Display();
	obj[0].Display();

	system("pause");
	return 0;
}
