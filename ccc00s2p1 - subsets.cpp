/*
PEG
Date Started: 2017/10/28, Date Finished: 2017/10/28
*/

#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;
#pragma warning(disable:4996)

int n, e, check[257], go[257];
char x, y;
string in;
vector<char> node[257], ans[257];

void dfs(char cur) {
	if (check[cur]) {
		return;
	}

	if (cur > 'Z') {
		if (find(ans[e].begin(), ans[e].end(), cur) == ans[e].end()) {
			ans[e].push_back(cur);
		}

		return;
	}

	check[cur] = 1;

	int siz = node[cur].size();
	for (int i = 0; i < siz; i++) {
		dfs(node[cur][i]);
	}
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> x >> in >> y;

		node[x].push_back(y);

		go[x] = 1;
		if (y <= 'Z') {
			go[y] = 1;
		}
	}

	for (char i = 'A'; i <= 'Z'; i++) {
		if (go[i]) {
			memset(check, 0, sizeof(check));
			e = i;
			dfs(i);

			sort(begin(ans[e]), end(ans[e]));
			int len = ans[e].size();

			printf("%c = {", e);
			for (int j = 0; j < len; j++) {
				printf("%c", ans[e][j]);
				if (j != len - 1) {
					printf(",");
				}
			}
			printf("}\n");
		}
	}

	system("pause");
}
