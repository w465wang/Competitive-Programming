/*
PEG
Date Started: 2017/09/02, Date Finished: 2017/09/05
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<int> last = { 12, 12, 12, 12, 12, 12, 12, 12, 12 };
string affect;

void recurse(vector<int> dials, int move, vector<int> seq, vector<int> cnt)
{
	if (move != 0)
	{
		if (dials == last)
		{
			seq.erase(seq.end() - 1);

			for (int k = 0; k < seq.size(); k++)
			{
				cout << seq[k] << " ";
			}
			cout << "\n";

			system("pause");
			exit(0);
		}

		if (cnt[move] > 3 || seq.size() > 28)
			return;

		if (move == 1)
			affect = "ABDE";
		else if (move == 2)
			affect = "ABC";
		else if (move == 3)
			affect = "BCEF";
		else if (move == 4)
			affect = "ADG";
		else if (move == 5)
			affect = "BDEFH";
		else if (move == 6)
			affect = "CFI";
		else if (move == 7)
			affect = "DEGH";
		else if (move == 8)
			affect = "GHI";
		else if (move == 9)
			affect = "EFHI";

		for (int j = 0; j < affect.size(); j++)
		{
			int it = affect[j] - 'A';

			dials[it] += 3;
			if (dials[it] > 12)
				dials[it] %= 12;
		}
	}

	for (int j = 1; j <= 9; j++)
	{
		if (j >= move)
		{
			seq.push_back(j);
			cnt[j] += 1;
			recurse(dials, j, seq, cnt);

			seq.erase(seq.end() - 1);
			cnt[j] -= 1;
		}
	}
}

int main()
{
	int c;
	vector<int> dials;

	for (int i = 0; i < 9; i++)
	{
		cin >> c;
		dials.push_back(c);
	}

	recurse(dials, 0, {}, { 0,0,0,0,0,0,0,0,0,0 });
}