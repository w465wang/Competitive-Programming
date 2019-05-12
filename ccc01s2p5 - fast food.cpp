/*
PEG
Date Started: 2018/02/11, Date Finished: 2018/02/11
*/

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
#pragma warning(disable:4996)

int n;

int main() {
	scanf("%d", &n);

	while (n) {
		int trial = 0;
		vector<pair<int, int>> rest;
		vector<int> cnt;

		for (int i = 0, x, y; i < n; i++) {
			scanf("%d%d", &x, &y);
			rest.push_back({ x,y });
			cnt.push_back(0);
		}

		for (double i = 0; i < 10; i += 0.05) {
			for (double j = 0; j < 10; j += 0.05) {
				trial++;

				int it; double mn = 1000.0;
				for (int k = 0; k < n; k++) {
					double dist = (i - rest[k].first) * (i - rest[k].first) + (j - rest[k].second) * (j - rest[k].second);

					if (dist < mn) {
						mn = dist;
						it = k;
					}
				}

				cnt[it]++;
			}
		}

		for (int i = 0; i < n; i++) {
			printf("Restaurant at (%d,%d) serves %.0lf%% of the population.\n", rest[i].first, rest[i].second, (double)cnt[i] / trial * 100);
		}

		scanf("%d", &n);
	}

	system("pause");
}
