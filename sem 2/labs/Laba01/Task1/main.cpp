#include "Word.h"



void DisplayCommonWord(Word*, int);
void FillWords(Word*, int);
void DisplayAlphabeticalWords(Word*, int);
bool IsStringLarger(char*, char*);
void BubbleSortWords(Word*, int);
void DisplayWordPages(Word*, int);
bool IsEqual(char*, char*);
int Menu();
void SystemFun();



int main()
{

	int wordsCount;
	cout << "Enter count of words: ";
	cin >> wordsCount;

	Word* words = new Word[wordsCount];
	FillWords(words, wordsCount);

	while (true)
	{
		system("cls");
		int key = Menu();
		if (key == 0)
			return 0;
		system("cls");
		switch (key)
		{
		case 1:
			DisplayCommonWord(words,wordsCount);
			SystemFun();
			break;
		case 2:
			DisplayAlphabeticalWords(words, wordsCount);
			SystemFun();
			break;
		case 3:
			DisplayWordPages(words, wordsCount);
			SystemFun();
			break;
		default:
			cout << "\nIncorrect input! Try again!";
			SystemFun();
		}
	}

	return 0;
}

int Menu()
{
	int k;
	cout << "\n Enter the number:"
		"\n 1 - FIND WORDS WITH N PAGES"
		"\n 2 - DISPLAY WORDS IN ALPHABETICAL ORDER"
		"\n 3 - FIND WORD OF THE PAGE"
		"\n 0 - EXIT\n";
	cin >> k;
	return k;
}

void SystemFun()
{
	cout << endl;
	system("pause");
	system("cls");
}

void DisplayCommonWord(Word* words, int wordsCount)
{
	system("cls");

	int minPages;
	cout << endl << "Enter words with how much pages you want to find: ";
	cin >> minPages;

	cout << "Words with more than " << minPages << " pages: ";
	for (int i = 0; i < wordsCount; i++)
	{
		if (words[i].GetPagesCount() >= minPages)
		{
			cout << words[i].GetWord() << " ";
		}
	}

	cout << endl;
}

void FillWords(Word * words, int count)
{
	for (int i = 0; i < count; i++)
	{
		words[i].EnterWord();
	}
}

void DisplayAlphabeticalWords(Word * words, int count)
{
	system("cls");

	BubbleSortWords(words, count);

	cout << endl << "Words in Alphabetical order: ";
	for (int i = 0; i < count; i++)
	{
		cout << words[i].GetWord() << " ";
	}

	cout << endl;
}

bool IsStringLarger(char * str1, char * str2)
{
	int i = 0;
	while (str1[i] != '\0' || str2[i] != '\0')
	{
		if (tolower(str1[i]) < tolower(str2[i]))
		{
			return true;
		}

		if (tolower(str1[i]) > tolower(str2[i]))
		{
			return false;
		}

		i++;
	}

	return false;
}

void BubbleSortWords(Word * words, int count)
{
	bool swaped = true;

	while (swaped)
	{
		swaped = false;

		for (int i = 1; i < count; i++)
		{
			if (IsStringLarger(words[i].GetWord(), words[i - 1].GetWord()))
			{
				swap(words[i], words[i - 1]);
				swaped = true;
			}
		}
	}
}

void DisplayWordPages(Word * words,int count)
{
	system("cls");

	cout << endl << "Enter the word of the page you want to find: ";
	char* word = new char[STRING_SIZE];
	cin.ignore(1);
	cin.getline(word, STRING_SIZE);

	for (int i = 0; i < count; i++)
	{
		if (IsEqual(words[i].GetWord(), word))
		{
			cout << "Pages with '" << word << "': ";
			for (int j = 0; j < words[i].GetPagesCount(); j++)
			{
				cout << words[i].GetWordPages()[j] << " ";
			}
		}
	}
	cout << endl;
}

bool IsEqual(char * str1, char * str2)
{
	if (strlen(str1) != strlen(str2))
	{
		return false;
	}

	for (int i = 0; i < strlen(str1); i++)
	{
		if (str1[i] != str2[i])
		{
			return false;
		}
	}

	return true;
}
