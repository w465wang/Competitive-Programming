/*
PEG
Date Started: 2017/10/07, Date Finished: 2017/10/14
9/15: 2017/10/09
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#pragma warning(disable:4996)
typedef pair<int, int> pii;

int n, dis[2001], dp[2001], cp[2001];
vector<pair<int, pii>> lst;
vector<pii> point = { { 0,0 } };

int calc(int x1, int y1, int x2, int y2)
{
	return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

int main()
{
	scanf("%d", &n);

	for (int i = 1, x, y; i <= n; i++) {
		scanf("%d%d", &x, &y);

		for (int j = 0; j < i; j++) {
			lst.push_back({ calc(point[j].first, point[j].second, x, y),{ j, i } });
		}

		point.push_back({ x,y });
	}

	sort(lst.begin(), lst.end());

	int len = lst.size();
	for (int i = 0, d, u, v; i < len; i++) {
		d = lst[i].first; u = lst[i].second.first; v = lst[i].second.second;

		if (d > dis[u]) {
			dis[u] = d; cp[u] = dp[u];
		}

		if (d > dis[v]) {
			dis[v] = d; cp[v] = dp[v];
		}

		dp[u] = max(dp[u], cp[v] + 1);

		if (u) {
			dp[v] = max(dp[v], cp[u] + 1);
		}
	}

	printf("%d\n", dp[0]);

	system("pause");
}