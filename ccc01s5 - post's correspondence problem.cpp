/*
PEG
Date Started: 2017/08/30, Date Finished: 2017/09/04
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int m, n;
vector<string> a, b;
string l;
bool yes = false;

void recurse(int it, string k1, string k2, int cnt, vector<int> ans)
{
	if (!yes)
	{
		ans.push_back(it + 1);

		if (k1 != "" && k1 == k2)
		{
			cout << cnt << "\n";
			for (int i = 0; i < cnt; i++)
			{
				cout << ans[i] << "\n";
			}

			yes = true;
			return;
		}

		if (k1.size() >= k2.size())
		{
			if (k1.find(k2) == string::npos)
				return;
		}
		else if (k2.size() < k1.size())
		{
			if (k2.find(k1) == string::npos)
				return;
		}

		if (cnt == m)
		{
			ans.erase(ans.end() - 1);
			return;
		}

		for (int j = 0; j < n; j++)
		{
			recurse(j, k1 + a[it], k2 + b[it], cnt + 1, ans);
		}
	}
}

int main()
{
	cin >> m >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> l;
		a.push_back(l);
	}

	for (int i = 0; i < n; i++)
	{
		cin >> l;
		b.push_back(l);
	}

	for (int i = 0; i < n; i++)
	{
		if (!yes)
			recurse(i, "", "", 0, { });
	}

	if (!yes)
		cout << "No solution.\n";

	system("pause");
}