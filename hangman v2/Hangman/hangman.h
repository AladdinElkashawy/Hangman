#pragma once
#include <string>
#include <vector>
using namespace std;
class player {
public:
	string name;
	int score;
}n;
class word
{
public:
	string name;
	string meaning;
	string category;
};

class hangman
{
private:

	int wtry;
	int score;
	string cword;
	string wtmp;
	string cmean;
	string hiden_word;


public:
	hangman();
	vector<word> movies;
	vector<word> songs;
	void load();
	void random_word(int s);
	void game_continue();
	bool checkwin(string s);
	bool checkchar(char s);
	void file_Score();
}g;