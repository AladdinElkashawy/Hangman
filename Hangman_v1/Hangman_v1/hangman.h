#pragma once
#include <string>
#include <vector>

class hangman
{
private:
	int numofrand;
	int wtry;
	string cword;
	string cmean;
	string hiden_word;

	struct word
	{
		string name;
		string meaning;
	};
	vector<word> data;


public:
	hangman();
	void category();
	void random_word();
	void game_continue();
	bool checkwin(string s);
	bool checkchar(char s);
	~hangman();
};

