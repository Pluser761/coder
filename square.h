#pragma once
#include <string>
#include <iostream>

using namespace std;

class square
{
private:
	char ch[5][5] = {
		{ 'A', 'B', 'C', 'D', 'E'},
		{ 'F', 'G', 'H', 'I', 'K'},
		{ 'L', 'M', 'N', 'O', 'P'},
		{ 'Q', 'R', 'S', 'T', 'U'},
		{ 'V', 'W', 'X', 'Y', 'Z'}
	};

	int mode = NULL;
	string modes[3] = {
		"Haphman",
		"Square",
		"None"
	};
public:
	square()
	{
		this->mode = 0;
	}
	square(string mode)
	{
		for (int i = 0; i < 3; i++)
			if (modes[i] == mode) this->mode = i;
		if (this->mode == NULL)
		{
			cout << "No such mode, Haphman set" << endl;
			this->mode = 0;
		}
	}
	~square(){}
};