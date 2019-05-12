/*
PEG
Date Started: 2017/11/29, Date Finished: 2017/11/29
*/

#include <iostream>
#include <queue>
#include <string.h>
#include <algorithm>
using namespace std;
#pragma warning(disable:4996)

int n, x, y, ans, check[17][17][7][7];
bool done = false;

void bfs(int startx, int starty, int endx, int endy) {
    queue<pair<int, int>> Q, vel; queue<int> move;
    Q.push({ startx,starty }); vel.push({ 0,0 }); move.push(0);
    
    while (!Q.empty()) {
        int row = Q.front().first, col = Q.front().second, mov = move.front(), velx = vel.front().first, vely = vel.front().second;
        Q.pop(); move.pop(); vel.pop();
        
        if (abs(velx) <= 3 && abs(vely) <= 3) {
            if (row == endx && col == endy) {
                ans = mov; done = true;
                return;
            } else if (row >= 0 && row < x && col >= 0 && col < y && !check[row][col][velx + 3][vely + 3]) {
                check[row][col][velx + 3][vely + 3] = 1;
                for (int i = -1; i <= 1; i++) {
                    for (int j = -1; j <= 1; j++) {
                        Q.push({ row + velx + i,col + vely + j });
                        vel.push({ velx + i,vely + j });
                        move.push(mov + 1);
                    }
                }
            }
        }
    }
}

int main() {
    scanf("%d", &n);
    
    for (int i = 0, a, b, c, d, e, f, g, h, p; i < n; i++) {
        scanf("%d%d%d%d%d%d%d", &x, &y, &a, &b, &c, &d, &p);
        
        for (int j = 0; j < p; j++) {
            scanf("%d%d%d%d", &e, &f, &g, &h);
            
            for (int k = e; k <= f; k++) {
                for (int l = g; l <= h; l++) {
                    for (int m = -3; m <= 3; m++) {
                        for (int o = -3; o <= 3; o++) {
                            check[k][l][m + 3][o + 3] = 1;
                        }
                    }
                }
            }
        }
        
        bfs(a, b, c, d);
        
        if (done) {
            printf("Optimal solution takes %d hop(s).\n", ans);
        } else {
            printf("No solution.\n");
        }
        
        memset(check, 0, sizeof(check)); done = false;
    }
    
    system("pause");
}
