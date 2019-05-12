/*
PEG
Date Started: 2017/07/06, Date Finished: 2017/07/06
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int t, c, m;
	cin >> t;
	cin >> c;

	vector<int> time(0);
	for (int i = 0; i < c; i++)
	{
		cin >> m;
		time.push_back(m);
	}

	sort(time.begin(), time.end());

	int sum = 0;
	int p = 0;
	while (sum <= t && p < c)
	{
		sum += time[p];
		if (sum <= t)
		{
			p++;
		}
	}

	cout << p << "\n";

	system("pause");
}
