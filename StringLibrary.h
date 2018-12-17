#include <iostream>;

using namespace std;

const int N = 256;

bool stringEquality(char*, char *, int);
bool stringEquality(char*, char *);
bool isLetter(char);
bool isEqual(char *, char *);

int substringPosition(char*, char*, int);
int substringPosition(char *, int, char *, int);
int substringPosition(char *, char *);
int stringLength(char *);

char stringCompare(char *, char *, int);
char stringCompare(char *, char *);

void toLower(char * str);
void toUpper(char * str);
void arrayOfWords(char* str, char * newString[N][N]);
void stringReplace(char*, char*, char*, char*);


int substringPosition(char* str, char* substring, int start)
{
	int n = stringLength(str),
		m = stringLength(substring);

	if (m > n)
	{
		return -1;
	}

	int count = 0, 
		index = -1;
	
	for (int i = start; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (substring[j] == str[i + count])
			{
				index = i;
				count++;
				if (j == m - 1)
				{
					return index;
				}
			}
			else
			{
				index = -1;
				count = 0;
				break;
			}
		}
	}
	return index;
}

void stringReplace(char* str, char* substing, char* replace, char* newString)
{

	int newLength = stringLength(replace), 
		oldLength = stringLength(substing), 
		sLength = stringLength(str), 
		start = 0, 
		oldStart = 0, 
		count = 0, 
		difference = newLength - oldLength;

	int index = substringPosition(str, substing, start);

	for (int i = 0; i < index; i++)
	{
		newString[i] = str[i];
	}

	while (index != -1)
	{
		for (int j = index + count * (difference), i = 0; j < index + newLength + count * (difference); j++, i++)
		{
			newString[j] = replace[i];
		}
		start = index + newLength;

		int newIndex = substringPosition(str, substing, start);
		
		while (newIndex != -1)
		{
			for (int i = index + newLength + count * (difference), j = index + oldLength; j < newIndex; i++, j++)
			{
				newString[i] = str[j];
			}
			break;
		}

		while (newIndex == -1)
		{
			for (int i = index + newLength + count * (difference), j = index + oldLength; j < sLength; i++, j++)
			{
				newString[i] = str[j];
			}
			break;
		}

		index = substringPosition(str, substing, start);
		count++;
	}
}

void arrayOfWords(char* str, char * newString[N][N])
{

	int nextLetter = 0, nextWord = 0, flag = 0;

	for (int i = 0; i < stringLength(str); i++)
	{
		if (isLetter(str[i]))
		{
			newString[nextLetter][nextWord] = str[i];
			nextLetter++;
		}
		else
		{
			if (isLetter(str[i + 1]))
			{
				nextWord++;
				nextLetter = 0;
			}
		}

	}

}

bool isLetter(char symbol)
{
	if ((symbol >= 'A' && symbol <= 'Z') || (symbol >= 'a' && symbol <= 'z'))
	{
		return true;
	}
	return false;
}


bool stringEquality(char * firstStr, char * secondStr)
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

int substringPosition(char * firstStr, char * subStr)
{
	int position = -1;

	for (int i = 0; i < stringLength(firstStr); i++)
	{
		if (firstStr[i] == subStr[0])
		{
			position = i;

			for (int j = 0; j < stringLength(subStr); j++)
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

int substringPosition(char * firstStr, int N, char * subStr, int n)
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

char stringCompare(char * firstStr, char * secondStr)
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

int stringLength(char * string)
{
	int length = 0;

	while (string[length] != '\0')
	{
		length++;
	}

	return length;
}

bool isEqual(char * firstStr, char * secondStr)
{
	if (stringLength(firstStr) != stringLength(secondStr))
	{
		return false;
	}

	for (int i = 0; i < stringLength(firstStr); i++)
	{
		if (firstStr[i] != secondStr[i])
		{
			return false;
		}
	}

	return true;
}

void toUpper(char * str)
{
	const int difference = 'a' - 'A';

	for (int i = 0; i < stringLength(str); i++)
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			str[i] -= difference;
		}
	}
}

void toLower(char * str)
{
	const int difference = 'A' - 'a';

	for (int i = 0; i < stringLength(str); i++)
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			str[i] -= difference;
		}
	}
}