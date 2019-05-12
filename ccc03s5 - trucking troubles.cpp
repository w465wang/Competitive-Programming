/*
PEG
Date Started: 2017/11/03, Date Finished: 2017/11/05
*/

#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;
#pragma warning(disable:4996)

int c, R, d, p[10001], r[10001], dest[10001];
vector<pair<int, pair<int, int>>> edge;

int find_set(int x) {
	if (x != p[x]) {
		p[x] = find_set(p[x]);
	}

	return p[x];
}

void union_set(int x, int y) {
	if (r[x] > r[y]) {
		p[y] = x;
	} else {
		p[x] = y;
	}

	if (r[x] == r[y]) {
		r[y]++;
	}
}

int main() {
	scanf("%d%d%d", &c, &R, &d);

	for (int i = 1; i <= c; i++) {
		p[i] = i;
	}

	for (int i = 0, x, y, w; i < R; i++) {
		scanf("%d%d%d", &x, &y, &w);
		edge.push_back({ w,{ x, y } });
	}

	sort(edge.rbegin(), edge.rend());

	for (int i = 0, x; i < d; i++) {
		scanf("%d", &x);
		dest[x] = 1;
	}

	for (int i = 0, x, y, w; i < R; i++) {
		x = edge[i].second.first; y = edge[i].second.second; w = edge[i].first;

		if (find_set(x) != find_set(y) && d) {
			if (dest[x]) {
				dest[x] = 0;
				d--;
			}
			if (dest[y]) {
				dest[y] = 0;
				d--;
			}

			union_set(find_set(x), find_set(y));
		}

		if (!d) {
			printf("%d\n", w);
			i = R;
		}
	}

	system("pause");
}

/*
int c, r, d, wei, mx = 0, cnt, check[10001], dest[10001], weight[100001];
vector<pair<int, int>> node[10001];
vector<int> city;
bool done = false;

void dfs(int cur) {
    if (check[cur] || done) {
        return;
    }

	if (dest[cur]) {
		cnt++;
		dest[cur] = 0;
	}

	if (cnt == d) {
		done = true;
		return;
	}
    
    check[cur] = 1;
   
    int siz = node[cur].size();
    for (int i = 0; i < siz; i++) {
		if (node[cur][i].second >= wei) {
			dfs(node[cur][i].first);
		}
    }
}

int main() {
    scanf("%d%d%d", &c, &r, &d);
    
    for (int i = 0, x, y, w; i < r; i++) {
        scanf("%d%d%d", &x, &y, &w);
		node[x].push_back({ y,w });
		node[y].push_back({ x,w });
		weight[w] = 1;
		mx = max(mx, w);
	}
    
    for (int i = 0, x; i < d; i++) {
        scanf("%d", &x);
		dest[x] = 1;
		city.push_back(x);
    }

	int it = mx;
	while (!done && it > 0) {
		memset(check, 0, sizeof(check));
		wei = it; cnt = 0;
		dfs(1);
			
		for (int i = 0; i < d; i++) {
			if (!dest[city[i]]) {
				dest[city[i]] = 1;
			}
		}

		it -= 300;
	}

	done = false;
	it += 600;

	while (!done && it >= 0) {
		if (weight[it]) {
			memset(check, 0, sizeof(check));
			wei = it; cnt = 0;
			dfs(1);

			for (int i = 0; i < d; i++) {
				if (!dest[city[i]]) {
					dest[city[i]] = 1;
				}
			}
		}

		it--;
	}

	printf("%d\n", it + 1);

    system("pause");
}
*/