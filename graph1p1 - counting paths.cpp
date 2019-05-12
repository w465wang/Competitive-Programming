/*
PEG
Date Started: 2017/11/24, Date Finished: 2017/12/02
*/

#include <iostream>
using namespace std;
#pragma warning(disable:4996)

int n, k, cnt, grid[101][101], look[101][101];
bool check[101][101];

int recurse(int cur, int len) {
	if (!len) {
		return 1;
	}

	if (check[cur][len]) {
		return look[cur][len];
	}

	check[cur][len] = 1;

	int tot = 0;
	for (int i = 0; i < n; i++) {
		if (grid[cur][i]) {
			tot += recurse(i, len - 1);
		}
	}

	look[cur][len] = tot;
	return tot;
}

int main() {
	scanf("%d%d", &n, &k);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &grid[i][j]);
		}
	}

	for (int i = 0; i < n; i++) {
		cnt += recurse(i, k);
	}

	printf("%d\n", cnt);

	system("pause");
}
