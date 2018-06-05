// Assignment8.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include "string"
#include "ctime"
#include "vector"


using namespace std;

// declaring the function that returns a character and takes a string
char AskYesNo(string question);

void main()
{
	AskYesNo("would you like to continue ?");
    return;
}

// defining the function that returns a character and takes a string
char AskYesNo(string question)
{
	char again;
	//puts out the question you put in
	cout << question << endl;

	// ask to put in y/n untill you do
	do 
	{

		cout << "(y/n)";
		cin >> again;

	} while ((again != 'y') && (again != 'n'));

	return again;
}
