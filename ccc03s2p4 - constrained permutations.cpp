/*
PEG
Date Started: 2017/09/02, Date Finished: 2017/09/04
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n, k, x, y;
	cin >> n >> k;

	vector<int> perm;
	vector<vector<int>> cons;

	for (int i = 1; i <= n; i++)
	{
		perm.push_back(i);
	}

	for (int i = 0; i < k; i++)
	{
		cin >> x >> y;
		cons.push_back({ x,y });
	}

	int cnt = 0;
	bool yes = true;
	for (int i = 0; i < k; i++)
	{
		int it1 = find(perm.begin(), perm.end(), cons[i][0]) - perm.begin();
		int it2 = find(perm.begin(), perm.end(), cons[i][1]) - perm.begin();

		if (it1 > it2)
			yes = false;
	}

	if (yes)
		cnt++;

	while (next_permutation(perm.begin(), perm.end()))
	{
		bool yes = true;
		for (int i = 0; i < k; i++)
		{
			int it1 = find(perm.begin(), perm.end(), cons[i][0]) - perm.begin();
			int it2 = find(perm.begin(), perm.end(), cons[i][1]) - perm.begin();

			if (it1 > it2)
				yes = false;
		}

		if (yes)
			cnt++;
	}

	cout << cnt << "\n";

	system("pause");
}