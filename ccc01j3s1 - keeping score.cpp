/*
PEG
Date Started: 2017/07/07, Date Finished: 2017/07/07
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int point(char card, int sum)
{
	if (card == 'J')
	{
		sum += 1;
	}
	else if (card == 'Q')
	{
		sum += 2;
	}
	else if (card == 'K')
	{
		sum += 3;
	}
	else if (card == 'A')
	{
		sum += 4;
	}

	return sum;
}

int ton(int length, int sum)
{
	if (length < 3)
	{
		sum += 3 - length;
	}

	return sum;
}

int main()
{
	string deck;
	cin >> deck;

	char suit;
	int len = deck.length();

	vector<char> club(0);
	vector<char> diamond(0);
	vector<char> heart(0);
	vector<char> spade(0);

	int c = 0;
	int d = 0;
	int h = 0;
	int s = 0;
	for (int i = 0; i < len; i++)
	{
		if (deck[i] == 'C' || deck[i] == 'D' || deck[i] == 'H' || deck[i] == 'S')
		{
			if (deck[i] == 'C')
			{
				suit = 'C';
			}
			else if (deck[i] == 'D')
			{
				suit = 'D';
			}
			else if (deck[i] == 'H')
			{
				suit = 'H';
			}
			else if (deck[i] == 'S')
			{
				suit = 'S';
			}
		}
		else
		{
			if (suit == 'C')
			{
				club.push_back(deck[i]);
				c = point(deck[i], c);
			}
			else if (suit == 'D')
			{
				diamond.push_back(deck[i]);
				d = point(deck[i], d);
			}
			else if (suit == 'H')
			{
				heart.push_back(deck[i]);
				h = point(deck[i], h);
			}
			else if (suit == 'S')
			{
				spade.push_back(deck[i]);
				s = point(deck[i], s);
			}
		}
	}

	cout << "Cards Dealt Points\n";

	cout << "Clubs ";
	int lenC = club.size();
	c = ton(lenC, c);
	for(int i1 = 0; i1 < lenC; i1++)
	{
		cout << club[i1] << " ";
	}
	cout << c << "\n";

	cout << "Diamonds ";
	int lenD = diamond.size();
	d = ton(lenD, d);
	for (int i2 = 0; i2 < lenD; i2++)
	{
		cout << diamond[i2] << " ";
	}
	cout << d << "\n";

	cout << "Hearts ";
	int lenH = heart.size();
	h = ton(lenH, h);
	for (int i3 = 0; i3 < lenH; i3++)
	{
		cout << heart[i3] << " ";
	}
	cout << h << "\n";

	cout << "Spades ";
	int lenS = spade.size();
	s = ton(lenS, s);
	for (int i4 = 0; i4 < lenS; i4++)
	{
		cout << spade[i4] << " ";
	}
	cout << s << "\n";

	cout << "Total " << c + d + h + s << "\n";

	system("pause");
}
