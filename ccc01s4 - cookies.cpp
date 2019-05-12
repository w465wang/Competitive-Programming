/*
PEG
Date Started: 2018/02/04, Date Finished: 2018/02/11
*/

#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
#pragma warning(disable:4996)
typedef pair<int, int> pi;

int n, maxX = 0, maxY = 0, minX = 1000, minY = 1000;
vector<pi> coor;

double best(double i, double j) {
	double mx = 0.0;

	for (int k = 0; k < n; k++) {
		double dist = (i - coor[k].first) * (i - coor[k].first) + (j - coor[k].second) * (j - coor[k].second);

		if (dist > mx) {
			mx = dist;
		}
	}

	return mx;
}

int main() {
	scanf("%d", &n);
	
	for (int i = 0, x, y; i < n; i++) {
		scanf("%d%d", &x, &y);
		coor.push_back({ x,y });

		maxX = max(maxX, x);
		maxY = max(maxY, y);
		minX = min(minX, x);
		minY = min(minY, y);
	}

	double curX = (minX + maxX) / 2, curY = (minY + maxY) / 2, jump = max(maxY - minY, maxX - minX);
	double bestX, bestY, bestMX, curMX;

	while (jump > 0.000001) {
		bestX = curX + jump; bestY = curY;
		bestMX = best(curX + jump, curY);
		
		curMX = best(curX - jump, curY);
		if (bestMX > curMX) {
			bestX = curX - jump; bestMX = curMX;
		}

		curMX = best(curX, curY + jump);
		if (bestMX > curMX) {
			bestY = curY + jump; bestMX = curMX;
		}

		curMX = best(curX, curY - jump);
		if (bestMX > curMX) {
			bestY = curY - jump; bestMX = curMX;
		}

		curX = bestX; curY = bestY;
		jump *= 0.999;
		//cout << curX << " " << curY << " " << bestMX << "\n";
	}

	printf("%.2lf\n", sqrt(bestMX) * 2);

	system("pause");
}
