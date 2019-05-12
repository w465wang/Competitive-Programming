/*
PEG
Date Started: 2017/10/09, Date Finished: 2017/10/12
*/

#include <iostream>
#include <algorithm>
using namespace std;
#pragma warning(disable:4996)

int n, ans = 0, a[401][401], pre[401];

int main()
{
    scanf("%d", &n);
    
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i][i]);
        pre[i] = a[i][i] + pre[i - 1];
        ans = max(ans, a[i][i]);
        
        if (a[i][i] == a[i - 1][i - 1])
            a[i - 1][i] = a[i][i] * 2;
        
        ans = max(ans, a[i - 1][i]);
    }
    
    for (int i = 2; i <= n - 1; i++) {
        for (int j = 1, start, end, t1, t2; j <= n - i; j++) {
            start = j; end = j + i;
            
            while (start < end) {
                if (a[j][start]) {
                    t1 = pre[start] - pre[j - 1];
                } else {
                    t1 = 0;
                }
                
                if (a[end][j + i]) {
                    t2 = pre[j + i] - pre[end - 1];
                } else {
                    t2 = 0;
                }
                
                if (t1 == t2) {
                    if (t1 == 0) {
                        a[j][j + i] = 0;
                    } else if (a[j][start] == a[end][j + i]) {
                        if (a[start][start] == a[end][end] || a[j][start]) {
                            a[j][j + i] = t1 * 2;
                            
                            if (a[start + 1][end - 1] && start + 1 != end - 1) {
                                a[j][j + i] += a[start + 1][end - 1];
                                break;
                            }
                        }
                    }

                    start++;
                    end--;
                } else if (t1 < t2) {
                    a[j][j + i] = 0;
                    start++;
                } else if (t1 > t2) {
                    a[j][j + i] = 0;
                    end--;
                }
            }
        
            if (start == end && t1 == t2 && a[j][j + i])
                a[j][j + i] += a[start][start];

            ans = max(ans, a[j][j + i]);
        }
    }
    
    printf("%d\n", ans);
    
    system("pause");
}
