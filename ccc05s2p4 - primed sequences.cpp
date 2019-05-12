/*
PEG
Date Started: 2018/02/10, Date Finished: 2018/02/10
*/

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
#pragma warning(disable:4996)

int t, n, num, nums[10002], pre[10002];
vector<int> divi;

void init(int it, int stop) {
    if (it > stop)
        divi.push_back(num);
    else if (num % it == 0)
        return;
    else
        init(it + 1, stop);
}

int main() {
    scanf("%d", &t);
    
    for (int i = 2; i <= 10000; i++) {
        num = i;
        init(2, sqrt(i));
    }
    
    int siz = divi.size();
    
    for (int i = 0; i < t; i++) {
        scanf("%d", &n);
        
        for (int j = 1; j <= n; j++) {
            scanf("%d", &nums[j]);
            
            pre[j] = nums[j] + pre[j - 1];
        }
        
        bool done = false;
        for (int k = 2; k <= n; k++) {
            for (int j = 1; j <= n - k + 1; j++) {
                int seq = pre[j + k - 1] - pre[j - 1];

                for (int l = 0; l < siz; l++) {
                    if (divi[l] * divi[l] <= seq) {
                        if (seq % divi[l] == 0) {
                            break;
                        }
                    } else {
                        printf("Shortest primed subsequence is length %d: ", k);
                        for (int q = j; q <= j + k - 1; q++) {
                            printf("%d ", nums[q]);
                        }
                        printf("\n");
                        
                        done = true;
                        break;
                    }
                }
                
                if (done) {
                    break;
                }
            }
            
            if (done) {
                break;
            }
        }
        
        if (!done) {
            printf("This sequence is anti-primed.\n");
        }
    }
    
    system("pause");
}
