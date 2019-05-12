/*
PEG
Date Started: 2018/01/13, Date Finished: 2018/01/13
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#pragma warning(disable:4996)
typedef pair<int, int> pi;

int n, x, y, node[10001];

void dfs(int cur, int cnt) {
    if (cur == y) {
        printf("Yes %d\n", cnt);
        return;
    } else if (!cur || (cur == x && cnt >= 0)) {
        printf("No\n");
        return;
    }
    
    dfs(node[cur], cnt + 1);
}

int main() {
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &x, &y);
        node[x] = y;
    }
    
    scanf("%d%d", &x, &y);
    while (x) {
        dfs(x, -1);
        scanf("%d%d", &x, &y);
    }
    
    system("pause");
}
