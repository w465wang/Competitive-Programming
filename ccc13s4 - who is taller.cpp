/*
PEG
Date Started: 2017/10/27, Date Finished: 2017/10/28
*/

#include <iostream>
#include <map>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;
#pragma warning(disable:4996)

int n, m, e, check[1000001];
vector<int> node[1000001];
bool tall = false;

void dfs(int q) {
	//cout << p << " " << q << "\n";
	if (check[q] || tall) {
		return;
	}

	check[q] = 1;

	if (q == e) {
		tall = true;

		return;
	}

	int siz = node[q].size();
	for (int j = 0; j < siz; j++) {
		dfs(node[q][j]);
	}
}

int main() {
	scanf("%d%d", &n, &m);

	for (int i = 0, x, y; i < m; i++) {
		scanf("%d%d", &x, &y);

		node[x].push_back(y);
	}

	scanf("%d%d", &n, &m);
	e = m;
	dfs(n);

	if (tall) {
		printf("yes\n");
	} else {
		memset(check, 0, sizeof(check));
		e = n;
		dfs(m);

		if (tall) {
			printf("no\n");
		} else {
			printf("unknown\n");
		}
	}

	system("pause");
}