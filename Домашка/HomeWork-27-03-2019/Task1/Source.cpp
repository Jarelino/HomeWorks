// Строка -> Массив слов -> Сорт по ключу
#include <iostream>
#include "StringLibrary.h"

using namespace std;
using namespace StringExtension;

int main()
{
	char* string;
	string = inputString();

	int n = 0;
	char** wordsArray = obtainWords(string,n);

	displayWords(wordsArray, n);

	system("pause");
	return 0;
}