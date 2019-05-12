/*
PEG
Date Started: 2017/11/25, Date Finished: 2017/11/25
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#pragma warning(disable:4996)

long long ans, n, t, x[2005], y[2005], tint[1005], compx[2005], compy[2005], arr[2005][2005];
vector<long long> sortx, sorty;

int main() {
    scanf("%lld%lld", &n, &t);
    
    for (int i = 0; i < n; i++) {
        scanf("%lld%lld%lld%lld%lld", &x[i * 2], &y[i * 2], &x[i * 2 + 1], &y[i * 2 + 1], &tint[i]);
		if (find(sortx.begin(), sortx.end(), x[i * 2]) == sortx.end()) {
			sortx.push_back(x[i * 2]);
		}
		if (find(sortx.begin(), sortx.end(), x[i * 2 + 1]) == sortx.end()) {
			sortx.push_back(x[i * 2 + 1]);
		}
		if (find(sorty.begin(), sorty.end(), y[i * 2]) == sorty.end()) {
			sorty.push_back(y[i * 2]);
		}
		if (find(sorty.begin(), sorty.end(), y[i * 2 + 1]) == sorty.end()) {
			sorty.push_back(y[i * 2 + 1]);
		}
    }

	sort(sortx.begin(), sortx.end());
	sort(sorty.begin(), sorty.end());
    
    for (int i = 0, a, b, c, d; i < n; i++) {
        a = lower_bound(sortx.begin(), sortx.end(), x[i * 2]) - sortx.begin() + 1;
        b = lower_bound(sorty.begin(), sorty.end(), y[i * 2]) - sorty.begin() + 1;
        c = lower_bound(sortx.begin(), sortx.end(), x[i * 2 + 1]) - sortx.begin() + 1;
        d = lower_bound(sorty.begin(), sorty.end(), y[i * 2 + 1]) - sorty.begin() + 1;
        
        compx[a] = x[i * 2]; compx[c] = x[i * 2 + 1];
        compy[b] = y[i * 2]; compy[d] = y[i * 2 + 1];

        arr[a][b] += tint[i];
        arr[a][d] -= tint[i];
        arr[c][b] -= tint[i];
        arr[c][d] += tint[i];
    }
    
    for (int i = 1; i <= 2 * n + 1; i++) {
        for (int j = 1; j <= 2*n + 1; j++) {
            arr[i][j] += arr[i][j - 1];
        }
    }
    
	int lenx = sortx.size(), leny = sorty.size();
    for (int i = 1; i <= lenx; i++) {
		long long start = -1; long long end = 0;

        for (int j = 1; j <= leny; j++) {
            arr[i][j] += arr[i - 1][j];
			
            if (arr[i][j] >= t) {		
				if (start == -1) {
					start = compy[j];
				}
				
				end = compy[j + 1];
			} else {
				if (start != -1) {
					ans += (compx[i + 1] - compx[i]) * (end - start);
				}

				start = -1; end = 0;
			}
        }
    }
    
	printf("%lld\n", ans);

    system("pause");
}