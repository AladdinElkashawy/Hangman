#include <iostream>
#include <fstream>
#include <string>
#include<vector>
#include "hangman.h"
using namespace std;

void main()
{
	hangman g1;
	bool exit = false;
	while (!exit)
	{
		int chose;
		cout << "enter your chose ?\n";
		cin >> chose;
		switch (chose)
		{

		case '1':
			g1.game_continue();
			break;
		case '2':
			///how to play
			break;
		case '3':
			///score
			break;
		case '4':
			/////cridet
			break;
		case '5':
			///Exit
			exit = true;
			break;
		default:
			break;
		}

	}
}