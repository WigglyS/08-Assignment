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
string checktextinput(string guess, string keyword, string output);
// fuction that determines what happes as the turns increase
int turnevent(int turns);
void pickUp(string guess);


vector<string> inventory;
int turnCount = 0;
bool tankLoaded = false;
bool hatchopen = false;
bool tankEscape = false;

void main()
{
	//Story setup ===================================================
	cout << "You wake up, its freezing, looking around it appears you are in a metal box."endl;
	cout << "before you remember it is actually a tank, all of you comrads are dead or unconcious"endl;
	cout << "Around you you notice one of you comrads have a gun, there is a radio station, in the back the tank shells are stored,"endl;
	cout << "in the front there are the driving controls and a machine gun, there are multiple vision slits and"endl;
	cout << "at the top the main hatch is closed."endl;
	cout << "You hear a rumbling coming from outside the tank."endl;
	
	//main input section =============================================
	do {
		int danger = turnevent(turnCount);

		cout << "What do you do?\n";
		cin >> guess;

		pickUp();
		checktextinput(guess, "look outside", "the bright white snow nearly blind you,off in the distance you see many tanks moving tward you");



		turnCount++;
	} while ((turnCount =< 8)||(tankEscape == false));

	
    return;
}
void pickUp(string guess)
{
	if ((guess == "pick up gun")&&(inventory.find(guess)== string::npos))
	{
		inventory.push_back("gun");
		cout<< "you pick the gun"
	}
	else if (inventory.find(guess) != string::npos) 
	{
		"You already picked up the gun!";
	}
	if ((guess == "pick up tank shell") && (inventory.find(guess) == string::npos))
	{
		cout << "you pick up a tank shell";
		inventory.push_back("tank shell");
	}
	else if (inventory.find(guess) != string::npos)
	{
		"You can hold more that 1 tank shell";
	}
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
