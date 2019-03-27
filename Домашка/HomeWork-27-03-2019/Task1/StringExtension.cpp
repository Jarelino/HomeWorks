#include <iostream>
#include "StringLibrary.h";

#pragma warning(disable : 4996);

using namespace std;


char* StringExtension::inputString()
{
	int stringSize = 256;
	char* string = new char[stringSize];

	cout << "Input your string (length <= 256) : ";
	cin.getline(string, stringSize, '\n');

	return string;
}

int StringExtension::stringLength(char* string)
{
	int i = 0;

	while (string[i] != '\0')
	{
		i++;
	}

	return i;
}


void StringExtension::displayString(char* string)
{
	cout << "Your string: " << string << endl;
}


char** StringExtension::obtainWords(char * source, int & n)
{
	char* copy = new char[strlen(source) + 1];
	strcpy(copy,source);

	char** words = new char*[strlen(copy) / 2];
	n = 0;
	char symbols[] = "	1234567890-=!@#$%^&*()_+{}|][:;'<>?/., \x22";
	char* pword = strtok(copy, symbols);
	words[n] = new char[strlen(pword) + 1];
	strcpy(words[n], pword);

	n++;
	while (pword)
	{
		pword = strtok('\0', symbols);
		if (pword)
		{
			words[n] = new char[strlen(pword) + 1];
			strcpy(words[n], pword);
			n++;
		}
	}

	delete[] copy;
	return words;
}

void StringExtension::displayWords(char** words, int n)
{
	for (int i = 0; i < n; i++)
		std::cout << (i + 1) << ". " << words[i] << std::endl;
}
