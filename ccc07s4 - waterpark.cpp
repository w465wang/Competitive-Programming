/*
PEG
Date Started: 2017/09/12, Date Finished: 2017/09/17
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, x, y, a[10000] = {};
vector<pair<int, int>> conn;

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	cin >> x >> y;

	while (x != 0)
	{
		conn.push_back({ x,y });

		cin >> x >> y;
	}

	sort(conn.begin(), conn.end());

	int len = conn.size();
	for (int i = 0; i < len; i++)
	{
		if (conn[i].first == 1)
			a[conn[i].second] = 1;
		else
			a[conn[i].second] += a[conn[i].first];
	}

	cout << a[n] << "\n";

	system("pause");
}


