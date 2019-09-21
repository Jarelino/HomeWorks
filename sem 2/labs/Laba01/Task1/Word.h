const int STRING_SIZE = 256;

#include <iostream>
using namespace std;

class Word
{
public:
	Word();
	~Word();

	void EnterWord();

	char* GetWord();
	int* GetWordPages();
	int GetPagesCount();
private:
	char* word;
	int* wordPages;
	int pagesCount;

	void SetWord(char*);
	void SetWordPages(int*);
	void SetPagesCount(int);

};

