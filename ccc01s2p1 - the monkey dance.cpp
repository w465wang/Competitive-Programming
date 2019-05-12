/*
PEG
Date Started: 2018/02/03, Date Finished: 2018/02/03
*/

#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;
#pragma warning(disable:4996)
typedef pair<int, int> pi;

int n, node[105], check[105], ans;

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    } 
    
	return gcd(b, a % b);
}

void dfs(int cur, int cnt) {
    if (check[cur]) {
        if (cnt) {
            ans = ans * cnt / gcd(ans, cnt);
        }
        
        return;
    }
    
    check[cur] = 1;
    dfs(node[cur], cnt + 1);
}

int main() {
    scanf("%d", &n);
    
    while (n) {
        ans = 1;
        
        for (int i = 0, x, y; i < n; i++) {
            scanf("%d%d", &x, &y);
            node[x] = y;
        }
        
        for (int i = 1; i <= n; i++) {
            dfs(i, 0);
        }
        
        printf("%d\n", ans);
        memset(node, 0, sizeof(node)); memset(check, 0, sizeof(check));
        scanf("%d", &n);
    }
    
    
    system("pause");
}
