#include <iostream>;

using namespace std;

char stringCompare(char *, char *, int);

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

	switch (stringCompare(firstStr, secondStr, N))
	{
	case 'g':
		cout << "First string (" << firstStr << ") is grater than second string (" << secondStr << ")\n";
		break;
	case 'l':
		cout << "First string (" << firstStr << ") is less than second string (" << secondStr << ")\n";
		break;
	case 'e':
		cout << "First string (" << firstStr << ") is equal to second string (" << secondStr << ")\n";
		break;
	}

	system("pause");
	return 0;
}

char stringCompare(char * firstStr, char * secondStr, int N)
{
	for (int i = 0; i < N; i++)
	{
		if (firstStr[i] > secondStr[i])
		{
			return 'g';
		}
		else if (firstStr[i] < secondStr[i])
		{
			return 'l';
		}
	}

	return 'e';
}

