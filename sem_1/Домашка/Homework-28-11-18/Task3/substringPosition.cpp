#include <iostream>;

using namespace std;

int substringPosithion(char *,int, char *, int);

int main()
{
	const int N = 256;
	char firstStr[N];
	char subStr[N];

	cout << "Enter your first string with a length <= 256 : ";
	cin >> firstStr;

	int n = -1;
	while (n < 0 || n > 256)
	{
		cout << "Enter length of your substring <= 256 : ";
		cin >> n;
	}
	
	cout << "Enter your substring : ";
	cin >> subStr;

	system("cls");

	int position = substringPosithion(firstStr, N, subStr, n);

	if (position == -1)
	{
		cout << "There is no such substring in your string" << endl;
	}
	else
	{
		cout << "Position of you substring is : " << position << endl;
	}


	system("pause");
	return 0;
}

int substringPosithion(char * firstStr, int N, char * subStr, int n)
{
	int position = -1;

	for (int i = 0; i < N; i++)
	{
		if (firstStr[i] == subStr[0])
		{
			position = i;

			for (int j = 0; j < n; j++)
			{
				if (firstStr[i + j] != subStr[j])
				{
					position = -1;
				}
			}
		}
	}

	return position;
}