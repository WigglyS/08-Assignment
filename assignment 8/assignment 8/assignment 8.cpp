// Assignment8.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include "string"
#include "ctime"
#include "vector"


using namespace std;



int inputhandler(string guess, int danger);
// fuction that determines what happes as the turns increase
int turnevent(int turns);
// function for adding items to the inventory
int pickUp(string guess);

vector<string> inventory{ "no gun", "no tank shells" };
vector<string>::iterator myIterator;
int turnCount = 1;
bool tankLoaded = false;
bool hatchopen = false;
bool tankEscape = false;
int valid;

void main()
{
	//Story setup ===================================================
	cout << "You wake up, its freezing, looking around it appears you are in a metal box." << endl;
	cout << "before you remember it is actually a tank, all of you comrads are dead or unconcious" << endl;
	cout << "Around you you notice one of you comrads have a gun, there is a radio station, in the back the tank shells are stored," << endl;
	cout << "in the front there are the driving controls and a machine gun, there are multiple vision slits and" << endl;
	cout << "at the top the main hatch is closed." << endl;
	cout << "You hear a rumbling coming from outside the tank." << endl;

	//main input section =============================================
	do {
		cout << turnCount << endl;
		int danger = turnevent(turnCount);
		string guess;

		cout << "What do you do?\n";
		//takes the whole line as a imput
		getline (cin, guess);
	
		//function to handle all the inputs returns if it is a valid move
		valid = inputhandler(guess, danger);

		//checks to see if the user actually made a valid move
		if (valid = 1)
		{
			turnCount++;
		}

	} while ((turnCount <= 8) && (tankEscape == false));

	if (tankEscape == true)
	{
		cout << "you make it back to your comrads saftley and live to fight another day!\n";
	}
	if (tankEscape == false)
	{
		cout << "\n";
	}

	system("pause");

	return;
}




int inputhandler(string guess, int danger)
{

	int valid = 0;
	valid = pickUp(guess);

	//ifs for all the text options
	if (guess == "look outside")
	{
		cout << "when you look out you see lots of snow and in the distance a large number of enemy tanks moving tward you\n";
		valid = 1;
	}
	if (guess == "open hatch" && (hatchopen == false))
	{
		cout << "you open the main hatch\n";
		hatchopen = true;
		valid = 1;
	}
	else if (guess == "open hatch" && (hatchopen == true))
	{
		cout << "you already opened the hatch\n";
		valid = 0;
	}

	if (guess == "load the tank" && (tankLoaded == false) && (inventory[1] == "tank shell"))
	{
		cout << "you load the tank\n";
		tankLoaded = true;
		valid = 1;
	}
	else if (guess == "load the tank" && (tankLoaded == false) && (inventory[1] == "no tank shells"))
	{
		cout << "you dont have a tank shell to load it with\n";
		valid = 1;
	}
	else if (guess == "load the tank" && (tankLoaded == true) && (inventory[1] == "tank shell"))
	{
		cout << "you already loaded it\n";
		valid = 0;
	}

	if (guess == "fire the tank"&& tankLoaded == true)
	{
		cout << "you pull the trigger on the tanks gun and hear a loud bang as it fires, but you don't hit anything\n";
		tankLoaded = false;
		valid = 1;
	}
	else if (guess == "fire the tank" && (tankLoaded == false))
	{
		cout << "the tank is not loaded\n";
		valid = 1;
	}

	if (guess == "exit tank" && (hatchopen == true))
	{
		if (danger == 0)
		{
			cout << "you escape the tank and run to saftey\n";
			tankEscape = true;
		}
		else if (danger == 1)
		{
			cout << "you escape the tank as you are running to saftey you hear the tank explode behind you\n";
			tankEscape = true;
		}
		else if (danger == 2)
		{
			cout << "as you are getting out of the hatch an enemy tank shell hits you and you die\n";
		}
		valid = 1;
	}

	return valid;
}





int pickUp(string guess)
{
	int valid = 0;
	if ((guess == "pick up gun") && (inventory[0] != guess))
	{
		inventory[0] = "gun";
		cout << "you pick the gun\n";
		valid = 1;

	}
	else if (inventory[0] == (guess))
	{
		"You already picked up the gun!\n";
	}
	if ((guess == "pick up tank shell") && (inventory[1] != guess))
	{
		cout << "you pick up a tank shell\n";
		inventory[1] = "tank shell";
		valid = 1;
	}
	else if (inventory[1] == guess)
	{
		"You can hold more that 1 tank shell\n";
	}
	return valid;
}


int turnevent(int turns)
{
	int danger = 0;
	if (turns >= 5)
	{
		cout << "The rumbling is getting louder\n";
		danger = 1;
	}
	if (turns >= 8)
	{
		cout << "You hear and explosion close by\n";
		danger = 2;
	}
	return danger;
}

