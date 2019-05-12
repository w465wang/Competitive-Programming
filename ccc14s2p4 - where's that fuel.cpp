/*
Peg
Date Started: 2017/07/31, Date Finished: 2017/07/31
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n, p, a, b;
	cin >> n >> p;

	vector<pair<int, int>> planets;
	int count = 1;
	int fuel = 0;

	for (int i = 1; i <= n; i++)
	{
		scanf_s("%d", &a);
		scanf_s("%d", &b);

		if (i == p)
		{
			fuel += a;
		}
		else if (a - b >= 0)
		{
			planets.push_back({ b,a - b });
		}
	}

	sort(planets.begin(), planets.end());
	int len = planets.size();
	for (int j = 0; j < len; j++)
	{
		if (planets[j].first <= fuel)
		{
			count++;
			fuel += planets[j].second;
		}
	}

	cout << fuel << "\n";
	cout << count << "\n";

	system("pause");
}
