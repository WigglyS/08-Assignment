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
//
string checkinput(string guess, string keyword, string output);
// fuction that determines what happes as the turns increase
int turnevent(int turns);



vector<string> inventory;
int turnCount = 0;
bool tankLoaded = false;

void main()
{
	//Story setup ===================================================
	cout << "You wake up, its freezing, looking around it appears you are in a metal box."endl;
	cout << "before you remember it is actually a tank, all of you comrads are dead or unconcious"endl;
	cout << "Around you there is a radio station, in the back the tank shells are stored,"endl;
	cout << "in the front there are the driving controls and a machine gun, there are multiple vision slits and"endl;
	cout << "at the top the main hatch is closed."endl;
	cout << "You hear a rumbling coming from outside the tank."endl;
	
	//main input section =============================================
	do {
		int danger = turnevent(turnCount);

		cout << "What do you do?\n";
		cin >> guess;

		checkinput(guess, "run", "you run");


		turnCount++;
	} while ((turnCount =< 8));

	
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
