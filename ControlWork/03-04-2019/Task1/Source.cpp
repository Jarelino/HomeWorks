/*
	Дана инглиш строка
	Закодировать все слова заданной длины по правилу: БУКВА -> ЦИФРА В РАнгл (z-1, a-29);
	abc -> (29)(28)(27)
	!!!! Изменить правило шифрования
	A-Z (65-90) a-z (97-122)	
*/
#pragma warning(disable : 4996)
#include <iostream>

using namespace std;

const int stringSize = 256;


typedef char*(*codeRule)(char*);

void stringReplace(char* , char* , char* );
void task(char*, int, codeRule);
int substringPosition(char*, char*, int);
char* inputString();
int stringLength(char*);
char* code(char*);

int main()
{
	char* string = inputString();


	int n;
	cout << "Word length count ";
	cin >> n;

	task(string, n, code);

	cout << string << endl;

	system("pause");
	return 0;
}


char* inputString()
{
	char* string = new char[stringSize];

	cout << "Input your string (<= 256 symbols): ";
	cin.getline(string, stringSize);

	return string;
}

int stringLength(char* string)
{
	int i = 0;

	while (string[i] != '\0')
	{
		i++;
	}

	return i;
}


char* code(char* word)
{
	char* codedWord = new char[stringSize];

	const char* symbolsUp = "ZYXWVUTSRQPONMLKJIHGFEDCBA";
	const char* symbolsDown = "zyxwvutsrqponmlkjihgfedcba";

	int length = 0;

	for (int i = 0; i < stringLength(word); i++)
	{

		for (int j = 0; j < strlen(symbolsUp); j++)
		{
			if (word[i] == symbolsUp[j] || word[i] == symbolsDown[j])
			{
				//КОСТЫЛЬ
				codedWord[length] = '(';
				length++;

				if (j > 9)
				{
					codedWord[length] = 48 + (j+1) / 10;
					length++;
				}

				codedWord[length] = 48 + (j+1) % 10;
				length++;

				codedWord[length] = ')';
				length++;
			}
		}
	}
	
	codedWord[length] = '\0';

	return codedWord;
}

void task(char* string, int count, codeRule codeRule)
{
	char* str = new char[stringSize];
	strcpy(str, string);
	char* newString = strtok(str, " ,.");
	while (newString != NULL)
	{
		if (stringLength(newString) == count)
		{
			stringReplace(string, newString, codeRule(newString));
		}

		newString = strtok(NULL, " ,.-");
		
	}
	
	delete[] newString;
	delete[] str;
}


void stringReplace(char* str, char* substing, char* replace)
{
	char* newString = new char[stringSize];

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

	newString[stringLength(str) + difference] = '\0';
	strcpy(str, newString);
}

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