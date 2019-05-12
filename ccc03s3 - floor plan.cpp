/*
PEG
Date Started: 2017/10/30, Date Finished: 2017/10/30
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
#pragma warning(disable:4996)

int f, r, c, wood, room = 0, floo[26][26];
string ln;
vector<int> all;

void dfs(int row, int col) {
	if (floo[row][col] || row < 0 || row == r || col < 0 || col == c) {
		return;
	}

	wood++;
	floo[row][col] = 2;

	dfs(row + 1, col);
	dfs(row - 1, col);
	dfs(row, col + 1);
	dfs(row, col - 1);
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> f >> r >> c;

	for (int i = 0; i < r; i++) {
		cin >> ln;

		for (int j = 0; j < c; j++) {
			if (ln[j] == 'I') {
				floo[i][j] = 1;
			}
			else {
				floo[i][j] = 0;
			}
		}
	}

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			wood = 0;

			if (!floo[i][j]) {
				dfs(i, j);
				all.push_back(wood);
			}
		}
	}

	sort(all.rbegin(), all.rend());

	int it = 0, len = all.size();
	while (f >= 0 && it < len) {
		f -= all[it];

		if (f >= 0) {
			room++;
			it++;
		}
	}

	if (room == 1) {
		printf("%d room, %d square metre(s) left over\n", room, f + all[it]);
	}
	else {
		printf("%d rooms, %d square metre(s) left over\n", room, f + all[it]);
	}

	system("pause");
}