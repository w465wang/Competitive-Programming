/*
PEG
Date Started: 2017/11/07, Date Finished: 2017/11/09
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
#pragma warning(disable:4996)

int n, init, check[102], house[102], go[102], from[102];
vector<string> order, fin;
string ppl[102], name;
bool cycle = false;

void dfs(int cur) {
    if (cycle) {
        return;
    }
    
    if (check[cur]) {
        if (cur == init) {
            cycle = true;
        }
        return;
        
    }
    
    check[cur] = 1;
    order.insert(order.begin(), ppl[cur]);
    
    if (go[cur]) {
        dfs(go[cur]);
    }
}

void rdfs(int cur) {
    if (cycle) {
        return;
    }
    
    if (check[cur]) {
        if (cur == init) {
            cycle = true;
        }
        return;
    }
    
    check[cur] = 1;
    order.push_back(ppl[cur]);
    
    if (from[cur]) {
        rdfs(from[cur]);
    }
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 1, x, y; i <= n; i++) {
		cin >> name >> x >> y;
        ppl[x] = name;
		house[i] = x;
        go[x] = y;
        from[y] = x;
	}

	for (int i = 1; i <= n; i++) {
        init = house[i];
        
        if (!check[init]) {
            dfs(init);
        }
        
        if (from[init] && !check[from[init]]) {
            rdfs(from[init]);
        }
        
        for (string j : order) {
            fin.push_back(j);
        }
        order.clear();
	}

	if (cycle) {
		cout << "Impossible\n";
    } else {
        for (int i = 0; i < fin.size(); i++) {
            cout << fin[i] << "\n";
        }
    }

	system("pause");
}
