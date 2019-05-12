/*
PEG
Date Started: 2017/07/15, Date Finished: 2017/07/16
*/

#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n, arm;
	cin >> n;
	bool twin;

	set<vector<int>> all;

	for (int i = 0; i < n; i++)
	{
		twin = false;
		vector<int> flake;

		for (int i1 = 0; i1 < 6; i1++)
		{
			cin >> arm;
			flake.push_back(arm);
		}

		sort(flake.begin(), flake.end());
		
		int allLen = all.size();
		all.insert(flake);

		if (all.size() == allLen)
		{
			twin = true;
			cout << "Twin snowflakes found.\n";
			break;
		}
	}
	
	if (twin == false)
	{
		cout << "No two snowflakes are alike.\n";
	}

	system("pause");
}