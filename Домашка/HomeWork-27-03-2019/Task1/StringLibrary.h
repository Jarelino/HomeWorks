#pragma once



namespace StringExtension
{
	char* inputString();

	int stringLength(char*);
	
	void displayString(char*);

	char** obtainWords(char *, int & );

	void displayWords(char**, int);
}