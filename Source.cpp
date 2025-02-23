#include <iostream>
#include "coder.h"
#include "foo.h"

#include <map>
#include <algorithm>

using namespace std;

struct node
{
	node *left = nullptr;
	node *right = nullptr;

	int priority = 0;
	char letter = '*';

	int get_priority(int res) const
	{
		if (left != nullptr) res = left->get_priority(res);
		if (right != nullptr) res = right->get_priority(res);
		res += priority;
		return res;
	}

	node()
	{

	}
	node(char letter)
	{
		this->letter = letter;
		this->priority = 1;
	}
};

void encoder_filler(map<char, string> &encoder, node *current, string code)
{
	if (current->letter != '*')
		encoder[current->letter] = code;
	else
	{
		encoder_filler(encoder, current->left, code + '0');
		encoder_filler(encoder, current->right, code + '1');
	}
}

string encode(string message)
{
	string result = "";

	/*
	map<char, int, greater<int>> alpha;

	for (int i = 0; i < message.length(); i++)
		if (auto it = alpha.find(message[i]) == alpha.end())
			alpha[message[i]] = 1;
		else
			alpha[message[i]]++;
	*/
	vector<node*> tree;

	for (int i = 0; i < message.length(); i++)
	{
		auto it = find_if(tree.begin(), tree.end(), [&letter = message[i]](const node *current) -> bool
		{
			return (*current).letter == letter;
		});
		if (it != tree.end())
			((*it)->priority)++;
		else
			tree.push_back(new node(message[i]));
	}

	for (int i = 0; i < tree.size(); i++)
		cout << tree.at(i)->letter << " = " << tree.at(i)->priority << endl;

	while (tree.size() != 1)
	{
		sort(tree.begin(), tree.end(), [](const node *a, const node *b) -> bool
		{
			return (a->get_priority)(0) < (b->get_priority)(0);
		});
		node *current = new node();
		current->left = tree.at(0);
		current->right = tree.at(1);
		tree.erase(tree.begin());
		tree.erase(tree.begin());
		tree.push_back(current);
	}

	map<char, string> encoder;

	encoder_filler(encoder, tree[0], "");

	for (int i = 0; i < message.length(); i++)
		result += encoder[message[i]];

	//cout << "good";
	return result;
}

string decode(string coded)
{
	string result;



	return result;
}


int main()
{


	cout << encode("beep boop beer!") << endl;
	/*
	string tmp = "string";
	
	coder code;
	code.mode_set();
	tmp = (code.*(code.encode))(tmp);
	cout << tmp << endl;
	tmp = (code.*(code.decode))(tmp);
	cout << tmp << endl;
	*/

	system("pause");
	return 0;
}