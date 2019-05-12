/*
PEG
Date Started: 2017/10/27, Date Finished: 2017/10/28
*/

#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
#pragma warning(disable:4996)

int n, m, a, b, c, arr[101][101], check[101][101];
bool done = false;

void dfs(int row, int col) {
	if (check[row][col] || done || row < 0 || row == m || col < 0 || col == n) {
		return;
	}

	if (!(arr[row][col] == a || arr[row][col] == b || arr[row][col] == c)) {
		return;
	}

	if (row == m - 1) {
		done = true;

		return;
	}

	check[row][col] = 1;
	dfs(row, col + 1);
	dfs(row, col - 1);
	dfs(row + 1, col);
	dfs(row - 1, col);
}

int main() {
	scanf("%d%d", &n, &m);

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &arr[i][j]);
		}
	}

	for (int i = 0; i <= 9; i++) {
		for (int j = i; j <= 9; j++) {
			for (int k = j; k <= 9; k++) {
				if (!done) {
					a = i; b = j; c = k;

					for (int col = 0; col < n; col++) {
						memset(check, 0, sizeof(check));
						dfs(0, col);
					}
				}
			}
		}
	}

	if (done) {
		printf("%d %d %d\n", a, b, c);
	} else {
		printf("-1 -1 -1\n");
	}

	system("pause");
}