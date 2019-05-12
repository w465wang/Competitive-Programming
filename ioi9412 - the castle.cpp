/*
PEG
Date Started: 2017/11/08, Date Finished: 2017/11/08
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#pragma warning(disable:4996)

int n, m, room = 0, siz, mx1 = 0, mx2 = 0, check[52][52], castle[52][52];
vector<int> rooms = {0};
pair<int, int> brk;
char f;

void dfs(int row, int col) {
    if (check[row][col] || row == 0 || row > n || col == 0 || col > m) {
        return;
    }
    
    check[row][col] = room;
    siz++;
    
    if (castle[row][col] == 1) {
        dfs(row - 1, col); dfs(row + 1, col); dfs(row, col + 1);
    } else if (castle[row][col] == 2) {
        dfs(row + 1, col); dfs(row, col - 1); dfs(row, col + 1);
    } else if (castle[row][col] == 4) {
        dfs(row - 1, col); dfs(row + 1, col); dfs(row, col - 1);
    } else if (castle[row][col] == 8) {
        dfs(row - 1, col); dfs(row, col - 1); dfs(row, col + 1);
    } else if (castle[row][col] == 3) {
        dfs(row + 1, col); dfs(row, col + 1);
    } else if (castle[row][col] == 6) {
        dfs(row + 1, col); dfs(row, col - 1);
    } else if (castle[row][col] == 12) {
        dfs(row - 1, col); dfs(row, col - 1);
    } else if (castle[row][col] == 5) {
        dfs(row - 1, col); dfs(row + 1, col);
    } else if (castle[row][col] == 10) {
        dfs(row, col - 1); dfs(row, col + 1);
    } else if (castle[row][col] == 9) {
        dfs(row - 1, col); dfs(row, col + 1);
    } else if (castle[row][col] == 7) {
        dfs(row + 1, col);
    } else if (castle[row][col] == 14) {
        dfs(row, col - 1);
    } else if (castle[row][col] == 11) {
        dfs(row, col + 1);
    } else if (castle[row][col] == 13) {
        dfs(row - 1, col);
    } else if (castle[row][col] == 0) {
        dfs(row - 1, col); dfs(row + 1, col); dfs(row, col - 1); dfs(row, col + 1);
    }
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> m >> n;
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> castle[i][j];
        }
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (!check[i][j]) {
                room++;
                siz = 0;
                dfs(i, j);
                rooms.push_back(siz);
                mx1 = max(mx1, siz);
            }
        }
    }
    
    for (int j = 1; j <= m; j++) {
        for (int i = n; i > 0; i--) {
            if (i - 1 > 0 && check[i][j] != check[i - 1][j]) {
                if (rooms[check[i][j]] + rooms[check[i - 1][j]] > mx2) {
                    mx2 = rooms[check[i][j]] + rooms[check[i - 1][j]];
                    brk = {i, j};
                    f = 'N';
                }
            }
            if (j + 1 <= m && check[i][j] != check[i][j + 1]) {
                if (rooms[check[i][j]] + rooms[check[i][j + 1]] > mx2) {
                    mx2 = rooms[check[i][j]] + rooms[check[i][j + 1]];
                    brk = {i, j};
                    f = 'E';
                }
            }
        }
    }
    
    printf("%d\n%d\n%d\n%d %d %c\n", rooms.size() - 1, mx1, mx2, brk.first, brk.second, f);
    
    system("pause");
}
