/*
PEG
Date Started: 2017/08/30, Date Finished: 2017/09/04
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int w, d, di, v, vi, len;
vector<int> digs;
bool yes;

void recurse(int num, int cnt)
{
	if (cnt == w || num < 0)
	{
		if (find(digs.begin(), digs.end(), num) != digs.end())
			yes = true;

		return;
	}

	for (int k = 0; k < len; k++)
	{
		if (digs[k] != 0 && num % digs[k] == 0 && !yes)
		{
			recurse(num /= digs[k], cnt + 1);
			num *= digs[k];
		}
	}

	for (int j = 0; j < len; j++)
	{
		if (!yes)
		{
			recurse(num -= digs[j], cnt + 1);
			num += digs[j];
		}
	}
}

int main()
{
	cin >> w >> d;

	for (int i = 0; i < d; i++)
	{
		cin >> di;
		digs.push_back(di);
	}

	sort(digs.begin(), digs.end());
	len = digs.size();

	cin >> v;

	for (int i = 0; i < v; i++)
	{
		yes = false;

		cin >> vi;
		recurse(vi, 0);

		if (yes)
			cout << "Y\n";
		else
			cout << "N\n";
	}

	system("pause");
}