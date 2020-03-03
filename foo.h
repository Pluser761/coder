#pragma once
#include <iostream>
#include <string>

using namespace std;

char alpha[10][10] = {
		{ 'A', 'B', 'C', 'D', 'E',   'F', 'G', 'H', 'I', 'K' },
		{ 'F', 'G', 'H', 'I', 'K',   'A', 'B', 'C', 'D', 'E' },
		{ 'L', 'M', 'N', 'O', 'P',   'V', 'W', 'X', 'Y', 'Z' },
		{ 'Q', 'R', 'S', 'T', 'U',   'Q', 'R', 'S', 'T', 'U' },
		{ 'V', 'W', 'X', 'Y', 'Z',   'L', 'M', 'N', 'O', 'P' },

		{ 'Q', 'R', 'S', 'T', 'U',   'A', 'B', 'C', 'D', 'E' },
		{ 'L', 'M', 'N', 'O', 'P',   'F', 'G', 'H', 'I', 'K' },
		{ 'A', 'B', 'C', 'D', 'E',   'L', 'M', 'N', 'O', 'P' },
		{ 'F', 'G', 'H', 'I', 'K',   'Q', 'R', 'S', 'T', 'U' },
		{ 'V', 'W', 'X', 'Y', 'Z',   'V', 'W', 'X', 'Y', 'Z' },
};

class foo
{
private:
	string mode_1(string data)
	{
		cout << "mode_1" << endl;
		return "";
	}
	string mode_2(string data)
	{
		cout << "mode_2" << endl;
		return "";
	}

	string(foo::*work)(string);
public:

	string run()
	{
		return (this->*work)("HELL");
	}

	foo()
	{
		work = &foo::mode_2;
	}
	~foo()
	{

	}
};