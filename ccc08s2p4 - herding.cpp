/*
PEG
Date Started: 2017/11/07, Date Finished: 2017/11/07
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
#pragma warning(disable:4996)

int n, m, ans = 1, trap[1001][1001], check[1001][1001];
string in;
vector<pair<int, int>> temp;

void dfs(int row, int col) {
	if (row < 0 || row == n || col < 0 || col == m) {
		ans++;
		return;
	}

	if (check[row][col]) {
		if (check[row][col] == ans) {
			ans++;
		} else {
			int len = temp.size();
			for (int i = 0; i < len; i++) {
				check[temp[i].first][temp[i].second] = check[row][col];
			}
		}

		temp.clear();
		return;
	}

	check[row][col] = ans;
	temp.push_back({ row, col });

	if (trap[row][col] == 'N') {
		dfs(row - 1, col);
	} else if (trap[row][col] == 'S') {
		dfs(row + 1, col);
	} else if (trap[row][col] == 'W') {
		dfs(row, col - 1);
	} else if (trap[row][col] == 'E') {
		dfs(row, col + 1);
	}
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> in;

		for (int j = 0; j < m; j++) {
			trap[i][j] = in[j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			dfs(i, j);
		}
	}

	printf("%d\n", ans - 1);

	system("pause");
}