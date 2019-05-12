/*
PEG
Date Started: 2017/10/27, Date Finished: 2017/10/27
*/

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;

int len, cnt = 0, check[27][27], same[27][27];
map<int, vector<int>> node;
string in;
vector<string> all, bomb;

void dfs(pii p, string path) {
	if (check[p.first][p.second]) {
		return;
	}

    if (p.second == 1) {
		all.push_back(path);

		return;
    }
    
    int siz = node[p.second].size();
	for (int j = 0; j < siz; j++) {
		check[p.first][p.second] = 1;
		check[p.second][p.first] = 1;
		dfs({ p.second, node[p.second][j] }, path + (char)('A' + node[p.second][j]));
		check[p.first][p.second] = 0;
		check[p.second][p.first] = 0;
    }
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    cin >> in;
    
    while (in != "**") {
        int t1 = in[0] - 'A', t2 = in[1] - 'A';

        if (node.find(t1) == node.end()) {
            node[t1] = {t2};
        } else {
            node[t1].push_back(t2);
        }
        
        if (node.find(t2) == node.end()) {
            node[t2] = {t1};
        } else {
            node[t2].push_back(t1);
        }
        
        cin >> in;
    }

	len = node[0].size();
	for (int i = 0; i < len; i++) {
		string r = "";
		r.append(1, 'A');
		r.append(1, (char)(node[0][i] + 'A'));
		dfs({0, node[0][i]}, r);
	}
	
	len = all.size();
	for (int i = 0, siz; i < len; i++) {
		siz = all[i].size();

		for (int j = 0, t1, t2; j < siz - 1; j++) {
			t1 = min(all[i][j] - 'A', all[i][j + 1] - 'A');
			t2 = max(all[i][j] - 'A', all[i][j + 1] - 'A');

			same[t1][t2]++;
		}
	}

	for (int i = 0; i < 26; i++) {
		for (int j = i + 1; j < 26; j++) {
			if (same[i][j] == len) {
				string r = "";
				r.append(1, (char)(i + 'A'));
				r.append(1, (char)(j + 'A'));
				bomb.push_back(r);
				cnt++;
			}
		}
	}

	len = bomb.size();
	for (int i = 0; i < len; i++) {
		cout << bomb[i] << "\n";
	}
	printf("There are %d disconnecting roads.\n", cnt);
    
    system("pause");
}