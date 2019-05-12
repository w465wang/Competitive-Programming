/*
PEG
Date Started: 2017/12/04, Date Finished: 2017/12/04
*/

#include <iostream>
#include <queue>
#include <string.h>
#include <algorithm>
using namespace std;
#pragma warning(disable:4996)
typedef long long ll;
typedef pair<int, int> pii;

int n, r, c, pr, pc, kr, kc, temp, check[101][101];
bool done = false, win = false, stale = false;

void bfs() {
    queue<pii> Q; queue<int> pawn;
    Q.push({ kr,kc }); pawn.push(pr);
    
    while (!Q.empty() && !done) {
        int row = Q.front().first, col = Q.front().second, mov = pawn.front();
        Q.pop(); pawn.pop();
        
        if (row > 0 && row <= r && col > 0 && col <= c && check[row][col] < 2) {
            check[row][col]++;
            
            if (mov == r && !stale) {
                printf("Loss in %d knight move(s).\n", mov - pr - 1);
                done = true;
            } else if (row == mov && col == pc) {
                printf("Win in %d knight move(s).\n", mov - pr);
                done = true; win = true;
            } else if (row == mov + 1 && col == pc && !stale) {
                stale = true; temp = mov - pr;
            }
            
            Q.push({ row + 1,col + 2 }); pawn.push(mov + 1);
            Q.push({ row + 1,col - 2 }); pawn.push(mov + 1);
            Q.push({ row - 1,col + 2 }); pawn.push(mov + 1);
            Q.push({ row - 1,col - 2 }); pawn.push(mov + 1);
            Q.push({ row + 2,col + 1 }); pawn.push(mov + 1);
            Q.push({ row + 2,col - 1 }); pawn.push(mov + 1);
            Q.push({ row - 2,col + 1 }); pawn.push(mov + 1);
            Q.push({ row - 2,col - 1 }); pawn.push(mov + 1);
        }
    }
    
    if (!win && stale) {
        printf("Stalemate in %d knight move(s).\n", temp);
    }
}

int main() {
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        scanf("%d%d%d%d%d%d", &r, &c, &pr, &pc, &kr, &kc);
        bfs();
        
        memset(check, 0, sizeof(check)); done = false; win = false; stale = false;
    }
    
    system("pause");
}
