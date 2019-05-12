/*
PEG
Date Started: 2017/11/08, Date Finished: 2017/11/09
*/

#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <string.h>
#include <algorithm>
using namespace std;
#pragma warning(disable:4996)

int n, check[101];
map<int, vector<string>> node;
map<string, int> urls;
string link, in, from, to;
bool done = false;

void dfs(string cur, int it) {
    if (check[it] || done) {
        return;
    }
    
	if (cur == to) {
		done = true;
		return;
	}

    check[it] = 1;
    
    int siz = node[it].size();
    for (int i = 0; i < siz; i++) {
		dfs(node[it][i], urls[node[it][i]]);
    }
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> link;
		urls[link] = i;
		node[i] = { };
        
        getline(cin, in);
        
        while (in.find("</HTML>") == -1) {
            int start = 0;
            
            while (in.find("<A HREF=", start) != -1) {
                start = in.find("<A HREF=", start) + 9;
                string url = "";
                
                while (in[start] != '"') {
                    url += in[start];
                    
                    start++;
                }
                
                cout << "Link from " << link << " to " << url << "\n";
                node[i].push_back(url);
            }
            
            getline(cin, in);
        }
    }

    cin >> from;
    while (from != "The") {
        cin >> to;
		dfs(from, urls[from]);

		if (done) {
			cout << "Can surf from ";
		} else {
			cout << "Can't surf from ";
		}

		cout << from << " to " << to << "\n";
        
        cin >> from;
		memset(check, 0, sizeof(check)); done = false;
    }
    
    system("pause");
}
