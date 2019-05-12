/*
PEG
Date Started: 2017/10/30, Date Finished: 2017/11/06
12/15: 2017/10/30
*/

#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;
#pragma warning(disable:4996)

int n, m, it = 0, check[40001];
vector<int> node[40001], path[2];
bool done = false;

void dfs(int cur) {
	if (check[cur] || done) {
		return;
	}

	if (cur == n) {
		path[it].push_back(cur);
		done = true;
		return;
	}

	check[cur] = 1;
	path[it].push_back(cur);

	int siz = node[cur].size();
	for (int i = 0; i < siz; i++) {
		dfs(node[cur][i]);
	}

	if (!done) {
		path[it].pop_back();
	}
}

int main() {
	scanf("%d%d", &n, &m);

	for (int i = 0, a, b; i < m; i++) {
		scanf("%d%d", &a, &b);
		node[a].push_back(b);
		node[b].push_back(a);
	}

	dfs(1);
	for (int i = 1; i <= n; i++) {
		reverse(node[i].begin(), node[i].end());
	}
	it = 1; done = false; memset(check, 0, sizeof(check));
	dfs(1);

	if (path[0] != path[1]) {
		printf("Yes\n");
	} else {
		printf("No\n");
	}

	system("pause");
}
