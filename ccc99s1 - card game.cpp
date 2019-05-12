/*
PEG
Date Started: 2017/07/07, Date Finished: 2017/07/07
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool face(int j, int p, vector<string> deck)
{
	bool add = true;
	for (int k = j; k < j + p; k++)
	{
		if (deck[k] == "ace" || deck[k] == "king" || deck[k] == "queen" || deck[k] == "jack")
		{
			add = false;
		}
	}

	return add;
}

int main()
{
	vector<int> score(0);
	score.push_back(0);
	score.push_back(0);

	vector<string> deck(0);
	string card;
	for (int i = 0; i < 52; i++)
	{
		cin >> card;
		deck.push_back(card);
	}

	for (int j = 0; j < 52; j++)
	{
		int p = 0;
		bool add = false;
		if (deck[j] == "ace" && j <= 47)
		{
			p = 4;
			add = face(j + 1, p, deck);
		}
		else if (deck[j] == "king" && j <= 48)
		{
			p = 3;
			add = face(j + 1, p, deck);
		}
		else if (deck[j] == "queen" && j <= 49)
		{
			p = 2;
			add = face(j + 1, p, deck);
		}
		else if (deck[j] == "jack" && j <= 50)
		{
			p = 1;
			add = face(j + 1, p, deck);
		}

		char player;
		if (j % 2 == 0)
		{
			player = 'A';
		}
		else if (j % 2 == 1)
		{
			player = 'B';
		}

		if (add == true)
		{
			score[j % 2] += p;
			cout << "Player " << player << " scores " << p << " point(s).\n";
		}
	}

	cout << "Player A: " << score[0] << " point(s).\n";
	cout << "Player B: " << score[1] << " point(s).\n";
	system("pause");
}
