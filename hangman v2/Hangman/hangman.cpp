#include "hangman.h"
#include <vector>
#include<string>
#include <iostream>
#include <fstream>
#include <ctime>
#include <stdlib.h>
using namespace std;

hangman::hangman() {
	load();
}

fstream Scores;

void hangman::load()
{
	fstream file;
	word temp;
	file.open("m.txt");
	while (true)
	{
		getline(file, temp.name);
		if (temp.name == "pause")
			break;
		getline(file, temp.meaning);
		if (temp.meaning == "pause")
			break;
		getline(file, temp.category);
		if (temp.category == "pause")
			break;

		if (temp.category == "movie")
		{
			movies.push_back(temp);
		}
		else if (temp.category == "song")
		{
			songs.push_back(temp);
		}
	}

	file.close();
}


bool hangman::checkwin(string s) {

	if (s == cword)
		return true;
	else
		return false;
}

bool hangman::checkchar(char s) {
	bool flag = false;

	for (int i = 0; i < cword.size(); i++) {
		if (s == wtmp[i] || s - 32 == wtmp[i] || s + 32 == wtmp[i]) {
			hiden_word[i] = s;
			wtmp[i] = '0';
			flag = true;
		}
	}
	return flag;
}


void hangman::random_word(int s)
{
	int numofrand;
	srand(time(0));
	if (s == 1) {
		numofrand = rand() % movies.size();
		cword = movies[numofrand].name;
		cmean = movies[numofrand].meaning;
	}
	else if (s == 2) {
		numofrand = rand() % songs.size();
		cword = songs[numofrand].name;
		cmean = songs[numofrand].meaning;
	}
	wtmp = cword;
	hiden_word = cword;
	for (int i = 0; i < cword.size(); i++)
	{
		hiden_word[i] = '#';
		if (cword[i] == ' ')
			hiden_word[i] = ' ';

	}
	wtry = 0;
}
void hangman::game_continue()
{
	Scores.open("Scores.txt", ios::app);
	cout << "please enter player's name: ";
	cin >> n.name;
	string ans;
	bool resume = true;
	cout << "Enter category?" << endl;
	cout << "1-Movies" << endl;
	cout << "2-Songs" << endl;
	int s;
	cin >> s;
	random_word(s);
	while (resume)
	{
		cout << cmean << endl;



		if (wtry < 3)
		{
			cout << "Enter Word :";
			cin.ignore();
			getline(cin, ans);
			if (checkwin(ans))
			{
				n.score += 10;
				cout << "right answer !" << endl;
				cout << "Do you want continue? enter YES or NO" << endl;
				string yorn;
				cin >> yorn;
				if (yorn == "yes" || yorn == "YES")
					random_word(s);
				else
				{
					file_Score();
					resume = false;
				}

			}
			else
			{
				cout << "try again" << endl;
				wtry++;


			}
		}
		else if (wtry >= 3 && wtry < 6)
		{
			cout << "Enter character :";

			cout << hiden_word << endl;
			cin >> ans;
			while (ans.length() > 1)
			{
				cout << "you should enter only one character" << endl;
				cout << "enter a character : " << endl;
				cin >> ans;

			}

			if (checkchar(ans[0]))
			{
				if (checkwin(hiden_word))
				{
					n.score += 10;
					cout << "right answer !" << endl;
					cout << "Do you want continue? enter YES or NO" << endl;
					string yorn;
					cin >> yorn;
					if (yorn == "yes" || yorn == "YES"|| yorn=="y"||yorn=="Y")
						random_word(s);
					else
					{
						file_Score();
						resume = false;
					}

				}
			}
			else
			{
				wtry++;
				cout << "try again" << endl;
				continue;
			}
		}
		else
		{
			cout << "GAME OVER !" << endl;
			cout << "Your score is " << n.score << endl;
			file_Score();
			resume = false;
		}
	}
	Scores.close();
}

void hangman::file_Score() {

	Scores << "Name\t\tScore\n";

	Scores << n.name << "\t\t"
		<< n.score << endl
		<< "____" << endl;
}