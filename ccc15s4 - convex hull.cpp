/*
PEG
Date Started: 2017/11/29, Date Finished: 2017/12/02
*/

#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <algorithm>
using namespace std;
#pragma warning(disable:4996)

int k, n, m, A, B, ans = 2000000000;
vector<vector<int>> best(2001, vector<int>(201, 2000000000));
vector<pair<int, pair<int, int>>> node[2001];

void bfs() {
    queue<int> Q; queue<pair<int, int>> path;
    Q.push(A); path.push({ 0,k });
    
    while (!Q.empty()) {
        int cur = Q.front(), len = path.front().first, hull = path.front().second, siz = node[cur].size();
        Q.pop(); path.pop();

        if (len < ans && hull > 0 && len < best[cur][hull]) {
            if (cur == B) {
                ans = len;
            } else {
                for (int i = 0; i < siz; i++) {
                    Q.push(node[cur][i].first);
                    path.push({ len + node[cur][i].second.first, hull - node[cur][i].second.second });
                }
            }

			best[cur][hull] = len;
        }
    }
}

int main() {
    scanf("%d%d%d", &k, &n, &m);
    
    for (int i = 0, a, b, t, h; i < m; i++) {
        scanf("%d%d%d%d", &a, &b, &t, &h);
        node[a].push_back({ b,{ t,h } });
        node[b].push_back({ a,{ t,h } });
    }
    
    scanf("%d%d", &A, &B);
    bfs();
    
	if (ans == 2000000000) {
		printf("-1\n");
	} else {
		printf("%d\n", ans);
	} 
    
    system("pause");
}
