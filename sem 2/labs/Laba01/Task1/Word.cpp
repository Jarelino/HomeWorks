#include "Word.h"


Word::Word()
{
	this->word = new char[STRING_SIZE];
	this->pagesCount = 0;
	this->wordPages = new int[0];
}

Word::Word(char* word, int pagesCount, int* wordPages)
{
	this->SetWord(word);
	this->SetPagesCount(pagesCount);
	this->SetWordPages(wordPages);
}


Word::~Word()
{
}

void Word::EnterWord()
{
	cin.ignore(1);
	cout << "Enter word: ";
	cin.getline(this->word, STRING_SIZE);

	cout << "Enter count of pages with this word: ";
	cin >> this->pagesCount;

	this->wordPages = new int[pagesCount];

	cout << "Enter pages with this word: ";
	for (int i = 0; i < this->pagesCount; i++)
	{
		cin >> this->wordPages[i];
	}
}

char * Word::GetWord()
{
	return this->word;
}

int * Word::GetWordPages()
{
	return this->wordPages;
}

int Word::GetPagesCount()
{
	return this->pagesCount;
}

void Word::SetWord(char * newWord)
{
	this->word = newWord;
}

void Word::SetWordPages(int * newWordPages)
{
	this->wordPages = newWordPages;
}

void Word::SetPagesCount(int newPagesCount)
{
	this->pagesCount = newPagesCount;
}
