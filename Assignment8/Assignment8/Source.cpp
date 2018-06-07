#include "stdafx.h"
#include "iostream"
#include "string"
#include "ctime"
#include "vector"

using namespace std;

string checkinput(string guess, string keyword, string output)
{
	if (guess == keyword)
	{
		cout << output;
	}
	return output;
}