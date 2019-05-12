/*
PEG
Date Started: 2017/11/18, Date Finished: 2017/11/18
*/

#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <algorithm>
using namespace std;
#pragma warning(disable:4996)

int t, n, ans = 2000000, terr[30][30], check[30][30];

void bfs() {
	queue<pair<int, int>> Q, oxy;
	Q.push({ 1,1 }); oxy.push({ terr[1][1],0 });

	while (!Q.empty()) {
		int row = Q.front().first, col = Q.front().second, pre = oxy.front().first, con = oxy.front().second;
		Q.pop(); oxy.pop();

		if (abs(terr[row][col] - pre) <= 2) {
			if (pre > terr[1][1] || terr[row][col] > terr[1][1]) {
				con++;
			}

			if (row == n && col == n) {
				ans = min(ans, con);
			} else if (row > 0 && row <= n && col > 0 && col <= n && !check[row][col]) {
				check[row][col] = 1;

				Q.push({ row + 1,col }); oxy.push({ terr[row][col],con });
				Q.push({ row - 1,col }); oxy.push({ terr[row][col],con });
				Q.push({ row,col + 1 }); oxy.push({ terr[row][col],con });
				Q.push({ row,col - 1 }); oxy.push({ terr[row][col],con });
			}
		}
	}
}

int main() {
	scanf("%d", &t);

	for (int i = 0; i < t; i++) {
		scanf("%d", &n);

		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				scanf("%d", &terr[j][k]);
			}
		}

		bfs();

		if (ans == 2000000) {
			printf("CANNOT MAKE THE TRIP\n\n");
		} else {
			printf("%d\n\n", ans);
		}

		memset(terr, 0, sizeof(terr));
		memset(check, 0, sizeof(check));
		ans = 2000000;
	}

	system("pause");
}
