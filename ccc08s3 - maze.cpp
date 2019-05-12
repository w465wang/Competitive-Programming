/*
PEG
Date Started: 2017/11/18, Date Finished: 2017/11/18
*/

#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <string.h>
#include <algorithm>
using namespace std;
#pragma warning(disable:4996)

int t, r, c, check[25][25];
char city[25][25];
string line;

int bfs() {
	queue<pair<int, int>> Q;
	queue<int> inter;
	Q.push({ 0,0 });
	inter.push(1);

	while (!Q.empty()) {
		int row = Q.front().first, col = Q.front().second, num = inter.front();
		Q.pop(); inter.pop();

		if (row == r - 1 && col == c - 1 && city[row][col] != '*') {
			return num;
		} else if (row >= 0 && row < r && col >= 0 && col < c && !check[row][col]) {
			check[row][col] = 1;
			
			if (city[row][col] == '+' || city[row][col] == '-') {
				Q.push({ row,col + 1 }); inter.push(num + 1);
				Q.push({ row,col - 1 }); inter.push(num + 1);
			}
			if (city[row][col] == '+' || city[row][col] == '|') {
				Q.push({ row + 1,col }); inter.push(num + 1);
				Q.push({ row - 1,col }); inter.push(num + 1);
			}
		}
	}

	return 0;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> t;

	for (int i = 0; i < t; i++) {
		cin >> r >> c;
		for (int j = 0; j < r; j++) {
			cin >> line;
			for (int k = 0; k < c; k++) {
				city[j][k] = line[k];
			}
		}

		int tot = bfs();
		if (tot) {
			cout << tot << "\n";
		} else {
			cout << -1 << "\n";
		}

		memset(city, 0, sizeof(city));
		memset(check, 0, sizeof(check));
	}
	
	system("pause");
}
