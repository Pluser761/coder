#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class coder
{
private:
	char square[5][5] = {
		{ 'a', 'b', 'c', 'd', 'e'},
		{ 'f', 'g', 'h', 'i', 'k'},
		{ 'l', 'm', 'n', 'o', 'p'},
		{ 'q', 'r', 's', 't', 'u'},
		{ 'v', 'w', 'x', 'y', 'z'}
	};
	string square_e(string message)
	{
		string result = "";
		for (int k = 0; k < message.length(); k++)
			for (int i = 0; i < 5; i++)
				for (int j = 0; j < 5; j++)
					if (message[k] == square[i][j])
						result += to_string(i + 1) + to_string(j + 1);
		return result;
	}
	string square_d(string coded)
	{
		vector<int> arr;
		int num = 0;
		for (int i = 0; i + 1 < coded.length(); i = i + 2)
		{
			num += coded[i] - '0';
			num *= 10;
			num += coded[i + 1] - '0';
			arr.push_back(num);
			num = 0;
		}
		string result = "";
		for (int i = 0; i < arr.size(); ++i)
			result += square[arr[i] / 10 - 1][arr[i] % 10 - 1];
		return result;
	}

	string haph_e(string message)
	{
		string result = "";



		return result;
	}
	string haph_d(string coded)
	{
		string result = "";



		return result;
	}

	char alpha[10][10] = {
		{ 'a', 'b', 'c', 'd', 'e',   'f', 'g', 'h', 'i', 'k' },
		{ 'f', 'g', 'h', 'i', 'k',   'a', 'b', 'c', 'd', 'e' },
		{ 'l', 'm', 'n', 'o', 'p',   'v', 'w', 'x', 'y', 'z' },
		{ 'q', 'r', 's', 't', 'u',   'q', 'r', 's', 't', 'u' },
		{ 'v', 'w', 'x', 'y', 'z',   'l', 'm', 'n', 'o', 'p' },

		{ 'q', 'r', 's', 't', 'u',   'a', 'b', 'c', 'd', 'e' },
		{ 'l', 'm', 'n', 'o', 'p',   'f', 'g', 'h', 'i', 'k' },
		{ 'a', 'b', 'c', 'd', 'e',   'l', 'm', 'n', 'o', 'p' },
		{ 'f', 'g', 'h', 'i', 'k',   'q', 'r', 's', 't', 'u' },
		{ 'v', 'w', 'x', 'y', 'z',   'v', 'w', 'x', 'y', 'z' },
	};
	string none_e(string message)
	{
		string result = "";
		for (int k = 0; k < message.length(); k++)
		{
			int i1, j1;
			for (int i = 0; i < 5; i++)
				for (int j = 0; j < 5; j++)
					if (alpha[i][j] == message[k])
					{
						i1 = i;
						j1 = j;
					}

			int i2, j2;
			for (int i = 5; i < 10; i++)
				for (int j = 5; j < 10; j++)
					if (alpha[i][j] == message[k])
					{
						i2 = i;
						j2 = j;
					}

			result += alpha[i2][j1];
			result += alpha[i1][j2];
		}
		return result;
	}
	string none_d(string coded)
	{
		string result = "";
		int i1, j1, i2, j2 = -1;
		for (int k = 0; k < coded.length(); k++)
		{
			if (k % 2 == 0)
			{
				if (j2 != -1)
				{
					if (alpha[i2][j1] == alpha[i1][j2])
						result += alpha[i2][j1];
					j2 != -1;
				}

				for (int i = 5; i < 10; i++)
					for (int j = 0; j < 5; j++)
						if (alpha[i][j] == coded[k])
						{
							i1 = i;
							j1 = j;
						}
			}
			else
			{
				for (int i = 0; i < 5; i++)
					for (int j = 5; j < 10; j++)
						if (alpha[i][j] == coded[k])
						{
							i2 = i;
							j2 = j;
						}
			}
		}
		result += alpha[i2][j1];
		return result;
	}

	string modes[3] = {
		"Haphman",
		"Square",
		"None"
	};

public:
	string(coder::*encode)(string);
	string(coder::*decode)(string);

	coder()
	{
		encode = &coder::haph_e;
		decode = &coder::haph_d;
	}
	~coder() {}

	void mode_set()
	{
		for (int i = 0; i < 3; i++)
			cout << i << " - " << modes[i] << endl;
		cout << "Enter mode number: ";
		int mode;
		cin >> mode;
		switch (mode)
		{
		case 0:
			encode = &coder::haph_e;
			decode = &coder::haph_d;
			break;
		case 1:
			encode = &coder::square_e;
			decode = &coder::square_d;
			break;
		case 2:
			encode = &coder::none_e;
			decode = &coder::none_d;
			break;
		default:
			cout << "No such number" << endl;
			break;
		}
	}
};