/*
CCC
Date Started: 2018/02/14, Date Finished: 2018/02/14
*/

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> pi;

int n, m, point[102][102], check[102][102];
char grid[102][102];
vector<pi> coor;
pi start;

void bfs() {
    queue<pi> Q; queue<int> step;
    Q.push(start); step.push(0);
    
    while (!Q.empty()) {
        int row = Q.front().first, col = Q.front().second, mov = step.front();
        Q.pop(); step.pop();

        if (row >= 0 && row < n && col >= 0 && col < m && mov < point[row][col] && grid[row][col] != 'W' && !check[row][col]) {
            point[row][col] = mov;
            
            if (grid[row][col] == 'S') {
                mov++;
                
                Q.push({row + 1, col}); step.push(mov);
                Q.push({row - 1, col}); step.push(mov);
                Q.push({row, col + 1}); step.push(mov);
                Q.push({row, col - 1}); step.push(mov);
            } else if (grid[row][col] == '.') {
                mov++;
                
                Q.push({row + 1, col}); step.push(mov);
                Q.push({row - 1, col}); step.push(mov);
                Q.push({row, col + 1}); step.push(mov);
                Q.push({row, col - 1}); step.push(mov);
            } else if (grid[row][col] == 'U') {
                Q.push({row - 1, col}); step.push(mov);
            } else if (grid[row][col] == 'D') {
                Q.push({row + 1, col}); step.push(mov);
            } else if (grid[row][col] == 'L') {
                Q.push({row, col - 1}); step.push(mov);
            } else if (grid[row][col] == 'R') {
                Q.push({row, col + 1}); step.push(mov);
            }
        }
    }
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
            point[i][j] = 2000000;
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '.') {
                coor.push_back({i,j});
            } else if (grid[i][j] == 'S') {
                start = {i,j};
            } else if (grid[i][j] == 'C') {
                check[i][j] = 1;
                for (int k = i + 1; k < n; k++) {
                    if (grid[k][j] == '.' || grid[k][j] == 'S') {
                        check[k][j] = 1;
                    } else if (grid[k][j] == 'W') {
                        break;
                    }
                    
                }
                for (int k = i - 1; k >= 0; k--) {
                    if (grid[k][j] == '.' || grid[k][j] == 'S') {
                        check[k][j] = 1;
                    } else if (grid[k][j] == 'W') {
                        break;
                    }
                    
                }
                for (int k = j + 1; k < m; k++) {
                    if (grid[i][k] == '.' || grid[i][k] == 'S') {
                        check[i][k] = 1;
                    } else if (grid[i][k] == 'W') {
                        break;
                    }
                }
                for (int k = j - 1; k >= 0; k--) {
                    if (grid[i][k] == '.' || grid[i][k] == 'S') {
                        check[i][k] = 1;
                    } else if (grid[i][k] == 'W') {
                        break;
                    }
                }
            }
        }
    }

    bfs();
    
    int siz = coor.size();
    for (int i = 0; i < siz; i++) {
        if (point[coor[i].first][coor[i].second] == 2000000) {
            printf("-1\n");
        } else {
            printf("%d\n", point[coor[i].first][coor[i].second]);
        }
    }
}
