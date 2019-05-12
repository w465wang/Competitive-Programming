/*
PEG
Date Started: 2017/11/02, Date Finished: 2017/11/02
*/

#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;
#pragma warning(disable:4996)

int x, y, deg, check[51], checkf[51];
vector<int> node[51];
char ins;

void dfs(int cur, int p) {
	if (check[cur]) {
		return;
	}

	if (cur == y) {
		deg = min(deg, p);

		return;
	}

	check[cur] = 1;

	int siz = node[cur].size();
	for (int i = 0; i < siz; i++) {
		dfs(node[cur][i], p + 1);
	}

	check[cur] = 0;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	node[1] = { 6 }; node[2] = { 6 }; node[3] = { 4,5,6,15 }; node[4] = { 3,5,6 };
	node[5] = { 3,4,6 }; node[6] = { 1,2,3,4,5,7 }; node[7] = { 6,8 }; node[8] = { 7,9 };
	node[9] = { 8,10,12 }; node[10] = { 9,11 }; node[11] = { 10,12 }; node[12] = { 9,11,13 };
	node[13] = { 12,14,15 }; node[14] = { 13 }; node[15] = { 3,13 }; node[16] = { 17,18 };
	node[17] = { 16,18 }; node[18] = { 16,17 };
	
	cin >> ins;
	while (ins != 'q') {
		cin >> x;

		if (ins == 'i') {
			cin >> y;
			if (find(node[x].begin(), node[x].end(), y) == node[x].end()) {
				node[x].push_back(y);
			}
			if (find(node[y].begin(), node[y].end(), x) == node[y].end()) {
				node[y].push_back(x);
			}
		} else if (ins == 'd') {
			cin >> y;
			node[x].erase(find(node[x].begin(), node[x].end(), y));
			node[y].erase(find(node[y].begin(), node[y].end(), x));
		} else if (ins == 'n') {
			printf("%d\n", node[x].size());
		} else if (ins == 'f') {
			int len = node[x].size(), cnt = 0;
			checkf[x] = 1;
			for (int i = 0; i < len; i++) {
				checkf[node[x][i]] = 1;
			}
			for (int i = 0, lol; i < len; i++) {
				lol = node[node[x][i]].size();
				for (int j = 0; j < lol; j++) {
					if (!checkf[node[node[x][i]][j]]) {
						cnt++;
						checkf[node[node[x][i]][j]] = 1;
					}
				}
			}
			printf("%d\n", cnt);
			memset(checkf, 0, sizeof(checkf));
		} else if (ins == 's') {
			cin >> y;
			deg = 2000000; 
			dfs(x, 0);
			if (deg != 2000000) {
				printf("%d\n", deg);
			} else {
				printf("Not connected\n");
			}
			memset(check, 0, sizeof(check));
		}

		cin >> ins;
	}

	system("pause");
}
