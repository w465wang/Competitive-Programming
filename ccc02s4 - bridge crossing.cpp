/*
PEG
Date Started: 2017/10/09, Date Finished: 2017/10/15
*/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
#pragma warning(disable:4996)

int m, q, mem[101][101], temp[101], fin[101], mn = 2000000000;
string name[101];

void part(int it, int time)
{
	if (time >= mn || it > q + 1)
		return;

	if (it == q + 1) {
		mn = time;
		for (int i = 0; i <= 100; i++) {
			fin[i] = temp[i];
		}

		return;
	}

	for (int i = 1; i <= m; i++) {
		temp[it] = 1;
		part(it + i, time + mem[it][it + i - 1]);
		temp[it] = 0;
	}
}

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	cin >> m >> q;

	for (int i = 1; i <= q; i++) {
		cin >> name[i] >> mem[i][i];
	}

	for (int i = 1; i < m; i++) {
		for (int j = 1; j <= q - i; j++) {
			mem[j][j + i] = max(mem[j][j + i - 1], mem[j + 1][j + i]);
		}
	}

	part(1, 0);

	cout << "Total Time: " << mn;
	for (int i = 1; i <= q; i++) {
		if (fin[i]) {
			cout << "\n";
		}
		cout << name[i] << " ";
	}
	cout << "\n";

	system("pause");
}