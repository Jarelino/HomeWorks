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

char* stringReplace(char* , char* , char* );
char* task(char*, int, codeRule);
char* inputString();
char* encrypt(char*);
char toUpperCase(char);
char* encryptLetter(char);

int main()
{
	char* string = inputString();


	int n;
	cout << "Word length count ";
	cin >> n;

	string = task(string, n, encrypt);

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

char toUpperCase(char letter)
{
	if (letter >= 'A' && letter <= 'Z')
	{
		return letter;
	}
	else
	{
		return letter - 32;
	}
}

char* encryptLetter(char letter)
{
	letter = toUpperCase(letter);
	int number = 91 - letter;
	char* result = new char[5];
	result[0] = '(';

	if (number / 10 > 0)
	{
		result[1] = (number / 10) + '0';
		result[2] = (number	% 10) + '0';
		result[3] = ')';
		result[4] = '\0';
	}
	else
	{
		result[1] = (number % 10) + '0';
		result[2] = ')';
		result[3] = '\0';
	}

	return result;
}



char* encrypt(char* word)
{
	char* result = new char[1];
	result[0] = '\0';

	int length = 0;

	for (int i = 0; i < strlen(word); i++)
	{
		length += strlen(encryptLetter(word[i]));
		strcat(result, encryptLetter(word[i]));
	}

	result[length + 1] = '\0';
	return result;
}


char* task(char* string, int count, codeRule codeRule)
{
	char* str = new char[stringSize];
	strcpy(str, string);
	
	char* word = strtok(str, " ,.");

	while (word != NULL)
	{
		if (strlen(word) == count)
		{
			string = stringReplace(string, word, codeRule(word));
		}

		word = strtok(NULL, " ,.-");
		
	}
	
	delete[] word;
	delete[] str;

	return string;
}


char* stringReplace(char* source, char* strToReplace, char* replaceString)
{
	int oldLength = strlen(source);

	int difference = strlen(replaceString) - strlen(strToReplace);

	char* result = new char[strlen(source) + difference + 1];

	strncpy(result, source, oldLength - strlen(strstr(source, strToReplace)));
	result[strlen(source) - strlen(strstr(source, strToReplace))] = '\0';

	strcat(result, replaceString);
	strcat(result, strstr(source, strToReplace) + strlen(strToReplace));

	return result;
}
