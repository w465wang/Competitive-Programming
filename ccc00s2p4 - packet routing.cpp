/*
PEG
Date Started: 2017/10/27, Date Finished: 2017/10/27
*/

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
#pragma warning(disable:4996)

int n, w, p, d, trav, check[101][101];
map<int, vector<pair<int, int>>> node;

void dfs(int pre, int cur, int time) {
	if (pre != 0) {
		if (check[pre][cur]) {
			return;
		}
		//cout << pre << " " << cur << " " << time << "\n";
		if (cur == d) {
			trav = min(trav, time);

			return;
		}
	}

	int siz = node[cur].size();
	for (int i = 0; i < siz; i++) {
		check[pre][cur] = 1;
		check[cur][pre] = 1;
		dfs(cur, node[cur][i].first, time + node[cur][i].second);
		check[pre][cur] = 0;
		check[cur][pre] = 0;
	}
}

int main() {
	scanf("%d%d%d", &n, &w, &p);

	for (int i = 0, x, y, t; i < w; i++) {
		scanf("%d%d%d", &x, &y, &t);

		if (node.find(x) == node.end()) {
			node[x] = { { y,t } };
		} else {
			node[x].push_back({ y,t });
		}

		if (node.find(y) == node.end()) {
			node[y] = { { x,t } };
		} else {
			node[y].push_back({ x,t });
		}
	}

	for (int i = 0, s; i < p; i++) {
		trav = 2000000000;
		scanf("%d%d", &s, &d);
		dfs(0, s, 0);
		printf("%d\n", trav);
	}

	system("pause");
}