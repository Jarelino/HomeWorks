#include <iostream>;

using namespace std;

bool stringEquality(char*, char *, int);

int main()
{
	const int N = 256;
	char firstStr[N];
	char secondStr[N];

	cout << "Enter your first string with a length <= 256 : ";
	cin >> firstStr;

	cout << "Enter your second string with a length <= 256 : ";
	cin >> secondStr;

	system("cls");

	if (stringEquality(firstStr, secondStr, N))
	{
		cout << "Strings are equal" << endl;
	}
	else
	{
		cout << "Strings aren't equal" << endl;
	}

	system("pause");
	return 0;
}

bool stringEquality(char * firstStr, char * secondStr, int N)
{
	for (int i = 0; i < N; i++)
	{
		if (firstStr[i] != secondStr[i])
		{
			return false;
		}
	}

	return true;
}

