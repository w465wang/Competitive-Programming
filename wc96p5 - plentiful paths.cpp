/*
PEG
Date Started: 2017/09/12, Date Finished: 2017/09/12
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int grid[101][101] = { }, m, n, r, c;

void path(int row, int col)
{
    if (row > m)
    {
        cout << grid[m][n] << "\n";
        return;
    }
    
    int plus = 0;
    if (grid[row][col] == -1)
        plus = 1;
    
    grid[row][col] = max(grid[row - 1][col], grid[row][col - 1]) + plus;
    
    col++;
    if (col > n)
    {
        row++;
        col = 1;
    }
    
    path(row, col);
}

int main()
{
    cin >> m >> n;
    cin >> r >> c;
    while (r != 0 && c != 0)
    {
        grid[r][c] = -1;
        cin >> r >> c;
    }
    
    path(1, 1);
    
    system("pause");
}


