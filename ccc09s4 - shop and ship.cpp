#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <algorithm>
using namespace std;
#pragma warning(disable:4996)

int n, t, k, d, ans = 2000000000, check[5002], cost[5002], fin[5002];
vector<pair<int, int>> node[5002];
priority_queue<pair<int, int>> pq;

int main() {
	scanf("%d%d", &n, &t);

	for (int i = 1; i <= n; i++) {
		cost[i] = 2000000000;
		fin[i] = 2000000000;
	}

	for (int i = 0, x, y, c; i < t; i++) {
		scanf("%d%d%d", &x, &y, &c);
		node[x].push_back({ y,c });
		node[y].push_back({ x,c });
	}
    
	scanf("%d", &k);

	for (int i = 0, x, p; i < k; i++) {
		scanf("%d%d", &x, &p);
		fin[x] = p;
	}

	scanf("%d", &d);

	pq.push({ 0,d });
	cost[d] = 0;

	while (!pq.empty()) {
		int c = -pq.top().first, cur = pq.top().second;
		pq.pop();

		if (!check[cur]) {
			cost[cur] = c;
			check[cur] = 1;

			int siz = node[cur].size();
			for (int i = 0; i < siz; i++) {
				if (cost[cur] + node[cur][i].second < cost[node[cur][i].first]) {
					pq.push({ -(c + node[cur][i].second),node[cur][i].first });
				}
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		if (fin[i] != 2000000000) {
			ans = min(ans, cost[i] + fin[i]);
		}
	}

	printf("%d\n", ans);

    system("pause");
}
