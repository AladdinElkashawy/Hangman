#include <iostream>
#include <fstream>
#include <string>
#include<vector>
#include "hangman.cpp"
#include <fstream>
#include <stdlib.h>
#include<iomanip>
using namespace std;

int main()
{


	bool exit = false;
	while (!exit)
	{
		int choice;
		cout << "1- Start game" << endl;
		cout << "2- How to play" << endl;
		cout << "3- Score" << endl;
		cout << "4- Credit" << endl;
		cout << "5- Exit" << endl;

		cout << "please Enter your choice ?\n";
		cin >> choice;
		switch (choice)
		{

		case 1:
			g.game_continue();
			break;
		case 2:
			cout << " You should read the description of the word then you will try to enter the correct word " << endl;
			cout << " & you have 3 trials if you you enter the correct word your score will be incremented " << endl;
			cout << "else you fail in the 3 trials a hint will appear to you telling you the number of characters in the word " << endl;
			cout << " & you will enter character by character & also you have only 3 trials if you win your score will be incremented else you fail " << endl;
			///how to play
			break;
		case 3:
			Scores.open("Scores.txt", ios::in);
			cout << Scores.rdbuf();
			Scores.close();
			break;
		case 4:
			cout << " This project is done by : " << endl;
			cout << "Ahmed Yasser " << endl;
			cout << "Alaaeldin Abderhman" << endl;
			cout << "Goher Assem" << endl;
			cout << "Hossam Bassem" << endl;
			cout << "Mohammad Tarek" << endl;
			cout << "Nour Khaild" << endl;
			/////Credit
			break;
		case 5:
			///Exit
			exit = true;
			break;
		default:
			break;
		}

	}

	return 0;
}