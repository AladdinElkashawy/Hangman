#include "hangman.h"
#include <vector>
#include<string>
#include <iostream>
#include <fstream>
using namespace std;


hangman::hangman()
{
	wtry = 0;
}

void hangman::category()
{
	fstream file;
	word temp;
	cout << "enter category?" << endl;
	char ch;
	cin >> ch;
	switch (ch)
	{
	case 'm':
		file.open("m.txt");
		break;

	case's':
		file.open("s.txt");
		break;
	default:
		break;
	}


	while (true)
	{
		getline(file, temp.name);
		if (temp.name == "pause")
		{
			break;
		}
		getline(file, temp.meaning);
		data.push_back(temp);
	}
	file.close();

}
bool hangman::checkwin(string s) {
	string cword;

	if (s == cword)
		return true;
	else
		return false;
}
bool hangman::checkchar(char s) {
	string cword;
	bool flag = false;
	for (int i = 0; i < cword.size; i++) {
		if (s == cword[i]) {
			flag = true;
		}
	}
	return flag;
}

void hangman::random_word()
{
	numofrand = rand() % data.size();
	cword = data[numofrand].name;
	cmean = data[numofrand].meaning;
	for (int i = 0; i < cword.size(); i++)
		hiden_word[i] = '_';
	wtry = 0;
}

void hangman::game_continue()
{
	category();
	string ans;
	bool right_ans, right_character, resume = true;
	random_word();
	while (resume)
	{
		cout << cmean;
		if (wtry < 3)
		{
			cout << "enter word:";
			cin >> ans;
			right_ans = checkwin(ans);
			if (!right_ans)
			{
				wtry++;
			}
			else
			{
				//score++
				cout << "good right answer" << endl;
				cout << "do you want continue?!!enter y!!" << endl;
				char yorn;
				cin >> yorn;
				if (yorn == 'y' || yorn == 'Y')
					random_word();
				else
					resume = false;
			}
		}
		else if (wtry > 3 && wtry < 6)
		{
			cout << hiden_word<<endl;
			cout << "Guess a charcter ?:";
			cin >> ans;
			right_character = checkchar(ans[0]);

			if (!right_character)
			{
				wtry++;
			}
			else
			{
				//diplaychar(ans[0]);
				right_ans = checkwin(hiden_word);
				if (right_ans)
				{
					//score++
					cout << "good right answer" << endl;
					cout << "do you want continue?!!enter y!!" << endl;
					char yorn;
					cin >> yorn;
					if (yorn == 'y' || yorn == 'Y')
						random_word();
					else
						resume = false;
				}
			}
		}
		else
		{
			cout << "Game over" << endl;
			resume = false;
		}

	}
}
hangman::~hangman()
{
}
